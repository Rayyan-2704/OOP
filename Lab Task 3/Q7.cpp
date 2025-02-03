#include <iostream>
#include <string>
using namespace std;

class Shop{
    string items[100];
    float prices[100];
    int counter = 0;

public:
    void add(){
        int n;
        cout << "Enter the number of items to add: ";
        cin >> n;

        for(int i=0 ; i<n ; i++){
            cout << "Enter item name: ";
            cin >> items[counter];
            cout << "Enter the price of the item: ";
            cin >> prices[counter];
            counter++;
        }
    }

    void edit(){
        string temp;
        cout << "Enter the name of the item you want to edit the price for: ";
        cin >> temp;

        int flag = 0;
        for(int i=0 ; i<counter ; i++){
            if(items[i] == temp){
                float newPrice;
                cout << "Item found. Enter the new price of the item: ";
                cin >> newPrice;
                prices[i] = newPrice;
                flag = 1;
                cout << "Price updated successfully" << endl;
                break;
            }
        }
        
    if(!(flag)){
        cout << "Item not found!" << endl;
    }
    }

    void display(){
        cout << endl << "Displaying all the items and their prices below" << endl;
        for(int i=0 ; i<counter ; i++){
            cout << "Item " << (i+1) << ": " << items[i] << " | " << "Price: $" << prices[i] << endl;
        }
    }
};

int main(){
    Shop s1;
    s1.add();
    s1.display();
    s1.edit();
    s1.display();
    return 0;
}