#include<iostream>
#include<vector>
#include<string>
using namespace std;

//class OrderBookEntry // this is the name of the class
//{
//public: // parts of the class that can be seen from outside
//    string timestamp, product, type;
//    double price,amount; // this is a data member (AKA a variable inside a class)
//    enum class OrderBookType {bid, ask};
//    OrderBookEntry( double _price){
//        price = _price;
//    }
//
//}; 
class OrderBookEntry {
public:
  std::string timestamp;
  std::string tradingPair;
  std::string orderType;
  double price;
  double quantity;

  // Constructor
  OrderBookEntry(const std::string& timestamp, const std::string& tradingPair,
                 const std::string& orderType, double price, double quantity)
      : timestamp(timestamp), tradingPair(tradingPair), orderType(orderType),
        price(price), quantity(quantity) {}
};



double computeAveragePrice(const std::vector<OrderBookEntry>& orderBook) {
  double total = 0.0;
  for (const auto& entry : orderBook) {
    total += entry.price;
  }
  return total / orderBook.size();
}

double computeLowPrice(const std::vector<OrderBookEntry>& orderBook) {
  double lowestPrice = orderBook[0].price;
  for (const auto& entry : orderBook) {
    if (entry.price < lowestPrice) {
      lowestPrice = entry.price;
    }
  }
  return lowestPrice;
}

double computeHighPrice(const std::vector<OrderBookEntry>& orderBook) {
  double highestPrice = orderBook[0].price;
  for (const auto& entry : orderBook) {
    if (entry.price > highestPrice) {
      highestPrice = entry.price;
    }
  }
  return highestPrice;
}

double computePriceSpread(const std::vector<OrderBookEntry>& orderBook) {
  double lowestPrice = orderBook[0].price;
  double highestPrice = orderBook[0].price;
  for (const auto& entry : orderBook) {
    if (entry.price < lowestPrice) {
      lowestPrice = entry.price;
    }
    if (entry.price > highestPrice) {
      highestPrice = entry.price;
    }
  }
  return highestPrice - lowestPrice;
}


int main()
{
	std::vector<OrderBookEntry> orderBook;

    while(true)
    {
        int userOption;
        cout << "1: Print help" << endl;
        cout << "2: Print exchange stats" << endl;
        cout << "3: Place an ask" << endl;
        cout << "4: Place a bid" << endl;
        cout << "5: Print wallet" << endl;
        cout << "6: Continue" << endl;
        cout << "Type in 1-6" << endl;
        cin >> userOption;
        if (userOption == 1)
        {
            cout << "Help - choose options from the menu\nand follow the on screen instructions." << endl;
        }
        else if (userOption == 2)
        {
            cout << "You chose Print exchange stats!" << endl;
        }
        else if (userOption == 3)
        {
            cout << "You chose Place an ask!" << endl;
        }
        else if (userOption == 4)
        {
            cout << "You chose Place a bid!" << endl;
        }
        else if (userOption == 5)
        {
            cout << "You chose Print wallet!" << endl;
        }
        else if (userOption == 6)
        {
            cout << "You chose Continue!" << endl;
        }
        else
        {
            cout << "Warning!\nWrong Choice, Select Again!" << endl;
        }
    }
    
    return 0;
}

