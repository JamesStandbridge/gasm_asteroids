#ifndef MISSILE_H
#define MISSILE_H

#include <ElementEspace.h>


class Missile : public ElementEspace
{
    public:
        Missile(Coordonnees const& p_position, float rotation);
        virtual void reagirCollision(TypeElement typeAutre) override;

    protected:

    private:
        static constexpr float VITESSE{2000.f};
};

#endif // MISSILE_H
