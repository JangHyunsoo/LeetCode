#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

/*
* Author : Hyunsoo Jang
* GitHub : https://github.com/JangHyunsoo/LeetCode
*/

class Solution389 {
/*
* Runtime : 6ms, 12.47%
* Memory Usagee : 6.6M, 66.85%
*/
public:
    static char findTheDifference(std::string s, std::string t) {
        int sum = 0;
        for (auto c : t) {
            sum += static_cast<int>(c);
        }
        for (auto c : s) {
            sum -= static_cast<int>(c);
        }

        return static_cast<char>(sum);
    }
};

class Solution771 {
/*
* Runtime : 3ms, 40.99%
* Memory Usagee : 6.2M, 59.48%
*/
public:
    static int numJewelsInStones(std::string jewels, std::string stones) {
        int count = 0;
        
        for (auto jewel : jewels) {
            for (auto stone : stones) {
                if (stone == jewel) ++count;
            }
        }

        return count;
    }
};

int main() {

    std::string s{ "abcde" };
    std::string t{ "abcdef" };
    std::cout << "Solution389" << '\n' << Solution389::findTheDifference(s, t) << '\n';
    
    std::cout << "Solution771" << '\n' << Solution771::numJewelsInStones(s, t) << '\n';
}