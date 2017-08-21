/// \file roundforest.cpp
/// \brief RoundForest class implementation

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <pthread.h>
#include "appli.h"
#include "roundforest.h"
#include "excepterr.h"
#include "logger.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

using namespace std;

static void* threadDataSetsHandle(void* in_RoundForestThreadInfo);
//constructor
RoundForest::RoundForest(const string& in_sFilename, int in_nMachineNumber,
        bool in_bMainMachine): m_sFileName(in_sFilename), m_nMachineNumber(in_nMachineNumber), 
    m_bMainMachine(in_bMainMachine)
{
}
const int MAX_MACHINE_NUMBER = 100;
class RoundForestThreadInfo
{
    public:
        RoundForestThreadInfo(): m_CoutMutex(PTHREAD_MUTEX_INITIALIZER)
                { m_TheLogger = Logger::getInstance();}
        ~RoundForestThreadInfo(){};
        void logIt(LoggerLevelEnum in_nLevel, const string& in_sFile, const string& in_sFunction, 
                int in_nLine, const string& in_sPhrase);
        void setDataSetName(const string& in_sDataSetname){m_sDataSetName = in_sDataSetname;} 
        const string& getDataSetName(){return m_sDataSetName;}
        void setTid(int in_nTid){m_nTid = in_nTid;};
        int getTid(){return m_nTid;}
    private:
        string m_sDataSetName;
        pthread_mutex_t m_CoutMutex;
        Logger* m_TheLogger;
        int m_nTid;
};       

/**
 * \fn  RoundForestThreadInfo::logIt
 * \brief enveloppe logIt du logger pour gerer le mutex
 * \param[in] (LoggerLevelEnum in_nLevel, const string& in_sFile, const string& in_sFunction,
 *             int in_nLine, const string& in_sPhrase
 */
void RoundForestThreadInfo::logIt(LoggerLevelEnum in_nLevel, const string& in_sFile, const string& in_sFunction,
        int in_nLine, const string& in_sPhrase)
{
    pthread_mutex_lock(&m_CoutMutex);
    m_TheLogger->logIt(in_nLevel, in_sFile, in_sFunction, in_nLine, in_sPhrase);
    pthread_mutex_unlock(&m_CoutMutex);
}

/**
 * \fn RoundForest::doIt()
 * \brief We are interested in:
 * 1) Finding 1000 most active users (profile names)
 * 2) Finding 1000 most commented food items (item ids).
 * 3) Finding 1000 most used words in the reviews
 * Any errors will be reported by the HTTP codes.
 * - We are interested in clean testable code (add tests if you have time).
 *   - How do you make sure that there are no duplicates in the file?
 *   - We are interested in using full multi core CPU power.
 *   - We will be running this on machine with 500MB of RAM. How do you make sure that we
 *   are not using more than that? How are you going to monitor the memory usage of your
 *   program?
 *   - Our goal is to support the files with up to 100M reviews on multiple machines with
 *   500MB of RAM and 4 core CPUs. How are you going to make it happen?
 *   Please provide working code (command to compile and run the program) that prints output of
 *   point: 1,2,3 to standard output sorted alphabetically. 
 */
void RoundForest::doIt()
{
    string sPrefix;
    pthread_t tid[MAX_MACHINE_NUMBER];
    std::string* pStrRet = NULL;

    RoundForestThreadInfo* prfThreadInfo[MAX_MACHINE_NUMBER];
    cout<<"roundforest is running" << endl;
    for (int i = 0; i < MAX_MACHINE_NUMBER; i++)
        prfThreadInfo[i] = NULL;
    char szNum[2 + 1];
    //split the file to the relevent part depending i
    //on the machine number and the index
    createDataSets();
    //loop on the x<nn> data set files in the directory
    int nThrdNum(0);;
    for (int i = 0; i < MAX_MACHINE_NUMBER; i++)
    {
        sprintf(szNum, "%02d", i);
        sPrefix = "x";
        sPrefix += szNum;
        if (access(sPrefix.c_str(), F_OK ) == -1)
            continue;
        nThrdNum++;
        cout << sPrefix <<endl;
        prfThreadInfo[i] = new RoundForestThreadInfo;
        //invoke thread prend un fichier dataset - traite - met en base
        prfThreadInfo[i]->setDataSetName(sPrefix);
        prfThreadInfo[i]->setTid(i);
        pthread_create (&tid[i], NULL, threadDataSetsHandle, (void*) prfThreadInfo[i]);
    }
    for(int j=0; j< nThrdNum; j++)
    {
        string s("thread ");
        s += to_string(tid[j]);
        s += " finished";
        pthread_join(tid[j], (void**)&pStrRet);
        Logger::getInstance()->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, s); 
    }
    if (pStrRet != NULL)
        delete(pStrRet);
    for (int i = 0; i < MAX_MACHINE_NUMBER; i++)
        delete prfThreadInfo[i];

    //wait until no more y<nn> files
    //get the staitstics from db


    return;
}

/**
 * rename a dataset file to from x<xx> to y<xx>
 * insert it to db (memory managing here)
 * remove the y<nn> file
 */
void* threadDataSetsHandle(void* in_pRoundForestThreadInfo)
{
    std::string* psErr = new(std::string);
    RoundForestThreadInfo* pThreadInfo = static_cast<RoundForestThreadInfo*> (in_pRoundForestThreadInfo);
    string sLog("thread index: ");
    sLog+=std::to_string(pThreadInfo->getTid()) + " dataset name: " + pThreadInfo->getDataSetName();
    pThreadInfo->logIt(DBG, __FILE__, __FUNCTION__, __LINE__, sLog);

    pthread_exit((void*)psErr);//thread will stop anyway. But mandatory for using psErr in the calling func
    return NULL;
} 

/**
 * \fn RoundForest::createDataSets()
 * \brief create the data set files from the amazon file
 *        if the m_bMainmachie = true
 */
void RoundForest::createDataSets()
{
    if (!m_bMainMachine)
        return;
    cout<<"roundforest datasets creation" << endl;
    int nNumLines = textFileLinesNumber(m_sFileName);
    std::cout << "Number of lines in text file: " << nNumLines
            << "num of machines: " << m_nMachineNumber << endl;
    //number of line of each file is nNumLines / machine number
    int nNumLinesEachDateSet = nNumLines / m_nMachineNumber;
    std::cout << "Number of lines in datasets: " << nNumLinesEachDateSet << endl;

    string sCommand("split --numeric-suffixes --lines=" +
            std::to_string(nNumLinesEachDateSet) + " " + m_sFileName);
    //cout << sCommand << endl;
//  system(sCommand.c_str());
}
