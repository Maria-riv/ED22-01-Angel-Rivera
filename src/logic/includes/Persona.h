#ifndef PERSONA_H
#define PERSONA_H

#include <opencv2/opencv.hpp>

using namespace cv;

class Persona{
    private:
    int xComienzo;
    int yComienzo;
    int xFin;
    int yFin;
    int xCentro;
    int yCentro;
public:
    Persona(Rect&);

    int getXComienzo();
    int getYComienzo();
    int getXFin();
    int getYFin();
    int getXCentro();
    int getYCentro();
};

#endif