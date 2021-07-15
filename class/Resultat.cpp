
#include "Resultat.h"



// ************************CREATION MATCH******************************




void Match::CreationMatch() {

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
    std::cin >> Match::idchampionnat; //Récupération de l'id du championnat
    string cham;
     stringstream divis;
     divis << Match::idchampionnat;
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

     std::cin >> Match::iddivision; // Récupération de l'id de la division

     string div;
     stringstream division;
     division << Match::iddivision;
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

     std::cin >> Match::idsaison; // Récupération de l'id de la division

     string saisid;
     stringstream intervertion6;
     intervertion6 << Match::idsaison;
     intervertion6>>saisid;



    // Affichage liste des équipes de la division et choix de l'equipe 1
    system ("cls");
    cout << "choisissez l'equipe 1\n" ;
    string r4 ="select equipes.id, equipes.nom from saisons, appartenir, divisions, equipes where appartenir.division = '"+div+"' AND appartenir.saison = '"+saisid+"' AND appartenir.equipe = equipes.id AND saisons.id = '"+saisid+"' AND divisions.id = '"+div+"';";
    sqlite3_prepare_v2(db, r4.c_str(), -1, &stmt, 0);
    int id3;
    const unsigned char* nomEq;

while(sqlite3_step(stmt) != SQLITE_DONE){
        id3 = sqlite3_column_int(stmt,0);
        nomEq = sqlite3_column_text(stmt,1);

        cout<<id3<<"-"<<nomEq<<endl;
}

     std::cin >> Match::ideq1; // Récupération de l'id de l'équipe 1
     string idequipe1;
     stringstream intervertion3;
     intervertion3 << Match::ideq1;
     intervertion3>>idequipe1;

    // Affichage liste des équipes de la division et choix de l'equipe 2
    system ("cls");
    cout << "choisissez l'equipe 2\n" ;
    string r5 = "select equipes.id, equipes.nom from saisons, appartenir, divisions, equipes where appartenir.division = '"+div+"' AND appartenir.saison = '"+saisid+"' AND appartenir.equipe = equipes.id AND saisons.id = '"+saisid+"' AND divisions.id = '"+div+"' AND equipes.id != '"+idequipe1+"';";
    sqlite3_prepare_v2(db, r5.c_str(), -1, &stmt, 0);
    int id4;
    const unsigned char* nomEq2;

    while(sqlite3_step(stmt) != SQLITE_DONE){
        id4 = sqlite3_column_int(stmt,0);
        nomEq2 = sqlite3_column_text(stmt,1);

        cout<<id4<<"-"<<nomEq2<<endl;
}

     std::cin >> Match::ideq2; // Récupération de l'id de l'équipe 2
     string idequipe2;
     stringstream intervertion4;
     intervertion4 << Match::ideq2;
     intervertion4>>idequipe2;


    // Points, scores et goal différentiel à zéro pour signifier que le match n'est pas encore joué

    Match::score_1 = 0;
    Match::score_2 = 0;
    Match::point_1 = 0;
    Match::point_2 = 0;
    Match::gd1 = 0;
    Match::gd2 = 0;


    // date et journee

    cout << "Date du match " ;

    std::cin >> Match::date;

    cout << "Journee du match " ;


     std::cin >> Match::journee;
     string jrnee;
     stringstream intervertion;
     intervertion << Match::journee;
     intervertion>>jrnee;


// affichage du match
    string r6 ="select equipes.nom, equipes.nom from equipes where equipes.id = '"+idequipe1+"' OR equipes.id = '"+idequipe2+"';";
    sqlite3_prepare_v2(db, r6.c_str(), -1, &stmt, 0);
    const unsigned char* nomequ1;
    const unsigned char* nomequ2;
    int saut = 1;

    while(sqlite3_step(stmt) != SQLITE_DONE){
    nomequ1 = sqlite3_column_text(stmt,0);
    nomequ2 = sqlite3_column_text(stmt,1);

if(saut%2 !=0)
{
    cout<<Match::date<<"   -   journee "<<jrnee<<"   "<<nomequ1;
    saut++;
}
else
{
    cout<<"  "<<"-"<<"  "<<nomequ2<<endl;
    saut++;
}



}

// insertion du match dans la bd
string point1;
     stringstream intervertion10;
     intervertion10 << Match::point_1;
     intervertion10>>point1;

     string point2;
     stringstream intervertion9;
     intervertion9 << Match::point_2;
     intervertion9>>point2;

     string score1;
     stringstream intervertion11;
     intervertion11 << Match::score_1;
     intervertion11>>score1;

      string score2;
     stringstream intervertion12;
     intervertion12 << Match::score_2;
     intervertion12>>score2;

      string gdiff1;
     stringstream intervertion13;
     intervertion13 << Match::gd1;
     intervertion13>>gdiff1;

     string gdiff2;
     stringstream intervertion14;
     intervertion14 << Match::gd2;
     intervertion14>>gdiff2;

    string r8 ="insert into matchs (date, journee, score_1, score_2, point_1, point_2, goaldiff1, goaldiff2, iddiv, idsais, equipe_1, equipe_2) values ('"+date+"', '"+jrnee+"', '"+score1+"', '"+score2+"', '"+point1+"', '"+point2+"', '"+gdiff1+"', '"+gdiff2+"', '"+div+"', '"+saisid+"', '"+idequipe1+"', '"+idequipe2+"');";
    rc = sqlite3_exec(db, r8.c_str(), NULL, NULL, &err);
            if (rc != SQLITE_OK){
                cout << "Erreur d'insertion" << err;
}
}



