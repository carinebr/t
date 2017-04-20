/// \file appli.cpp
/// \brief  application level data handling
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "appli.h"
#include "excepterr.h"
using namespace std;

/// \fn Appli::Appli()
/// \brief constructor
Appli::Appli(void)
{
    //m_ptrAppli = NULL;
    //cout << "appli class constructor" <<endl;
}

/// \fn Appli::~Appli() 
/// \brief destructor
Appli::~Appli(void)
{
    m_Instance = NULL;
    //cout << "appli class destructor" <<endl;
}
/// \fn static Appli::getInstance()
/// \brief restricts the instantiation of the appli class to be singletone
Appli* Appli::getInstance()
{
    if (m_Instance == NULL)
        m_Instance = new Appli;
    //cout << "Appli::getInstance() invoqued" <<endl;
    return m_Instance;
}

/**
 * \fn Appli::readIniFile(const string& in_sIniFile)
 * \brief lit l'ini file et ecrit les donnees dans le map
 * \param[in] in_sIniFile      nom de l'ini file
 * \return 0 - ok else ko
 */
int Appli::readIniFile()
{
    // open ini file
    ifstream iniFile(m_sIniFile.c_str());
    if (!iniFile)
    {
        string sErr("open ");
        sErr.append(m_sIniFile).append(" failure");
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }
    string sLine;
    //todo put the name/values in a map
    while (getline(iniFile, sLine))
    {
        cout<< sLine <<endl;
    }

    //lecture des champs
    //fermeture 
    iniFile.close();
    return 0;
}
/**
 * \fn const string& Appli::getIniFileName()
 * \brief get fctn for m_sIniFile
 * \return m_sIniFile the ini file name
 */
const string& Appli::getIniFileName()
{
    return m_sIniFile;
}
/**
 * \fn Appli::setIniFile(const string& in_sIniFile)
 * \brief set fctn of m_sIniFile member
 * \param[in] in_sIniFile      nom de l'ini file
 */
void Appli::setIniFile(const string& in_sIniFile)
{
    m_sIniFile = in_sIniFile;
}

