#ifndef GESTIONNAIRERESSOURCES_H
#define GESTIONNAIRERESSOURCES_H


#include <unordered_map>
#include <string_view>
#include <iostream>
#include "ExceptionRessourceIntrouvable.h"


template <typename T>
class GestionnaireRessources
{
    public:
        GestionnaireRessources() = delete;
        static T const& getRessource(std::string_view const& chemin) {
            auto resultat = ressources.find(chemin);
            if(resultat == std::end(ressources)) {
                if(!ressources[chemin].loadFromFile(chemin.data())) {
                    throw ExceptionRessourceIntrouvable{chemin};
                }
                return ressources[chemin];
            }
            return resultat->second;
        }

    private:
        static std::unordered_map<std::string_view, T> ressources;
};

#endif // GESTIONNAIRERESSOURCES_H
