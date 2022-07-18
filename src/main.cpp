#include <iostream>
#include "logic/includes/CentroidTracker.h"
#include "logic/includes/LinkedList.h"
#include "logic/includes/Persona.h"
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;
using namespace std;

string CLASSES[] = {"background", "aeroplane", "bicycle", "bird", "boat",
	"bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
	"dog", "horse", "motorbike", "person", "pottedplant", "sheep",
	"sofa", "train", "tvmonitor"};
/*
* Funcion que permite la detección y conteo de personas
* Calcula el centroide 
* Utiliza un video 
* Retorna un vector con el contador de personas que entran (0)  y que salen (1)
*/
pair<int,int> watchVideo1(){
    //vector que almacenara la informacion de entrada y salida
    pair<int,int> infoGente;
    // Se inicializa una instancia de la clase centroidTracker
    auto centroidTracker = new CentroidTracker(20);
    //Se crea la LinkedList
    LinkedList trackableObjects = LinkedList();
    VideoCapture cap("C:/Users/maria/OneDrive/Escritorio/Proyecto estructura/src/example_01.mp4");

    string modelTxt = "E:/Repos VS Code/Centroid-Object-Tracking/model/deploy.prototxt";
    string modelBin = "E:/Repos VS Code/Centroid-Object-Tracking/model/res10_300x300_ssd_iter_140000.caffemodel";

    auto net = dnn::readNetFromCaffe(modelTxt, modelBin);
    //Contadores de entrada y salida
    int totalUp = 0; //personas que entran
    int totalDown = 0; // personas que salen

    while (cap.isOpened()) {
        // Declaracion del cameraFrame de la clase Mat
        Mat cameraFrame;
        //Lectura de frames
        cap.read(cameraFrame); 
        // Cambio de tamaño de una imagen
        resize(cameraFrame, cameraFrame, Size(400, 300));
       
        vector<vector<int>> rects;
        //Deteccion a traves de una colección de imagenes que recopila
        auto inputBlob = dnn::blobFromImage(cameraFrame, 1.0, Size(400, 300), Scalar(104.0, 177.0, 123.0));
        net.setInput(inputBlob);
        auto detection = net.forward("detection_out");
        Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

        float confidenceThreshold = 0.4;//Limite en la deteccion
        for (int i = 0; i < detectionMat.rows; i++) {
            float confidence = detectionMat.at<float>(i, 2);

            if (confidence > confidenceThreshold) {
                //Limitantes en la imagen
                int xLeftTop = static_cast<int>(detectionMat.at<float>(i, 3) * cameraFrame.cols);
                int yLeftTop = static_cast<int>(detectionMat.at<float>(i, 4) * cameraFrame.rows);
                int xRightBottom = static_cast<int>(detectionMat.at<float>(i, 5) * cameraFrame.cols);
                int yRightBottom = static_cast<int>(detectionMat.at<float>(i, 6) * cameraFrame.rows);
                // creacion del recuadro rojo
                Rect object((int) xLeftTop, (int) yLeftTop, (int) (xRightBottom - xLeftTop),
                            (int) (yRightBottom - yLeftTop));
                rectangle(cameraFrame, object, Scalar(0, 255, 0), 2);
                rects.insert(rects.end(), {xLeftTop, yLeftTop, xRightBottom, yRightBottom});
            }
        } 
        Point p1 = (0,300/2);
        Point p2 = (400,300/2);
        line(cameraFrame,p1,p2,Scalar(0, 0, 255));

        auto objects = centroidTracker->update(rects);

        if (!objects.empty()) {
            for (auto obj: objects) {
                //creacion del objeto persona
                Persona p = trackableObjects.get(obj.first);
                //creacion del ID para identificar a las personas
                if(p.getId() == -1){
                    p = Persona(obj.second.first,obj.second.second,obj.first);
                }
                else{
                    int y = p.promedioYC();
                    int direccion = obj.second.second - y;

                    if(p.getCounted() == false){
                        // Se identifica si la persona sube y se le suma 1
                        if(direccion > 0 && obj.second.second < (300/2)){
                            totalUp++;
                            p.setCounted(true);
                        }
                        //Se identifica si la persona baja y se le suma 1
                        else if (direccion < 0 && obj.second.second > (300/2))
                        {
                           totalDown++;
                           p.setCounted(true); 
                        }
                    }
                }
                trackableObjects.add(p);
                circle(cameraFrame, Point(obj.second.first, obj.second.second), 4, Scalar(255, 0, 0), -1);
                string ID = std::to_string(obj.first);
                cv::putText(cameraFrame, ID, Point(obj.second.first - 10, obj.second.second - 10),
                            FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255, 0), 2);
            }
        }
        //Vector que almacena los contadores obtenidos 
        vector<pair<string,string>> info;
        info[0] = make_pair("Arriba: ",totalUp);
        info[1] = make_pair("Abajo: ",totalDown);
        int pos = 250;

        for(auto i: info){
            string display = i.first + i.second;
            putText(cameraFrame,display,Point(10,pos),FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255, 0), 2);
        }
        
        imshow("Detection", cameraFrame);
        char c = (char) waitKey(1);
        if (c == 27)
            break;
    }
    infoGente = make_pair(totalUp,totalDown);// Se guardan los contadores en el vector
    delete centroidTracker; // se destruye la instancia de clase centroidTracker
    destroyAllWindows(); // Destructor
    return infoGente;// retorna el vector
}
/*
* Funcion que permite la detección y conteo de personas
* Calcula el centroide 
* Utiliza la camara 
* Retorna un vector con el contador de personas que entran (0)  y que salen (1)
* La logica es la misma que la funcion anterior
*/
pair<int,int> watchVideo2(){
    // Declaracion del cameraFrame de la clase Mat
    pair<int,int> infoGente;
    // Se inicializa una instancia de la clase centroidTracker
    auto centroidTracker = new CentroidTracker(20);
    //Se crea la LinkedList
    LinkedList trackableObjects = LinkedList();
    // ejecuta la camara
    VideoCapture cap(0);

    string modelTxt = "E:/Repos VS Code/Centroid-Object-Tracking/model/deploy.prototxt";
    string modelBin = "E:/Repos VS Code/Centroid-Object-Tracking/model/res10_300x300_ssd_iter_140000.caffemodel";

    auto net = dnn::readNetFromCaffe(modelTxt, modelBin);

    int totalUp = 0;
    int totalDown = 0;

    while (cap.isOpened()) {
        Mat cameraFrame;
        cap.read(cameraFrame); 

        resize(cameraFrame, cameraFrame, Size(400, 300));

        vector<vector<int>> rects;
        
        auto inputBlob = dnn::blobFromImage(cameraFrame, 1.0, Size(400, 300), Scalar(104.0, 177.0, 123.0));
        net.setInput(inputBlob);
        auto detection = net.forward("detection_out");
        Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

        float confidenceThreshold = 0.4;
        for (int i = 0; i < detectionMat.rows; i++) {
            float confidence = detectionMat.at<float>(i, 2);

            if (confidence > confidenceThreshold) {
                int xLeftTop = static_cast<int>(detectionMat.at<float>(i, 3) * cameraFrame.cols);
                int yLeftTop = static_cast<int>(detectionMat.at<float>(i, 4) * cameraFrame.rows);
                int xRightBottom = static_cast<int>(detectionMat.at<float>(i, 5) * cameraFrame.cols);
                int yRightBottom = static_cast<int>(detectionMat.at<float>(i, 6) * cameraFrame.rows);

                Rect object((int) xLeftTop, (int) yLeftTop, (int) (xRightBottom - xLeftTop),
                            (int) (yRightBottom - yLeftTop));
                rectangle(cameraFrame, object, Scalar(0, 255, 0), 2);
                rects.insert(rects.end(), {xLeftTop, yLeftTop, xRightBottom, yRightBottom});
            }
        } 
        Point p1 = (0,300/2);
        Point p2 = (400,300/2);
        line(cameraFrame,p1,p2,Scalar(0, 0, 255));

        auto objects = centroidTracker->update(rects);

        if (!objects.empty()) {
            for (auto obj: objects) {
                Persona p = trackableObjects.get(obj.first);
                if(p.getId() == -1){
                    p = Persona(obj.second.first,obj.second.second,obj.first);
                }
                else{
                    int y = p.promedioYC();
                    int direccion = obj.second.second - y;

                    if(p.getCounted() == false){
                        if(direccion > 0 && obj.second.second < (300/2)){
                            totalUp++;
                            p.setCounted(true);
                        }
                        else if (direccion < 0 && obj.second.second > (300/2))
                        {
                           totalDown++;
                           p.setCounted(true); 
                        }
                    }
                }
                trackableObjects.add(p);
                circle(cameraFrame, Point(obj.second.first, obj.second.second), 4, Scalar(255, 0, 0), -1);
                string ID = std::to_string(obj.first);
                cv::putText(cameraFrame, ID, Point(obj.second.first - 10, obj.second.second - 10),
                            FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255, 0), 2);
            }
        }
        vector<pair<string,string>> info;
        info[0] = make_pair("Arriba: ",totalUp);
        info[1] = make_pair("Abajo: ",totalDown);
        int pos = 250;

        for(auto i: info){
            string display = i.first + i.second;
            putText(cameraFrame,display,Point(10,pos),FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255, 0), 2);
        }
        
        imshow("Detection", cameraFrame);
        char c = (char) waitKey(1);
        if (c == 27)
            break;
    }
    infoGente = make_pair(totalUp,totalDown);// Se guardan los contadores en el vector
    delete centroidTracker; // se destruye la instancia de clase centroidTracker
    destroyAllWindows(); // Destructor
    return infoGente;// retorna el vector
}
/*
* Validacion de entrada de usuario
*/
bool validacion(string x){
    if(x == "SI"){
        return true;
    }else 
    if(x == "si"){
        return true;
    }else
    if(x == "Si"){
        return true;
    }else
    if(x == "sI"){
        return true;
    }
    return false;
}
//Calculo de la velocidad del flujo de entrada o salida
int calculoVelocidad(int x){
    return x/60;
}
/*
* Se despliega el menu del guardia
* con la informacion correspondiente
*/
void desplegarMenuGuardia(int op){
    pair<int,int> vec;
    cout << "** MENU GUARDIA **" << endl;
    cout << "DETECTAR PERSONAS" << endl;
    if(op == 0){
        vec = watchVideo1();
    }else
    {
       vec = watchVideo2();
    }
    cout << "--CONTEO DE ENTRADA DE PERSONAS--" << endl;
    cout << "PERSONAS QUE ENTRAN: ";
    cout << vec.first << endl;
    cout << "--CONTEO DE SALIDA DE PERSONAS--" << endl;
    cout << "PERSONAS QUE SALEN: ";
    cout << vec.second << endl;
    cout << "VELOCIDAD DE FLUJO DE PERSONAS QUE ENTRAN";
    cout << calculoVelocidad(vec.first) << endl;
    cout << "VELOCIDAD DE FLUJO DE PERSONAS QUE SALEN";
    cout << calculoVelocidad(vec.second) << endl;
}
/*
*  Menu en donde se encuentra las opciones inicio de
*  sesion del guardia y del admin
*/
void iniciarSesion(){
    string opcion3;
    int countType = 0;
    cout << "Bienvenido al sistema de vigilancia de ACME\n" << "\nDesea inicar sesion?\n" << endl;
    cin >> opcion3;
    while (validacion(opcion3)) {
        int opcion;
        cout << "Como desea iniciar sesion?\n" << "\n(1) Iniciar como ADMINISTRADOR\n" << "(2) Iniciar como GUARDIA" << "\n(3) Cerrar Sesion\n" << endl;
        cin >> opcion;
        switch(opcion){
            //MENU ADMIN
            case 1:
                cout << "Bienvenido al menu ADMIN" << endl << "Seleccione como se va a trabajar con el conteo de personas: \n(1) Conteo con un video \n(2) Conteo con la camara";
                int eleccion;
                cin >> eleccion;
                cout << "Seleccione como se va a trabajar con el conteo de personas: \n(1) Conteo con un video \n(2) Conteo con la camara \n";
                cin >> countType;
                while(eleccion != 1 || eleccion !=2){
                    cout << "Operacion no valida, intente de nuevo" << endl;
                    cin >> eleccion;
                }
                //con video
                if(eleccion == 1){
                    countType = 0;
                    watchVideo1();
                }
                // con camara
                else{
                    countType = 1;
                    watchVideo2();
                }
                break;
            case 2:
                // MENU GUARDIA

                cout << "Bienvenido al menu GUARDIA" << endl << "¿Desea empezar con el conteo de personas? [si][no]\n";
                string opcion4;
                cin >> opcion4;      
                cout << "Seleccione como se va a trabajar: \n(1) Con un video \n(2) Con la camara \n";
                cin >> countType;
                if(validacion(opcion4)){
                    cout << "DESPLGANDO ESTADISTICAS..."<< endl;
                    if(countType == 0){
                        desplegarMenuGuardia(countType);
                    }
                    else{
                        desplegarMenuGuardia(countType);
                    }
                }
                break;
        }
        cout << "¿Desea realizar otra accion?" << endl;
        cin >> opcion3;
    }
    cout << "Cerrando sesion...";
}
// Main en donde se ejecuta la funcion iniciar sesion
int main() {
    iniciarSesion();
    return 0;
}