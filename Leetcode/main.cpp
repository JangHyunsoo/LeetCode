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
* n = s.length() �̶���ϰ� m = t.length() = s.length() + 1 = n + 1 ����ϸ�
* 31��°�� for���� m�� �ݺ��ϸ� ������ �ݺ��� 1�������� m�� �����ϸ�
* 34��°�� for���� n�� �ݺ��ϸ� ������ ���� ���� �ݺ��� 1�������� n�� �����Ѵ�.
* ���� ó���� sum = 0�� �����ϴ� �Ͱ� ���� O(n+m+1)�� ���⿡ m = n + 1�� �����ϸ� O(2n+2)�̴�. 
* ���⼭ ����� ����� �������� O(n)�̴�.
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
* n = jewels.length(), m = stones.length()��� �ϸ�
* 70��° ���� 1�� for������ n�� �ݺ��ϰ� 71��° �ٿ��� m�� �ݺ��Ѵ�.
* ���� n*m �� ���� 70��° ���� condition�� true�̸� ������ 2���ϰ� �ƴ϶�� 1��������
* O(n*m)�̶�� �� �� �ִ�. ������ numJewelsInStones2�� O(n+m)������ n�� m�� ũ�Ⱑ �ʹ� �۾� �� ������ ���°� ����.
* solve3���� std::unorder_map�� ������� �ʰ� 
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