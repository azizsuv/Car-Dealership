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
	string serv;
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
	
	string getname() {
		return name;
	}
	
	double getprice() {
		returnn price;
	}
	
	bool getempty() {
		return empty;
	}
	
	void addCarserve(string s, double c) {
		Carserve *newcar = new Carserve;
		newcar -> serv = s;
		newcar -> cost = c;
		newcar -> next = head;
		head = newcar;
	}
	
	void print() 
};
