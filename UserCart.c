// Title : User shopping cart
// Author : Priyanka Verma
// RegNo : 21MCME01
// Created : 05/01/24
// Last Modified : -

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "StoreActions.h" 


int main()
{

    int option;
    char itemName[50];
    int quantity;
    printf("Welcome To the Store! \n");

    //Menu action
    do
    {
        printf("Choose any of the following actions : \n");
        printf("1. Display Items \n");
        printf("2. Add Items \n");
        printf("3. Update Quantity \n");
        printf("4. Checkout \n");
        printf("5. Exit \n");
        printf("Please choose your desired action : ");    //choosing the desired action
        scanf("%d", &option);

        switch (option)
        {
        case 1 :
            printf("***************************** \n");
            displayItems("StoreItems");
            printf("***************************** \n");
            break;
        case 2 :
            printf("***************************** \n");
            printf("Enter the name of the item to add to the cart: ");
            scanf("%s", itemName);

            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            
            addToCart(itemName, quantity);
            printf("***************************** \n");
            break;
        case 4:
            printf("***************************** \n");
            checkoutAndSaveOrders();
            printf("***************************** \n");
            break;
        case 5 :
            system("/Users/priyankaverma/Desktop/SE_LAB/shop"); 
            break;
        default:
            break;
        }
    }while (option != 5);

    return 0;
    
}