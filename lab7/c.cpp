#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>
using namespace std;

struct User {
	string username, password, role;
	int ID;
	User *next;
	User *previous;
} *userHead, *userTail, *userTemp;

struct Clothe {
	string clotheName, description, colour, category, CID;
	int quantity;
	Clothe *next;
	Clothe *previous;
} *clotheHead, *clotheTail, *clotheTemp, *newHead, *newTail, *newTemp;

struct Order {
	int OID;
	int quantity;
	int ID;
	string username, CID, clotheName;
	Order *next;
	Order *previous;
} *orderHead, *orderTail, *orderTemp;

// function headers
Clothe *createNewClothe(string CID, string clotheName, string description, string colour, int quantity, string category);
Order *createNewOrder(int OID, int ID, string username, string CID, string clotheName, int quantity);
User *createNewUser(int ID, string username, string password, string role);

void addUser(int ID, string username, string password, string role);
void login();
void exit(int ID, string username, string role);
void adminMenu(int ID, string username, string role);
void customerMenu(int ID, string username, string role);

void addClothe(string CID, string clotheName, string description, string colour, int quantity, string category);
void addOrder(int OID, int ID, string username, string CID, string clotheName, int quantity);

int compareInsensitive(string s1, string s2);
bool checkNumber(string str);

// admin
void addClothe();
void deleteClothe();
void displayClothe();
void sortClotheQuantity(string CID, string clotheName, string description, string colour, int quantity, string category);
void displaySortedCloth();

void displayOrder();
void displaySingleOrder(int ID, string username, string role);

// customer
void displaySingleClothe(int ID, string username, string role);
void sortClotheCategory(string CID, string clotheName, string description, string colour, int quantity, string category);
void searchClotheColour();

void addOrder(int ID, string username);

int main() {
	clotheHead = clotheTail = NULL;
	userHead = userTail = NULL;
	orderHead = orderTail = NULL;

	addUser(1, "Bill", "abc123", "Admin");
	addUser(2, "John", "1234", "User");
	addUser(3, "Mark", "1234", "User");

	addClothe("SRT001", "Mickey Mouse T-Shirt", "Long Sleeve", "Black", 23, "bShirt");
	addClothe("SRT002", "Butterfly Blouse", "Short Sleeve", "White", 5, "bShirt");
	addClothe("SKT001", "Bubble Skirt", "Short Skirt", "Yellow", 30, "aSkirt");
	addClothe("SKT002", "Jeans Skirt", "Long Skirt", "Yellow", 14, "eSkirt");
	addClothe("SKT003", "Cotton Skirt", "Long Skirt", "Black", 15, "zSkirt");

	addOrder(1, 2, "John", "SKT003", "Cotton Skirt", 2);
	addOrder(2, 3, "Mark", "SKT002", "Jeans Skirt", 10);

	login();
	return 1;
}

Clothe *createNewClothe(string CID, string clotheName, string description, string colour, int quantity, string category) {
	Clothe *newnode = new Clothe;

	newnode->CID = CID;
	newnode->clotheName = clotheName;
	newnode->description = description;
	newnode->colour = colour;
	newnode->quantity = quantity;
	newnode->category = category;
	newnode->next = NULL;
	newnode->previous = NULL;

	return newnode;
};

Order *createNewOrder(int OID, int ID, string username, string CID, string clotheName, int quantity) {
	Order *newnode = new Order;

	newnode->OID = OID;
	newnode->ID = ID;
	newnode->username = username;
	newnode->CID = CID;
	newnode->clotheName = clotheName;
	newnode->quantity = quantity;
	newnode->next = NULL;
	newnode->previous = NULL;

	return newnode;
};

User *createNewUser(int ID, string username, string password, string role) {
	User *newnode = new User;

	newnode->ID = ID;
	newnode->username = username;
	newnode->password = password;
	newnode->role = role;
	newnode->next = NULL;
	newnode->previous = NULL;

	return newnode;
};

