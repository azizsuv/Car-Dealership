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
	
	void setname(string n) {
		name = n;
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
	
	void addcarserve(string s, double c) {
		Carserve *newcar = new Carserve;
		newcar -> serv = s;
		newcar -> cost = c;
		newcar -> next = head;
		head = newcar;
	}
	
	void print() {
		Carserve *temp = head;
		while(temp != NULL) {
			cout << "Service : " << temp -> serve <<
			" , Cost : " << temp -> cost << "$" << endl;
			temp = temp -> next;
		}
	}
};
	
class Dealer {
	private:
	car car[15];
	string file;
	
	public:
	Dealer() {
		file = "Cars.txt";
		load();
	}
		
	~Dealer() {
		save();
	}
	
	int getHASH(int id) {
		return id % 15;
	}
	
	void load() {
		ifstream in(file.c_str())
		if(!in) return;
		in id;
		double price;
		string n;
		while(in >> id >> n >> price) {
			int d = getHASH(id);
			cars[d].setcar(id , n, price);
		}
		in.close();
	}
	
	void save() {
		ofstream out(file.c_str());
		for(int i = 0; i < 15; i++) {
			if(!cars[i].getempty()) {
				cout << cars[i].getid() 
				<< " " cars[i].getname() 
				<< " " << cars[i].getprice() 
				<< endl;
			}
		}
		out.close();
	}
	
	void add() {
		int i;
		double p;
		string n;
		cout << "Enter car ID : ";
		cin >> i;
		cout << "Enter car Name : ";
		cin >> n;
		cout << "Enter car price : ";
		cin >> p;
		int d = getHASH(i);
		if(cars[d].getempty() == false) {
			cout << "sorry this spot its taken by another CAR ..." 
			<< endl;
			return;
		}
		cars[d].setcar(i, n, p);
		cout << "car added successfully ..." << endl;
	}
	
	void edit() {
		int i;
		double p;
		string n;
		cout << "Enter the car ID for edit : ";
		cin >> i;
		int d = getHASH(i);
		if(cars[i].getempty() || cars[i].getid != i) {
			cout << "Sorry car not found ..." << endl;
			return;
		}
		cout << "Enter new name - or 'No' for No new name : ";
		cin >> n;
		if(n != "No") {
			cars.[i].setname(n);
		} else {
			cout << "No modify on Name ..." << endl;
		}
		
		cout << "Enter new price : ";
		cin >> p;
		cars[i]setprice(p);
		
	}
	
};

