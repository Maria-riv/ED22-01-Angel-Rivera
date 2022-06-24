#include "includes/Persona.h"

Persona::Persona(int xC, int yC, int idObj){
    this->centroids.push_back({xC,yC});
    this->counted = false;
    this->id = idObj;
}

Persona::Persona(){
    
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

void Persona::setCentroids(vector<pair<int,int>> actCentroids){
    this->centroids = actCentroids;
}