#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

void listContacts(AddressBook *addressBook, int sortCriteria) // function defination
{
    switch (sortCriteria) // Select sorting method
    {
    case 1:
        printf("Sorting by name\n");
        for (int i = 0; i < addressBook->contactCount - 1; i++)
        {
            for (int j = 0; j < addressBook->contactCount - i - 1; j++) // Compare adjacent contacts
            {
                if (strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0) // Compare names
                {
                    // Compare two contacts and swap them if needed.
                    Contact temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = temp;
                }
            }
        }

        // then display all contacts in a properly formatted table.
        printf("\nContact Found!\n");
        printf("--------------------------------------------------------------\n");
        printf("%-6s %-20s %-15s %-30s\n", "S.No", "Name", "Phone", "Email");
        printf("--------------------------------------------------------------\n");

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            printf("%-6d %-20s %-15s %-30s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        printf("--------------------------------------------------------------\n");
        break;

    case 2:
        printf("Sorting by Phone\n");
        for (int i = 0; i < addressBook->contactCount - 1; i++)
        {
            for (int j = 0; j < addressBook->contactCount - i - 1; j++)
            {
                if (strcmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0) // Compare phone
                {
                    // Compare two contacts and swap them if needed.
                    Contact temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = temp;
                }
            }
        }

        // then display all contacts in a properly formatted table.
        printf("\nContact Found!\n");
        printf("--------------------------------------------------------------\n");
        printf("%-6s %-20s %-15s %-30s\n", "S.No", "Name", "Phone", "Email");
        printf("--------------------------------------------------------------\n");

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            printf("%-6d %-20s %-15s %-30s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        printf("--------------------------------------------------------------\n");
        break;

    case 3:
        printf("Sorting by Email\n");
        for (int i = 0; i < addressBook->contactCount - 1; i++)
        {
            for (int j = 0; j < addressBook->contactCount - i - 1; j++)
            {
                if (strcmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0) // Compare mail
                {
                    // Compare two contacts and swap them if needed.
                    Contact temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = temp;
                }
            }
        }

        // then display all contacts in a properly formatted table.
        printf("\nContact Found!\n");
        printf("--------------------------------------------------------------\n");
        printf("%-6s %-20s %-15s %-30s\n", "S.No", "Name", "Phone", "Email");
        printf("--------------------------------------------------------------\n");

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            printf("%-6d %-20s %-15s %-30s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        printf("--------------------------------------------------------------\n");
        break;
        // If the input is wrong, Show error message
    default:
        printf("Invalid Input\n");
    }
    // Sort contacts based on the chosen criteria
}

void initialize(AddressBook *addressBook) // function defination
{
    // addressBook->contactCount = 0;
    // populateAddressBook(addressBook);

    // Load contacts from file during initialization(After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) // function defination
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

void createContact(AddressBook *addressBook) // function defination
{
    if (addressBook->contactCount >= MAX_CONTACTS) // Check if address book is full
    {
        printf("Address Book is full.\n");
        return;
    }

    /* ---------- NAME ---------- */

    // Check whether the name is empty, has extra spaces, or contains invalid characters
    while (1)
    {
        printf("Enter name: ");

        scanf(" %49[^\n]", addressBook->contacts[addressBook->contactCount].name);

        char *name = addressBook->contacts[addressBook->contactCount].name;

        int valid = 1;
        int i;

        /* Empty name */
        if (strlen(name) == 0)
        {
            valid = 0;
        }

        /* No leading space */
        if (name[0] == ' ')
        {
            valid = 0;
        }

        /* No trailing space */
        if (name[strlen(name) - 1] == ' ')
        {
            valid = 0;
        }

        /* Only alphabets and spaces */
        for (i = 0; name[i] != '\0'; i++)
        {
            if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' '))
            {
                valid = 0;
                break;
            }
        }

        if (valid)
        {
            break;
        }

        printf("Invalid name!\n");
        printf("Name should contain only alphabets and spaces.\n");
    }

    /* ---------- PHONE ---------- */

    // Check phone number length, starting digit, and remaining digits
    while (1)
    {
        printf("Enter phone: ");

        scanf(" %19[^\n]", addressBook->contacts[addressBook->contactCount].phone);

        char *phone = addressBook->contacts[addressBook->contactCount].phone;

        int valid = 1;
        int i;

        /* Exactly 10 characters */
        if (strlen(phone) != 10)
        {
            valid = 0;
        }

        /* First digit must be 6, 7, 8 or 9 */
        if (phone[0] < '6' || phone[0] > '9')
        {
            valid = 0;
        }

        /* All characters must be digits */
        for (i = 0; phone[i] != '\0'; i++)
        {
            if (phone[i] < '0' || phone[i] > '9')
            {
                valid = 0;
                break;
            }
        }

        if (valid)
        {
            break;
        }

        printf("Invalid phone number!\n");
        printf("Phone must contain exactly 10 digits and start with 6, 7, 8 or 9.\n");
    }

    /* ---------- EMAIL ---------- */

    // Check @, dot, spaces, and email format
    while (1)
    {
        printf("Enter email: ");

        scanf(" %49[^\n]", addressBook->contacts[addressBook->contactCount].email);

        char *email = addressBook->contacts[addressBook->contactCount].email;

        int valid = 1;
        int atCount = 0;
        int dotCount = 0;
        int atPosition = -1;
        int i;

        /* Check @, dot and spaces */
        for (i = 0; email[i] != '\0'; i++)
        {
            if (email[i] == '@')
            {
                atCount++;
                atPosition = i;
            }

            if (email[i] == '.')
            {
                dotCount++;
            }

            /* No spaces */
            if (email[i] == ' ')
            {
                valid = 0;
            }
        }

        /* Exactly one @ */
        if (atCount != 1)
        {
            valid = 0;
        }

        /* At least one dot */
        if (dotCount < 1)
        {
            valid = 0;
        }

        /* @ or . cannot be first */
        if (email[0] == '@' || email[0] == '.')
        {
            valid = 0;
        }

        /* @ or . cannot be last */
        if (email[strlen(email) - 1] == '@' || email[strlen(email) - 1] == '.')
        {
            valid = 0;
        }

        /* Dot must be after @ */
        if (atPosition != -1)
        {
            int dotAfterAt = 0;

            for (i = atPosition + 1; email[i] != '\0'; i++)
            {
                if (email[i] == '.')
                {
                    dotAfterAt = 1;
                    break;
                }
            }

            if (dotAfterAt == 0)
            {
                valid = 0;
            }
        }

        if (valid)
        {
            break;
        }

        printf("Invalid email format!\n");
        printf("Example: abc@gmail.com\n");
    }

    /* ---------- ADD CONTACT ---------- */

    // Check for duplicate phone number
    while (1)
    {
        int duplicate = 0;

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, addressBook->contacts[addressBook->contactCount].phone) == 0)
            {
                duplicate = 1;
                break;
            }
        }

        if (duplicate)
        {
            printf("Phone number already exists!\n");
            printf("Enter a different phone number: ");
            scanf(" %19[^\n]", addressBook->contacts[addressBook->contactCount].phone);
        }
        else
        {
            break;
        }
    }

    // Check for duplicate email
    while (1)
    {
        int duplicate = 0;

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, addressBook->contacts[addressBook->contactCount].email) == 0)
            {
                duplicate = 1;
                break;
            }
        }

        if (duplicate)
        {
            printf("Email already exists!\n");
            printf("Enter a different email: ");
            scanf(" %49[^\n]", addressBook->contacts[addressBook->contactCount].email);
        }
        else
        {
            break;
        }
    }
    addressBook->contactCount++; // Increase contact count after adding the contact

    printf("\nContact created successfully.\n");

    /* Define the logic to create a Contacts */
}

