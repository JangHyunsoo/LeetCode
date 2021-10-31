#pragma once
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
    * Runtime : 0ms, 100.00%
    * Memory Usage : 6.6MB, 88.28%
    * 그때그때마다 속도와 메모리가 다르게 나옴.
    * 코드를 바꿔도 계속 다르게 나옴.
    * 가장 빠른 결과
    */

    /*
    * big O : O(n)
    * n = s.length() 이라고하고 m = t.length() = s.length() + 1 = n + 1 라고하면
    * 34번째줄 for문은 m번 반복하며 연산은 반복당 1번임으로 m번 연산하며
    * 37번째줄 for문은 n번 반복하며 연산은 위와 같이 반복단 1번임으로 n번 연산한다.
    * 따라서 처음에 sum = 0을 대입하는 것과 합쳐 O(n+m+1)고 여기에 m = n + 1을 대임하면 O(2n+2)이다.
    * 여기서 최고차항만 남기고 상수와 계수는 생략이 가능함으로 O(n)이다.
    */
public:
    static char findTheDifference(std::string s, std::string t) {
        short sum = 0; // word (2 byte)

        for (auto c : t) {
            sum += c;
        }
        for (auto c : s) {
            sum -= c;
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
    * big O : O(n+m) Solve3번 기준
    * jewels의 크기를 n이라하고 stones의 크기를 m이라고 두고 arr의 생성 시간 'z' - 'A' + 1을 상수 c라고 하면
    * arr를 생성하며 c의 연산을 한다.
    * for1에서 stones의 크기만큼 반복하면 내부에서 1의 연산이 반복됨으로 m만큼 연산한다.
    * count를 생성하며 1의 연산을 한다.
    * for2에서는 jewels의 크기만큼 반복하고 내부에서 1의 연산이 반복됨으로 n만큼의 연산을한다.
    * 따라서 O(n+m+c+1)이다 하지만 여기서 최고차항만을 남기면 상수인 c + 1은 생략가능함으로 O(n+m)이 된다.
    */
public:
    static int numJewelsInStones1(std::string jewels, std::string stones) {
        // 처음 풀었을 때 너무 느리게 나와 다시 풀었다.
        // 당연히 n*m 시간에 끝나 어쩔 수 없었다.
        int count = 0;

        for (auto jewel : jewels) {
            for (auto stone : stones) {
                if (stone == jewel) ++count;
            }
        }

        return count;
    }
    static int numJewelsInStones2(std::string jewels, std::string stones) {
        // 위를 문제점을 보완하고자 map을 사용하여 n+m으로 바꾸려했다.
        // 하지만 위에 결과보다 좋지 않은 결과가 나왔다.
        // 아마 find함수가 문제인 듯 하다.
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
        // find를 사용하지 않기 위하여 배열을 사용하였다.
        // char 배열을 사용한 이유는 stones의 최대 크기가 50이기 때문에 128을 넘을 수 없었다.
        // 생각한 결과 대로 n + m이라 처음 풀이보다 빠른 결과가 나왔다.
        char arr['z' - 'A' + 1]{ 0, };

        for (auto c : stones) { // for1
            ++arr[c - 'A'];
        }

        int count = 0;

        for (auto c : jewels) { // for2
            count += arr[c - 'A'];
        }

        return count;
    }
};