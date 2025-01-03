# Phonebook Application

The Phonebook Application is a simple console-based program written in C++ to manage a collection of contacts. It supports adding, searching, deleting, and displaying contacts, with an additional feature to load contacts from a file at the start of the program.

## Features
- **Add Contact**: Add a new contact by providing a name and phone number.
- **Search Contact**: Search for a contact by name and display its details.
- **Delete Contact**: Remove a contact from the phonebook by name.
- **Display All Contacts**: View all stored contacts.
- **Load Contacts from File**: Automatically load contacts from a file when the program starts.
- **Read Multiple Files**: Load contacts from multiple files for enhanced flexibility.


### Loading Multiple Files
To load contacts from multiple files, modify the `loadFromFile` method in the program to accept a list of file names. Example:
```cpp
void loadFromFiles(const vector<string>& fileNames) {
    for (const auto& fileName : fileNames) {
        ifstream file(fileName);
        if (!file) {
            cout << "Could not open file: " << fileName << endl;
            continue;
        }
        string line;
        while (getline(file, line)) {
            size_t commaPos = line.find(',');
            if (commaPos != string::npos) {
                string name = line.substr(0, commaPos);
                string phoneNumber = line.substr(commaPos + 1);
                addContact(name, phoneNumber);
            }
        }
        file.close();
    }
    cout << "Contacts loaded from multiple files." << endl;
}
```
Pass a list of files to the method, such as:
```cpp
vector<string> files = {"contacts1.txt", "contacts2.txt"};
phoneBook.loadFromFiles(files);
```

### Program Flow
1. When the program starts, it will attempt to load contacts from `contacts.txt`.
2. Optionally, load additional contacts from multiple files if implemented.
3. You can interact with the application through a menu:
   - Option 1: Add a contact.
   - Option 2: Search for a contact.
   - Option 3: Delete a contact.
   - Option 4: Display all contacts.
   - Option 5: Exit the program.
4. Perform operations as needed.

## Output
![Screenshot 2025-01-03 182924](https://github.com/user-attachments/assets/952190bd-8d84-4035-a8c3-24ccc0cd0c18)










