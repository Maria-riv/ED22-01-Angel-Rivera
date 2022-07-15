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

void watchVideo1(){
    auto centroidTracker = new CentroidTracker(20);
    LinkedList trackableObjects = LinkedList();
    VideoCapture cap("Docs/example_01.mp4");

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
    delete centroidTracker;
    destroyAllWindows();
}

void watchVideo2(){
    auto centroidTracker = new CentroidTracker(20);
    LinkedList trackableObjects = LinkedList();
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
    delete centroidTracker;
    destroyAllWindows();
}
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
void iniciarSesion(){
    string opcion3;
    int countType;
    cout << "Bienvenido al sistema de vigilancia de ACME\n" << "\nDesea inicar sesion?\n" << endl;
    cin >> opcion3;
    while (validacion(opcion3)) {
        int opcion;
        cout << "Como desea iniciar sesion?\n" << "\n(1) Iniciar como ADMINISTRADOR\n" << "(2) Iniciar como GUARDIA" << "\n(3) Cerrar Sesion\n" << endl;
        cin >> opcion;
        switch(opcion){
            case 1:
                cout << "Bienvenido al menu ADMIN" << endl << "Seleccione como se va a trabajar con el conteo de personas: \n(1) Conteo con un video \n(2) Conteo con la camara";
                int eleccion;
                cin >> eleccion;
                while(eleccion != 1 || eleccion !=2){
                    cout << "Operacion no valida, intente de nuevo" << endl;
                    cin >> eleccion;
                }
                if(eleccion == 1){
                    countType = 1;
                }
                else{
                    countType = 2;
                }
                break;
            case 2:
                cout << "Bienvenido al menu GUARDIA" << endl << "¿Desea empezar con el conteo de personas? [si][no]\n";
                string opcion4;
                cin >> opcion4;
                if(validacion(opcion4)){
                    if(countType == 1){
                        watchVideo1();
                    }
                    else{
                        watchVideo2();
                    }
                }
                break;
        }
        cout << "¿Desea realizar otra accion?" << endl;
        cin >> opcion3;
    }
    if(!validacion(opcion3)){
        cout << "REINTENTE. . . ";
        iniciarSesion();
    }
    cout << "Cerrando sesion...";
}
int main() {
    iniciarSesion();
    return 0;
}