void searchContact(AddressBook *addressBook) // function defination
{
    int choice;
    char search[50];

    printf("\n===== Search Contact =====\n");
    printf("1. Search by Name\n");
    printf("2. Search by Phone\n");
    printf("3. Search by Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1: // Search by name
    {
        int found = 0;

        printf("Enter name: ");
        scanf(" %49[^\n]", search);

        // Find all contacts with the same name
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcasecmp(search, addressBook->contacts[i].name) == 0)
            {
                printf("\nContact Found!\n");
                printf("-------------------------\n");
                printf("S.No  : %d\n", i + 1);
                printf("Name  : %s\n", addressBook->contacts[i].name);
                printf("Phone : %s\n", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);
                printf("-------------------------\n");

                found = 1;
            }
        }

        if (!found)
        {
            printf("\nContact not found.\n");
        }

        break;
    }

    case 2: // Search by phone
        printf("Enter phone: ");
        scanf(" %[^\n]", search);

        // Compare the entered phone number with contact phone numbers
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(search, addressBook->contacts[i].phone) == 0)
            {
                // Display the contact if found
                printf("\nContact Found!\n");
                printf("-------------------------\n");
                printf("Name  : %s\n", addressBook->contacts[i].name);
                printf("Phone : %s\n", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);
                printf("-------------------------\n");
                return;
            }
        }

        printf("\nContact not found.\n");
        break;

    case 3: // Search by email
        printf("Enter email: ");
        scanf(" %[^\n]", search);

        // Compare the entered email with contact emails
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(search, addressBook->contacts[i].email) == 0)
            {
                // Display the contact if found
                printf("\nContact Found!\n");
                printf("-------------------------\n");
                printf("Name  : %s\n", addressBook->contacts[i].name);
                printf("Phone : %s\n", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);
                printf("-------------------------\n");
                return;
            }
        }

        printf("\nContact not found.\n");
        break;

    default: // Otherwise invalid choice
        printf("\nInvalid choice! Please select 1, 2, or 3.\n");
    }
    /* Define the logic for search */
}