// ************************MODIFICATION MATCH******************************






void Match::ModificationMatch()
{




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
    std::cin >> Match::idchampionnat; //Récupération de l'id du championnat
    string cham;
     stringstream divis;
     divis << Match::idchampionnat;
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

     std::cin >> Match::iddivision; // Récupération de l'id de la division

     string div;
     stringstream division;
     division << Match::iddivision;
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

     std::cin >> Match::idsaison; // Récupération de l'id de la division

     string saisid;
     stringstream intervertion6;
     intervertion6 << Match::idsaison;
     intervertion6>>saisid;


    // Affichage et Selection du match à modifier

    system ("cls");
    cout << "Entrer le numero du match a modifier "<<endl;

    string req2 = "select matchs.id,  matchs.date, matchs.journee, equipes.nom, equipes.nom, matchs.point_1, matchs.point_2, matchs.score_1, matchs.score_2  from matchs, equipes, divisions, saisons where saisons.id = matchs.idsais AND saisons.id ='"+saisid+"' AND matchs.iddiv= '"+div+"' AND matchs.iddiv = divisions.id AND (matchs.equipe_1= equipes.id OR matchs.equipe_2= equipes.id ); " ;
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
    cout<<id<<" "<<date<<"   -   journee "<<jrnee<<"   "<<"("<<pt1<<")"<<eq1<<" "<<sc1;
    saut++;
}
else
{
    cout<<"  "<<"-"<<"  "<<sc2<<" "<<eq2<<"("<<pt2<<")"<<endl;
    saut++;
}
}

     std::cin >> Match::id;

     string idm;
     stringstream intervertion;
     intervertion << Match::id;
     intervertion>>idm;
     int val;
     cout<<"Choisissez le champ a modifier"<<endl;
     cout<<"1- la date du match"<<endl;
     cout<<"2- la journee"<<endl;

     cin>>val;
     if(val==1)
     { string val1;
        cout<<"Entrez la nouvelle valeur date du match (ex: 01/04/2021)"<<endl;
        cin>>val1;
        string r1 = "update matchs set date  ='"+val1+"' where matchs.id ='"+idm+"';";
    rc = sqlite3_exec(db, r1.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
        std::cout << "Erreur de modification de la date " << err;

        }

     }
     else
     {



        cout<<"Entrez la nouvelle valeur de la journee (exemple : 4)"<<endl;
        int val2;
        cin>>val2;
         string jrn;
        stringstream intervertion2;
        intervertion2 <<  val2;
        intervertion2>>jrn;
        string r2 = "update matchs set journee  ='"+jrn+"' where matchs.id ='"+idm+"';";
        rc = sqlite3_exec(db, r2.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
        std::cout << "Erreur de modification de la journee " << err;

        }
     }

     }




// ************************Suppression MATCH******************************




