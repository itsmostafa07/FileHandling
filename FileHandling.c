#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char service[50];
    char email[50];
    char password[50];
} Account;

void AddAccount()
{
    FILE *file = fopen("accounts.dat", "ab");
    if (file == NULL)
    {
        printf("\nError Opening Accounts File\n");
        return;
    }

    Account new_acc;

    printf("\nEnter New Service: ");
    scanf("%49s", new_acc.service);

    printf("\nEnter Your Email or Username: ");
    scanf("%49s", new_acc.email);

    printf("\nEnter Your Password: ");
    scanf("%49s", new_acc.password);

    fwrite(&new_acc, sizeof(Account), 1, file);

    fclose(file);
    printf("\nAccount Added Successfully!\n");
}

void ViewAccount()
{
    FILE *file = fopen("accounts.dat", "rb");
    if (file == NULL)
    {
        printf("\nError Opening Accounts File\n");
        return;
    }

    char search_service[50];

    printf("\nEnter service name to view: ");
    scanf("%49s", search_service);

    Account acc;

    int found = 0;

    while (fread(&acc, sizeof(Account), 1, file))
    {
        if (strcmp(acc.service, search_service) == 0)
        {
            printf("\nService: %s\nEmail: %s\nPassword: %s\n", acc.service, acc.email, acc.password);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nError! This Service doesn't exist.\n");
    }

    fclose(file);
}

void UpdateAccount()
{
    FILE *file = fopen("accounts.dat", "rb+");

    if (file == NULL) 
    {
        printf("No accounts found!\n\n");
        return;
    }

    Account acc;

    char service[50];
    int found = 0, position;

    printf("Enter service name to update: ");
    scanf("%49s", service);

    while (fread(&acc, sizeof(Account), 1, file)) 
    {
        if (strcmp(acc.service, service) == 0) 
        {
            found = 1;
            position = ftell(file) - sizeof(Account);

            break;
        }
    }

    if (found)
    {
        int choice;

        printf("\n1. Update email\n2. Update password\n3. Both\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 3)
        {
            printf("Enter new email: ");
            scanf("%49s", acc.email);
        }

        if (choice == 2 || choice == 3)
        {
            printf("Enter new password: ");
            scanf("%49s", acc.password);
        }

        fseek(file, position, SEEK_SET);
        fwrite(&acc, sizeof(Account), 1, file);
        printf("Account updated successfully!\n\n");
    }

    else
    {
        printf("Service not found!\n\n");
    }

    fclose(file);
}

void DeleteAccount()
{
    FILE *originalFile, *tempFile;
    Account acc;

    char service[50];
    int found = 0;

    originalFile = fopen("accounts.dat", "rb");
    if (originalFile == NULL)
    {
        printf("No accounts found!\n\n");
        return;
    }

    tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL)
    {
        printf("Error creating temporary file!\n");
        fclose(originalFile);
        return;
    }

    printf("\nEnter service name to delete: ");
    scanf("%49s", service);

    while (fread(&acc, sizeof(Account), 1, originalFile))
    {
        if (strcmp(acc.service, service) == 0)
        {
            found = 1;
        }

        else
        {
            fwrite(&acc, sizeof(Account), 1, tempFile);
        }
    }

    fclose(originalFile);
    fclose(tempFile);

    if (found)
    {
        remove("accounts.dat");
        rename("temp.dat", "accounts.dat");
        printf("Account deleted successfully!\n\n");
    }

    else
    {
        remove("temp.dat");
        printf("Service not found!\n\n");
    }
}

void RenameService()
{
    FILE *file = fopen("accounts.dat", "rb+");
    if (file == NULL)
    {
        printf("No accounts found!\n\n");

        return;
    }

    Account acc;

    char old_name[50], new_name[50];
    int found = 0, position;

    printf("\nEnter current service name: ");
    scanf("%49s", old_name);
    printf("Enter new service name: ");
    scanf("%49s", new_name);

    while (fread(&acc, sizeof(Account), 1, file))
    {
        if (strcmp(acc.service, old_name) == 0)
        {
            found = 1;
            position = ftell(file) - sizeof(Account);

            break;
        }
    }

    if (found)
    {
        strncpy(acc.service, new_name, sizeof(acc.service));

        fseek(file, position, SEEK_SET);
        fwrite(&acc, sizeof(Account), 1, file);

        printf("Service renamed successfully!\n\n");
    }

    else
    {
        printf("Service '%s' not found!\n\n", old_name);
    }

    fclose(file);
}

void ListServices()
{
    FILE *file = fopen("accounts.dat", "rb");
    if (file == NULL)
    {
        printf("\nNo services Found\n\n");

        return;
    }

    Account acc;

    int count = 0;
    int has_services = 0;

    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0)
    {
        printf("\nNo services Found\n\n");
        fclose(file);

        return;
    }
    
    rewind(file);

    printf("\nSaved Services:\n");
    printf("----------------\n");

    while (fread(&acc, sizeof(Account), 1, file))
    {
        printf("%d. %s\n", ++count, acc.service);
        has_services = 1;
    }

    fclose(file);

    if (!has_services)
    {
        printf("No services Found\n");
    }
    printf("\nTotal services: %d\n\n", count);
}

int main()
{
        printf("------------------------------------------------------------------------------------------------------------------------");
        printf("\n\t\t\t\t\t\t   Accounts Manager\n");
        printf("\t\t\t\t\t Your Digital Vault For Your Accounts\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");

    int choice;

    do
    {
        printf("1. Add Account\n");
        printf("2. List Services\n");
        printf("3. View Accounts\n");
        printf("4. Update Account\n");
        printf("5. Delete Account\n");
        printf("6. Rename Service\n");
        printf("7. Exit\n");
        printf("----------------------");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                AddAccount();
                printf("\n----------------------\n");
                break;

            case 2:
                ListServices();
                printf("\n----------------------\n");
                break;

            case 3:
                ViewAccount();
                printf("\n----------------------\n");
                break;

            case 4:
                UpdateAccount();
                printf("\n----------------------\n");
                break;

            case 5:
                DeleteAccount();
                printf("\n----------------------\n");
                break;

            case 6:
                RenameService();
                printf("\n----------------------\n");
                break;

            case 7:
                printf("Exiting...\n");
                printf("\n----------------------\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
                printf("\n----------------------\n");
        }
    } while (choice != 7);

    return 0;
}
