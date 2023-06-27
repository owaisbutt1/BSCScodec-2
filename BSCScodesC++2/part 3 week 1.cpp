#include <iostream>
#include <vector>
#include <string>
/** function prototype*/
std::vector<std::string> tokenise(std::string csvLine, char separator);
/** function implementation */
std::vector<std::string> tokenise(std::string csvLine, char separator) {
	std::vector<std::string> tokens;
// put your implementation of the pseudocode here!
	return tokens;
}
int main() {
	std::string s = "hello,I,have three tokens";
	std::vector<std::string> tokens = tokenise(s, ',');
// note the use of const and & below
// const says I won't edit t
// & says I don't want to copy t from one of the tokens
// I want to access the original version of the token
	for (const std::string& t : tokens) {
		std::cout << t << std::endl;
	}
}