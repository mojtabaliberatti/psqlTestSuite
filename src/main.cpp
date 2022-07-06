#include <iostream>


#include "general.h"

#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <string.h>

PGconn *conn; 
void do_exit(PGconn *conn)
{
	PQfinish(conn);
	exit(1);
}

void do_select(const char *paramValues[1])
{
    const char *stm = "SELECT * FROM emp WHERE Id=$1";
	PGresult *res = PQexecParams(conn, stm, 1, NULL, paramValues, NULL, NULL, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		printf("No data retrieved 1\n");
		PQclear(res);
		return ; 
	}

	printf("do_select 1 %s %s %s\n", PQgetvalue(res, 0, 0), PQgetvalue(res, 0, 1), PQgetvalue(res, 0, 2));

	PQclear(res);

}

void do_select_all(void)
{
    const char *stm = "SELECT * FROM emp";
	PGresult *res = PQexecParams(conn, stm, 0, NULL, NULL, NULL, NULL, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		printf("No data retrieved all \n");
		PQclear(res);
		return ;
	}

	printf(" do_select_all %s %s %s\n", PQgetvalue(res, 0, 0), PQgetvalue(res, 0, 1), PQgetvalue(res, 0, 2));

	PQclear(res);

}
int main(void)
{
    const int LEN = 10;
	const char *paramValues[1];
	conn = PQconnectdb("host=localhost port=6432 user=mojtaba password=123456@Mk dbname=XE");

	if (PQstatus(conn) == CONNECTION_BAD) {
		fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
		do_exit(conn);
	}

	int ver = PQserverVersion(conn);

	printf("Server version: %d\n", ver);
    
	char str[LEN];

	snprintf(str, LEN, "%d", 1);
	paramValues[0] = str;    

    do_select(paramValues);
	// for(int i=0; i<1;  i++)
	// 	do_select_all();

	
	PQfinish(conn);

	return 0;
}