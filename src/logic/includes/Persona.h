#ifndef PERSONA_H
#define PERSONA_H

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Persona{
    private:

    vector<pair<int,int>> centroids;
    int id;
    bool counted;
    

public:
    Persona(int,int,int);
    Persona();

    vector<pair<int,int>> getCentroids();
    void addCentroids(pair<int,int>);
    void setCounted(bool);
    bool getCounted();
    int getId();
    void setId(int);
    int promedioYC();
};

#endif