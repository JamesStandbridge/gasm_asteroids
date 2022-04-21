#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"
#include "ElementEspace.h"
#include "Explosion.h"
#include "Espace.h"
#include "Jeu.h"


class Vaisseau : public ElementEspace
{
    public:
        explicit Vaisseau(Espace& p_espace, sf::Color const& couleur);
        ~Vaisseau();

        virtual void reagirCollision(TypeElement typeAutre) override;

    protected:
        virtual void mettreAJour(float temps) override;

    private:
        void actualiserEtat();

        bool accelerationEnCours{false};
        bool tourneAGauche{false};
        bool tourneADroite{false};

        Espace& espace;
        sf::Clock dernierTir{};

        static constexpr float ACCELERATION{4000.f};
        static constexpr float COEFF_FROTTEMENTS{2.f};
        static constexpr float VITESSE_ANGULAIRE{120.f};
};

#endif // VAISSEAU_H_INCLUDED
