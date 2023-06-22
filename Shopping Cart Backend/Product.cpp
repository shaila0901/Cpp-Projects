#ifndef PRODUCT_H
#define PRODUCT_H

#include<string>
#include<unordered_map>

using namespace std;

class Product
{
    public:
        Product() {}

        virtual ~Product() {}

        Product(int u_id, string name,int price)
        {
            id = u_id;
            this->name = name;
            this->price = price;
        }

        string getDisplayName()
        {
            return name + " : Rs " + to_string(price) + "\n";
        }

        string getShortName()
        {
            return name.substr(0,1);
        }

        friend class Item;
        friend class Cart;

    private:

        int id;
        string name;
        int price;
};

#endif // PRODUCT_H

