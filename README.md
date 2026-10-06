# Address Book Management System

A console-based **Address Book Management System developed in C** that allows users to create, search, edit, delete, and list contacts. The project also supports sorting contacts and storing contact information in a file for persistent data management.

## 📌 Project Overview

The Address Book project is a menu-driven application written in the **C programming language**.

It provides basic contact management operations such as:

- Create a new contact
- Search for an existing contact
- Edit contact details
- Delete a contact
- List all contacts
- Sort contacts by Name, Phone, or Email
- Save contacts to a file
- Load contacts from a file when the program starts

The project demonstrates practical usage of **structures, functions, arrays, pointers, string handling, file handling, and modular programming in C**.

---

## ✨ Features

### 1. Create Contact

Allows the user to add a new contact with:

- Name
- Phone number
- Email address

Input validation is performed for contact details.

### 2. Search Contact

Contacts can be searched using:

- Name
- Phone number
- Email address

### 3. Edit Contact

Existing contact details can be modified.

The user can edit:

- Name
- Phone number
- Email address

### 4. Delete Contact

Allows the user to delete a contact after confirmation.

### 5. List Contacts

Displays all stored contacts.

Contacts can be sorted by:

- Name
- Phone
- Email

### 6. File Handling

Contact information can be stored in a file so that the data can be retained after the program exits.

The project uses:

- `fopen()`
- `fscanf()`
- `fprintf()`
- `fclose()`

---

## 🛠️ Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Operating System:** Linux / Ubuntu / WSL
- **Version Control:** Git
- **Repository:** GitHub

---

## 📂 File Structure

```text
AddressBook/
│
├── main.c
├── contact.h
├── contact.c
├── file.h
├── file.c
├── contacts.txt
├── .gitignore
├── LICENSE
└── README.md
```

### File Description

| File           | Description                                                                                         |
| -------------- | --------------------------------------------------------------------------------------------------- |
| `main.c`       | Contains the main function and menu-driven program                                                  |
| `contact.h`    | Contains structures, constants, and function declarations                                           |
| `contact.c`    | Contains contact creation, searching, editing, deleting, listing, sorting, and initialization logic |
| `file.h`       | Contains declarations for file handling functions                                                   |
| `file.c`       | Contains functions for saving and loading contacts                                                  |
| `contacts.txt` | Stores contact information permanently                                                              |
| `.gitignore`   | Specifies files that should not be uploaded to GitHub                                               |
| `LICENSE`      | Defines the license and usage permissions                                                           |
| `README.md`    | Documentation for the project                                                                       |

---

## 🧱 Data Structures

The project uses two main structures.

### Contact

```c
typedef struct
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;
```

This structure stores the information of one contact.

### AddressBook

```c
typedef struct
{
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;
```

This structure stores multiple contacts and keeps track of the number of contacts.

---

## ▶️ How to Run the Project

### Step 1: Clone the Repository

```bash
git clone https://github.com/your-username/address-book.git
```

### Step 2: Navigate to the Project Directory

```bash
cd address-book
```

### Step 3: Compile the Program

Using GCC:

```bash
gcc main.c contact.c file.c -o addressbook
```

### Step 4: Run the Program

```bash
./addressbook
```

---

## 💻 Program Menu

After running the program, the following menu is displayed:

```text
Address Book Menu:

1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save and Exit

Enter your choice:
```

---

## 📋 Example Usage

### Create Contact

```text
Enter your choice: 1

Enter name: Rahul Patil
Enter phone: 9876543210
Enter email: rahul@gmail.com

Contact created successfully.
```

### Search Contact

```text
Enter your choice: 2

===== Search Contact =====

1. Search by Name
2. Search by Phone
3. Search by Email

Enter your choice: 1
Enter name: Rahul Patil

Contact Found!
-------------------------
Name  : Rahul Patil
Phone : 9876543210
Email : rahul@gmail.com
-------------------------
```

### List Contacts

```text
Enter your choice: 5

1. Sort by Name
2. Sort by Phone
3. Sort by Email

Enter sorting choice: 1

S1.No   Name            Phone           Email
1       Rahul Patil     9876543210      rahul@gmail.com
```

### Save and Exit

```text
Enter your choice: 6

Saving and Exiting...
Contacts saved successfully.
```

---

## 📄 File Storage Format

Contacts are stored in `contacts.csv`.

Example:

```text
2
Rahul Patil,9876543210,rahul@gmail.com
Amit Kumar,8765432109,amit@gmail.com
```

The first line represents the total number of contacts.

Each following line contains:

```text
Name,Phone,Email
```

---

## 🧠 Concepts Used

This project demonstrates the following C programming concepts:

- Variables and data types
- `if-else`
- `switch-case`
- Loops
- Arrays
- Strings
- Structures
- Pointers
- Functions
- Header files
- Modular programming
- String functions
- File handling
- Input validation
- Sorting
- Searching
- Dynamic data management using structures

---

## 🔄 Program Flow

```text
                 ┌─────────────────┐
                 │     Program     │
                 │      Start      │
                 └────────┬────────┘
                          │
                          ▼
                 ┌─────────────────┐
                 │ Load Contacts   │
                 │   From File     │
                 └────────┬────────┘
                          │
                          ▼
                 ┌─────────────────┐
                 │  Display Menu   │
                 └────────┬────────┘
                          │
          ┌───────────────┼───────────────┐
          │               │               │
          ▼               ▼               ▼
      Create          Search/Edit      Delete/List
      Contact          Contact          Contact
          │               │               │
          └───────────────┼───────────────┘
                          │
                          ▼
                 ┌─────────────────┐
                 │  Save & Exit    │
                 └────────┬────────┘
                          │
                          ▼
                 ┌─────────────────┐
                 │  Save Contacts  │
                 │    To File      │
                 └────────┬────────┘
                          │
                          ▼
                 ┌─────────────────┐
                 │      Exit       │
                 └─────────────────┘
```

---

## 🎯 Project Objective

The main objective of this project is to develop a **menu-driven Address Book application in C** that efficiently manages contact information and demonstrates the practical implementation of **structures, functions, pointers, strings, sorting, searching, and file handling**.

---

## 🚀 Future Enhancements

The project can be further enhanced by adding:

- Duplicate contact detection
- More advanced search options
- Case-insensitive sorting
- Password protection
- Contact groups/categories
- Improved user interface
- Database integration
- Import/export functionality

---

## 👨‍💻 Author

**Prashant Bashetti**

C Programming | Embedded Systems | Software Development

---

## 📜 License

This project is licensed under the **MIT License**. See the `LICENSE` file for more information.
