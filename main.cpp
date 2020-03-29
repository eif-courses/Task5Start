#include <iostream>
#include <list>
#include <utility>

using namespace std;

class Product {
public:
  Product(string name, string description, double price) {
    this->name = std::move(name);
    this->description = std::move(description);
    this->price = price;
  }

  const string &getName() const {
    return name;
  }

  const string &getDescription() const {
    return description;
  }

  double getPrice() const {
    return price;
  }

  void setDescription(const string &description) {
    Product::description = description;
  }

private:
  string name;
  string description;
  double price;
};

class Shop {
public:
  Shop(const string &name) : name(name) {}

  void addProduct(Product &product) {
    this->products.push_back(product);
  }
  list<Product> getProducts(){
    return this->products;
  }
  list<Product> getOrderedProducts(bool isAscending){
    // true -> 1, 2, 3, 4
    // false -> 4, 3, 2, 1
    if(isAscending){
      // p1 = 1, p2 = 2;
      // p1 - p2 = 1 - 2 = -1; // p1 < p2
      products.sort([](Product & p1, Product & p2){ return p1.getName() < p2.getName();});
    } else{
      products.sort([](Product & p1, Product & p2){ return p1.getName() > p2.getName();});
    }
    return this->products;
  }
  void searchPriceByComputerName(const string & n){
    for(Product &p: products){
      if(p.getName() == n){
        cout << p.getName() << "Price: " << p.getPrice();
      }
    }
  }



private:
  string name;
  list<Product> products;


};


int main() {

  Product dell("Dell",
               "Dell Inspiron N7110 8GB RAM, I7 7500k, Nvidia RTX 2080, NVme 1TB SSD",
               1500.00);
  Product lenovo("Lenovo",
               "Lenovo 5X 8GB RAM, I7 7500k, Nvidia RTX 2080, NVme 1TB SSD",
               1350.00);
  Product acer("Acer",
               "Acer Predator 32GB RAM, I9 9500k, Nvidia RTX 2080, NVme 1TB SSD",
               1900.00);

  Shop elektromarkt("Elektromarkt");
  Shop waltmart("Waltmart");
  Shop varle("Varle");

  elektromarkt.addProduct(dell);
  elektromarkt.addProduct(dell);
  elektromarkt.addProduct(acer);
  elektromarkt.addProduct(lenovo);

  cout<< "=============ORIGINAL==================="<< endl;

  for(Product &p: elektromarkt.getProducts())
    cout << p.getDescription() << endl;

  cout<< "=============ASCENDING==================="<< endl;

  for(Product &p: elektromarkt.getOrderedProducts(true))
    cout << p.getDescription() << endl;

  cout<< "===============DESCENDING================="<< endl;

  for(Product &p: elektromarkt.getOrderedProducts(false))
    cout << p.getDescription() << endl;

  cout << "FIND PRODUCT PRICE BY NAME:";

  string keyword;
  cin >> keyword;

  elektromarkt.searchPriceByComputerName(keyword);





  return 0;
}
