#include <iostream>
#include <string>
#include "Resource.h"
#include "MySql.h"

using namespace std;

void Resource::searchResource()
{
	cout << "How many do you need?:" << endl;
	cout << "When do you need them?:" << endl;
	cout << "For how long?:" << endl;
}

void Resource::listResources() {
	
	MYSQL* connection = MySql::connectToDatabase();
	string query = "select id, name from resources";
		MySql::list(query, connection);
}

void Resource::addResource() {
	cout << "\n*************** Add Resource ****************\n" << endl;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter total quantity: ";
	cin >> totalQuantity;
	cout << "Enter available quantity: ";
	cin >> availableQuantity;
	

	//save customer data into the database

	MYSQL* connection = MySql::connectToDatabase();

	string query = "insert into resources(name, total_quantity, available_quantity) values('" + name + "',  " + to_string(totalQuantity)+", " + to_string(availableQuantity)+")";

	MySql::writeToDatabase(query, connection);
}