#include <iostream>
#include "speechsamples.h"

using namespace std;
int main(int argc, char *argv[])
{
    const int WINDOWS_SIZE_MSEC = 10;
    double dMean, dStdDeviation;
    if (argc != 2)
    {
        cout << "should run \"vikisense <speech samples file name> \""
            << endl;
        return 0;
    }

    cout << "vikisense is running ! assuming 4KHz sampling rate"
        << std::endl;
    try
    {
        SpeechSamples speech(argv[1], 4000);
        speech.fetchSpeechInfo();
        cout << "$$1 -  " << argv[1] << " loaded" << endl; 
        speech.calculateMeanStdDev(200, &dMean, &dStdDeviation);
        cout << "$$2 -  For the first 200 ms, mean: " << dMean 
            << "  std deviation: " << dStdDeviation << endl;
        //mark in a new vector the sample as 0/1 depending upon 
        //|val-mean|/stddev<0.3
        vector<int> vecTask;
        speech.markSampleStdScore(200, dMean, dStdDeviation, vecTask);
        //display it
        cout << "$$3 -  After marking 0/1 depending upon |x-mean|/std "
            " (standard score vector):" << endl;
        vector<int>::iterator itr;
        for (itr = vecTask.begin(); itr != vecTask.end(); itr++)
            cout << *itr;
        cout <<endl;
        speech.convertWindowsToZeroOrOne(WINDOWS_SIZE_MSEC,
                4000, vecTask);
        cout << "$$4-5 - After converting 10 msec windows to 0 / 1" << endl;
        for (itr = vecTask.begin(); itr != vecTask.end(); itr++)
            cout << *itr;
        cout <<endl;
        
        //collect samples corresponding to 1
        speech.collectOriginalSamplesrCorespToOne(vecTask);
        cout <<"$$6 -  After collecting original corresponding to 1!" << endl;
        for (itr = vecTask.begin(); itr != vecTask.end(); itr++)
            cout << *itr << " ";
        cout <<endl;
    }
    catch (...)
    {
        cout << "error in the program. exiting .." << endl;
    }
    return 0;
}
