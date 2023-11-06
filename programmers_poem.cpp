#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <unordered_map>
#include <utility>
#include <unordered_set>

// using namespace std;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string temp;
    std::getline(std::cin, temp);
    // get lines of ryhming words
    std::vector<std::string> rhyming_words_lines;
    for (int8_t i = 0; i < n; ++i)
    {
        std::string temp_string;
        std::getline(std::cin, temp_string);
        rhyming_words_lines.push_back(temp_string);
    }
    std::getline(std::cin, temp);

    // get lines of poem
    std::vector<std::string> poem_lines;
    for (int8_t i = 0; i < m; ++i)
    {
        std::string temp_string;
        std::getline(std::cin, temp_string);
        poem_lines.push_back(temp_string);
    }

    std::vector<std::set<std::string>> rhyming_words;
    for (auto &i : rhyming_words_lines) {
        std::istringstream iss(i);
        std::set<std::string> temp_words;
        std::string temp_word;
        while (std::getline(iss, temp_word, ' ')) {
            temp_words.insert(temp_word);
        }
        rhyming_words.push_back(temp_words);
    }
    // for (auto &i : rhyming_words) {
    //     for (auto &j : i) {
    //         std::cout << j << "  ";
    //     }
    //     std::cout << (i.contains("fuck") ? "has it" : "shit") << "\n";
    //     std::cout << "\n";
    // }
    std::vector<std::string> end_poem_lines;
    for (auto &i : poem_lines) {
        std::istringstream iss(i);
        std::string temp_word;
        while (std::getline(iss, temp_word, ' ')) {}
        end_poem_lines.push_back(temp_word);
    }
    for (auto &i : end_poem_lines) {
        for (auto &j : i) 
            j = tolower(j);
    }

    std::vector<std::pair<std::set<std::string>, int>> temp_vals;
    for (size_t i = 0; i < rhyming_words.size(); ++i) {
        std::pair<std::set<std::string>, int> temp_pair;
        temp_pair.first = rhyming_words[i];
        temp_pair.second = i+1;
        // rhyming_words[i], i
        temp_vals.push_back(temp_pair);
    }
    // for (auto &i : temp_vals)
    //     std::cout << i.second << "\n";

    std::vector<int> rhyming_pattern;
    for (auto &i : end_poem_lines) {
        int done = 0;
        for (size_t j=0; j < rhyming_words.size(); ++j) {
            if (rhyming_words[j].contains(i)) {
                rhyming_pattern.push_back(temp_vals[j].second);
                done = 1;
                break;
            // } else {
            //     rhyming_pattern.push_back(-1);
            //     break;
            }
        }
        if (!done)
            rhyming_pattern.push_back(-1);
    }
    // for (auto &i : rhyming_pattern)
    //     std::cout << i << "\n";
    
    char temp_char = '-';
    std::unordered_map<std::string, std::pair<char, int>> output;
    for (auto &i : rhyming_pattern) {
        if (!output.contains(std::to_string(i))) {
            // if (temp_char == 'X')
            //     temp_char++;
            if (i==-1) {
                output.insert(std::make_pair(std::to_string(i), std::make_pair('X', 0)));
            } else {
                output.insert(std::make_pair(std::to_string(i), std::make_pair(temp_char, 1)));
                // temp_char++;
            }
        } else {
            output[std::to_string(i)].second++;
        }
    }
    
    // std::unordered_map<std::string, int> final_output;
    for (auto &i : rhyming_pattern) {
        // auto test = output[];
        if (output[std::to_string(i)].second == 1) {
            output[std::to_string(i)].first = 'X';
        }
    }

    temp_char = 'A';
    for (auto &i : rhyming_pattern) {
        if (temp_char == 'X')
            temp_char++;
        if (output[std::to_string(i)].first == '-') {
            output[std::to_string(i)].first = temp_char;
            temp_char++;
        }
    }

    
    for (auto &[key, value] : output) {
        if (temp_char == 'X')
            temp_char++;
        if (value.first == '-') {
            value.first = temp_char;
            temp_char++;
        }
    }

    
    // auto print_key_value = [](const auto& key, const std::pair<char, int>& value)
    // {
    //     std::cout << "Key:[" << key << "] Value:[" << value.first << " | " << value.second << "]\n";
    // };
    // for (const auto &[key, value]: output)
    //     print_key_value(key, value);

    for (auto &i : rhyming_pattern)
        std::cout << output[std::to_string(i)].first;


}