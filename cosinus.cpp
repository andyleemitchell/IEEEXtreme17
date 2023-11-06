#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <limits>

#define PI 3.141592653589793238462643383279502884197169399375105820974944

// using namespace std;

inline double toRadians(double angle_deg) {
    return angle_deg * (PI / 180);
}

double objectiveFunction(double a, int n) {
    return std::abs(cos(toRadians(n * a)));
}

uint64_t minimizeN(double a) {
    uint64_t min_n = 0;
    for(int k=0; k < 1000; k++) {
        int temp = 90 + 180*k;
        if (temp%((int)a) == 0) {
            min_n = temp/a;
            break;
        }
    }
    if (min_n == 0) {
        
    }

    return min_n;
}

int main() {
    int n;

    std::vector<float> mynumbers;

    std::cin >> n;
    
    for (int8_t i = 0; i < n; ++i)
    {
        float temp_num;
        std::cin >> temp_num;
        mynumbers.push_back(temp_num);
    }

    for(auto &i : mynumbers)
    {
        std::cout << minimizeN(i) << std::endl;
        // std::cout << PI/() << std::endl;
    }

    // std::cout << std::abs(cos(toRadians(90 * 1)));


    return 0;
}