#include "Equipe.h"


// Pour créer une équipe


void Equipe::CreationEquipe(){
    sqlite3* db; char* err; sqlite3_stmt* stmt;
    int rc=sqlite3_open("mydb.db", &db);
    int test=0;
    while(test==0){
        system ("cls");
        cout << "Entrer l'equipe (ex : Chelsea): " ;
        cin >> Equipe::nom;
        string requete = "select * from equipes where nom = '"+Equipe::nom+"';";
        sqlite3_prepare_v2(db,requete.c_str(), -1, &stmt, 0);
        if(sqlite3_step(stmt)!= SQLITE_DONE){
                cout<<" l'equipe saisie existe deja."<<endl;
        }else{
            string query = "insert into equipes (nom) VALUES ('"+Equipe::nom+"');";
            rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
            if (rc != SQLITE_OK){
                cout << "Erreur d'insertion" << err;
            }test=1;
        }
    }
}


// pour modifier une équipe

void Equipe::ModificationEquipe()
{
       system ("cls");
    cout << "Entrer le numero pour choisir l'equipe A modifier "<<endl;

    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    sqlite3_prepare_v2(db, "select * from equipes ", -1, &stmt, 0);
    int id;
    const unsigned char* nom;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        nom = sqlite3_column_text(stmt,1);

        cout<<id<<" - "<<nom<<endl;
}

     std::cin >> Equipe::idequipe;
     string eq;
     stringstream equip;
     equip << Equipe::idequipe;
     equip>>eq;
           system ("cls");
        cout<<"Entrez le nouveau nom de l'equipe (ex : Chelsea)"<<endl;
        string val;
        cin>>val;



        string query = "update equipes set nom = '"+val+"'where id ='"+eq+"';";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
        std::cout << "Erreur de modification   " << err;
        }


    // pour afficher la nouvelle liste des equipes
        else {
            system ("cls");
            cout << "\nFelicitations, voici la nouvelle liste de equipes\n "<<endl;
            sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    string q2 = "select * from equipes;" ;
    sqlite3_prepare_v2(db, q2.c_str(), -1, &stmt, 0);

    int id;
    const unsigned char* nom;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        nom = sqlite3_column_text(stmt,1);

        cout<<id<<" - "<<nom<<endl;
}



    }


     }



// Pour supprimer une equipe

void Equipe::SuppressionEquipe()
{
       system ("cls");
    cout << "Entrer le numero de l'equipe a supprimer "<<endl;
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    sqlite3_prepare_v2(db, "select * from equipes ", -1, &stmt, 0);
    int id;
    const unsigned char* nom;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        nom = sqlite3_column_text(stmt,1);

        cout<<id<<"-"<<nom<<endl;
}

     std::cin >> Equipe::idequipe;

     string eq;
     stringstream equip;
     equip << Equipe::idequipe;
     equip>>eq;
    string query = "delete from equipes where id ='"+eq+"';";
    rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK){
        std::cout << "Erreur de suppression   " << err;

}
}

void Equipe::AffichageEquipe()

// Affichage des equipes liees appartenant a un Championnat, une division et une saison
{
       system ("cls");
 cout<<"Entrer le numero correspondant au championnat "<<endl;


    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;



    sqlite3_prepare_v2(db, "select * from Championnats ", -1, &stmt, 0);
    int id1;
    const unsigned char* pays;


while(sqlite3_step(stmt) != SQLITE_DONE){
        id1 = sqlite3_column_int(stmt,0);
        pays = sqlite3_column_text(stmt,1);

        cout<<id1<<"-"<<pays<<endl;
}
    std::cin >> Equipe::idchampionnat; //Récupération de l'id du championnat
    string cham;
     stringstream divis;
     divis << Equipe::idchampionnat;
     divis>>cham;



    //Affichage des divisions liées au championnat choisi

       system ("cls");
    cout << "Entrer le numero correspondant a la division "<<endl;

    string r3 ="select divisions.id, divisions.libelle, championnats.pays from divisions, championnats where divisions.idchampionnat = championnats.id AND divisions.idchampionnat = '"+cham+"';";
    sqlite3_prepare_v2(db, r3.c_str(), -1, &stmt, 0);
    int id2;
    const unsigned char* libelle;

while(sqlite3_step(stmt) != SQLITE_DONE){
        id2 = sqlite3_column_int(stmt,0);
        libelle = sqlite3_column_text(stmt,1);

        cout<<id2<<"-"<<libelle<<endl;
}

     std::cin >>Equipe::iddivision; // Récupération de l'id de la division

     string div;
     stringstream division;
     division << Equipe::iddivision;
     division>>div;


     //Affichage des saisons

       system ("cls");
    cout << "Entrer le numero correspondant a la saison "<<endl;

    string r7 ="select * from saisons ;";
    sqlite3_prepare_v2(db, r7.c_str(), -1, &stmt, 0);
    int id6;
    const unsigned char* libelle6;

while(sqlite3_step(stmt) != SQLITE_DONE){
        id6 = sqlite3_column_int(stmt,0);
        libelle6 = sqlite3_column_text(stmt,1);

        cout<<id6<<"-"<<libelle6<<endl;
}

     std::cin >> Equipe::idsaison; // Récupération de l'id de la division

     string saisid;
     stringstream intervertion6;
     intervertion6 << Equipe::idsaison;
     intervertion6>>saisid;



    // Affichage liste des équipes de la division
           system ("cls");
        cout << "Voici les equipes du championnat\n" ;
    string r4 ="select equipes.nom from saisons, appartenir, divisions, equipes where appartenir.division = '"+div+"' AND appartenir.saison = '"+saisid+"' AND appartenir.equipe = equipes.id AND saisons.id = '"+saisid+"' AND divisions.id = '"+div+"';";
    sqlite3_prepare_v2(db, r4.c_str(), -1, &stmt, 0);
    const unsigned char* nomEq;

while(sqlite3_step(stmt) != SQLITE_DONE){
        nomEq = sqlite3_column_text(stmt,0);

        cout<<nomEq<<endl;
}
}