void editContact(AddressBook *addressBook) // function defination
{
    int choice;
    int index = -1;
    char search[50];

    printf("\n===== Edit Contact =====\n");
    printf("1. Edit by Name\n");
    printf("2. Edit by Phone\n");
    printf("3. Edit by Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    /* ---------- SEARCH CONTACT ---------- */

    switch (choice)
    {
    case 1: // Find contact by name
    {
        int count = 0;
        int selected;

        printf("Enter name: ");
        scanf(" %49[^\n]", search);

        // Find all contacts with the same name
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcasecmp(search, addressBook->contacts[i].name) == 0)
            {

                printf("\n%d. %s | %s | %s\n\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

                count++;
            }
        }

        if (count == 0)
        {
            index = -1;
            break;
        }

        // If more than one contact has the same name
        if (count > 1)
        {
            printf("Enter index of contact to edit: ");
            scanf("%d", &selected);

            // Check selected index
            if (selected < 1 || selected > addressBook->contactCount ||
                strcasecmp(search, addressBook->contacts[selected - 1].name) != 0)
            {
                printf("Invalid index.\n");
                return;
            }
            index = selected - 1;
        }
        else
        {
            // Only one contact found
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcasecmp(search, addressBook->contacts[i].name) == 0)
                {
                    index = i;
                    break;
                }
            }
        }
        break;
    }

    case 2: // Find contact by phone
        printf("Enter phone: ");
        scanf(" %49[^\n]", search);

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(search, addressBook->contacts[i].phone) == 0)
            {
                index = i;
                break;
            }
        }
        break;

    case 3: // Find contact by email
        printf("Enter email: ");
        scanf(" %49[^\n]", search);

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(search, addressBook->contacts[i].email) == 0)
            {
                index = i;
                break;
            }
        }
        break;

    default: // Otherwise invalid choice
        printf("\nInvalid choice!\n");
        return;
    }

    /* ---------- CONTACT NOT FOUND ---------- */

    if (index == -1)
    {
        printf("\nContact not found.\n");
        return;
    }

    /* ---------- DISPLAY CONTACT ---------- */

    printf("\nContact Found!\n");
    printf("-------------------------\n");
    printf("Name  : %s\n", addressBook->contacts[index].name);
    printf("Phone : %s\n", addressBook->contacts[index].phone);
    printf("Email : %s\n", addressBook->contacts[index].email);
    printf("-------------------------\n");

    /* ---------- WHAT TO EDIT ---------- */

    int editChoice;

    printf("\nWhat do you want to edit?\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");
    scanf("%d", &editChoice);

    /* ---------- EDIT NAME ---------- */

    if (editChoice == 1)
    {
        char newName[50];

        while (1)
        {
            printf("Enter new name: ");
            scanf(" %49[^\n]", newName);

            int valid = 1;

            /* No leading space */
            if (newName[0] == ' ')
            {
                valid = 0;
            }

            /* No trailing space */
            if (newName[strlen(newName) - 1] == ' ')
            {
                valid = 0;
            }

            /* Only alphabets and spaces */
            for (int i = 0; newName[i] != '\0'; i++)
            {
                if (!((newName[i] >= 'A' && newName[i] <= 'Z') || (newName[i] >= 'a' && newName[i] <= 'z') || newName[i] == ' '))
                {
                    valid = 0;
                    break;
                }
            }

            if (valid)
            {
                strcpy(addressBook->contacts[index].name, newName);
                printf("\nName updated successfully.\n");
                break;
            }

            printf("Invalid name!\n");
            printf("Name should contain only alphabets and spaces.\n");
        }
    }

    /* ---------- EDIT PHONE ---------- */

    else if (editChoice == 2)
    {
        char newPhone[20];

        while (1)
        {
            printf("Enter new phone: ");
            scanf(" %19[^\n]", newPhone);

            int valid = 1;

            /* Exactly 10 digits */
            if (strlen(newPhone) != 10)
            {
                valid = 0;
            }

            /* First digit must be 6-9 */
            if (newPhone[0] < '6' || newPhone[0] > '9')
            {
                valid = 0;
            }

            /* Check digits */
            for (int i = 0; newPhone[i] != '\0'; i++)
            {
                if (newPhone[i] < '0' || newPhone[i] > '9')
                {
                    valid = 0;
                    break;
                }
            }

            if (!valid)
            {
                printf("Invalid phone number!\n");
                printf("Phone must contain exactly 10 digits and start with 6, 7, 8 or 9.\n");
                continue;
            }

            /* Check duplicate phone */
            int duplicate = 0;

            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (i != index && strcmp(newPhone, addressBook->contacts[i].phone) == 0)
                {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate)
            {
                printf("Phone number already exists!\n");
                continue;
            }

            strcpy(addressBook->contacts[index].phone, newPhone);

            printf("\nPhone updated successfully.\n");
            break;
        }
    }

    /* ---------- EDIT EMAIL ---------- */

    else if (editChoice == 3)
    {
        char newEmail[50];

        while (1)
        {
            printf("Enter new email: ");
            scanf(" %49[^\n]", newEmail);

            int valid = 1;
            int atCount = 0;
            int dotCount = 0;
            int atPosition = -1;

            /* Check email characters */
            for (int i = 0; newEmail[i] != '\0'; i++)
            {
                if (newEmail[i] == '@')
                {
                    atCount++;
                    atPosition = i;
                }

                if (newEmail[i] == '.')
                {
                    dotCount++;
                }

                /* No spaces */
                if (newEmail[i] == ' ')
                {
                    valid = 0;
                }
            }

            /* Exactly one @ */
            if (atCount != 1)
            {
                valid = 0;
            }

            /* At least one dot */
            if (dotCount < 1)
            {
                valid = 0;
            }

            /* Cannot start with @ or . */
            if (newEmail[0] == '@' || newEmail[0] == '.')
            {
                valid = 0;
            }

            /* Cannot end with @ or . */
            if (newEmail[strlen(newEmail) - 1] == '@' || newEmail[strlen(newEmail) - 1] == '.')
            {
                valid = 0;
            }

            /* Dot must come after @ */
            if (atPosition != -1)
            {
                int dotAfterAt = 0;

                for (int i = atPosition + 1; newEmail[i] != '\0'; i++)
                {
                    if (newEmail[i] == '.')
                    {
                        dotAfterAt = 1;
                        break;
                    }
                }

                if (dotAfterAt == 0)
                {
                    valid = 0;
                }
            }

            if (!valid)
            {
                printf("Invalid email format!\n");
                printf("Example: abc@gmail.com\n");
                continue;
            }

            /* Check duplicate email */
            int duplicate = 0;

            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (i != index && strcmp(newEmail, addressBook->contacts[i].email) == 0)
                {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate)
            {
                printf("Email already exists!\n");
                continue;
            }

            strcpy(addressBook->contacts[index].email, newEmail);

            printf("\nEmail updated successfully.\n");
            break;
        }
    }
    else
    {
        printf("\nInvalid edit choice!\n");
        return;
    }

    /* ---------- DISPLAY UPDATED CONTACT ---------- */

    printf("\nUpdated Contact Details:\n");
    printf("-------------------------\n");
    printf("Name  : %s\n", addressBook->contacts[index].name);
    printf("Phone : %s\n", addressBook->contacts[index].phone);
    printf("Email : %s\n", addressBook->contacts[index].email);
    printf("-------------------------\n");

    /* Define the logic for Editcontact */
}

