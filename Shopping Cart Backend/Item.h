#ifndef ITEM_H
#define ITEM_H

#include<string>
#include<unordered_map>

using namespace std;

class Item
{
    public:
        Item() {}

        virtual ~Item() {}

        Item(Product p, int q):product(p), quantity(q){}

        int getItemPrice()
        {
            return quantity * product.price;
        }

        string getItemInfo()
        {
            return to_string(quantity) + " x " + product.name + " Rs. " + to_string(quantity * product.price) + "\n";
        }

        friend class Cart;

    private:
        Product product;
        int quantity;
};

#endif // ITEM_H
