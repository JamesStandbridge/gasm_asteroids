#include "Jeu.h"

#include <memory>
#include <string>

#include "Asteroide.h"
#include "Vaisseau.h"
#include "GestionnaireRessources.h"
#include "font.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>




const sf::Color COULEUR_VAISSEAU{sf::Color{128,255,128}};


Jeu::Jeu(Espace& p_espace) : espace{p_espace}
{
    if(!police.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size)) {
        throw std::runtime_error{"Police introuvable"};
    }

    try {
        spriteAccueil.setTexture(GestionnaireRessources<sf::Texture>::getRessource("ressources/gasm_accueil.png"));
    } catch(std::exception const& exception) {
        initialiserException(exception);
    }


    musique.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessource("ressources/HORRIBLESON.wav"));
}

void Jeu::demarrer()
{
    score = 0;
    enCours = true;
    espace.ajouter(std::make_unique<Vaisseau>(espace, COULEUR_VAISSEAU));
    espace.ajouter(std::make_unique<Asteroide>(espace));
    espace.ajouter(std::make_unique<Asteroide>(espace));
    espace.ajouter(std::make_unique<Asteroide>(espace));
    espace.ajouter(std::make_unique<Asteroide>(espace));
    espace.ajouter(std::make_unique<Asteroide>(espace));
    espace.ajouter(std::make_unique<Asteroide>(espace));
    musique.play();
}

void Jeu::terminer()
{
    enCours = false;
    //espace.vider();
}

void Jeu::afficher(sf::RenderWindow& fenetre)
{
    actualiserScore();
    fenetre.draw(*texteScore);
    if(!enCours) {
        fenetre.draw(spriteAccueil);
    }
    if(texteException) {
        fenetre.draw(*texteException);
    }
}

void Jeu::initialiserException(std::exception const& exception)
{
    texteException = std::make_unique<sf::Text>();
    texteException->setFont(police);
    texteException->setString(exception.what());
    texteException->setFillColor(sf::Color::Red);
}

void Jeu::actualiserScore()
{
    score += espace.recupererScoreFrame();
    texteScore = std::make_unique<sf::Text>();
    texteScore->setFont(police);
    texteScore->setString(std::to_string(score));
    texteScore->setFillColor(sf::Color::White);
}
