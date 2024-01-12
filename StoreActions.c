// Title : User shopping cart
// Author : Priyanka Verma
// RegNo : 21MCME01
// Created : 05/01/24
// Last Modified : -

#include "StoreActions.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int isCheckoutSuccessful = 0;

void displayItems(char* filename) {
    FILE* storeptr;
    char itemName[50];
    int quantity;
    float price;

    storeptr = fopen(filename, "r");

    if (storeptr == NULL) {
        printf("Error opening items file!\n");
        exit(1);
    }

    while (fscanf(storeptr, "%s %d %f", itemName, &quantity, &price) == 3) {
        printf("%s - Quantity: %d, Price: %.2f\n", itemName, quantity, price);
    }

    fclose(storeptr);
}


void addToCart(char* itemName, int quantity) {
    FILE* cartFile;

    // Append the cart file
    cartFile = fopen("cart.txt", "a");

    if (cartFile == NULL) {
        printf("Error opening cart file!\n");
        exit(1);
    }

    fprintf(cartFile, "%s %d\n", itemName, quantity);

    fclose(cartFile);
    printf("Item added to the cart successfully!\n");
}

void checkoutAndSaveOrders() {
    FILE *cartFile = fopen("cart.txt", "r");
    FILE *ordersFile = fopen("orders.txt", "a");
    FILE *storeFile = fopen("StoreItems", "r+");

    if (cartFile != NULL && ordersFile != NULL && storeFile != NULL) {
        char itemName[50];
        int quantity;
        float totalAmount = 0;

        // Display and save order details
        printf("Order Details:\n");

        // Read items from the cart and calculate total amount
        while (fscanf(cartFile, "%s %d", itemName, &quantity) == 2) {
            float price = getPriceFromStoreItems(itemName);

            float itemTotal = price * quantity;
            totalAmount += itemTotal;

            printf("Item: %s, Quantity: %d, Price per item: %.2f, Total: %.2f\n",
                   itemName, quantity, price, itemTotal);

            // Save order details to the orders.txt file
            fprintf(ordersFile, "Item: %s, Quantity: %d, Price per item: %.2f, Total: %.2f\n",
                   itemName, quantity, price, itemTotal);

            // Update quantity in the StoreItems file
            updateQuantityInStoreItems(itemName, quantity);

        }

        // Add 5% tax
        float tax = totalAmount * 0.05;
        totalAmount += tax;

        // Display and save subtotal, tax, and total amount
        printf("Subtotal: %.2f\n", totalAmount - tax);
        printf("Tax (5%%): %.2f\n", tax);
        printf("Total Amount: %.2f\n", totalAmount);

        fprintf(ordersFile, "Subtotal: %.2f\n", totalAmount - tax);
        fprintf(ordersFile, "Tax (5%%): %.2f\n", tax);
        fprintf(ordersFile, "Total Amount: %.2f\n", totalAmount);
        fprintf(ordersFile, "****************************\n");

        fclose(cartFile);
        fclose(ordersFile);
        fclose(storeFile);

        // Clear the cart file only if the quantity is updated successfully
        if (isCheckoutSuccessful) {
            cartFile = fopen("cart.txt", "w");
            if (cartFile != NULL) {
                fclose(cartFile);
                printf("Checkout completed. Orders saved in orders.txt. Cart cleared.\n");
            } else {
                printf("Error opening cart file for clearing.\n");
            }
        }
    } else {
        printf("Error opening cart, orders, or StoreItems file.\n");
    }
}

void addNewItem(char* itemName, int quantity, float price) {
    FILE* storeFile;

    // Append file
    storeFile = fopen("StoreItems", "a");

    if (storeFile == NULL) {
        printf("Error opening StoreItems file!\n");
        exit(1);
    }

    // Add new item
    fprintf(storeFile, "%s %d %.2f\n", itemName, quantity, price);

    fclose(storeFile);
    printf("New item added to StoreItems successfully!\n");
}

void displayAllOrders() {
    FILE *ordersFile = fopen("orders.txt", "r");

    if (ordersFile != NULL) {
        char line[100];  // Adjust the size as needed

        printf("All Order Details:\n");

        // Read and display each line from the orders file
        while (fgets(line, sizeof(line), ordersFile) != NULL) {
            printf("%s", line);
        }

        fclose(ordersFile);
    } else {
        printf("Error opening orders file.\n");
    }
}

void updateQuantityInStoreItems(char* itemName, int quantity) {
    FILE* storeFile = fopen("StoreItems", "r");
    FILE* tempFile = fopen("tempStoreItems", "w");

    if (storeFile != NULL && tempFile != NULL) {
        char storeItemName[50];
        int storeQuantity;
        float price;
        int updatedQuantity = 0;
        int quantityUpdated = 0;

        while (fscanf(storeFile, "%s %d %f", storeItemName, &storeQuantity, &price) == 3) {
            if (strcmp(itemName, storeItemName) == 0) {
                // Ensure the updated quantity is not negative
                updatedQuantity = storeQuantity - quantity;
                if (updatedQuantity < 0) {
                    printf("Error: Quantity cannot be negative. Update canceled.\n");
                    quantityUpdated = 0; // Set to 0 to indicate the update was not successful
                } else {
                    fprintf(tempFile, "%s %d %.2f\n", storeItemName, updatedQuantity, price);
                    quantityUpdated = 1; // Set to 1 to indicate the update was successful
                }
            } else {
                fprintf(tempFile, "%s %d %.2f\n", storeItemName, storeQuantity, price);
            }
        }

        fclose(storeFile);
        fclose(tempFile);

        if (quantityUpdated) {
            remove("StoreItems");
            rename("tempStoreItems", "StoreItems");
            printf("Quantity updated successfully.\n");
            isCheckoutSuccessful = 1; // Set to 1 to indicate successful checkout
        } else {
            isCheckoutSuccessful = 0; // Set to 0 to indicate unsuccessful checkout
        }
    } else {
        printf("Error opening files.\n");
    }
}
