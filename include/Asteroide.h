#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "ElementEspace.h"
#include "Espace.h"

class Asteroide : public ElementEspace
{
    public:
        explicit Asteroide(Espace& p_espace, Asteroide* parent = nullptr);
        virtual void reagirCollision(TypeElement typeAutre) override;

    private:
        Espace& espace;
};

#endif // ASTEROIDE_H
