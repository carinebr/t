/// \file tcpserver.cpp
/// \brief TcpServer class implementation

#include <iostream>
#include <string>
#include "appli.h"
#include "tcpserver.h"
#include "excepterr.h"
#include "logger.h"
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;


/// \fn TcpServer::TcpServer()
/// constructor
/// 
TcpServer::TcpServer(int in_nPort):m_nPort(in_nPort)
{
}

/// \fn TcpServer::~TcpServer(void)
/// destructor
TcpServer::~TcpServer(void)
{

}

/**
 * \fn TcpServer::listen()
 * \brief listen to the localhost port
 */
void TcpServer::startListening()
{
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        string sErr("socket() error");
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(m_nPort);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
                sizeof(serv_addr)) < 0) 
    {
        string sErr("bind() error");
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, 
            (struct sockaddr *) &cli_addr, 
            &clilen);
    if (newsockfd < 0) 
    {
        string sErr("accept() error");
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }
    bzero(buffer,256);
    n = read(newsockfd,buffer,255);
    if (n < 0)
    {
        string sErr("reding from socket");
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }
    printf("Here is the message: %s\n",buffer);
    n = write(newsockfd,"I got your message",18);
    if (n < 0)
    {
        string sErr("writting to socket error");
        throw ExceptErr(1, 0, sErr, __FILE__, __FUNCTION__, __LINE__);
    }
    close(newsockfd);
    close(sockfd);
}
