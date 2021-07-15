
#include "Championnat.h"




void Championnat::CreationChampionnat(){
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;
    int test=0;
    while(test==0){

        system ("cls");
        cout << "Pour creer un championnat, entrer le pays (ex: Cote d'Ivoire ): " ;
        cin >> Championnat::pays;
        string requete = "select * from championnats where pays = '"+Championnat::pays+"';";
        sqlite3_prepare_v2(db,requete.c_str(), -1, &stmt, 0);
        if(sqlite3_step(stmt)!= SQLITE_DONE){
                cout<<" le championnat saisi existe deja."<<endl;
        }
        else{
            string query = "insert into championnats (pays) VALUES ('"+Championnat::pays+"');";
            rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
            if (rc != SQLITE_OK){
                cout << "Erreur d'insertion" << err;
            }
            else {
               system ("cls");
               cout << "Championnat de "<<Championnat::pays<<" cree "<<endl ;
            }test=1;
        }
    }
}


// pour modifier un championnat
void Championnat::ModificationChampionnat()
{
    system ("cls");
    cout << "Entrer le numero pour choisir le championnat A modifier "<<endl;

    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    sqlite3_prepare_v2(db, "select * from championnats ", -1, &stmt, 0);
    int id;
    const unsigned char* pays;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        pays = sqlite3_column_text(stmt,1);

        cout<<id<<" - "<<pays<<endl;
}

     std::cin >> Championnat::idchampionnat;
     string cham;
     stringstream champi;
     champi << Championnat::idchampionnat;
     champi>>cham;
        system ("cls");
        cout<<"Entrez le nouveau pays du championnat : (ex : France)"<<endl;
        string val;
        cin>>val;



        string query = "update championnats set pays = '"+val+"'where id ='"+cham+"';";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
        std::cout << "Erreur de modification   " << err;
        }


    // pour afficher la nouvelle liste des championnats
        else {
           cout << "Felicitations, voici la nouvelle liste de championnats "<<endl;
            sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    string q2 = "select * from championnats;" ;
    sqlite3_prepare_v2(db, q2.c_str(), -1, &stmt, 0);

    int id;
    const unsigned char* pays;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        pays = sqlite3_column_text(stmt,1);

        cout<<id<<" - "<<pays<<endl;
}
    }


     }



// Pour supprimer un championnat

void Championnat::SuppressionChampionnat()
{
            system ("cls");
    cout << "Entrer le numero du championnat a supprimer "<<endl;
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    sqlite3_prepare_v2(db, "select * from championnats ", -1, &stmt, 0);
    int id;
    const unsigned char* pays;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        pays = sqlite3_column_text(stmt,1);

        cout<<id<<"-"<<pays<<endl;
}

     std::cin >> Championnat::idchampionnat;

     string cham;
     stringstream champi;
     champi << Championnat::idchampionnat;
     champi>>cham;
    string query = "delete from championnats where id ='"+cham+"';";
    rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK){
        std::cout << "Erreur de suppression   " << err;

}
}




// Affichage championnat

void Championnat::AffichageChampionnat()
{
 std::cout << termcolor::red;
 system ("cls");
cout<<"\n*** *** *** *** La liste des championnats *** *** *** *** \n"<<endl;
std::cout << termcolor::reset;

sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;


sqlite3_prepare_v2(db, "select * from Championnats ", -1, &stmt, 0);
int id;
    const unsigned char* pays;
system ("cls");
while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        pays = sqlite3_column_text(stmt,1);


        cout<<"Le championnat de "<<pays<<endl;
}

}