void Match::SuppressionMatch() {


//Affichage des championnats

    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("mydb.db", &db);
    char* err;

    cout << "Entrer le numero correspondant au championnat "<<endl;

    sqlite3_prepare_v2(db, "select * from Championnats ", -1, &stmt, 0);
    int id1;
    const unsigned char* pays;

while(sqlite3_step(stmt) != SQLITE_DONE){
        id1 = sqlite3_column_int(stmt,0);
        pays = sqlite3_column_text(stmt,1);

        cout<<id1<<"-"<<pays<<endl;
}
    std::cin >> Match::idchampionnat; //Récupération de l'id du championnat
    string cham;
     stringstream divis;
     divis << Match::idchampionnat;
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

     std::cin >> Match::iddivision; // Récupération de l'id de la division

     string div;
     stringstream division;
     division << Match::iddivision;
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

     std::cin >> Match::idsaison; // Récupération de l'id de la division

     string saisid;
     stringstream intervertion6;
     intervertion6 << Match::idsaison;
     intervertion6>>saisid;


    // Affichage et Selection du match à SUPPRIMER

    system ("cls");
    cout << "Entrer le numero du match a supprimer "<<endl;

    string req2 = "select matchs.id,  matchs.date, matchs.journee, equipes.nom, equipes.nom, matchs.point_1, matchs.point_2, matchs.score_1, matchs.score_2  from matchs, equipes, divisions, saisons where saisons.id = matchs.idsais AND saisons.id ='"+saisid+"' AND matchs.iddiv= '"+div+"' AND matchs.iddiv = divisions.id AND (matchs.equipe_1= equipes.id OR matchs.equipe_2= equipes.id ); " ;
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
    cout<<id<<" "<<date<<"   -   journee "<<jrnee<<"   "<<"("<<pt1<<")"<<eq1<<" "<<sc1;
    saut++;
}
else
{
    cout<<"  "<<"-"<<"  "<<sc2<<" "<<eq2<<"("<<pt2<<")"<<endl;
    saut++;
}
}

     std::cin >> Match::id;

     string idm;
     stringstream intervertion;
     intervertion << Match::id;
     intervertion>>idm;

        string r1 = "delete from matchs where matchs.id ='"+idm+"';";
    rc = sqlite3_exec(db, r1.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
        std::cout << "Erreur de suppression du match" << err;

        }

}









// *****************************AFFICHAGE DES resultats************************************************




void Match::AffichageResultats(){
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
    std::cin >> Match::idchampionnat; //Récupération de l'id du championnat
    string cham;
     stringstream divis;
     divis << Match::idchampionnat;
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

     std::cin >> Match::iddivision; // Récupération de l'id de la division

     string div;
     stringstream division;
     division << Match::iddivision;
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

     std::cin >> Match::idsaison; // Récupération de l'id de la division

     string saisid;
     stringstream intervertion6;
     intervertion6 << Match::idsaison;
     intervertion6>>saisid;


    // Affichage des resultats

    std::cout << termcolor::yellow;
    system ("cls");
    cout<< "\n**************** Les resultats *****************\n"<<endl;

    string req2 = "select matchs.id,  matchs.date, matchs.journee, equipes.nom, equipes.nom, matchs.point_1, matchs.point_2, matchs.score_1, matchs.score_2  from matchs, equipes, divisions, saisons where saisons.id = matchs.idsais AND saisons.id ='"+saisid+"' AND matchs.iddiv= '"+div+"' AND matchs.iddiv = divisions.id AND (matchs.equipe_1= equipes.id OR matchs.equipe_2= equipes.id ) AND ( matchs.point_1 != 0 OR  matchs.point_2!=0 ); " ;
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
    cout<<id<<" "<<date<<"   -   journee "<<jrnee<<"   "<<"("<<pt1<<")"<<eq1<<" "<<sc1;
    saut++;
}
else
{
    cout<<"  "<<"-"<<"  "<<sc2<<" "<<eq2<<"("<<pt2<<")"<<endl;
    saut++;
}
}
std::cout << termcolor::reset;
}





//**********************Ajouter resultat*****************************************************************

