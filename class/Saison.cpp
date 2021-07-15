
#include "Saison.h"




void Saison::CreationSaison(){
    sqlite3* db; char* err; sqlite3_stmt* stmt;
    int rc=sqlite3_open("mydb.db", &db);
    int test=0;
    while(test==0){
            system ("cls");
        std::cout << "Entrer la saison (exp : 2019-2020 ): " ;
        std::cin >> Saison::libelle;
        string requete = "select * from saisons where libelle = '"+Saison::libelle+"';";
        sqlite3_prepare_v2(db,requete.c_str(), -1, &stmt, 0);
        if(sqlite3_step(stmt)!= SQLITE_DONE){
                cout<<" la saison saisie existe deja."<<endl;
        }else{
            string query = "insert into saisons (libelle) VALUES ('"+Saison::libelle+"');";
            rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
            if (rc != SQLITE_OK){
                std::cout << "Erreur d'insertion" << err;
            }test=1;
        }
    }
}






// pour modifier une saison

void Saison::ModificationSaison()
{           system ("cls");
    cout << "Entrer le numero pour choisir la saison a modifier "<<endl;

    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    sqlite3_prepare_v2(db, "select * from saisons ", -1, &stmt, 0);
    int id;
    const unsigned char* libelle;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        libelle = sqlite3_column_text(stmt,1);

        cout<<id<<" - "<<libelle<<endl;
}

     std::cin >> Saison::idsaison;
     string sais;
     stringstream saison;
     saison << Saison::idsaison;
     saison>>sais;
        system ("cls");
        cout<<"Entrez le nouveau libelle de la saison (ex : 2014-2015)"<<endl;
        string val;
        cin>>val;



        string query = "update saisons set libelle = '"+val+"'where id ='"+sais+"';";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
        std::cout << "Erreur de modification   " << err;
        }


    // pour afficher la nouvelle liste des saisons
        else {
                system ("cls");
           cout << "Felicitations, voici la nouvelle liste de saisons "<<endl;
            sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    string q2 = "select * from saisons;" ;
    sqlite3_prepare_v2(db, q2.c_str(), -1, &stmt, 0);

    int id;
    const unsigned char* libelle;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        libelle = sqlite3_column_text(stmt,1);

        cout<<id<<" - "<<libelle<<endl;
}
    }


     }



// Pour supprimer une Saison

void Saison::SuppressionSaison()
{
    system ("cls");
    cout << "Entrer le numero de la Saison a supprimer "<<endl;
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    sqlite3_prepare_v2(db, "select * from saisons ", -1, &stmt, 0);
    int id;
    const unsigned char* libelle;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        libelle = sqlite3_column_text(stmt,1);

        cout<<id<<"-"<<libelle<<endl;
}

     std::cin >> Saison::idsaison;

     string sais;
     stringstream saison;
     saison << Saison::idsaison;
     saison>>sais;
    string query = "delete from saisons where id ='"+sais+"';";
    rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK){
        std::cout << "Erreur de suppression   " << err;

}
}


// Affichage des saisons

void Saison::AffichageSaison()
{

 std::cout << termcolor::red;
 system ("cls");
cout<<"++++++++++ La liste des saisons ++++++++++\n"<<endl;
std::cout << termcolor::reset;


sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    sqlite3_prepare_v2(db, "select * from saisons ", -1, &stmt, 0);
    int id;
    const unsigned char* libelle;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        libelle = sqlite3_column_text(stmt,1);

        cout<<id<<" - "<<libelle<<endl;

}
}
