/// \file b.cpp
/// \brief SpeechSamples class implementation
#include "speechsamples.h"

#include <iostream>
#include <string>
#include <fstream>
#include <numeric>
#include <cmath>
#include "appli.h"
#include "logger.h"

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
    for (itr = v.begin(); itr != v.end(); itr++)
    {
    //    cout << *itr << endl;
    }
    cout << samplesNumbers(200) <<endl;
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
 * \return the i element of the vector member
 */
unsigned char SpeechSamples::operator[](int i)const
{
    return v[i];
}
