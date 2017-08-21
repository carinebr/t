#ifndef ROUNDFOREST_H_INCLUDED
#define ROUNDFOREST_H_INCLUDED
/// \file roundforest.h
/// \brief roundforest class header
#include <string>
using namespace std;

class RoundForest
{
    public :
        //constructor
        RoundForest(const string& in_sFilename, int in_nMachineNumber,
                bool in_nMainMachine);

        //destructor
        virtual ~RoundForest(void){};

        const string& getFileName() const{return m_sFileName;}
        void setFileName(const string& in_sFileName){m_sFileName = in_sFileName;}

        int getMachineNumber() const{return m_nMachineNumber;}
        void setMachineNumber(int in_nMachineNumber){m_nMachineNumber =  in_nMachineNumber;}

       void doIt();
       void createDataSets();
    private:
        string m_sFileName;
        int m_nMachineNumber;
        int m_nMachineIndex;
        bool m_bMainMachine;
};
#endif  //ROUNDFOREST_H_INCLUDED
