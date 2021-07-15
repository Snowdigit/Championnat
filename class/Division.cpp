#include "Division.h"


// Pour créer une division

void Division::CreationDivision(){


     sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;
    system ("cls");
    cout << "Entrer le numero pour choisir championnat "<<endl;

    sqlite3_prepare_v2(db, "select * from Championnats ", -1, &stmt, 0);
int id;
    const unsigned char* pays;

while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        pays = sqlite3_column_text(stmt,1);

        cout<<id<<"-"<<pays<<endl;
}

     std::cin >> Division::idchampionnat;
     string cham;
     stringstream division;
     division << Division::idchampionnat;
     division>>cham;

    cout << "Entrer la division  (ex : ligue1) : " ;
    std::cin >> Division::libelle;



    string r1 = "insert into divisions (libelle,idchampionnat) VALUES ('"+Division::libelle+"','"+cham+"');";
    rc = sqlite3_exec(db, r1.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK){
        std::cout << "Erreur d'insertion" << err;

}
}


// pour modifier une division
void Division::ModificationDivision()
{   system ("cls");
     cout << "Entrer le numero de la division a Modifier "<<endl;
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    sqlite3_prepare_v2(db, "select divisions.id, divisions.libelle, championnats.pays from divisions, championnats where divisions.idchampionnat = championnats.id ", -1, &stmt, 0);
    int id;
    const unsigned char* libelle;
    const unsigned char* pays;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        libelle = sqlite3_column_text(stmt,1);
        pays = sqlite3_column_text(stmt,2);

        cout<<id<<" - "<<libelle<<" - "<<pays<<endl;
}

     std::cin >> Division::iddivision;
     string cham;
     stringstream division;
     division << Division::iddivision;
     division>>cham;
     system("cls");
     bool test = 1;
     int id_valeur;
     while(test)
     {
         system ("cls");
     cout<<"Choisissez le champ a modifier :"<<endl;
     cout<< "1.Nom de la division"<<endl;
     cout<< "2.Le Championnat"<<endl;
     int val1;
     cin>>val1;

     if(val1== 1)
     {  system ("cls");
        cout<<"Entrez la nouveau libelle de la division : (ex : Ligue1)"<<endl;
        string val;
        cin>>val;
        string query = "update divisions set libelle = '"+val+"'where id ='"+cham+"';";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
        std::cout << "Erreur de modification   " << err;
}



    // pour afficher les nouvelles divisions d'un championnat lorsqu'une division est modifiée
        else {
                system ("cls");
           cout << "Felicitations, voici la nouvelle liste de divisions dans le championnat "<<endl;
            sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;
    string q2 = "select divisions.id, divisions.libelle, championnats.pays from divisions, championnats where divisions.idchampionnat = championnats.id AND divisions.idchampionnat = '"+cham+"';";
    sqlite3_prepare_v2(db, q2.c_str(), -1, &stmt, 0);
    int id;
    const unsigned char* libelle;
    const unsigned char* pays;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        libelle = sqlite3_column_text(stmt,1);
        pays = sqlite3_column_text(stmt,2);

        cout<<id<<" - "<<libelle<<" - "<<pays<<endl;



        }

        // Fin

     }
     test = 0;
     }
     else if(val1==2)
     {
         system ("cls");
        cout << "Entrer le numero du championnat correspondant "<<endl;
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
        std::cin >> Division::idchampionnat;
        string newid;
        stringstream division;
        division << Division::idchampionnat;
        division>>newid;

        string query = "update divisions set idchampionnat = '"+newid+"'where id ='"+cham+"';";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
        std::cout << "Erreur de modification   " << err;

        }
        test = 0;

     }
}



}

// Pour supprimer une division

void Division::SuppressionDivision()
{
    system ("cls");
    cout << "Entrer le numero de la division a supprimer "<<endl;
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    sqlite3_prepare_v2(db, "select * from divisions ", -1, &stmt, 0);
    int id;
    const unsigned char* libelle;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        libelle = sqlite3_column_text(stmt,1);

        cout<<id<<"-"<<libelle<<endl;
}

     std::cin >> Division::iddivision;

     string cham;
     stringstream division;
     division << Division::iddivision;
     division>>cham;
    string query = "delete from divisions where id ='"+cham+"';";
    rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK){
        std::cout << "Erreur de suppression   " << err;

}
}



