#include <iostream>
#include <string>
#include "Customer.h"

#include "MySql.h"



using namespace std;

void Customer::customerRegistration()
{
	cout << "\n*************** Registration ****************\n" << endl;
	cout << "Enter firstName: ";
	cin >> firstName;
	cout << "Enter lastName: ";
	cin >> lastName;
	cout << "Enter email addres: ";
	cin >> emailAddress;
	cout << "Enter password: ";
	cin >> password;
	cout << "Enter confirmPassword: ";
	cin >> confirmPassword;

	//validate password
	//not less than 8 characters
	while (password.length() < 8)

	{
		cout << "Password should not be less than 8 character long. " << endl;
		cout << "Please re-enter your password: ";
		cin >> password;
	}
	
	//ensure correctness of password
	while (password != confirmPassword)
	{
		cout << "Password and password confirmation must match. " << endl;
		cout << "Please confirm your password: ";
		cin >> confirmPassword;
	}

	//save customer data into the database

	MYSQL* connection = MySql::connectToDatabase();

	string query ="insert into customers(first_name, last_name, email_address, password) values('"+firstName+"', '"+lastName+"', '"+ emailAddress+"', '"+password+"')";
	
	MySql::writeToDatabase(query, connection);

	cout << "Registration completed: " << endl;

	
}

//void Customer::getProfile()
//{
//	string firstName;
//	cout << "\n*************** Registration ****************\n" << endl;
//	cout << "Enter firstName: ";
//	cin >> firstName;
//	cout << "Enter lastName: ";
//	cin >> lastName;
//	cout << "Enter email: ";
//	cin >> emailAddress;
//	cout << "Enter password: ";
//	cin >> password;
//	cout << "Enter confirmPassword: ";
//	cin >> confirmPassword;
//	cout << "Registration completed: " << endl;
//
//
//	while (password.length() < 8)
//	{
//		cout << "Password should not be less than 8 character long. " << endl;
//		cout << "Please re-enter your password: ";
//		cin >> password;
//	}
//
//}
void Customer::login()
{
	
	cout << "\n*************** LOG IN ****************\n" << endl;
	cout << "Please log in" << endl;
	cout << "Enter email: ";
	cin >> emailAddress;
	cout << "Enter password: ";
	cin >> password;

	string query = "select * from customers where email_address='" + emailAddress + "' and password = '" + password + "'";

	MYSQL* connection = MySql::connectToDatabase();

	bool found = MySql::exists(query, connection);

	if (found) {
		this->loggedIn = true;
	}
	else {
		this->loggedIn - false;
	}


}


