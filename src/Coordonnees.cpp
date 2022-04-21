#include "Coordonnees.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int Coordonnees::maxX;
int Coordonnees::maxY;


Coordonnees::Coordonnees(float xInit, float yInit) : x{xInit}, y{yInit} {}
Coordonnees::Coordonnees() {}

float Coordonnees::getX() const
{
    return x;
}

float Coordonnees::getY() const
{
    return y;
}

void Coordonnees::operator+=(Vecteur const& autre)
{
    x += autre.x;
    y += autre.y;
    if(x > Coordonnees::maxX) x = 0;
    if(y > Coordonnees::maxY) y = 0;
    if(x < 0) x = Coordonnees::maxX;
    if(y < 0) y = Coordonnees::maxY;
}

void Coordonnees::initialiserEspace(int initX, int initY)
{
    Coordonnees::maxX = initX;
    Coordonnees::maxY = initY;
}

int Coordonnees::getHauteurEspace()
{
    return Coordonnees::maxY;
}

int Coordonnees::getLongueurEspace()
{
    return Coordonnees::maxX;
}

float Coordonnees::calculerDistance(Coordonnees const& autre) const
{
    //différence absolue entre les deux points
    auto delta = Vecteur{
        std::min({abs(x - autre.x), abs(x - autre.x - getLongueurEspace()), abs(x - autre.x + getLongueurEspace())}),
        std::min({abs(y - autre.y), abs(y - autre.y - getHauteurEspace()), abs(y - autre.y + getHauteurEspace())})
    };

    //calcul de la distance avec la formule rcarré(x*x + y*y)
    return sqrt(delta.x * delta.x + delta.y * delta.y);
}
