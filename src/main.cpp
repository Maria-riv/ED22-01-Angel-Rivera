#include <iostream>
#include "logic/includes/CentroidTracker.h"
#include "logic/includes/LinkedList.h"
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
    vector<vector<int>> trackers;
    LinkedList trackable_people();    

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

        if(frame.empty()){
            break;
        }

        resize(frame, frame, Size(400, 300));
        

        if(totalFrames % skip_frames == 0){
            auto inputBlolb = blobFromImage(frame, 1.0, Size(400,300), Scalar(104.0, 177.0, 123.0));
            net.setInput(inputBlolb);
            auto detection = net.forward("detection_out");
            Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

            float confidenceThreshold = 0.2;
            for (int i = 0; i < detectionMat.rows; i++) {
                float confidence = detectionMat.at<float>(i, 2);

                if (confidence > confidenceThreshold) {
                    int xLeftTop = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
                    int yLeftTop = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
                    int xRightBottom = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
                    int yRightBottom = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);

                    Rect object((int) xLeftTop, (int) yLeftTop, (int) (xRightBottom - xLeftTop),
                                (int) (yRightBottom - yLeftTop));
                    rectangle(frame, object, Scalar(0, 255, 0), 2);

                    trackers.insert(trackers.end(), {xLeftTop, yLeftTop, xRightBottom, yRightBottom});
                }
            }
        }
        else{

        }
        
        imshow("Frame", frame);
        //Presionar ESC para terminar antes el trackeo
        char c = (char) waitKey(25);
        if(c == 27){
            break;
        }

        totalFrames++;
    }
    cap.release();
    destroyAllWindows();

    return 0;
}
