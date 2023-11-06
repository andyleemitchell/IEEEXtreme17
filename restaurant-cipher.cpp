#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>


inline int countLetters(std::string test_string, char test_char) {
    int count = 0;
    for (auto &iter : test_string)
        if (iter == test_char)
            count++;
    return count;
}

int main() {

    const std::string recipes[7] = {"A", "B", "C", "D", "E", "F", "G"};

    int n;
    std::cin >> n;
    std::vector<std::string> strings;

    std::string temp;
    std::getline(std::cin, temp);
    
    for (int8_t i = 0; i < n; ++i)
    {
        std::string temp_string;
        std::getline(std::cin, temp_string);
        strings.push_back(temp_string);
    }

    
    std::vector<std::pair<int, std::string>> occurances;

    for (auto &i : strings) {
        for (auto &j : recipes) {
            char test_char = (char)tolower(j[0]);
            occurances.push_back( 
                std::make_pair( countLetters(i, test_char), j ) 
            );
        }

        std::sort(occurances.begin(), occurances.end(), [](auto a, auto b) {return a.first > b.first; });
        std::cout << occurances.front().second << std::endl;
        occurances.clear();
    }

    return 0;
}
