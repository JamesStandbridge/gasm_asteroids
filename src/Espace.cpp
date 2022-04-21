#include <memory>
#include "Espace.h"
#include <iostream>

Espace::Espace()
{

}

void Espace::ajouter(std::unique_ptr<ElementEspace> element)
{
    aAjouter.push_back(std::move(element));
}

void Espace::actualiser()
{
    auto tempsBoucle = chrono.restart().asSeconds();

    for(auto i{0u}; i < elements.size(); ++i) {
        elements[i]->actualiser(tempsBoucle);
    }
}

void Espace::gererCollisions()
{
    for(auto i{0u}; i < elements.size(); ++i) {
        for(auto j{0u}; j < elements.size(); ++j) {
            if(i != j) {
                elements[i]->testerCollision(*elements[j]);
            }
        }
    }
}

void Espace::afficher(sf::RenderWindow& fenetre) const
{
    for(auto& element : elements) {
        element->afficher(fenetre);
    }
}

void Espace::nettoyer()
{
    auto finTableau = std::remove_if(std::begin(elements), std::end(elements), ElementEspace::estDetruit);

    auto ancienneTaille = elements.size();
    elements.erase(finTableau, std::end(elements));
    auto nouvelleTaille = elements.size();

    auto newScore = ancienneTaille - nouvelleTaille;

    if(newScore > 1) {
        ajouterScore(newScore * 100);
    }

    for(auto& element : aAjouter) {
        elements.push_back(std::move(element));
    }

    aAjouter.clear();
    if(aVider) {
        elements.clear();
    }
}

void Espace::vider()
{
    aVider = true;
}

int Espace::recupererScoreFrame()
{
    auto scoreFrameCourant = scoreFrame;
    scoreFrame = 0;
    return scoreFrameCourant;
}
