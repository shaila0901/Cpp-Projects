#ifndef CART_H
#define CART_H

#include<string>
#include<unordered_map>

using namespace std;

class Cart
{
    public:
        Cart() {}

        virtual ~Cart() {}

        void addProduct(Product product)
        {
            if(items.count(product.id)==0)
            {
                Item newItem(product,1);
                items[product.id] = newItem;
            }
            else
            {
                items[product.id].quantity += 1;
            }
        }

        int getTotal()
        {
		//Todo
            int total = 0;
            for(auto itemPair : items)
            {
                auto item = itemPair.second;
                total += item.getItemPrice();
            }
            return total;
        }

        string viewCart()
        {
            if(items.empty())
            {
                return "Cart is empty";
            }

            string itemizedList;
            int cart_total = getTotal();

            for(auto itemPair : items)
            {
                auto item = itemPair.second;
                itemizedList.append(item.getItemInfo());
            }

            return itemizedList + "\n Total Amount : Rs. " + to_string(cart_total) + '\n';
        }
	//later on
        bool isEmpty()
        {
            return items.empty();
        }

    private:
        unordered_map<int,Item> items;;
};

#endif // CART_H
