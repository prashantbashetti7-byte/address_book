#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100 // Maximum number of contacts

typedef struct // Structure to store contact details
{
    char name[50]; // Store contact name
    char phone[20]; // Store phone number
    char email[50]; // Store email address
} Contact;

typedef struct // Structure to store all contacts
{
    Contact contacts[MAX_CONTACTS]; // Store contact list
    int contactCount; // Store number of contacts
} AddressBook;

//The below all are function declaration

void createContact(AddressBook *addressBook); 
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);



#endif
