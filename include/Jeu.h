#ifndef JEU_H
#define JEU_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Espace.h"
#include <exception>

class Jeu
{
    public:
        Jeu(Espace& p_espace);
        void demarrer();
        void terminer();
        inline bool estEnCours() const {return enCours;};
        void afficher(sf::RenderWindow& fenetre);
        void initialiserException(std::exception const& exception);

    protected:

    private:
        void actualiserScore();
        Espace& espace;
        int score{0};
        bool enCours{false};
        sf::Sprite spriteAccueil{};
        sf::Font police{};
        sf::Sound musique{};
        std::unique_ptr<sf::Text> texteException{nullptr};
        std::unique_ptr<sf::Text> texteScore{nullptr};

};

#endif // JEU_H
