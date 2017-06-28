#ifndef APPLI_H_INCLUDED
#define APPLI_H_INCLUDED

#include <string>
#include <map>

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
        const string& getInivalue(const string& in_sKey);
    private:
        static Appli* m_Instance;
        ///constructor
        Appli();
        string m_sIniFile;
        map <string, string> m_mapIniValues;
};
#endif  //APPLI_H_INCLUDED
