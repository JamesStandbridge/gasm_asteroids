#include "Vaisseau.h"
#include <iostream>
#include "Coordonnees.h"
#include "Espace.h"
#include "Missile.h"

using namespace std;

Vaisseau::Vaisseau(Espace& p_espace, sf::Color const& couleur) : ElementEspace{"ressources/vaisseau.png"}, espace{p_espace}
{
    type = TypeElement::VAISSEAU;
    position = {Coordonnees::getLongueurEspace() / 2, Coordonnees::getHauteurEspace() / 2};
    sprite.setColor(couleur);
}

Vaisseau::~Vaisseau()
{
    cout << "Vaisseau détruit" << endl;
}

void Vaisseau::actualiserEtat()
{
    accelerationEnCours = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    tourneAGauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    tourneADroite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && dernierTir.getElapsedTime().asSeconds() > 0.4) {
        espace.ajouter(std::make_unique<Missile>(position, sprite.getRotation()));
        dernierTir.restart();
    }
}

void Vaisseau::mettreAJour(float temps)
{
    actualiserEtat();
    if(!detruit) {
        if(accelerationEnCours) {
            vitesse += Vecteur::creerDepuisAngle(ACCELERATION * temps, sprite.getRotation());
        }
        vitesse -= vitesse * COEFF_FROTTEMENTS * temps;

        if(tourneAGauche) {
            vitesseAngulaire = -VITESSE_ANGULAIRE;
        } else if(tourneADroite) {
            vitesseAngulaire = VITESSE_ANGULAIRE;
        } else {
            vitesseAngulaire = 0;
        }
    }
}

void Vaisseau::reagirCollision(TypeElement typeAutre)
{
    if(typeAutre == TypeElement::ASTEROIDE) {
        detruit = true;
        espace.ajouter(std::make_unique<Explosion>(position, true));
    }
}
