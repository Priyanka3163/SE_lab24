// Title : User shopping cart
// Author : Priyanka Verma
// RegNo : 21MCME01
// Created : 05/01/24
// Last Modified : -

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

struct CartItem {
    char itemName[50];
    int quantity;
    float price;
};

void DisplayItems(char* filename);
void addToCart(char* itemName, int quantity);

#endif