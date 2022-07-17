#ifndef PERSONA_H
#define PERSONA_H

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
//clase persona
class Persona{
    //atributo del objeto persona
    private:
    vector<pair<int,int>> centroids;// vector centroide (x,y)
    int id;// identificador de cada persona
    bool counted;// bool contado
    

public:
    //constructor
    Persona(int,int,int);
    Persona();
    //metodos
    vector<pair<int,int>> getCentroids(); // obtener centroides
    void addCentroids(pair<int,int>); // añadir centroides
    //metodos get y set de counted e ID
    void setCounted(bool);
    bool getCounted();
    int getId();
    void setId(int);
    //promedio de variacion del eje y en los centroides
    int promedioYC();
};

#endif