void addUser(int ID, string username, string password, string role) {
	User *newnode = createNewUser(ID, username, password, role);

	if (userHead == NULL) {
		userHead = userTail = newnode;
	} else if (ID <= userHead->ID) {
		newnode->next = userHead;
		userHead->previous = newnode;
		userHead = newnode;
	} else {
		userTemp = userHead;
		while (userTemp->next != NULL) {
			if (ID <= userTemp->next->ID) {
				break;
			};
			userTemp = userTemp->next;
		};
		newnode->next = userTemp->next;
		newnode->previous = userTemp;
		if (userTemp->next != NULL) {
			userTemp->next->previous = newnode;
		} else {
			userTail = newnode;
		};
		userTemp->next = newnode;
	};
};

void login() {
	string inputid, inputpass, username, password, role;
	int ID, convertedID;
	bool check = false;

	cout << "---------------Login---------------" << endl;
	cout << "Please enter username and password:" << endl;

	do {
		cout << "User ID: ";
		cin >> inputid;

		istringstream(inputid) >> convertedID;
		userTemp = userHead;
		while (userTemp != NULL) {
			if (convertedID == userTemp->ID) {
				ID = userTemp->ID;
				username = userTemp->username;
				password = userTemp->password;
				role = userTemp->role;
				check = true;
				break;
			};
			userTemp = userTemp->next;
		};

		if (check == false) {
			cout << "Invalid ID. Please type again." << endl;
		};
	} while (check == false);

	do {
		cout << "Password: ";
		cin >> inputpass;

		if (inputpass == password) {
			check = true;
		} else {
			cout << "Wrong password. Please type again." << endl << endl;
			check = false;
		};
	} while (check == false);

	cout << "Login Successfully." << endl << endl;

	if (role == "Admin") {
		adminMenu(ID, username, role);
	} else if (role == "User") {
		customerMenu(ID, username, role);
	};
};

void exit(int ID, string username, string role) {
	string input;
	bool check = false;

	do {
		cout << "Are you want to logout?(Y/N)" << endl;
		cin >> input;

		if (input == "Y") {
			check = true;
			login();
		} else if (input == "N") {
			check = true;
			if (role == "Admin") {
				cout << endl;
				adminMenu(ID, username, role);
			} else if (role == "User") {
				cout << endl;
				customerMenu(ID, username, role);
			};
		};
	} while (check == false);
};

void adminMenu(int ID, string username, string role) {
	int option = 0;

	cout << "------------Admin Menu-------------" << endl;
	cout << "1. Add Cloth\n";
	cout << "2. Delete Cloth\n";
	cout << "3. View Cloth List\n";
	cout << "4. View Sorted Cloth List(quantity)\n";
	cout << "5. View Customer Orders\n";
	cout << "6. View Single Order\n";
	cout << "7. Logout\n";

	cout << "Please select form menu(1-7): ";
	cin >> option;
	switch (option) {
		case 1:
			addClothe();
			cout << endl;
			adminMenu(ID, username, role);
			break;

		case 2:
			deleteClothe();
			cout << endl;
			adminMenu(ID, username, role);
			break;
		case 3:
			displayClothe();
			cout << endl;
			adminMenu(ID, username, role);
			break;
		case 4:
			newHead = newTail = NULL;
			clotheTemp = clotheHead;
			while (clotheTemp != NULL) {
				sortClotheQuantity(clotheTemp->CID, clotheTemp->clotheName, clotheTemp->description, clotheTemp->colour, clotheTemp->quantity, clotheTemp->category);
				clotheTemp = clotheTemp->next;
			};

			displaySortedCloth();
			cout << endl;
			adminMenu(ID, username, role);
			break;
		case 5:
			displayOrder();
			cout << endl;
			adminMenu(ID, username, role);
			break;
		case 6:
			displaySingleOrder(ID, username, role);
			break;
		case 7:
			exit(ID, username, role);
			break;
		default:
			cout << endl;
			adminMenu(ID, username, role);
	};
	cout << endl;
};

