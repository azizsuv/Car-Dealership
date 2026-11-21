#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Car {
	private:
	int id;
	double price;
	string name;
	bool empty;
	
	struct Carserve {
	string type;
	double cost;
	Carserve *next;
	} *head;
	
	public:
	car() {
		id = 0;
		price = 
		name = "";
		empty = true;
		head = NULL;
	}
	
	void setcar(int i, string n, double p) {
		id = i;
		name = n;
		price = p;
		empty = false;
	}
	
	void setprice(double p) {
		price = p;
	}
	
	void setempy(bool s) {
		empty = s;
	}
	
	int getid() {
		return id;
	}
};
