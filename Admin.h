#pragma once

#include <iostream>
#include <string>
#include "User.h"
using namespace std;

class Admin : public User
{
public:

	string username;
	string confirmPassword;

	bool loggedIn =false;

	void login();
	void adminRegistration();
	/*void logout();
	void listAdmins();
	void addCustomer();


	Admin getAdmin(string username);*/

};
