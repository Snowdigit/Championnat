#ifndef CHAMPIONNAT_H
#define CHAMPIONNAT_H
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include "../sqlite/sqlite/sqlite3.h"
#include "lib/termcolor/termcolor.hpp"
using namespace std;

class Championnat
{
    private:
        string pays;
        int idchampionnat;
        int iddivision;
        int idsaison;
    public:

        void CreationChampionnat();
        void ModificationChampionnat();
        void SuppressionChampionnat();
        void AffichageChampionnat();

};

#endif // CHAMPIONNAT_H
