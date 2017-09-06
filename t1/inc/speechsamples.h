#ifndef SPEECHSAMPLES_H_INCLUDED
#define SPEECHSAMPLES_H_INCLUDED
/// \file speechsamples.h
/// \brief SpeechSamples class header
#include <string>
#include <vector>
using namespace std;
typedef struct SpeechFormat
{
    char cAmplitude;
}SpeechFormatType;

class SpeechSamples
{
    public :
        //constructor
        SpeechSamples(const string& in_sSpeechFile,
                int in_nSamplingRate);
        //destructor
        ~SpeechSamples();
        //fetch the file info
        void fetchSpeechInfo();
        void calculateMeanStdDev(int in_nPeriodMsec,
                double* out_pdMean, double* out_pdStdDeviation)const;
        int samplesNumbers(int in_TimeInSec)const;
        unsigned char operator[](int i) const;

    private:
        unsigned char readBuffer2Amplitude(char* in_buff);

        string m_sSpeechFile;
        int m_nSamplingRate;
        vector<unsigned char> v;
};
#endif  //SPEECHSAMPLES_H_INCLUDED
