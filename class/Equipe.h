#ifndef EQUIPE_H
#define EQUIPE_H
#include <string>
#include <iostream>
#include "lib/termcolor/termcolor.hpp"
#include <sstream>
#include "../sqlite/sqlite/sqlite3.h"
using namespace std;




class Equipe
{
    public:

        void CreationEquipe();
        void ModificationEquipe();
        void SuppressionEquipe();
        void AffichageEquipe();

    private:
        string nom;
        int iddivision;
        int idequipe;
        int idchampionnat;
        int idsaison;
};

#endif // EQUIPE_H
