/* You are tasked with building a simple product management system for an online store.
    1. Create a function that allows the addition of a new product to the system. The function should
       take parameters such as product name, price, quantity, and any other relevant details.
    2. Implement a function that takes a product ID as input and displays detailed information about the
       product, including its name, price, quantity in stock, and any other relevant details.
    3. Design a function that enables the update of product information. It should take a product ID as
       well as the new details (e.g., updated price, quantity, etc.) and modify the existing product's
       information accordingly.
    4. Create a function that removes a product from the system based on its product ID. Ensure that
       the inventory is updated after the removal. */

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

typedef struct
{
    char productName[50];
    int productID;
    float price;
    int quantity;
} Product;

void initializeProducts(Product *&p, int &n);
void displayProducts(Product *p, int n);
void searchProduct(Product *p, int n);
void updateProductDetails(Product *p, int n);
void addProduct(Product *&p, int &n);
void removeProduct(Product *&p, int &n);

int main()
{
    int n, choice;
    Product *products = nullptr;

    cout << "------ Welcome to Product Management System ------" << endl;
    cout << "Enter 1 for the initialization of products." << endl;
    cout << "Enter 2 to add a new product to the system." << endl;
    cout << "Enter 3 to display all products and their details." << endl;
    cout << "Enter 4 to search for a product by its product ID." << endl;
    cout << "Enter 5 to update the details of a specific product." << endl;
    cout << "Enter 6 to remove a product from the system based on its product ID." << endl;
    cout << "Enter 7 to exit the program." << endl;

    while (1)
    {
        cout << endl
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            initializeProducts(products, n);
            break;

        case 2:
            addProduct(products, n);
            break;

        case 3:
            displayProducts(products, n);
            break;

        case 4:
            searchProduct(products, n);
            break;

        case 5:
            updateProductDetails(products, n);
            break;

        case 6:
            removeProduct(products, n);
            break;

        case 7:
            cout << "Exiting the program...." << endl;
            if (products != nullptr)
            {
                delete[] products;
            }
            return 0;

        default:
            cout << "Invalid choice entered! Try again." << endl;
        }
    }
}

void initializeProducts(Product *&p, int &n)
{
    cout << "Enter the total number of products to initialize: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of products. Please enter a positive number." << endl;
        return;
    }

    if (p != nullptr)
    {
        delete[] p;
        p = nullptr;
    }

    p = new Product[n];
    for (int i = 0; i < n; i++)
    {
        cout << endl << "Enter the details of product " << (i + 1) << ": " << endl;

        cout << "Enter the product ID: ";
        cin >> p[i].productID;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the product name: ";
        cin.getline(p[i].productName, 50);

        cout << "Enter the price of the product: ";
        cin >> p[i].price;

        cout << "Enter the quantity of the product: ";
        cin >> p[i].quantity;
    }
}

void displayProducts(Product *p, int n)
{
    if (p == nullptr || n <= 0)
    {
        cout << "No products have been initialized yet." << endl;
        return;
    }

    cout << "Displaying details of each product below" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl << "Details of product " << (i + 1) << ": " << endl;
        cout << "Product ID: " << p[i].productID << endl;
        cout << "Product Name: " << p[i].productName << endl;
        cout << "Price: " << fixed << setprecision(2) << p[i].price << endl;
        cout << "Quantity: " << p[i].quantity << endl;
    }
}

void searchProduct(Product *p, int n)
{
    if (p == nullptr || n <= 0)
    {
        cout << "No products have been initialized yet." << endl;
        return;
    }

    int id;
    cout << "Enter the product ID of the product to be searched: ";
    cin >> id;

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].productID == id)
        {
            cout << "Product Found: " << endl;
            cout << "Product ID: " << p[i].productID << endl;
            cout << "Product Name: " << p[i].productName << endl;
            cout << "Price: " << fixed << setprecision(2) << p[i].price << endl;
            cout << "Quantity: " << p[i].quantity << endl;
            flag = 1;
            break;
        }
    }

    if (!(flag))
    {
        cout << "No such product found that corresponds to your search." << endl;
    }
}

void updateProductDetails(Product *p, int n)
{
    if (p == nullptr || n <= 0)
    {
        cout << "No products have been initialized yet." << endl;
        return;
    }

    int id;
    cout << "Enter the product ID of the product to be updated: ";
    cin >> id;

    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (p[i].productID == id)
        {
            flag = 1;
            break;
        }
    }

    if (!(flag))
    {
        cout << "No such product found that corresponds to your search." << endl;
        return;
    }

    cout << endl << "Enter the updated details of product " << (i + 1) << ": " << endl;

    cout << "Enter the updated product ID: ";
    cin >> p[i].productID;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the updated product name: ";
    cin.getline(p[i].productName, 50);

    cout << "Enter the updated price of the product: ";
    cin >> p[i].price;

    cout << "Enter the updated quantity of the product: ";
    cin >> p[i].quantity;

    cout << "Product with product ID (" << id << ") updated successfully." << endl;
}

void addProduct(Product *&p, int &n)
{
    if (p == nullptr || n <= 0)
    {
        cout << "No products have been initialized yet." << endl;
        return;
    }

    Product *newProducts = new Product[n + 1];

    for (int i = 0; i < n; i++)
    {
        newProducts[i] = p[i];
    }

    delete[] p;
    p = newProducts;

    cout << endl << "Enter the details of the new product: " << endl;
    cout << "Enter the product ID: ";
    cin >> p[n].productID;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the product name: ";
    cin.getline(p[n].productName, 50);

    cout << "Enter the price of the product: ";
    cin >> p[n].price;

    cout << "Enter the quantity of the product: ";
    cin >> p[n].quantity;
    cout << "Product with product ID (" << p[n].productID << ") added successfully." << endl;
    n++;
}

void removeProduct(Product *&p, int &n)
{
    if (p == nullptr || n <= 0)
    {
        cout << "No products have been initialized yet." << endl;
        return;
    }

    int id;
    cout << "Enter the product ID of the product to be removed: ";
    cin >> id;

    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (p[i].productID == id)
        {
            flag = 1;
            break;
        }
    }

    if (!(flag))
    {
        cout << "No such product found that corresponds to your search." << endl;
        return;
    }

    Product *newProducts = new Product[n - 1];

    for (int j = 0; j < n; j++)
    {
        if (j == i)
        {
            continue;
        }
        newProducts[j] = p[j];
    }

    delete[] p;
    p = newProducts;
    cout << "Product with product ID (" << id << ") removed successfully." << endl;
    n--;
}
