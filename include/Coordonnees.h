#ifndef COORDONNEES_H
#define COORDONNEES_H

#include "Vecteur.h"

class Coordonnees
{
    public:
        static void initialiserEspace(int longueur, int hauteur);
        Coordonnees(float x, float y);
        Coordonnees();
        float getX() const;
        float getY() const;
        static int maxX;
        static int maxY;

        void operator+=(Vecteur const& autre);

        static int getHauteurEspace();
        static int getLongueurEspace();
        float calculerDistance(Coordonnees const& autre) const;

    private:
        float x{};
        float y{};
};


#endif // COORDONNEES_H
