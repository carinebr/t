#include <iostream>
#include "appli.h"
//
using namespace std;
//github.com prenom de mon amour + br sis:atom + 2 milles quinz
//cloner sous ~ ce projet   clone https://github.com/yehudabr/t
//git config user.email "yehuda_braun@yahoo.com"     c local au repertoire/repository
//git config user.name "<le nom>" idem!!
//ajouter les fichiers
//commit push etc...
//
//OK transformer Appli en singletone. 
//doxygene
//ouverture de fichier
//lecture ini
//coder une lecture ou un ping reseau - ex: google.com
//tester - exception
//multi threading
//reseau https://openclassrooms.com/courses/apprenez-le-fonctionnement-des-reseaux-tcp-ip
//       https://openclassrooms.com/courses/les-reseaux-de-zero
//declaration de l'instance (privee!) du singletone Appli
Appli* Appli::m_Instance = NULL;
int main()
{
    string sNomPrenom;
    Appli::getInstance();
    cout << "nom prenom" <<endl;
    getline(cin, sNomPrenom);
    cout<<"nom prenom:"<<sNomPrenom<<endl;
    delete Appli::getInstance();
    return 0;
}
