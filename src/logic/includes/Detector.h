#ifndef DETECTOR_H
#define DETECTOR_H

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Detector{
    private:
    Mat frame_actual; //frame actual
    Mat mascaraMOG2; //mascara de foreground generada por MOG2
    Ptr<BackgroundSubtractor> substractorMOG2; //sustractor de background MOG2
    int keyboard; //input 
    Point point1, point2; /* puntos de la linea de referencia */
    int drag = 0;                                                                                                                                                           
    int select_flag = 0;
    VideoCapture video;
    Mat im_detecciones;
    vector<KeyPoint> personas;
    vector<Point2f> prevPersonas;
    Point2f persona;
    Ptr<SimpleBlobDetector> detector;

    public:
    Detector(string);
    void mouseHandler(int,int,int,int,void*);
    bool ccw(Point2f,Point2f,Point2f);
    bool intersecta(Point2f,Point2f,Point2f,Point2f);
    

};

#endif