#pragma once
#include <mysql.h>
#include <statement.h>
#include <driver.h>

using namespace std;

class MySql
{

	public:

		static MYSQL* connectToDatabase();

		static void fetchFromDatabase(string query, MYSQL* connection);

		static void list(string query, MYSQL* connection);

		static int writeToDatabase(string query, MYSQL* connection);

		static bool exists(string query, MYSQL* connection);
};

