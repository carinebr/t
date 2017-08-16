#ifndef TCPCLIENT_H_INCLUDED
#define TCPCLIENT_H_INCLUDED
/// \file tcpclient.h
/// \brief tcpclient class header
#include <string>
using namespace std;

class TcpClient
{
    public :
        //constructor
        TcpClient(const string& in_sServerAddress, int in_nPort):
            m_sServerAddress(in_sServerAddress), m_nPort(in_nPort){}
        //destructor
        virtual ~TcpClient(void){};
        //get/set port
        int getPort() {return m_nPort;}
        void setPort(int in_nPort){m_nPort = in_nPort;}
        const string& getServerAddress() {return m_sServerAddress;}
        void setServerAddress(const string& in_sServerAddress) {m_sServerAddress = in_sServerAddress;}
        void uxClient();

    private:
        string m_sServerAddress;
        int m_nPort;
        void sendToServer(const string& in_sPhrase);
};
#endif  //TCPCLIENT_H_INCLUDED
