#include <iostream>
#include <string>
#include <map>
using namespace std;


class PhoneBookBase {
protected:
    map<string, string> contacts; 

public:
    
    PhoneBookBase() {
        cout << "PhoneBookBase initialized." << endl;
    }

    void addContact(const string& name, const string& phoneNumber) {
        contacts[name] = phoneNumber;
        cout << "Contact added successfully "<< endl;
    }

    void displayContacts() {
        if (contacts.empty()) {
            cout << "Phonebook is empty." << endl;
            return;
        }
        cout << "Phonebook entries:" << endl;
        for (const auto& entry : contacts) {
            cout << entry.first << " - " << entry.second << endl;
        }
    }
};


class PhoneBook : public PhoneBookBase {
public:
    
    void searchContact(const string& name) {
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            cout << "Found: " << it->first << " - " << it->second << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void deleteContact(const string& name) {
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            contacts.erase(it);
            cout << "Contact deleted successfully: " << name << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;
    string name, phoneNumber;

    do {
        cout << "\nPhonebook Application" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Display All Contacts" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter phone number: ";
            getline(cin, phoneNumber);
            phoneBook.addContact(name, phoneNumber);
            break;
        case 2:
            cout << "Enter name to search: ";
            cin.ignore();
            getline(cin, name);
            phoneBook.searchContact(name);
            break;
        case 3:
            cout << "Enter name to delete: ";
            cin.ignore();
            getline(cin, name);
            phoneBook.deleteContact(name);
            break;
        case 4:
            phoneBook.displayContacts();
            break;
        case 5:
            cout << "Exiting Phonebook Application." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