//***************************** Classement ******************************



void Division::Classement(){

//Affichage des championnats

    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;
    system ("cls");
    cout << "Entrer le numero correspondant au championnat "<<endl;

    sqlite3_prepare_v2(db, "select * from championnats ", -1, &stmt, 0);
    int id1;
    const unsigned char* pays;

while(sqlite3_step(stmt) != SQLITE_DONE){
        id1 = sqlite3_column_int(stmt,0);
        pays = sqlite3_column_text(stmt,1);

        cout<<id1<<"-"<<pays<<endl;
}
    std::cin >> Division::idchampionnat; //Récupération de l'id du championnat
    string cham;
     stringstream divis;
     divis << Division::idchampionnat;
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

     std::cin >> Division::iddivision; // Récupération de l'id de la division

     string div;
     stringstream division;
     division << Division::iddivision;
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

     std::cin >> Division::idsaison; // Récupération de l'id de la division

         string saisid;
         stringstream intervertion6;
         intervertion6 << Division::idsaison;
         intervertion6>>saisid;

        string req4 ="SELECT Eq.nom,Eq.point,Eq.Gdif from (SELECT Z.nom,sum(Z.point) as point,sum(Z.Gdif) as Gdif from (select E1.nom,sum(matchs.point_1) as point,sum(matchs.goaldiff1) as Gdif from matchs, equipes E1,divisions WHERE matchs.equipe_1 = E1.id and matchs.iddiv = divisions.id and divisions.id ='"+div+"' AND matchs.idsais = '"+saisid+"' GROUP by E1.nom UNION select E2.nom,sum(matchs.point_2) as point,sum(matchs.goaldiff2) as Gdif from matchs, equipes E2,divisions WHERE matchs.equipe_2 = E2.id and matchs.iddiv = divisions.id and divisions.id ='"+div+"' AND matchs.idsais = '"+saisid+"' GROUP by E2.nom) As Z GROUP by Z.nom) AS Eq ORDER by Eq.point DESC,Eq.Gdif DESC;";
        sqlite3_prepare_v2(db,req4.c_str() , -1, &stmt, 0);
        int point;
        int gdif;
        int pos = 0;
        const unsigned char* nomeq;
        system ("cls");
           std::cout << termcolor::red;
           std::cout <<"^^^^^^^^^^ Le Classement ^^^^^^^^^^\n" << std::endl;
           std::cout << termcolor::reset;
           cout<<"position ----"<<"  Equipes   "<<"----   points   ----"<<"Ecart de buts"<<endl;
           std::cout << termcolor::yellow;
        while(sqlite3_step(stmt) != SQLITE_DONE){
        nomeq = sqlite3_column_text(stmt,0);
        point = sqlite3_column_int(stmt,1);
        gdif = sqlite3_column_int(stmt,2);


    std::cout <<"\n________________________________________________________________\n" << std::endl;

    cout<<++pos<<"      ----   "<<nomeq<<"      ----   "<<point<<"    ----    "<<gdif<<endl;


        }
    std::cout << termcolor::reset;


}

//****************************Calendrier***********************//


