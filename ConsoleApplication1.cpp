// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Ship {
	int volume;
	int sailors;
	string name;
public:
	Ship(string name = "", int volume = 0, int sailors = 0){
		this->name = name;
		this->volume = volume >= 0 ? volume : 0;
		this->sailors = sailors >= 0 ? sailors : 0;
	}
	virtual void show();
};
void Ship::show() {
	cout << "Class: \tShip" << endl;
	cout << "Name:\t" << name << endl;
	cout << "Volume:\t" << volume << endl;
	cout << "Sailors:\t" << sailors << endl;
}

class Steamship : public Ship {
	float power;
public:
	Steamship(string name = "", int volume = 0, int sailors = 0, float power = 0) : 
		Ship(name, volume, sailors){
		this->power = power >= 0 ? power : 0;
	}
	void show() {
		Ship::show();
		cout << "Power:\t" << power << endl;
		cout << "Type: \tSteamship" << endl;
	};
};

class Saleboat : public Ship {
	int mast;
public:
	Saleboat(string name = "", int volume = 0, int sailors = 0, int mast = 0) :
		Ship(name, volume, sailors){
		this->mast = mast >= 0 ? mast : 0;
	}
	void show() {
		Ship::show();
		cout << "Mast:\t" << mast << endl;
		cout << "Type: \tSaleboat" << endl;
	};
};

class Corvet : public Saleboat {
	int orud;
public:
	Corvet(string name = "", int volume = 0, int sailors = 0, int mast = 0, int orud = 0) :
		Saleboat(name, volume, sailors, mast){
		this->orud = orud >= 0 ? orud : 0;
	}
	void show() {
		Saleboat::show();
		cout << "Orud:\t" << orud << endl;
		cout << "Vid: \tCorvet" << endl;
	};
};

int main() {
	Ship alpha("St. Maria", 1000, 40);
	alpha.show();

	Steamship beta("Titanic", 2000, 200, 2000);
	beta.show();

	Saleboat gamma("Chernaya Zemchuzina", 1100, 30, 4);
	gamma.show();

	Corvet delta("Alisa", 300, 10, 3, 15);
	delta.show();

	Ship* ships[] {&alpha, &beta, &gamma, &delta};
	for (int i = 0; i < 4; i++) {
		cout << '\n';
		ships[i]->show();
	}
	system("pause");
	return 0;
}