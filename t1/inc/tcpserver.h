#ifndef TCPSERVER_H_INCLUDED
#define TCPSERVER_H_INCLUDED
/// \file tcpserver.h
/// \brief tcpserver class header
#include <string>
using namespace std;

class TcpServer
{
    public :
        //constructor
        TcpServer(int in_Port);
        //destructor
        virtual ~TcpServer(void);
        //get/set port
        int getPort() {return m_nPort;}
        void setPort(int in_nPort){m_nPort = in_nPort;}
        void startListening();

    private:
        int m_nPort;
};
#endif  //TCPSERVER_H_INCLUDED