void Match::AjouterResultat() {

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
    std::cin >> Match::idchampionnat; //Récupération de l'id du championnat
    string cham;
     stringstream divis;
     divis << Match::idchampionnat;
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

     std::cin >> Match::iddivision; // Récupération de l'id de la division

     string div;
     stringstream division;
     division << Match::iddivision;
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

     std::cin >> Match::idsaison; // Récupération de l'id de la division

     string saisid;
     stringstream intervertion6;
     intervertion6 << Match::idsaison;
     intervertion6>>saisid;


    // Affichage et Selection du match à modifier

    system ("cls");
    cout << "Entrer le numero du resultat a ajouter "<<endl;

string req2 = "select matchs.id,  matchs.date, matchs.journee, equipes.nom, equipes.nom, matchs.point_1, matchs.point_2, matchs.score_1, matchs.score_2  from matchs, equipes, divisions, saisons where saisons.id = matchs.idsais AND saisons.id ='"+saisid+"' AND matchs.iddiv= '"+div+"' AND matchs.iddiv = divisions.id AND (matchs.equipe_1= equipes.id OR matchs.equipe_2= equipes.id ) AND  matchs.point_1= 0 AND  matchs.point_2=0 ; " ;    sqlite3_prepare_v2(db,req2.c_str(), -1, &stmt, 0);
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
    cout<<id<<" "<<date<<"   -   journee "<<jrnee<<"   "<<"("<<pt1<<")"<<eq1<<" "<<sc1;
    saut++;
}
else
{
    cout<<"  "<<"-"<<"  "<<sc2<<" "<<eq2<<"("<<pt2<<")"<<endl;
    saut++;
}
}

     std::cin >> Match::id;

     string idm;
     stringstream intervertion;
     intervertion << Match::id;
     intervertion>>idm;
    int val1;
    int val2;
    string sco1;
    string sco2;
    stringstream intervertion3;
    stringstream intervertion4;

    std::cout << termcolor::red;
    system ("cls");
    cout<<"\n******** C'est le moment d'entrer le resultat du match ********\n"<<endl;

    std::cout << termcolor::reset;


    cout<<"\nEntrez le nombre de buts de l'equipe a domicile\n"<<endl;
    cin>>val1;
    intervertion3 << val1;
    intervertion3>>sco1;

    cout<<"\nEntrez le nombre de buts de l'equipe a l'exterieur\n"<<endl;
    cin>>val2;
    intervertion4 <<val2;
    intervertion4>>sco2;
    if(val1>val2)

    {   // gestion des points
        string point1;
        string point2;
        stringstream div1;
        stringstream div2;
        int pt1 =3;
        int pt2 = 0;
        div1<<pt1;
        div1>>point1;
        div2<<pt2;
        div2>>point2;

        // gestion des goals differentiels

        string gdif1;
        string gdif2;
        stringstream class1;
        stringstream class2;
        int gd1 =val1-val2;
        int gd2 = val2-val1;
        class1<<gd1;
        class1>>gdif1;
        class2<<gd2;
        class2>>gdif2;



        string r3 = "update matchs set score_1='"+sco1+"' , score_2='"+sco2+"', point_1= '"+point1+"',point_2= '"+point2+"', goaldiff2= '"+gdif2+"', goaldiff1= '"+gdif1+"'  where matchs.id ='"+idm+"';";
        rc = sqlite3_exec(db, r3.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
        std::cout << "Erreur de modification du score" << err;

        }
    }
    else if (val1<val2)
    {
        string point1;
        string point2;
        stringstream intervertion1;
        stringstream intervertion2;
        int pt1 =0;
        int pt2 = 3;
        intervertion1<<pt1;
        intervertion1>>point1;
        intervertion2<<pt2;
        intervertion2>>point2;

        // gestion des goals differentiels

        string gdif1;
        string gdif2;
        stringstream class3;
        stringstream class4;
        int gd1 =val1-val2;
        int gd2 = val2-val1;
        class3<<gd1;
        class3>>gdif1;
        class4<<gd2;
        class4>>gdif2;

        string query = "update matchs set score_1='"+sco1+"' , score_2='"+sco2+"', point_1= '"+point1+"',point_2 = '"+point2+"',goaldiff2= '"+gdif2+"', goaldiff1= '"+gdif1+"' where matchs.id ='"+idm+"';";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
        std::cout << "Erreur de modification du score   " << err;

        }

    }
    else
    {
        string point1;
        string point2;
        stringstream intervertion6;
        stringstream intervertion7;
        int pt1 =1;
        int pt2 = 1;
        intervertion6<<pt1;
        intervertion6>>point1;
        intervertion7<<pt2;
        intervertion7>>point2;

        // gestion des goals differentiels

        string gdif1;
        string gdif2;
        stringstream class5;
        stringstream class6;
        int gd1 =0;
        int gd2 = 0;
        class5<<gd1;
        class5>>gdif1;
        class6<<gd2;
        class6>>gdif2;
        string query = "update matchs set score_1='"+sco1+"' , score_2='"+sco2+"', point_1='"+point1+"',point_2= '"+point2+"', goaldiff2= '"+gdif2+"', goaldiff1= '"+gdif1+"' where matchs.id ='"+idm+"';";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
        std::cout << "Erreur de modification du score  " << err;

            }
        }
     }

