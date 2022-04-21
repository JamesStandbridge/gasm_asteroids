#include "Explosion.h"
#include "GestionnaireRessources.h"

Explosion::Explosion(Coordonnees const& p_position, bool isPlayer) : ElementEspace{"ressources/explosion.png"}
{
    position = p_position;

    if(isPlayer) {
        son.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessource("ressources/Deathsound.wav"));
    } else {
        son.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessource("ressources/BoumAsteroid.wav"));
    }
    son.play();
}

void Explosion::mettreAJour(float temps)
{
    age += temps;
    if(age < DUREE_VIE) {
        sprite.setScale(age / DUREE_VIE, age / DUREE_VIE);
    } else {
        detruit = true;
    }
}

void Explosion::reagirCollision(TypeElement typeAutre) {}
