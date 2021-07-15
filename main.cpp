#include <iostream>
using namespace std;
#include "sqlite/sqlite/sqlite3.h"
#include "class/lib/termcolor/termcolor.hpp"
#include <string>
#include "class/Resultat.h"
#include "class/Division.h"
#include "class/Saison.h"
#include "class/Equipe.h"
#include "class/Championnat.h"
#include "class/Appartenir.h"



        Championnat c;
        Division d;
        Equipe e;
        Saison s;
        Appartenir a;
        Match m;


// Fonction pour le menu principal

   int menup (){

    cout<<" 1- Consulter les championnats"<<endl;
    cout<<" 2- Modifier les championnats"<<endl;
    cout<<" 3- Ajouter un championnat"<<endl;
    cout<<" 4- Supprimer un championnat"<<endl;
    cout<<" 5- Quitter"<<endl;
    std::cout <<"\n** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **" << std::endl;
    cout<<endl;
    cout<<"\nVeuillez choisir une option\n"<<endl;
    int mp;
    cin>>mp;
    switch (mp)
    {
    case 1:
             {
                system ("cls");
                c.AffichageChampionnat();
                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;

                }

    case 2:
                system ("cls");
                cout<<"\n Voici les differentes options, veuillez en choisir une... \n"<<endl;

                break;

    case 3:
                system ("cls");
                cout<<"\n Voici les differentes options, veuillez en choisir une... \n"<<endl;
                break;
    case 4:
                system ("cls");
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;
                break;
    case 5:
                system ("cls");
                exit(3);


    }
    return mp;
   }



// Fonction pour le menu 2

    int menu2 (){

                cout<<" \n"<<endl;

                cout<<"1- Consulter les divisions d'un championnat"<<endl;
                cout<<"2- Consulter les equipes d'un championnat"<<endl;
                cout<<"3- Consulter le calendrier d'un championnat"<<endl;
                cout<<"4- Consulter les resultats d'un championnat"<<endl;
                cout<<"5- Consulter le classement d'un championnat"<<endl;
                cout<<"6- Consulter les saisons "<<endl;
                cout<<"7- Revenir au menu principal"<<endl;
                cout<<"8- Quitter"<<endl;

                cout<<"\nChoisissez une option\n"<<endl;

                 int m2;
                cin>>m2;

                 switch (m2)
    {
    case 1:
                system ("cls");
                d.AffichageDivision();
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;

                break;

    case 2:
                system ("cls");
                e.AffichageEquipe();
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;

                break;

    case 3:
                system ("cls");
                d.Calendrier();
                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;
    case 4:
                system ("cls");
                m.AffichageResultats();
                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;

    case 5:
                system ("cls");
                d.Classement();
                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;

    case 6:
                system ("cls");
                s.AffichageSaison();
                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;

    case 7:
                system ("cls");

               menup();
               break;

    case 8:
                system ("cls");
                exit(3);
                break;

}

return m2;

    }

// Fonction pour le menu 3


   int menu3 (){

                cout<<" \n"<<endl;
                cout<<"1- Modifier le championnat"<<endl;
                cout<<"2- Modifier une division d'un championnat"<<endl;
                cout<<"3- Modifier un match d'un championnat"<<endl;
                cout<<"4- Modifier une saison"<<endl;
                cout<<"5- Ajouter un resultat"<<endl;
                cout<<"6- Lier une equipe a une division et une saison"<<endl;
                cout<<"7- Revenir au menu principal"<<endl;
                cout<<"8- Quitter"<<endl;

                cout<<"\nChoisissez une option\n"<<endl;

                 int m3;
                cin>>m3;

                 switch (m3)
    {

     case 1:

                system ("cls");
                c.ModificationChampionnat();
                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;

    case 2:

                system ("cls");
                d.ModificationDivision();
                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;


    case 3:
                system ("cls");
                m.ModificationMatch();
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;

                break;
    case 4:

                system ("cls");
                s.ModificationSaison();
                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;

     case 5:

                system ("cls");
                m.AjouterResultat();
                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;

    case 6:

                system ("cls");
                a.AppartientA();
                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;



    case 7:
                system ("cls");
                menup();
                break;

    case 8:
                system ("cls");
                exit(3);
                break;

}
return m3;
    }

// Fonction pour le menu 4



     int menu4 (){

                cout<<" \n"<<endl;
                cout<<"1- Creer un nouveau championnat"<<endl;
                cout<<"2- Ajouter une division a un championnat"<<endl;
                cout<<"3- Ajouter une equipe "<<endl;
                cout<<"4- Ajouter un match a championnat"<<endl;
                cout<<"5- Ajouter une saison"<<endl;
                cout<<"6- Revenir au menu principal"<<endl;
                cout<<"7- Quitter"<<endl;

                cout<<"\nChoisissez une option\n"<<endl;

                 int m4;
                cin>>m4;

                 switch (m4)
    {

    case 1:
                system ("cls");
                c.CreationChampionnat();
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;

                break;
    case 2:
                system ("cls");
                d.CreationDivision();
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;

                break;


    case 3:
                system ("cls");
                e.CreationEquipe();

                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;

    case 4:
                system ("cls");
                m.CreationMatch();
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;

                break;

    case 5:
                system ("cls");
                s.CreationSaison();
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;

                break;

    case 6:
                system ("cls");
                menup();
                break;

    case 7:
                system ("cls");
                exit(3);
                break;

}
return m4;
    }

// Fonction pour le menu 5



     int menu5 (){

                cout<<" \n"<<endl;
                cout<<"1- Supprimer un championnat"<<endl;
                cout<<"2- Supprimer une division d'un championnat"<<endl;
                cout<<"3- Supprimer une equipe"<<endl;
                cout<<"4- Supprimer un match d'un championnat"<<endl;
                cout<<"5- Supprimer une saison"<<endl;
                cout<<"6- Revenir au menu principal"<<endl;
                cout<<"7- Quitter"<<endl;

                cout<<"\nChoisissez une option\n"<<endl;

                int m5;
                cin>>m5;

                 switch (m5)
    {

    case 1:
                system ("cls");
                c.SuppressionChampionnat();
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;

                break;

    case 2:
                system ("cls");
                d.SuppressionDivision();
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;

                break;


    case 3:

                system ("cls");
                e.SuppressionEquipe();
                cout<<"\n Que voulez-vous faire ensuite ? \n"<<endl;

                break;

    case 4:

                system ("cls");
                m.SuppressionMatch();
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;

                break;

    case 5:

                system ("cls");
                s.SuppressionSaison();
                cout<<"\n Que voulez-vous faire ensuite ?\n "<<endl;

                break;

    case 6:
              system ("cls");
              menup();
              break;

    case 7:
                system ("cls");
                exit(3);
                break;

}
return m5;
    }







int main()
{




    std::cout << termcolor::yellow;
    std::cout <<"     **************      365 SOCCER       *************    " << std::endl;
    std::cout <<"**********************************************************************" << std::endl;
    std::cout << termcolor::reset;

int test = 1;

while(test == 1)
{


    switch (menup())
    {
        case 1 : menu2() ; break;

        case 2 : menu3(); break;

        case 3 : menu4(); break;

        case 4 : menu5(); break;

        default : menup(); break;


    }
}


    return 0;

}






















