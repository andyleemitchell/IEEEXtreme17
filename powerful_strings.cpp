#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

void constructStrings(const std::vector<std::string>& substrings, int n, std::vector<std::string>& result) {
    for (const std::string& s1 : substrings) {
        for (const std::string& s2 : substrings) {
            if (s1.back() == s2.front()) {
                std::string generatedString = s1 + s2;
                if (generatedString.length() == n) {
                    result.push_back(generatedString);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    string temp;
    vector<string> substrings;
    getline(cin, temp);
    for (int8_t i = 0; i < m; ++i)
    {
        string temp_string;
        getline(cin, temp_string);
        substrings.push_back(temp_string);
    }
    for(auto &i : substrings)
    {
        cout << i << endl;
    }
    // std::vector<std::string> result;
    // constructStrings();
    return 0;
}