void deleteContact(AddressBook *addressBook) // function defination
{
    int choice;
    int index = -1;
    char search[50];

    printf("\n===== Delete Contact =====\n");
    printf("1. Delete by Name\n");
    printf("2. Delete by Phone\n");
    printf("3. Delete by Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    /* ---------- SEARCH CONTACT ---------- */

    switch (choice)
    {
    case 1: // Delete by name
    {
        int count = 0;
        int selected;

        printf("Enter name: ");
        scanf(" %49[^\n]", search);

        // Find all contacts with the same name
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcasecmp(search, addressBook->contacts[i].name) == 0)
            {
                printf("\n%d. %s | %s | %s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

                count++;
            }
        }

        if (count == 0)
        {
            index = -1;
            break;
        }

        // If multiple contacts have the same name
        if (count > 1)
        {
            printf("\nEnter index of contact to delete: ");
            scanf("%d", &selected);

            // Check selected index
            if (selected < 1 || selected > addressBook->contactCount || strcasecmp(search, addressBook->contacts[selected - 1].name) != 0)
            {
                printf("Invalid index.\n");
                return;
            }

            index = selected - 1;
        }
        else
        {
            // Only one contact found
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcasecmp(search, addressBook->contacts[i].name) == 0)
                {
                    index = i;
                    break;
                }
            }
        }
        break;
    }

    case 2: // Search by phone
        printf("Enter phone: ");
        scanf(" %49[^\n]", search);

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(search, addressBook->contacts[i].phone) == 0)
            {
                index = i;
                break;
            }
        }
        break;

    case 3: // Search by email
        printf("Enter email: ");
        scanf(" %49[^\n]", search);

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(search, addressBook->contacts[i].email) == 0)
            {
                index = i;
                break;
            }
        }
        break;

    default:
        printf("\nInvalid choice!\n");
        return;
    }

    /* ---------- CONTACT NOT FOUND ---------- */

    // Check if contact was not found
    if (index == -1)
    {
        printf("\nContact not found.\n");
        return;
    }

    /* ---------- DISPLAY CONTACT ---------- */

    printf("\nContact Found!\n");
    printf("-------------------------\n");
    printf("Name  : %s\n", addressBook->contacts[index].name);
    printf("Phone : %s\n", addressBook->contacts[index].phone);
    printf("Email : %s\n", addressBook->contacts[index].email);
    printf("-------------------------\n");

    /* ---------- CONFIRM DELETE ---------- */

    char confirm;

    printf("Are you sure you want to delete this contact? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') // Check delete confirmation
    {
        /* Shift contacts to the left */

        for (int i = index; i < addressBook->contactCount - 1; i++) // Move contacts one position left
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1]; // Replace deleted contact
        }

        addressBook->contactCount--;

        printf("\nContact deleted successfully.\n");
    }
    
    else
    {
        printf("\nDelete operation cancelled.\n");
    }
    /* Define the logic for deletecontact */
}
