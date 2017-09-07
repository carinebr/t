/// \file b.cpp
/// \brief SpeechSamples class implementation
#include "speechsamples.h"

#include <iostream>
#include <string>
#include <fstream>
#include <numeric>
#include <cmath>

using namespace std;


using namespace std;

/// \fn SpeechSamples::SpeechSamples(void)
/// constructor
/// 
SpeechSamples::SpeechSamples(const string & in_sSpeechFile,
        int in_nSamplingRate):
    m_sSpeechFile(in_sSpeechFile), m_nSamplingRate(in_nSamplingRate)
{
}

//destructor
SpeechSamples::~SpeechSamples()
{
}

/**
 * \fn fetchSpeechInfo
 * \brief fetch the info contained in the speech file into a vector
 */
void SpeechSamples::fetchSpeechInfo()
{
    size_t nSampleSize(sizeof(SpeechFormatType));
    char* buff = new char [nSampleSize];
    ifstream speechFile;
    unsigned char ucAmplitude;
    
    try
    {
        //open the file
        speechFile.open(m_sSpeechFile.c_str(), ios::in | ios::binary);
        if (!speechFile)
        {
            throw string(m_sSpeechFile + " not open");
        }
        while (speechFile.read(buff, (int)nSampleSize))
        {
            ucAmplitude = readBuffer2Amplitude(buff);
            v.push_back(ucAmplitude);
        }
    }
    catch (const exception& e)
    {
        speechFile.close();
        delete []buff;
        throw;
    }
    vector<unsigned char>::iterator itr;
    for (itr = v.begin(); itr != v.begin()+800; itr++)
    {
        cout << +(*itr) << " ";
    }
    //cout << samplesNumbers(200) <<endl;
    speechFile.close();
    delete []buff;
}

/**
 * \fn int readBuffer2Amplitude(char* in_buff);
 * \brief transform a buffer to an speech amplitude
 * \param [in] in_buff
 */
unsigned char SpeechSamples::readBuffer2Amplitude(char* in_Buff)
{
    return static_cast<unsigned char>(in_Buff[0]);
}

/**
 * \fn samplesNumbers
 * \brief calculate the number of samples for a period of
 * the speech
 * \param[in] period in msec
 */
int SpeechSamples::samplesNumbers(int in_PeriodMSec)const
{
    return  (in_PeriodMSec * m_nSamplingRate)/1000;
}

/**
 * \fn calculateMean(int in_nSamplesNbr)
 */
void SpeechSamples::calculateMeanStdDev(int in_nPeriodNbr,
        double* out_pdMean, double* out_pdStdDeviation)const
{
    int nSamplesNbr(samplesNumbers(in_nPeriodNbr));
    //mean
    double sum = std::accumulate(v.begin(), v.begin() + nSamplesNbr, 0.0);
    *out_pdMean = sum / nSamplesNbr;
    //standard deviation
    double sq_sum = std::inner_product(v.begin(), v.begin() + nSamplesNbr,
            v.begin(), 0.0);
    *out_pdStdDeviation = std::sqrt(sq_sum /nSamplesNbr - (*out_pdMean) * (*out_pdMean));
    return;
}

/**
 * \fn operator[]
 * \brief enable using [] with the SpeechSamples class. Return the i element 
 * of the member vector
 */
unsigned char SpeechSamples::operator[](int i)const
{
    if (static_cast<size_t>(i) < v.size())
        return v[i];
    return 0;
}

/**
 * \fn markSampleStdScore
 * \brief set the vec sample value as 0/1 depending of |(x-mean)|/stddev
 */
 void SpeechSamples::markSampleStdScore(int in_nTimeInSec, 
         double in_dMean, double in_dStdDeviation, 
         vector<int>& out_v) const
{
    int nSamplesNbr = samplesNumbers(in_nTimeInSec);
    for (int i = 0; i < nSamplesNbr; i++)
    {
        if (in_dStdDeviation == 0)//div by 0!!!
        {
            out_v.push_back(0);
            continue;
        }
        if ((abs(v[i]-in_dMean)/in_dStdDeviation) < 0.3)
            out_v.push_back(0);
        else
            out_v.push_back(1);
    }
    return;
}

/**
 * \fn convert10MsWindowsToZeroOrOne
 * \brief divide the signal vector in 10ms sample and convert all the
 * the 10 msec windows samples to 0 or 1, depending upon the most 
 * occurences of 0 or 1
 */
void SpeechSamples::convertWindowsToZeroOrOne(int in_nPeriodWindowsMSec,
                int in_nSamplingRate, vector<int>& out_v) const
{
    int nWindowsNbr;
    int i, nZeroCounter(0), nOneCounter(0), nIndexInWin(0);
    int nWinSizeSamples =
        static_cast<double>(static_cast<double>(in_nPeriodWindowsMSec)/
                static_cast<double>(1000)) * in_nSamplingRate;
    cout << "nWinSizeSamples: " << nWinSizeSamples << endl;
    nWindowsNbr = out_v.size() / nWinSizeSamples;
    if (out_v.size()%nWinSizeSamples != 0)
        ++nWindowsNbr; 

    vector<int>::iterator itr;
    for (itr = out_v.begin(); itr != out_v.end(); itr++)
    {
        if (*itr == 0)
            ++nZeroCounter;
        else
            ++nOneCounter;
        if (nIndexInWin == nWinSizeSamples - 1)//end of the windows
        {
            for (i = 0; i < nWinSizeSamples; i++)
            {
                *(itr-i) = nZeroCounter> nOneCounter? 0: 1;
            }
            nIndexInWin = -1;
            nZeroCounter = nOneCounter = 0;
        }
        ++nIndexInWin;
    }
    return;
}
