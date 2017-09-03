#ifndef SQLCLIENT_H_INCLUDED
#define SQLCLIENT_H_INCLUDED

#include <string>
#include <mysql/mysql.h>

using namespace std;


/// \file logger.h
/// \brief log handler header
class SqlClient
{
    public :
        ///constructor
        SqlClient();
        ///destructor
        ~SqlClient();
        ///copy constructor
        SqlClient(const SqlClient& in_anotherSqlClient);
        void connect();
    private:
        MYSQL conn;
        MYSQL_RES *res;
        MYSQL_ROW row;
        string m_sSqlClient;
};
#endif  //SQLCLIENT_H_INCLUDED
