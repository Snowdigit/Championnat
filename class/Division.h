#ifndef DIVISION_H_INCLUDED
#define DIVISION_H_INCLUDED
#include <iostream>
#include <string>
#include <sstream>
#include "lib/termcolor/termcolor.hpp"
#include "../sqlite/sqlite/sqlite3.h"
using namespace std;


class Division
{
    private:
        string libelle;
        int idchampionnat;
        int iddivision;
        int idsaison;
    public:
        void CreationDivision();
        void ModificationDivision();
        void SuppressionDivision();
        void Calendrier();
        void Classement();
        void AffichageDivision();
};



#endif // DIVISION_H_INCLUDED