void customerMenu(int ID, string username, string role) {
	int option = 0;

	cout << "-----------Customer Menu------------" << endl;
	cout << "1. View Cloth List\n";
	cout << "2. View Sorted Cloth List(Category)\n";
	cout << "3. View Single Cloth\n";
	cout << "4. Search Cloth By Color\n";
	cout << "5. Add Order\n";
	cout << "6. Logout\n";

	cout << "Please select form menu(1-6): ";
	cin >> option;
	switch (option) {
		case 1:
			displayClothe();
			cout << endl;
			customerMenu(ID, username, role);
			break;

		case 2:
			newHead = newTail = NULL;
			clotheTemp = clotheHead;
			while (clotheTemp != NULL) {
				sortClotheCategory(clotheTemp->CID, clotheTemp->clotheName, clotheTemp->description, clotheTemp->colour, clotheTemp->quantity, clotheTemp->category);
				clotheTemp = clotheTemp->next;
			};

			displaySortedCloth();
			cout << endl;
			customerMenu(ID, username, role);
			break;
		case 3:
			newHead = newTail = NULL;
			clotheTemp = clotheHead;
			while (clotheTemp != NULL) {
				sortClotheCategory(clotheTemp->CID, clotheTemp->clotheName, clotheTemp->description, clotheTemp->colour, clotheTemp->quantity, clotheTemp->category);
				clotheTemp = clotheTemp->next;
			};

			displaySingleClothe(ID, username, role);
			cout << endl;
			customerMenu(ID, username, role);
			break;
		case 4:
			searchClotheColour();
			cout << endl;
			customerMenu(ID, username, role);
			break;
		case 5:
			addOrder(ID, username);
			cout << endl;
			customerMenu(ID, username, role);
			break;
		case 6:
			exit(ID, username, role);
			break;
		default:
			cout << endl;
			customerMenu(ID, username, role);
	};
	cout << endl;
};

void addClothe(string CID, string clotheName, string description, string colour, int quantity, string category) {
	Clothe *newnode = createNewClothe(CID, clotheName, description, colour, quantity, category);

	if (clotheHead == NULL) {
		clotheHead = clotheTail = newnode;
	} else {
		newnode->next = clotheHead;
		clotheHead->previous = newnode;
		clotheHead = newnode;
	};
};

void addOrder(int OID, int ID, string username, string CID, string clotheName, int quantity) {
	Order *newnode = createNewOrder(OID, ID, username, CID, clotheName, quantity);

	if (orderHead == NULL) {
		orderHead = orderTail = newnode;
	} else if (OID <= orderHead->OID) {
		newnode->next = orderHead;
		orderHead->previous = newnode;
		orderHead = newnode;
	} else {
		orderTemp = orderHead;

		while (orderTemp->next != NULL) {
			if (OID <= orderTemp->next->OID) {
				break;
			}
			orderTemp = orderTemp->next;
		}
		newnode->next = orderTemp->next;
		newnode->previous = orderTemp;

		if (orderTemp->next != NULL) {
			orderTemp->next->previous = newnode;
		} else {
			orderTail = newnode;
		}
		orderTemp->next = newnode;
	}
}


void addClothe() {
	string CID, clotheName, description, colour, category, quantity;
	int convquantity;
	bool check = true;
	cout << endl << "-------------Add Cloth-------------" << endl;
	cout << "Please enter details:" << endl;
	cout << "Cloth ID: ";
	cin.ignore();
	getline(cin, CID);
	cout << "Cloth Name: ";
	cin.ignore();
	getline(cin, clotheName);
	cout << "Description: ";
	cin.ignore();
	getline(cin, description);
	cout << "Color: ";
	cin.ignore();
	getline(cin, colour);
	do {
		cout << "quantity: ";
		cin >> quantity;

		if (checkNumber(quantity)) {
			istringstream(quantity) >> convquantity;
			check = true;
		} else {
			check = false;
		}
	} while (check == false);

	cout << "Category: ";
	cin.ignore();
	getline(cin, category);

	Clothe *newnode = createNewClothe(CID, clotheName, description, colour, convquantity, category);

	if (clotheHead == NULL) {
		clotheHead = clotheTail = newnode;
	}	else {
		newnode->next = clotheHead;
		clotheHead->previous = newnode;
		clotheHead = newnode;
	}
	cout << "Add successfully!" << endl;
}

