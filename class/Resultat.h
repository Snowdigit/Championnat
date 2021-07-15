#ifndef RESULTAT_H_INCLUDED
#define RESULTAT_H_INCLUDED
#include <string>
#include <iostream>
#include "../sqlite/sqlite/sqlite3.h"
using namespace std;
#include <sstream>
#include "lib/termcolor/termcolor.hpp"



class Match
{
    private:
        std::string date;
        int id;
        int ideq1;
        int ideq2;
        int idchampionnat;
        int iddivision;
        int idsaison;
        int journee;
        int score_1;
        int score_2;
        int point_1;
        int point_2;
        int gd1;
        int gd2;
        std::string eq1;
        std::string eq2;

    public:

        void CreationMatch();
        void ModificationMatch();
        void SuppressionMatch();
        void AffichageResultats();
        void AjouterResultat();

};




#endif // RESULTAT_H_INCLUDED
