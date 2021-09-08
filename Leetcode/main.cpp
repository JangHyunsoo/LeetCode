#include "common.h"
/*
Author : JangHyunssoo
Group : Koreatech
Git Url
*/

class Solution389 {
/*
Author : JangHyunssoo
Group : Koreatech
Email : hunsoo911@gmail.com
*/
public:
    char findTheDifference(std::string s, std::string t) {
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



int main() {



}