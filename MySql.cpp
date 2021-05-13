#include "MySql.h"

MYSQL* MySql::connectToDatabase() {

	MYSQL* conn;

	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "root", "finalproject", 3306, NULL, 0);

	if (conn) {
		puts("Successful connection to database!");
		return conn;
	}
	else {
		puts("Database connection failed");
		return 0;
	}
}

void MySql::fetchFromDatabase(string query, MYSQL* connection) {
	MYSQL_RES* response;
	MYSQL_ROW row;

	const char* q = query.c_str();
	int queryState = mysql_query(connection, q);
	if (!queryState)
	{
		response = mysql_store_result(connection);
		int i = 0;
		while (row = mysql_fetch_row(response))
		{
			printf("ID: %s, Name: %s, Value: %s\n", row[0], row[1], row[2]);
		}

	}
	else {
		cout << "Query failed: " << mysql_error(connection) << endl;

	}
}


int MySql::writeToDatabase(string query, MYSQL* connection) {
	const char* q = query.c_str();

	int queryState = mysql_query(connection, q);

	if (!queryState) {
		return 1;
	}

	return 0;
}

bool MySql::exists(string query, MYSQL* connection) {
	MYSQL_RES* response;
	MYSQL_ROW row;

	const char* q = query.c_str();
	int queryState = mysql_query(connection, q);
	if (!queryState)
	{
		response = mysql_store_result(connection);

		int i = 0;

		row = mysql_fetch_row(response);

		if (!row) {
			cout << "not found";

			return false;
		}
		puts("found");

		return true;

	}
}

	void MySql::list(string query, MYSQL * connection) {
		MYSQL_RES* response;
		MYSQL_ROW row;

		const char* q = query.c_str();
		int queryState = mysql_query(connection, q);
		if (!queryState)
		{
			response = mysql_store_result(connection);
			int i = 0;
			while (row = mysql_fetch_row(response))
			{
				cout << row[0] << " " << row[1] << endl;

			}

		}
		else {
			cout << "Query failed: " << mysql_error(connection) << endl;

		}
	}

