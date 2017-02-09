/// \file appli.cpp
/// \brief  application level data handling
#include <iostream>
#include "appli.h"

using namespace std;

/// \fn Appli::Appli()
/// \brief constructor
Appli::Appli(void)
{
    //m_ptrAppli = NULL;
    cout << "appli class constructor" <<endl;
}

/// \fn Appli::~Appli() 
/// \brief destructor
Appli::~Appli(void)
{
    m_Instance = NULL;
    cout << "appli class destructor" <<endl;
}
/// \fn static Appli::getInstance()
/// \brief restricts the instantiation of the appli class to be singletone
Appli* Appli::getInstance()
{
    if (m_Instance == NULL)
        m_Instance = new Appli;
    cout << "Appli::getInstance() invoqued" <<endl;
    return m_Instance;
}

/// \fn static void Appli::someFunction()
/// \brief does something
void Appli::someFunction()
{
    cout << "Appli::someFunction() invoqued" <<endl;
}

