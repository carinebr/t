/// \file tcpclient.cpp
/// \brief TcpClient class implementation

#include <iostream>
#include <string>
#include "appli.h"
#include "tcpclient.h"
#include "excepterr.h"
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <cstring>

using namespace std;

/**
 * \fn uxClient
 * \brief main client interface - loop
 */
void TcpClient::uxClient()
{
    string sPhrase;
    try
    {
        while (1)
        {
            cout << "entrer une phrase a envoyer a " 
                << getServerAddress() << " port : " << getPort() << endl;
            getline (cin, sPhrase);
            if (sPhrase == "f")
                break;
            sendToServer(sPhrase);
        }
    }
    catch(ExceptErr& e)
    {
        e.addStackInfo(__FILE__, __FUNCTION__, __LINE__);
        throw;//handled in the invoker funct
    }
    catch(const exception& e)
    {
        throw;//handled in the invoker funct
    }
}
/**
 * \fn TcpClient::sendToServer()
 * \brief send a phrase to the server
 * 1) Create a socket with the socket() system call
 * 2) Connect the socket to the address of the server
 *      using the connect() system call
 * 3) Send and receive data. There are a number of ways to do this,
 *      but the simplest is to use the read() and write() system calls.
 */
void TcpClient::sendToServer(const string &in_sPhrase)
{
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent * server;
    int n;
    char buffer[255 + 1];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        string sErr("socket() error");
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }
    server = gethostbyname(getServerAddress().c_str());
    if (server == NULL)
    {
        string sErr("no such host " + getServerAddress());
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)server->h_addr, 
            (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(m_nPort);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
    {
        string sErr("error connecting");
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }
    n = write(sockfd, in_sPhrase.c_str(), in_sPhrase.size());
    if (n<0)
    {
        string sErr("error writing to socket");
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd,buffer,255);
    if (n < 0)
    {
        string sErr("error reading from server");
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }

    close(sockfd);
}
