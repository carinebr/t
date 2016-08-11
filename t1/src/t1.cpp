#include <iostream>
#include "appli.h"

using namespace std;
//git   ouvrir un compte non reconnaisable sous git (nouveau mail???)
//ouvrir un projet 't' avec ce compte 
//cloner sous ~ ce projet 
//
//OK transformer Appli en singletone. 
//makefile
//ouverture de fichier
//lecture ini
//coder une lecture ou un ping reseau - ex: google.com
//tester - exception
//multi threading

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
