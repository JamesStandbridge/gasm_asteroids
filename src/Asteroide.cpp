#include "Asteroide.h"

#include <iostream>
#include <random>
#include "Explosion.h"

using namespace std;

Asteroide::Asteroide(Espace& p_espace, Asteroide* parent) : ElementEspace{"ressources/chreak_gasm.png"}, espace{p_espace}
{
    type = TypeElement::ASTEROIDE;
    auto generateur = std::random_device{};
    auto distributionPosition = std::uniform_real_distribution<float>{-150, 150};
    auto distributionVitesse = std::uniform_real_distribution<float>{80, 120};
    auto distributionAngle = std::uniform_real_distribution<float>{0, 360};
    auto distributionVitesseAngulaire = std::uniform_real_distribution<float>{10, 30};
    vitesse = Vecteur::creerDepuisAngle(distributionVitesse(generateur), distributionAngle(generateur));
    vitesseAngulaire = distributionVitesseAngulaire(generateur);


    if(parent) {
        sprite.setScale(parent->sprite.getScale().x / 1.8, parent->sprite.getScale().y / 1.8);
        position = parent->position;
    } else {
        position = {distributionPosition(generateur), distributionPosition(generateur)};
    }
}

void Asteroide::reagirCollision(TypeElement typeAutre)
{
    if(typeAutre == TypeElement::MISSILE) {
        detruit = true;

        if(sprite.getScale().x > 0.4) {
            espace.ajouter(std::make_unique<Asteroide>(espace, this));
            espace.ajouter(std::make_unique<Asteroide>(espace, this));
        }

        espace.ajouter(std::make_unique<Explosion>(position));
    }
}
