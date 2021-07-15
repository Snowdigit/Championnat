#ifndef APPARTENIR_H
#define APPARTENIR_H
#include <iostream>
#include <string>
#include "../sqlite/sqlite/sqlite3.h"
#include <sstream>
#include "lib/termcolor/termcolor.hpp"


class Appartenir
{
    private:

        int idsaison;
        int iddivision;
        int idequipe;

    public:
        void AppartientA();

};

#endif // APPARTENIR_H
