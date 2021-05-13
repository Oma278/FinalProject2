#pragma once
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Resource
{
public:
	string name;
	int totalQuantity = 0;
	int availableQuantity = 0;

	void searchResource();
	void addResource();
	void listResources();

};
