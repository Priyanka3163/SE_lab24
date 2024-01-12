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
    float price;
    printf("Welcome To the Store! \n");

    //Menu action
    do
    {
        printf("Choose any of the following actions : \n");
        printf("1. Display Items \n");
        printf("2. Add Items \n");
        printf("3. Update Quantity (didn't implement) \n");
        printf("4. Display Orders \n");
        printf("5. Exit \n");
        printf("Please choose your desired action : ");    
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

            printf("Enter the price: ");
            scanf("%f", &price);

            addNewItem(itemName,quantity,price);
            printf("***************************** \n");
            break;
        case 4 :
            printf("***************************** \n");
            displayAllOrders();
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