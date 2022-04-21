#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <ElementEspace.h>


class Explosion : public ElementEspace
{
    public:
        explicit Explosion(Coordonnees const& p_position, bool isPlayer = false);

        virtual void reagirCollision(TypeElement typeAutre) override;

    protected:
        virtual void mettreAJour(float temps) override;

    private:
        float age{};
        static constexpr float DUREE_VIE{0.5f};
};

#endif // EXPLOSION_H
