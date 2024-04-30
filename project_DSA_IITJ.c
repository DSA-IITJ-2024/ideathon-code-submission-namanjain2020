#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50

typedef struct
{
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Item;

void displayMenu();
void addItem(Item cart[], int *numItems);
void removeItem(Item cart[], int *numItems);
void displayCart(Item cart[], int numItems);
float calculateTotal(Item cart[], int numItems);

int main()
{
    Item cart[MAX_ITEMS];
    int numItems = 0;
    int choice;

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addItem(cart, &numItems);
            break;
        case 2:
            removeItem(cart, &numItems);
            break;
        case 3:
            displayCart(cart, numItems);
            break;
        case 4:
            printf("Total: Rs. %.2f\n", calculateTotal(cart, numItems));
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu()
{
    printf("\nShopping Cart Menu\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. View cart\n");
    printf("4. Calculate total\n");
    printf("5. Exit\n");
}

void addItem(Item cart[], int *numItems)
{
    if (*numItems < MAX_ITEMS)
    {
        printf("Enter item name: ");
        scanf("%s", cart[*numItems].name);
        printf("Enter item price: ");
        scanf("%f", &cart[*numItems].price);
        printf("Enter quantity: ");
        scanf("%d", &cart[*numItems].quantity);
        (*numItems)++;
    }
    else
    {
        printf("Cart is full. Cannot add more items.\n");
    }
}

void removeItem(Item cart[], int *numItems)
{
    int index;
    if (*numItems > 0)
    {
        printf("Enter index of item to remove: ");
        scanf("%d", &index);
        if (index >= 0 && index < *numItems)
        {
            for (int i = index; i < *numItems - 1; i++)
            {
                cart[i] = cart[i + 1];
            }
            (*numItems)--;
            printf("Item removed from cart.\n");
        }
        else
        {
            printf("Invalid index. Please try again.\n");
        }
    }
    else
    {
        printf("Cart is empty. Nothing to remove.\n");
    }
}

void displayCart(Item cart[], int numItems)
{
    if (numItems > 0)
    {
        printf("Items in cart:\n");
        for (int i = 0; i < numItems; i++)
        {
            printf("%d. %s - Rs. %.2f - Quantity: %d\n", i + 1, cart[i].name, cart[i].price, cart[i].quantity);
        }
    }
    else
    {
        printf("Cart is empty.\n");
    }
}

float calculateTotal(Item cart[], int numItems)
{
    float total = 0;
    for (int i = 0; i < numItems; i++)
    {
        total += cart[i].price * cart[i].quantity;
    }
    return total;
}
