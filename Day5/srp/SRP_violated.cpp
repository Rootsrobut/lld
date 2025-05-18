#include<iostream>
#include<vector>

using namespace std;

// Product class representing any item of any ECommerce.
class Product {
public:
    string name;
    double price;
    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};


class ShoppingCart {
private:
    vector<Product*> products; 
public:
    void addProduct(Product* p) { 
        products.push_back(p);
    }
    const vector<Product*>& getProducts() { 
        return products;
    } 

    // 1. Calculates total price in cart.
    double calculateTotal() {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }

    // 2. Violating SRP - Prints invoice (Should be in a separate class)
    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : products) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << calculateTotal() << endl;
    }

    // 3. Violating SRP - Saves to DB (Should be in a separate class)
    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);



    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    cart->printInvoice();  
    cart->saveToDatabase(); 
    




  const vector<Product*>& items = cart->getProducts();
  for (auto p : items) {
      cout << p->name << " - Rs " << p->price << endl;
  }
   return 0;
}