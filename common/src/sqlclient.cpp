/// \file sqlclient.cpp
/// \brief functionnality testing implementation

#include "sqlclient.h"


/// \fn SqlClient::SqlClient(void)
/// constructor
/// 
SqlClient::SqlClient()
{
}

/// \fn SqlClient::~SqlClient(void)
/// destructor
SqlClient::~SqlClient(void)
{
}

/**
 * \fn SqlClient::SqlClient(const SqlClient& in_anotherSqlClient)
 * \brief copy construtor
 */
SqlClient::SqlClient(const SqlClient& in_anotherSqlClient)
{
}

/**
 * \fn connect
 * \brief connect to the db
 */
void SqlClient::connect()
{
    mysql_init(&conn);
    mysql_options(&conn,MYSQL_READ_DEFAULT_GROUP,"t1");
    if (!mysql_real_connect(&conn,"localhost","developer","developer","dbdev",0,NULL,0))
    {
        fprintf(stderr, "Failed to connect to database: Error: %s\n",
                mysql_error(&conn));
    }
}

