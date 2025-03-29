/*
An E-commerce website provides multiple ways to calculate the total price of a customer's order based on the type of product. There are two main product categories:
1. Electronics: Tax rate 15%
2. Clothing: Tax rate 5%
The website supports different discount methods based on the type of user (Regular or Premium). Additionally, the website allows combining multiple carts and applying arithmetic operations to calculate total prices dynamically.
Task Requirements:
1. Create a base class Product with attributes like productID, price, and a virtual function calculatePrice().
2. Implement two derived classes:
    --> Electronics (Applies 15% tax)
    --> Clothing (Applies 5% tax)
3. Overload the applyDiscount method to handle different discount types:
    --> Percentage discount (e.g., 10% off)
    --> Fixed discount (e.g., $20 off)
    --> Buy One Get One Free
4. Override the calculatePrice method to apply category-specific tax rates.
5. Implement operator overloading for the ShoppingCart class:
    --> + to merge two shopping carts
    --> - to remove an item from the cart
    --> * to apply bulk discounts
    --> / to split cart total among multiple users
6. Create objects for Electronics and Clothing categories, demonstrate method overloading, overriding, and operator overloading by simulating an online shopping experience.
*/

#include <iostream>
using namespace std;

class Product {
protected:
    string productID;
    double price;

public:
    Product(string id, double p) : productID(id), price(p) {}
    virtual ~Product() {}

    virtual double calculatePrice() const = 0;
    virtual void applyDiscount(double percentage) {
        price *= (1 - percentage / 100);
    }
    virtual Product* clone() const = 0;

    string getProductID() const { return productID; }
    double getPrice() const { return price; }
};

class Electronics : public Product {
public:
    Electronics(string id, double p) : Product(id, p) {}
    double calculatePrice() const override { return price * 1.15; }
    void applyDiscount(double percentage) override {
        price *= (1 - percentage / 100);
    }
    Product* clone() const override {
        return new Electronics(*this);
    }
};

class Clothing : public Product {
public:
    Clothing(string id, double p) : Product(id, p) {}
    double calculatePrice() const override { return price * 1.05; }
    void applyDiscount(double percentage) override {
        price *= (1 - percentage / 100);
    }
    Product* clone() const override {
        return new Clothing(*this);
    }
};

class ShoppingCart {
private:
    Product* items[100];
    int itemCount;

public:
    ShoppingCart() : itemCount(0) {}

    ShoppingCart(const ShoppingCart& other) : itemCount(other.itemCount) {
        for (int i = 0; i < itemCount; ++i) {
            items[i] = other.items[i]->clone();
        }
    }

    ~ShoppingCart() {
        for (int i = 0; i < itemCount; ++i) {
            delete items[i];
        }
    }

    void addItem(Product* p) {
        if (itemCount < 100) {
            items[itemCount++] = p->clone();
        }
    }

    void removeItem(int index) {
        if (index < 0 || index >= itemCount) return;
        delete items[index];  // Free memory
        for (int i = index; i < itemCount - 1; ++i) {
            items[i] = items[i + 1];
        }
        itemCount--;
    }

    double totalPrice() const {
        double total = 0;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i]->calculatePrice();
        }
        return total;
    }

    ShoppingCart operator+(const ShoppingCart& other) const {
        ShoppingCart newCart = *this;
        for (int i = 0; i < other.itemCount && newCart.itemCount < 100; ++i) {
            newCart.addItem(other.items[i]);
        }
        return newCart;
    }

    ShoppingCart operator-(int index) const {
        ShoppingCart newCart = *this;
        newCart.removeItem(index);
        return newCart;
    }

    ShoppingCart operator*(double discount) const {
        ShoppingCart newCart;
        for (int i = 0; i < itemCount; ++i) {
            Product* discountedProduct = items[i]->clone();
            discountedProduct->applyDiscount(discount * 100);
            newCart.addItem(discountedProduct);
            delete discountedProduct;
        }
        return newCart;
    }

    double operator/(int users) const {
        return (users > 0) ? totalPrice() / users : 0;
    }

    void displayCart() const {
        for (int i = 0; i < itemCount; ++i) {
            cout << "Item " << i + 1 << ": " << items[i]->getProductID() << " - Price: " << items[i]->calculatePrice() << endl;
        }
        cout << "Total Price: " << totalPrice() << endl;
    }
};

int main() {
    ShoppingCart cart1, cart2;

    cart1.addItem(new Electronics("E001", 1000));
    cart1.addItem(new Clothing("C001", 500));

    cart2.addItem(new Electronics("E002", 800));
    cart2.addItem(new Clothing("C002", 400));

    cout << "Cart 1 Details:\n";
    cart1.displayCart();

    cout << "\nCart 2 Details:\n";
    cart2.displayCart();

    ShoppingCart mergedCart = cart1 + cart2;
    cout << "\nMerged Cart:\n";
    mergedCart.displayCart();

    ShoppingCart removedCart = mergedCart - 1;
    cout << "\nAfter Removing Item from Merged Cart:\n";
    removedCart.displayCart();

    ShoppingCart discountedCart = removedCart * 0.1;
    cout << "\nAfter Applying 10% Discount:\n";
    discountedCart.displayCart();

    double splitAmount = discountedCart / 3;
    cout << "\nEach Person Pays: " << splitAmount << endl;

    return 0;
}
