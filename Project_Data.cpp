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
	Car() {
		id = 0;
		price = 0;
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
	
	void setempty(bool s) {
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
		return price;
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
	
	void printserve() {
		Carserve *temp = head;
		while(temp != NULL) {
			cout << "Service : " << temp -> serv <<
			" , Cost : " << temp -> cost << "$" << endl;
			temp = temp -> next;
		}
	}
};
	
class Dealer {
	private:
	Car cars[15];
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
		ifstream in(file.c_str());
		if(!in) return;
		int id;
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
				out << cars[i].getid() 
				<< " " << cars[i].getname() 
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
		double p, c;
		string n, s;
		cout << "Enter the car ID for edit : ";
		cin >> i;
		int d = getHASH(i);
		if(cars[d].getempty() || cars[d].getid() != i) {
			cout << "Sorry car not found ..." << endl;
			return;
		}
		cout << "Enter new name - or 'No' for No new name : ";
		cin >> n;
		if(n != "No") {
			cars[d].setname(n);
		} else {
			cout << "No modify on Name ..." << endl;
		}
		
		cout << "Enter new price : ";
		cin >> p;
		cars[d].setprice(p);
		cout << "Add a service,";
		cout << " or enter 'No' for no service : ";
		cin >> s;
		if(s != "No") {
			cout << "Enter cost of service : ";
			cin >> c;
			
			cars[d].addcarserve(s, c);
		} else {
			cout << "No services added ..." << endl;
		}
	}
	
	void Delete() {
		int i;
		cout << "Enter car ID : ";
		cin >> i;
		int d = getHASH(i);
		if(cars[d].getempty() || cars[d].getid() != i) {
			cout << "Sorry car not found ..." << endl;
			return;
		}
		cars[d].setempty(true);
		cout << "The car has been deleted ..." << endl;
	}
	
	void search() {
		int i;
		cout << "Enter ID for searching : ";
		cin >> i;
		int d = getHASH(i);
		if (cars[d].getempty() || cars[d].getid() != i) {
            cout << "Car not found ..." << endl;;
            return;
        }

        cout << " - car found -" << endl;
        cout << "ID : " << cars[d].getid() << endl;
        cout << "Name : " << cars[d].getname() << endl;   
        cout << "Price : $" << cars[d].getprice() << endl; 
        
        cout << "car services : " << endl;; 
        cars[d].printserve();
	}
	
	void print() {
		cout << " - all cars - " << endl;
		cout << left << setw(10) << "ID" << setw(20) <<
		"Name" << setw(10) << "price" << endl;
		for (int i = 0; i < 15; i++) {
            if (!cars[i].getempty()) {
                cout << left << setw(10) << cars[i].getid() 
                     << setw(20) << cars[i].getname()      
                     << "$" << cars[i].getprice() << endl; 
            }
        }
	}
};

int main() {
	Dealer az;
	int choice;
	
	do {
		cout << endl;
		cout << " - Cars System - " << endl;
		cout << " Main Menu" << endl;
		cout << " 1. Add car" << endl;
		cout << " 2. Edit car" << endl;
		cout << " 3. Delete car" << endl;
		cout << " 4. Print cars" << endl;
		cout << " 5. Search car" << endl;
		cout << " 6. Exit" << endl;
		cout << " Enter your choice : ";
		cin >> choice;
		
		switch(choice) {
			case 1:
			az.add();
			break;
			
			case 2:
			az.edit();
			break;
			
			case 3:
			az.Delete();
			break;
			
			case 4:
			az.print();
			break;
			
			case 5:
			az.search();
			break;
			
			case 6:
			cout << "Exiting ..." << endl;
			break;
			
			default:
			cout << "Invalid input, try again ..." << endl;
			break;
			
		} 
	} while(choice != 6);
	
	return 0;
}