void deleteClothe() {
	cout << endl << "-----------Delete Cloth------------" << endl;

	string id;
	cout << "Please enter cloth ID: ";
	cin >> id;

	if (clotheHead == NULL) {
		cout << "No result found, cannot delete!" << endl;
	} else if (clotheHead->CID == id) {
		clotheTemp = clotheHead;
		clotheTemp->next->previous = NULL;
		clotheHead = clotheTemp->next;
		delete clotheTemp;
	} else {
		clotheTemp = clotheHead;

		while (clotheTemp->CID != id) {
			clotheTemp = clotheTemp->next;
			if (clotheTemp->next == NULL) {
				cout << "No result found, cannot delete!" << endl;
				return;
			}
		}
		clotheTemp->previous->next = clotheTemp->next;
		clotheTemp->next->previous = clotheTemp->previous;
		delete clotheTemp;
		cout << "Delete Successully!" << endl;
	}
}

void displayClothe() {
	cout << endl << "-----------Display Cloth----------" << endl;
	cout << left << setw(12) << "Cloth ID" << setw(28) << "Cloth Name" << setw(18) << "Description" << setw(13) << "Color" << setw(15) << "quantity" << setw(10) << "Category" << endl;
	clotheTemp = clotheHead;

	while (clotheTemp != NULL) {
		cout << left << setw(12) << clotheTemp->CID << setw(28) << clotheTemp->clotheName << setw(18) << clotheTemp->description << setw(13) << clotheTemp->colour << setw(15) << clotheTemp->quantity << setw(10) << clotheTemp->category << endl;
		clotheTemp = clotheTemp->next;
	}
}

void sortClotheQuantity(string CID, string clotheName, string description, string colour, int quantity, string category) {
	Clothe *newnode = createNewClothe(CID, clotheName, description, colour, quantity, category);

	if (newHead == NULL) {
		newHead = newTail = newnode;
	} else if (quantity <= newHead->quantity) {
		newnode->next = newHead;
		newHead->previous = newnode;
		newHead = newnode;
	} else {
		newTemp = newHead;
		while (newTemp->next != NULL) {
			if (quantity <= newTemp->next->quantity) {
				break;
			}
			newTemp = newTemp->next;
		}
		newnode->next = newTemp->next;
		newnode->previous = newTemp;

		if (newTemp->next != NULL) {
			newTemp->next->previous = newnode;
		} else {
			newTail = newnode;
		}
		newTemp->next = newnode;
	}
}

void displaySortedCloth() {
	cout << endl << "--------Display Sorted Cloth------" << endl;
	cout << left << setw(12) << "Cloth ID" << setw(28) << "Cloth Name" << setw(18) << "Description" << setw(13) << "Color" << setw(15) << "quantity" << setw(10) << "Category" << endl;
	clotheTemp = newHead;

	while (clotheTemp != NULL) {
		cout << left << setw(12) << clotheTemp->CID << setw(28) << clotheTemp->clotheName << setw(18) << clotheTemp->description << setw(13) << clotheTemp->colour << setw(15) << clotheTemp->quantity << setw(10) << clotheTemp->category << endl;
		clotheTemp = clotheTemp->next;
	}
}

