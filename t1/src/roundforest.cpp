/// \file roundforest.cpp
/// \brief RoundForest class implementation

#include <iostream>
#include <string>
#include "appli.h"
#include "roundforest.h"
#include "excepterr.h"
#include "logger.h"
#include "utils.h"
#include <stdlib.h>
using namespace std;

//constructor
RoundForest::RoundForest(const string& in_sFilename, int in_nMachineNumber,
        bool in_bMainMachine): m_sFileName(in_sFilename), m_nMachineNumber(in_nMachineNumber), 
    m_bMainMachine(in_bMainMachine)
{
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
    cout<<"roundforest is running" << endl;
    //split the file to the relevent part depending i
    //on the machine number and the index
    createDataSets();

    return;
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
    cout << sCommand << endl;
    system(sCommand.c_str());
}
