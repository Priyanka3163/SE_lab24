// Title : User shopping cart
// Author : Priyanka Verma
// RegNo : 21MCME01
// Created : 05/01/24
// Last Modified : -

#include "StoreStructures.h"
#include<stdio.h>
#include<stdlib.h>

int DisplayItems(char* filename)
{
    FILE* storeptr;
    char ItemString[100];  

    storeptr = fopen(filename, "r");

    if (storeptr != NULL)
    {
        while (fgets(ItemString, sizeof(ItemString), storeptr) != NULL)
        {
            printf("%s", ItemString);
        }
    }
    else
    {
        printf("No Items found\n");
    }

    fclose(storeptr);
    return 0;
}


void addToCart(char* itemName, int quantity) {
    FILE* cartFile;

    // Open the cart file in append mode
    cartFile = fopen("cart.txt", "a");

    if (cartFile == NULL) {
        printf("Error opening cart file!\n");
        exit(1);
    }

    // Write cart item information to the file
    fprintf(cartFile, "%s %d\n", itemName, quantity);

    fclose(cartFile);
    printf("Item added to the cart successfully!\n");
}