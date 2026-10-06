/*
Name : Prashant Vilas Bashetti.
Register no. : 26018_284
start date : 31/08/2026
end date : 09/09/2026
Project name : Address Book
*/

#include <stdio.h>
#include "contact.h"

int main()
{
    int choice;
    AddressBook addressBook;

    // Load contacts from file
    initialize(&addressBook);

    // Repeat menu until user selects Save and Exit
    do
    {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Save and Exit\n");
        // printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Create a new contact
            createContact(&addressBook);
            break;
        case 2:
            // Search for a contact
            searchContact(&addressBook);
            break;
        case 3:
            // Edit an existing contact
            editContact(&addressBook);
            break;
        case 4:
            // Delete a contact
            deleteContact(&addressBook);
            break;
        case 5:
        {
            int sortCriteria;

            // Select sorting method
            printf("1. Sort by Name\n");
            printf("2. Sort by Phone\n");
            printf("3. Sort by Email\n");

            // Get sorting choice
            printf("Enter sorting choice: ");
            scanf("%d", &sortCriteria);

            listContacts(&addressBook, sortCriteria);

            break;
        }
        case 6:
            // Save contacts and exit
            printf("Saving and Exiting...\n");
            saveContactsToFile(&addressBook);
            break;
        default:
            // If the input is wrong
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6); // Continue until choice is 6

    return 0;
}