void Division::Calendrier(){
//Affichage des championnats

    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;
    system ("cls");
    cout << "Entrer le numero correspondant au championnat "<<endl;

    sqlite3_prepare_v2(db, "select * from championnats ", -1, &stmt, 0);
    int id1;
    const unsigned char* pays;

while(sqlite3_step(stmt) != SQLITE_DONE){
        id1 = sqlite3_column_int(stmt,0);
        pays = sqlite3_column_text(stmt,1);

        cout<<id1<<"-"<<pays<<endl;
}
    std::cin >> Division::idchampionnat; //Récupération de l'id du championnat
    string cham;
     stringstream divis;
     divis << Division::idchampionnat;
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

     std::cin >> Division::iddivision; // Récupération de l'id de la division

     string div;
     stringstream division;
     division << Division::iddivision;
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

     std::cin >> Division::idsaison; // Récupération de l'id de la division

     string saisid;
     stringstream intervertion6;
     intervertion6 << Division::idsaison;
     intervertion6>>saisid;


    // Affichage du Calendrier
    system ("cls");
    std::cout << termcolor::yellow;
    cout<< "**************** Le calendrier *****************"<<endl;


    string req2 = "select matchs.id,  matchs.date, matchs.journee, equipes.nom, equipes.nom, matchs.point_1, matchs.point_2, matchs.score_1, matchs.score_2  from matchs, equipes, divisions, saisons where saisons.id = matchs.idsais AND saisons.id ='"+saisid+"' AND matchs.iddiv= '"+div+"' AND matchs.iddiv = divisions.id AND (matchs.equipe_1= equipes.id OR matchs.equipe_2= equipes.id ) AND  matchs.point_1= 0 AND  matchs.point_2=0 ; " ;
    sqlite3_prepare_v2(db,req2.c_str(), -1, &stmt, 0);
    int id;
    int jrnee;
    int pt1;
    int pt2;
    int sc1;
    int sc2;
    const unsigned char* date;
    const unsigned char* eq1;
    const unsigned char* eq2;
    int saut=1;


  while(sqlite3_step(stmt) != SQLITE_DONE){
        id = sqlite3_column_int(stmt,0);
        date = sqlite3_column_text(stmt,1);
        jrnee = sqlite3_column_int(stmt,2);
        eq1 = sqlite3_column_text(stmt,3);
        eq2 = sqlite3_column_text(stmt,4);
        pt1 = sqlite3_column_int(stmt,5);
        pt2 = sqlite3_column_int(stmt,6);
        sc1 = sqlite3_column_int(stmt,7);
        sc2 = sqlite3_column_int(stmt,8);

        if(saut%2 !=0)
{
    cout<<id<<" "<<date<<"   -   journee "<<jrnee<<"   "<<eq1;
    saut++;
}
else
{
    cout<<"  "<<"-"<<" "<<eq2<<endl;
    saut++;
}
}
std::cout << termcolor::reset;
}



// ************************AFFICHAGE DIVISIONS*******************************


void Division::AffichageDivision(){


//Affichage des championnats

    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;
    system ("cls");
    cout << "Entrer le numero correspondant au championnat "<<endl;

    sqlite3_prepare_v2(db, "select * from Championnats ", -1, &stmt, 0);
    int id1;
    const unsigned char* pays;

while(sqlite3_step(stmt) != SQLITE_DONE){
        id1 = sqlite3_column_int(stmt,0);
        pays = sqlite3_column_text(stmt,1);

        cout<<id1<<"-"<<pays<<endl;
}
    std::cin >> Division::idchampionnat; //Récupération de l'id du championnat
    string cham;
     stringstream divis;
     divis << Division::idchampionnat;
     divis>>cham;





    string r4 ="select championnats.pays from divisions, championnats where divisions.idchampionnat = championnats.id AND divisions.idchampionnat = '"+cham+"';";
    sqlite3_prepare_v2(db, r4.c_str(), -1, &stmt, 0);
    const unsigned char* pays2;


    // Affichage de l'en-tête

    if(sqlite3_step(stmt) != SQLITE_DONE)
        {
    system ("cls");
    pays2 = sqlite3_column_text(stmt,0);
    cout << "\n** ** ** ** **La liste des divisions du championnat de "<<pays2<<"** ** ** ** **\n"<<endl;
        }
    //Affichage des divisions liées au championnat choisi

    string r3 ="select divisions.id, divisions.libelle, championnats.pays from divisions, championnats where divisions.idchampionnat = championnats.id AND divisions.idchampionnat = '"+cham+"';";
    sqlite3_prepare_v2(db, r3.c_str(), -1, &stmt, 0);
    int id2;
    const unsigned char* libelle;


while(sqlite3_step(stmt) != SQLITE_DONE){
        id2 = sqlite3_column_int(stmt,0);
        libelle = sqlite3_column_text(stmt,1);

        cout<<id2<<"-"<<libelle<<endl;
}
}


