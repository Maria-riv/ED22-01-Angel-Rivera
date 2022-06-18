#include "includes/Detector.h"
#include <opencv2/highgui/highgui.hpp>

Detector::Detector(string nombreV){
    this->substractorMOG2 = createBackgroundSubtractorMOG2();
    VideoCapture cap(nombreV);
    this->capture = cap;
    
    //Comprueba que se pueda abrir el video
    if (!capture.isOpened()){
        printf("No fue posible abrir el archivo de video");
        getchar();
        exit(EXIT_FAILURE);
    }

    //Prepara los parametros de deteccion
    SimpleBlobDetector::Params params;
    params.minDistBetweenBlobs = 1.0f;
    params.filterByInertia = false;
    params.filterByConvexity = false;
    params.filterByColor = false;
    params.filterByCircularity = false;
    params.filterByArea = true;
    params.minArea = 100.0f;
    params.maxArea = 2500.0f;
    this->detector = SimpleBlobDetector::create(params);

};

void Detector::mouseHandler(int event, int x, int y, int flags, void* param){
    if (event == EVENT_LBUTTONDOWN && !drag)
    {
        /* left button clicked. ROI selection begins */
        point1 = Point(x, y);
        drag = 1;
    }
    
    if (event == EVENT_MOUSEMOVE && drag)
    {
        /* mouse dragged. ROI being selected */
        Mat img1 = frame_actual.clone();
        point2 = Point(x, y);
        line(img1, point1, point2, CV_RGB(255, 0, 0), 2, 8, 0);
        imshow("Frame", img1);
    }
    
    if (event == EVENT_LBUTTONUP && drag)
    {
        point2 = Point(x, y);
        drag = 0;
    }
    
    if (event == EVENT_LBUTTONUP)
    {
       /* ROI selected */
        select_flag = 1;
        drag = 0;
    }
};

bool Detector::ccw(Point2f A,Point2f B,Point2f C){
    return (C.y-A.y) * (B.x-A.x) > (B.y-A.y) * (C.x-A.x);
};

bool Detector::intersecta(Point2f A,Point2f B,Point2f C,Point2f D){
    return ccw(A,C,D) != ccw(B,C,D) && ccw(A,B,C) != ccw(A,B,D);
};

void Detector::iniciarDeteccion(){
    if (!capture.read(frame_actual)) {
        printf("No fue posible leer el frame");
        getchar();
        exit(EXIT_FAILURE);
    }
    
    cout<<("Dibuje la línea para el conteo y presione la barra espaciadora para continuar.");
    fflush(stdout); 
    while ((char)keyboard != 32){
        setMouseCallback("Frame", mouseHandler, NULL);
        Mat img1 = frame_actual.clone();
        line(img1, point1, point2, CV_RGB(255, 0, 0), 2, 8, 0);
        imshow("Frame", img1);
        keyboard = waitKey(30);
    }
}