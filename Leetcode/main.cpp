/*
* Author : Hyunsoo Jang
* GitHub : https://github.com/JangHyunsoo/LeetCode
*/
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

class Solution389 {
/*
* pass
* Runtime : 6ms, 12.47%
* Memory Usage : 6.6MB, 66.85%
*/

/*
* big O : O(n)
* n = s.length() 이라고하고 m = t.length() = s.length() + 1 = n + 1 라고하면
* 31번째줄 for문은 m번 반복하며 연산은 반복당 1번임으로 m번 연산하며
* 34번째줄 for문은 n번 반복하며 연산은 위와 같이 반복단 1번임으로 n번 연산한다.
* 따라서 처음에 sum = 0을 대입하는 것과 합쳐 O(n+m+1)고 여기에 m = n + 1을 대임하면 O(2n+2)이다. 
* 여기서 상수와 계수는 빠짐으로 O(n)이다.
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
* Solve1
* pass
* Runtime : 3ms, 40.99%
* Memory Usage : 6.2MB, 59.48%
*/

/*
* Solve2
* pass
* Runtime : 4ms, 37.44%
* Memory Usage : 6.5MB, 7.33%
* 
*/

/*
* Solve3
* pass
* Runtime : 0ms, 100,00%
* Memory Usage : 6.2MB, 59.64%
*/

/*
* big O : O(n*m)
* n = jewels.length(), m = stones.length()라고 하면
* 70번째 줄의 1차 for문에서 n번 반복하고 71번째 줄에서 m번 반복한다.
* 따라서 n*m 번 돌며 70번째 줄의 condition이 true이면 연산을 2번하고 아니라면 1번임으로
* O(n*m)이라고 할 수 있다. 하지만 numJewelsInStones2는 O(n+m)이지만 n과 m의 크기가 너무 작아 더 느리게 나온것 같다.
* solve3번은 std::unorder_map을 사용하지 않고 
*/
public:
    static int numJewelsInStones1(std::string jewels, std::string stones) {
        int count = 0;
        
        for (auto jewel : jewels) {
            for (auto stone : stones) {
                if (stone == jewel) ++count;
            }
        }

        return count;
    }
    static int numJewelsInStones2(std::string jewels, std::string stones) {
        std::unordered_map<char, int> m;

        for (auto c : stones) {
            if (m.find(c) == m.end()) {
                m[c] = 1;
            }
            else {
                m[c]++;
            }
        }

        int count = 0;

        for (auto c : jewels) {
            count += m[c];
        }

        return count;
    }
    static int numJewelsInStones3(std::string jewels, std::string stones) {
        char m['z' - 'A' + 1]{ 0, };

        for (auto c : stones) {
            ++m[c - 'A'];
        }

        int count = 0;

        for (auto c : jewels) {
            count += m[c - 'A'];
        }

        return count;
    }
};

int main() {

    std::string s{ "abcde" };
    std::string t{ "abcdef" };
    std::cout << "Solution389" << '\n' << Solution389::findTheDifference(s, t) << '\n';
    std::cout << "Solution771_1" << '\n' << Solution771::numJewelsInStones1(s, t) << '\n';
    std::cout << "Solution771_2" << '\n' << Solution771::numJewelsInStones2(s, t) << '\n';
}