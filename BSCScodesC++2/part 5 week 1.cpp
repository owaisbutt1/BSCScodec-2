#include <string>
#include <map>
class Wallet {
	public:
		Wallet();
		/** insert currency to the wallet */
		void insertCurrency(std::string type, double amount);
		/** remove currency from the wallet */
		bool removeCurrency(std::string type, double amount);
		/** check if the wallet contains this much currency or more */
		bool containsCurrency(std::string type, double amount);
		/** generate a string representation of the wallet */
		std::string toString();
	private:
		std::map<std::string,double> currencies;
};
#include<Wallet.h>
int main() {
	Wallet wallet{};
}
void Wallet::insertCurrency(std::string type, double amount) {
	currencies[type] += balance;
}
int main() {
	Wallet wallet{};
	wallet.insertCurrency("BTC", 1.5);
	std::cout << "Wallet should contain 1.5 BTC now" << std::endl;
	std::cout << wallet << std::endl;
	bool result = wallet.containsCurrency("BTC", 1.5);
	std::cout << "Result should be true " << result << std::endl;
	result = wallet.removeCurrency("BTC", 2.0);
	std::cout << "Result should be false " << result << std::endl;
	result = wallet.removeCurrency("BTC", 1.0);
	std::cout << "Result should be true " << result << std::endl;
}
