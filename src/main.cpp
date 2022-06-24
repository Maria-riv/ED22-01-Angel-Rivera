#include <iostream>
#include "logic/includes/CentroidTracker.h"
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace cv::dnn;
using namespace std;

string CLASSES[] = {"background", "aeroplane", "bicycle", "bird", "boat",
	"bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
	"dog", "horse", "motorbike", "person", "pottedplant", "sheep",
	"sofa", "train", "tvmonitor"};

int main(int, char**) {
    auto ct = new CentroidTracker(50);
    
    VideoCapture cap(0);
    if(!cap.isOpened()){
        cout << "No se puede abrir la camara";
    }
    
    String modelBin = "E:/Repos VS Code/ED22-01-Angel-Rivera/src/MobileNetSSD_deploy.caffemodel";
    String modelTxt = "E:/Repos VS Code/ED22-01-Angel-Rivera/src/MobileNetSSD_deploy.prototxt";
    auto net = dnn::readNetFromCaffe(modelTxt, modelBin);
    
    int totalEntrada = 0;
    int totalSalida = 0;
    int totalFrames = 0;
    int skip_frames = 0;

    while(cap.isOpened()){
        Mat frame;
        cap.read(frame);

        if(totalFrames % skip_frames == 0){
            resize(frame, frame, Size(400, 300));
            auto inputBlolb = blobFromImage(frame, 1.0, Size(400,300), Scalar(104.0, 177.0, 123.0));

            net.setInput(inputBlolb);
            auto detection = net.forward("detection_out");
            Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());
        }
        
        
    }

    return 0;
}
