#include<iostream>
using namespace std;

class Product{
private:
    int productId;
    string name;
    double price;
    int quantity;

public:
    void acceptDetails(){
        cout << "Enter ProductId:";
        cin >> productId;
        cout << "Enter Product Name:" ;
        cin >> name;
        cout << "Enter price:" ;
        cin >> price;
        cout<< "Enter Quantity:" ;
        cin >> quantity;
    }

    void displayDetails() const {
    cout << productId << " "
         << name << " "
         << price << " "
         << quantity << endl;
    }

    double totalValue() const {
    return price * quantity;
    }

   bool isLowStock(int threshold) const {
    return quantity < threshold;
}
};

// Function 1: Integer quantity
double reorderCost(int qty, double unitPrice)
{
    return qty * unitPrice;
}

// Function 2: Fractional quantity
double reorderCost(double qty, double unitPrice)
{
    return qty * unitPrice;
}

// Function 3: Integer quantity with tax
double reorderCost(int qty, double unitPrice, double taxRate)
{
    double cost = qty * unitPrice;
    double tax = cost * taxRate / 100;

    return cost + tax;
}

// Function with default argument
double applyDiscount(double price, double discountPercent = 10.0)
{
    double discount = price * discountPercent / 100;

    return price - discount;
}
int main(){
    
    // 1. Array of 5 Product objects on stack
    Product products[5];

    // 2. Accept details for all 5 products
    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter details for Product " << i + 1 << ":\n";
        products[i].acceptDetails();
    }

    // 3. Display all products
    cout << "\n===== INVENTORY REPORT =====\n";

    for (int i = 0; i < 5; i++)
    {
        products[i].displayDetails();
    }

    // 4. Find product with highest total value
    int highestIndex = 0;

    for (int i = 1; i < 5; i++)
    {
        if (products[i].totalValue() > products[highestIndex].totalValue())
        {
            highestIndex = i;
        }
    }

    cout << "\nHighest Value Product:\n";
    products[highestIndex].displayDetails();

    // 5. Enter stock threshold
    int threshold;

    cout << "\nEnter stock threshold: ";
    cin >> threshold;

    // 6. Display low-stock products
    cout << "\nLow Stock Products (Threshold: "
         << threshold << "):\n";

    for (int i = 0; i < 5; i++)
    {
        if (products[i].isLowStock(threshold))
        {
            products[i].displayDetails();
        }
    }

     // Calling reorderCost(int, double)
    double cost1 = reorderCost(10, 50.0);

    // Calling reorderCost(double, double)
    double cost2 = reorderCost(5.5, 100.0);

    // Calling reorderCost(int, double, double)
    double cost3 = reorderCost(10, 50.0, 18.0);

    // Calling applyDiscount() with default 10%
    double discount1 = applyDiscount(1000);

    // Calling applyDiscount() with custom discount
    double discount2 = applyDiscount(1000, 20.0);

    // Display results
    cout << "===== REORDER COST =====" << endl;

    cout << "Integer Quantity Cost: "
         << cost1 << endl;

    cout << "Fractional Quantity Cost: "
         << cost2 << endl;

    cout << "Cost with Tax: "
         << cost3 << endl;

    cout << "\n===== DISCOUNT =====" << endl;

    cout << "Default 10% Discount: "
         << discount1 << endl;

    cout << "Custom 20% Discount: "
         << discount2 << endl;

    return 0;
}
    