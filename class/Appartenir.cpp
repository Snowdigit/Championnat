
#include "Appartenir.h"

using namespace std;

void Appartenir::AppartientA()
{
    cout << "\n Vous devez attribuer une equipe a une division et a une saison\n "<<endl;


    // Choix de la saison

    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    cout << "Entrer le numero pour choisir la saison "<<endl;

    sqlite3_prepare_v2(db, "select * from saisons ", -1, &stmt, 0);
    int ids;
    const unsigned char* date;

while(sqlite3_step(stmt) != SQLITE_DONE){
        ids = sqlite3_column_int(stmt,0);
        date = sqlite3_column_text(stmt,1);

        cout<<ids<<"-"<<date<<endl;
}

     std::cin >> Appartenir::idsaison;
     string sais;
     stringstream div1;
     div1 << Appartenir::idsaison;
     div1>>sais;
     system("cls");

     // Choix de la division

     cout << "Entrer le numero pour choisir la division "<<endl;

    sqlite3_prepare_v2(db, "select divisions.id, divisions.libelle, championnats.pays from divisions, championnats where divisions.idchampionnat = championnats.id ", -1, &stmt, 0);
    int idd;
    const unsigned char* libelle;
    const unsigned char* pays;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        idd = sqlite3_column_int(stmt,0);
        libelle = sqlite3_column_text(stmt,1);
        pays = sqlite3_column_text(stmt,2);

        cout<<idd<<"-"<<libelle<<"-"<<pays<<endl;
}

     std::cin >> Appartenir::iddivision;
     string div;
     stringstream intervertion;
     intervertion << Appartenir::iddivision;
     intervertion>>div;
     system("cls");

// Choix de l'identifiant de l'equipe.
    cout << "Entrer le numero pour choisir l' equipe "<<endl;

    sqlite3_prepare_v2(db, "select * from equipes ", -1, &stmt, 0);
    int idE;
    const unsigned char* nomE;

while(sqlite3_step(stmt) != SQLITE_DONE){
        idE = sqlite3_column_int(stmt,0);
        nomE = sqlite3_column_text(stmt,1);

        cout<<idE<<"-"<<nomE<<endl;
}

     std::cin >> Appartenir::idequipe;
     string equip;
     stringstream intervertion3;
     intervertion3 << Appartenir::idequipe;
     intervertion3>>equip;

    string query = "insert into appartenir (saison,division,equipe) VALUES ('"+sais+"','"+div+"','"+equip+"');";
    rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK){
        std::cout << "Erreur d'insertion" << err;

}




}

