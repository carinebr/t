#ifndef APPLI_H_INCLUDED
#define APPLI_H_INCLUDED

#include <string>
using namespace std;
/// \file appli.h
/// \brief application data handling header
class Appli
{
    public :
        static Appli* getInstance();
        ///destructor
        ~Appli(void);
        int readIniFile();
        const string& getIniFileName();
        void setIniFile(const string& in_sIniFile);
    private:
        static Appli* m_Instance;
        ///constructor
        Appli();
        string m_sIniFile;
};
#endif  //APPLI_H_INCLUDED
