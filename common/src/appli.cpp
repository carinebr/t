#include <iostream>
#include "appli.h"

using namespace std;
Appli::Appli(void)
{
    //m_ptrAppli = NULL;
    cout << "appli class constructor" <<endl;
}

Appli::~Appli(void)
{
    m_Instance = NULL;
    cout << "appli class destructor" <<endl;
}
//instance - pour qu'Appli soit singletone
Appli* Appli::getInstance()
{
    if (m_Instance == NULL)
        m_Instance = new Appli;
    return m_Instance;
}

