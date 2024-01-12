// Title : User shopping cart
// Author : Priyanka Verma
// RegNo : 21MCME01
// Created : 05/01/24
// Last Modified : -

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

struct StoreItem {
    char itemName[50];
    int quantity;
    float price;
};

struct CartItem {
    char itemName[50];
    int quantity;
    float price;
};

void displayItems(char* filename);
void addToCart(char* itemName, int quantity);
void checkoutAndSaveOrders();
float getPriceFromStoreItems(char* itemName);
void addNewItem(char* itemName, int quantity, float price);
void displayAllOrders();
void updateQuantityInStoreItems(char* itemName, int quantityChange);


#endif