void displaySingleClothe(int ID, string username, string role) {
	cout << endl << "----------View Single Cloth---------" << endl;

	clotheTemp = newHead;
	string option;
	int convertedoption;
	while (clotheTemp != NULL) {
		cout << left << setw(12) << "Cloth ID" << setw(28) << "Cloth Name" << setw(18) << "Description" << setw(13) << "Color" << setw(15) << "quantity" << setw(10) << "Category" << endl;
		cout << left << setw(12) << clotheTemp->CID << setw(28) << clotheTemp->clotheName << setw(18) << clotheTemp->description << setw(13) << clotheTemp->colour << setw(15) << clotheTemp->quantity << setw(10) << clotheTemp->category << endl;

		cout << "1. Next\n";
		cout << "2. Previous\n";
		cout << "3. Exit\n";
		cout << "Please select form menu(1-3): ";
		cin >> option;

		istringstream(option) >> convertedoption;
		switch (convertedoption) {
			case 1:
				if (clotheTemp->next == NULL)
					cout << "This is the last cloth record! Cannot go next." << endl;
				else
					clotheTemp = clotheTemp->next;
				break;

			case 2:
				if (clotheTemp->previous == NULL)
					cout << "This is the first cloth record! Cannot go previous." << endl;
				else
					clotheTemp = clotheTemp->previous;
				break;

			case 3:
				cout << endl;
				customerMenu(ID, username, role);
				break;
			default:
				cout << "Wrong input." << endl;
				cout << endl;
				customerMenu(ID, username, role);
		}
		cout << endl;
	}
}

void sortClotheCategory(string CID, string clotheName, string description, string colour, int quantity, string category) {
	Clothe *newnode = createNewClothe(CID, clotheName, description, colour, quantity, category);

	if (newHead == NULL) {
		newHead = newTail = newnode;
	} else if (compareInsensitive(category, newHead->category) > 0) {
		newnode->next = newHead;
		newHead->previous = newnode;
		newHead = newnode;
	} else {
		newTemp = newHead;
		while (newTemp->next != NULL) {
			if (compareInsensitive(category, newTemp->next->category) > 0) {
				break;
			}
			newTemp = newTemp->next;
		}
		newnode->next = newTemp->next;
		newnode->previous = newTemp;

		if (newTemp->next != NULL) {
			newTemp->next->previous = newnode;
		} else {
			newTail = newnode;
		}
		newTemp->next = newnode;
	}
}

void searchClotheColour() {
	string colour;
	cout << "Please enter colour:";
	cin >> colour;

	cout << endl << "--------Search Based On Color-------" << endl;
	cout << left << setw(12) << "Cloth ID" << setw(28) << "Cloth Name" << setw(18) << "Description" << setw(13) << "Color" << setw(15) << "quantity" << setw(10) << "Category" << endl;
	clotheTemp = newHead;

	while (clotheTemp != NULL) {
		if (colour == clotheTemp->colour) {
			cout << left << setw(12) << clotheTemp->CID << setw(28) << clotheTemp->clotheName << setw(18) << clotheTemp->description << setw(13) << clotheTemp->colour << setw(15) << clotheTemp->quantity << setw(10) << clotheTemp->category << endl;
		}
		clotheTemp = clotheTemp->next;
	}
}

