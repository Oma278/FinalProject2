#pragma once
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "User.h"
using namespace std;

class Customer: public User
{
public:

	//void getProfile();

	void customerRegistration();
	//void listCustomers();


	string emailAddress;
	string firstName;
	string lastName;

	string confirmPassword;

	void login();
	bool loggedIn = false;



};


