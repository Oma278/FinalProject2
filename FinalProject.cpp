// MysqlTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Customer.h"
#include "Resource.h"
#include "admin.h"

using namespace std;

int main()
{

	char choice;

	Customer customer;
	Resource resource;
	Admin admin;
	


	while (customer.loggedIn == false  &&  admin.loggedIn == false) {
		cout << "\n\n Welcome to the Resource Reservation and Booking Site\n" << endl;
		cout << "Please register/log in" << endl;
		cout << "1. Register" << endl;
		cout << "2. Login" << endl;
		cout << "3. Admin Login" << endl;
		cout << "Enter your choice :" << endl;
		cin.get(choice);

		if (choice == '1')
		{
			cout << "Please Register your details: " << endl;
			customer.customerRegistration();

		}
		if (choice == '2')
		{
			cout << "Please Log in: " << endl;
			
			customer.login();
		}
		if (choice == '3')
		{
			cout << "Please Log in: " << endl;
			admin.login();

		}
			
			
		//std::cin.clear();


		while (!(choice == '1' || choice == '2' || choice == '3'))
		{
		    cin.clear();
			cout << "Please select a valid choice number: ";
			cin.get(choice);
		}

	}


	if (customer.loggedIn) {

		cout << "\n Book for resources\n" << endl;

		resource.listResources();
		cout << "1. Laptops: " << endl;
		cout << "2.Chairs and Tables: " << endl;
		cout << "Please select your choice: " << endl;
		cin.get(choice);



		resource.searchResource();

		while (choice != '1' && choice != '2')
		{
			cin.clear();
			cout << "Please select a valid choice number: ";
			cin.get(choice);
		}
	}

	 if (admin.loggedIn) {
		cout << "======= Resources =======" << endl;
		cout << "1. Add new resource" << endl;
		cout << "2. List resources" << endl << endl;

		cout << "======= Customers =======" << endl;
		cout << "3. Add new customer" << endl;
		cout << "4. List customers" << endl << endl;

		cout << "======= Admins =======" << endl;
		cout << "5. Add new admin" << endl;
		cout << "6. List admins" << endl << endl;

		cout << "======= Bookings =======" << endl;
		cout << "7. Add new booking" << endl;
		cout << "8. List bookings" << endl << endl;

		cout << "9. Logout" << endl;
		cin.get(choice);

		//if (choice == '1') {
			;
		//}
			switch (choice) {
			case '1':
				resource.addResource();
				break;

			default: resource.addResource();
				break;
			}

		while (choice != '1' && choice != '2')
		{
			cin.clear();
			cout << "Please select a valid choice number: ";
			cin.get(choice);
		}
	 }


}