void addOrder(int ID, string username) {
	int OID, convquantity, maxquantity = 0;
	string CID, clotheName, quantity;
	bool checkName = false, checkQuan = false;

	if (orderTail == NULL) {
		OID = 1;
	} else {
		OID = orderTail->OID + 1;
	}
	if (clotheHead == NULL) {
		cout << "No any cloth available. Cannot add order" << endl;
		return;
	}
	cout << endl << "-------------Add Order-------------" << endl;
	cout << "Please enter the details: " << endl;

	do {
		cout << "Cloth ID: ";
		cin >> CID;

		clotheTemp = clotheHead;
		while (clotheTemp != NULL) {
			if (CID == clotheTemp->CID) {
				clotheName = clotheTemp->clotheName;
				maxquantity = clotheTemp->quantity;
				checkName = true;
				break;
			}
			clotheTemp = clotheTemp->next;
		}

		if (checkName == false) {
			cout << "Cloth ID may wrong. No result found! Please type again." << endl << endl;
		} else if (maxquantity == 0) {
			cout << "The cloth was sold out." << endl << endl;
			return;
		}
	} while (checkName == false);

	do {
		cout << "quantity: ";
		cin >> quantity;

		istringstream(quantity) >> convquantity;
		if (convquantity <= maxquantity) {
			checkQuan = true;
		} else {
			cout << "The quantity entered cannot more than current stock quantity. Please type again" << endl << endl;
		}
	} while (checkQuan == false);

	Order *newnode = createNewOrder(OID, ID, username, CID, clotheName, convquantity);

	if (orderHead == NULL) {
		orderHead = orderTail = newnode;
	} else if (OID <= orderHead->OID) {
		newnode->next = orderHead;
		orderHead->previous = newnode;
		orderHead = newnode;
	} else {
		orderTemp = orderHead;

		while (orderTemp->next != NULL) {
			if (OID <= orderTemp->next->OID) {
				break;
			}
			orderTemp = orderTemp->next;
		}
		newnode->next = orderTemp->next;
		newnode->previous = orderTemp;

		if (orderTemp->next != NULL) {
			orderTemp->next->previous = newnode;
		} else {
			orderTail = newnode;
		}
		orderTemp->next = newnode;

	}
	clotheTemp->quantity = clotheTemp->quantity - convquantity;
	cout << "Add order successfully" << endl;
}

void displayOrder() {
	cout << endl << "------------Customer Orders--------" << endl;
	cout << left << setw(12) << "Order ID" << setw(28) << "User ID" << setw(18) << "Username" << setw(13) << "Cloth ID" << setw(15) << "Cloth Name" << setw(10) << "quantity" << endl;
	orderTemp = orderHead;

	while (orderTemp != NULL) {
		cout << left << setw(12) << orderTemp->OID << setw(28) << orderTemp->ID << setw(18) << orderTemp->username << setw(13) << orderTemp->CID << setw(15) << orderTemp->clotheName << setw(10) << orderTemp->quantity << endl;
		orderTemp = orderTemp->next;
	}
}

void displaySingleOrder(int ID, string username, string role) {
	cout << endl << "------------Single Order-----------" << endl;

	orderTemp = orderHead;
	string option;
	int convertedoption;
	while (orderTemp != NULL) {
		cout << left << setw(12) << "Order ID" << setw(28) << "User ID" << setw(18) << "Username" << setw(13) << "Cloth ID" << setw(15) << "Cloth Name" << setw(10) << "quantity" << endl;
		cout << left << setw(12) << orderTemp->OID << setw(28) << orderTemp->ID << setw(18) << orderTemp->username << setw(13) << orderTemp->CID << setw(15) << orderTemp->clotheName << setw(10) << orderTemp->quantity << endl;

		cout << "1. Next\n";
		cout << "2. Previous\n";
		cout << "3. Exit\n";
		cout << "Please select form menu(1-3): ";
		cin >> option;

		istringstream(option) >> convertedoption;
		switch (convertedoption) {
			case 1:
				if (orderTemp->next == NULL)
					cout << "This is the last order record! Cannot go next." << endl;
				else
					orderTemp = orderTemp->next;
				break;

			case 2:
				if (orderTemp->previous == NULL)
					cout << "This is the first order record! Cannot go previous." << endl;
				else
					orderTemp = orderTemp->previous;
				break;

			case 3:
				cout << endl;
				adminMenu(ID, username, role);
				break;
			default:
				cout << "Wrong input." << endl;
				cout << endl;
				adminMenu(ID, username, role);
		}
		cout << endl;
	}
}

int compareInsensitive(string s1, string s2) {
	// convert s1 and s2 to lowercase
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	// compare string s1 with string s2
	return s1.compare(s2);
};

bool checkNumber(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i]) == false)
			return false;
		return true;
	}
}
