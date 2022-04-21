#ifndef ELEMENTESPACE_H
#define ELEMENTESPACE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"

using namespace std;

enum class TypeElement {VAISSEAU, ASTEROIDE, MISSILE, AUTRE};

class ElementEspace
{
    public:
        virtual ~ElementEspace() = default;
        explicit ElementEspace(string_view const& cheminImage);
        ElementEspace(ElementEspace const& autre) = delete;
        void operator=(ElementEspace const& autre) = delete;
        void actualiser(float temps);

        virtual void reagirCollision(TypeElement) = 0;

        static inline bool estDetruit(std::unique_ptr<ElementEspace>& element) {return element->detruit;};

        virtual void afficher(sf::RenderWindow& fenetre) const;
        void testerCollision(ElementEspace& autre);
        float getRayon() const;

    protected:
        virtual void mettreAJour(float temps);

        sf::Sound son{};

        TypeElement type{TypeElement::AUTRE};
        bool detruit{false};
        Vecteur vitesse{0.f, 0.f};
        sf::Sprite sprite{};
        Coordonnees position{};
        float vitesseAngulaire{};
};

#endif // ELEMENTESPACE_H
