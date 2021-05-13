#include "Admin.h"
#include "MySql.h"

using namespace std;

void Admin::adminRegistration()
{
	cout << "\n*************** Create Admin ****************\n" << endl;

	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	//validate password
	//not less than 8 characters
	while (password.length() < 8)

	{
		cout << "Password should not be less than 8 character long. " << endl;
		cout << "Please re-enter your password: ";
		cin >> password;
	}

	//ensure correctness
	cout << "Enter confirmPassword: ";
	cin >> confirmPassword;

	while (password != confirmPassword)

	{
		cout << "Password and password confirmation must match. " << endl;
		cout << "Please confirm your password: ";
		cin >> confirmPassword;
	}

	//save Admin data into the database

	MYSQL* connection = MySql::connectToDatabase();

	string query = "insert into Users(username, password) values('" + username + "', '" + password + "')";

	MySql::writeToDatabase(query, connection);

	cout << "Registration completed: " << endl;


}


void Admin::login()
{

	cout << "\n*************** LOG IN ****************\n" << endl;
	cout << "Please log in" << endl;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	string query = "select * from Users where username='" + username + "' and password = '" + password + "'";

	MYSQL* connection = MySql::connectToDatabase();

	bool found = MySql::exists(query, connection);

	if (found) {
		this->loggedIn = true;
	}
	else {
		this->loggedIn - false;
	}


}

