#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::vector<OrderBookEntry> people;

    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        int age;
        double score;

        if (iss >> name >> age >> score) {
            people.emplace_back(name, age, score);
        } else {
            std::cerr << "Invalid line: " << line << std::endl;
        }
    }

    file.close();

    // Print summary statistics
    std::cout << "Number of valid lines: " << people.size() << std::endl;

    // Display information of each person
    for (const Person& person : people) {
        person.displayInfo();
    }

    return 0;
}

