#include "includes/Persona.h"
//constructor de persona
Persona::Persona(int xC, int yC, int idObj){
    this->centroids.push_back(make_pair(xC,yC));
    this->counted = false;
    this->id = idObj;
}

Persona::Persona(){
    this->counted = false;
    this->id = -1;
}

void Persona::setCounted(bool c){
    counted = c;
}

bool Persona::getCounted(){
    return counted;
}

int Persona::getId(){
    return this->id;
}

void Persona::setId(int newId){
    this->id = newId;
}

vector<pair<int,int>> Persona::getCentroids(){
    return this->centroids;
}

void Persona::addCentroids(pair<int,int> actCentroids){
    centroids.push_back(actCentroids);
}
//  Promedio de variacion del eje y en los centroides
int Persona::promedioYC(){
    int prom = 0;
    for(auto c: centroids){
        prom += c.second;
    }
    return prom/centroids.size();
}