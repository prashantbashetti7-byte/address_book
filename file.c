
#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fptr;

    /* Open file for writing */
    fptr = fopen("contacts.txt", "w");

    /* Check file opening */
    if (fptr == NULL)
    {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    /* Store all contacts */
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%d,%s,%s,%s\n",
                i + 1,
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fptr);

    printf("Contacts saved successfully.\n");
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fptr;

    /* Open file for reading */
    fptr = fopen("contacts.txt", "r");

    /* Check file opening */
    if (fptr == NULL)
    {
        printf("No contacts file found.\n");
        addressBook->contactCount = 0;
        return;
    }

    /* Start with zero contacts */
    addressBook->contactCount = 0;

    /* Read contacts until end of file */
    while (addressBook->contactCount < MAX_CONTACTS)
    {
        if (fscanf(fptr,
                   "%*d,%49[^,],%19[^,],%49[^\n]\n",
                   addressBook->contacts[addressBook->contactCount].name,
                   addressBook->contacts[addressBook->contactCount].phone,
                   addressBook->contacts[addressBook->contactCount].email) != 3)
        {
            break;
        }

        addressBook->contactCount++;
    }

    fclose(fptr);

    printf("Contacts loaded successfully.\n");
}
