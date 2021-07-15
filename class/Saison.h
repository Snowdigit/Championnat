#ifndef SAISON_H
#define SAISON_H
#include <string>
#include <iostream>
#include "../sqlite/sqlite/sqlite3.h"
#include <sstream>
using namespace std;
#include "lib/termcolor/termcolor.hpp"



class Saison
{
    public:

        void CreationSaison();
        void ModificationSaison();
        void SuppressionSaison();
        void AffichageSaison();

    private:
        string libelle;
        int idsaison;

};

#endif // SAISON_H
