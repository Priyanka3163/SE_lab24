// Title : User shopping cart
// Author : Priyanka Verma
// RegNo : 21MCME01
// Created : 05/01/24
// Last Modified : -


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store user information
struct User {
    char username[50];
    char password[50];
};

// Function to sign up a new user
void signup() {
    FILE *file;
    struct User user;

    // Open the file in append mode
    file = fopen("users.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter your username: ");
    scanf("%s", user.username);

    printf("Enter your password: ");
    scanf("%s", user.password);

    // Write user information to the file
    fprintf(file, "%s %s\n", user.username, user.password);

    fclose(file);
    printf("User signed up successfully!\n");
}

// Function to check if a user exists and authenticate
int login() {
    FILE *file;
    struct User user;
    char inputUsername[50];
    char inputPassword[50];

    // Open the file in read mode
    file = fopen("users.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter your username: ");
    scanf("%s", inputUsername);

    printf("Enter your password: ");
    scanf("%s", inputPassword);

    // Read user information from the file and check for authentication
    while (fscanf(file, "%s %s", user.username, user.password) == 2) {
        if (strcmp(user.username, inputUsername) == 0 && strcmp(user.password, inputPassword) == 0) {
            fclose(file);
            return 1; // Authentication successful
        }
    }

    fclose(file);
    return 0; // Authentication failed
}

int main() {
    // Declaration of variables
    char inputUsername[50];
    char inputPassword[50];
    char adminUsername[] = "admin";
    char adminPassword[] = "adminpass";
    int choice;

    do {
        printf("1. Sign Up\n");
        printf("2. Login\n");
        printf("3. Seller Login\n");  // New option for seller login
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                if (login()) {
                    printf("Login successful!\n");
                    printf("****************************\n");
                    printf("Loading the Store...\n");
                    system("/Users/priyankaverma/Desktop/SE_LAB/usercart");  
                    exit(0);
                } else {
                    printf("Login failed. Incorrect username or password.\n");
                }
                break;
            case 3:
                printf("Enter seller username: ");
                scanf("%s", inputUsername);

                printf("Enter seller password: ");
                scanf("%s", inputPassword);

                // Checking credentials
                if (strcmp(inputUsername, adminUsername) == 0 && strcmp(inputPassword, adminPassword) == 0) {
                    printf("Seller login successful!\n");
                    system("/Users/priyankaverma/Desktop/SE_LAB/seller");  
                    // Additional actions for seller login
                    exit(0);
                } else {
                    printf("Seller login failed. Incorrect username or password.\n");
                }
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}