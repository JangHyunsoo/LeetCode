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
    * �׶��׶����� �ӵ��� �޸𸮰� �ٸ��� ����.
    * �ڵ带 �ٲ㵵 ��� �ٸ��� ����.
    * ���� ���� ���
    */

    /*
    * big O : O(n)
    * n = s.length() �̶���ϰ� m = t.length() = s.length() + 1 = n + 1 ����ϸ�
    * 34��°�� for���� m�� �ݺ��ϸ� ������ �ݺ��� 1�������� m�� �����ϸ�
    * 37��°�� for���� n�� �ݺ��ϸ� ������ ���� ���� �ݺ��� 1�������� n�� �����Ѵ�.
    * ���� ó���� sum = 0�� �����ϴ� �Ͱ� ���� O(n+m+1)�� ���⿡ m = n + 1�� �����ϸ� O(2n+2)�̴�.
    * ���⼭ �ְ����׸� ����� ����� ����� ������ ���������� O(n)�̴�.
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
    * big O : O(n+m) Solve3�� ����
    * jewels�� ũ�⸦ n�̶��ϰ� stones�� ũ�⸦ m�̶�� �ΰ� arr�� ���� �ð� 'z' - 'A' + 1�� ��� c��� �ϸ�
    * arr�� �����ϸ� c�� ������ �Ѵ�.
    * for1���� stones�� ũ�⸸ŭ �ݺ��ϸ� ���ο��� 1�� ������ �ݺ������� m��ŭ �����Ѵ�.
    * count�� �����ϸ� 1�� ������ �Ѵ�.
    * for2������ jewels�� ũ�⸸ŭ �ݺ��ϰ� ���ο��� 1�� ������ �ݺ������� n��ŭ�� �������Ѵ�.
    * ���� O(n+m+c+1)�̴� ������ ���⼭ �ְ����׸��� ����� ����� c + 1�� �������������� O(n+m)�� �ȴ�.
    */
public:
    static int numJewelsInStones1(std::string jewels, std::string stones) {
        // ó�� Ǯ���� �� �ʹ� ������ ���� �ٽ� Ǯ����.
        // �翬�� n*m �ð��� ���� ��¿ �� ������.
        int count = 0;

        for (auto jewel : jewels) {
            for (auto stone : stones) {
                if (stone == jewel) ++count;
            }
        }

        return count;
    }
    static int numJewelsInStones2(std::string jewels, std::string stones) {
        // ���� �������� �����ϰ��� map�� ����Ͽ� n+m���� �ٲٷ��ߴ�.
        // ������ ���� ������� ���� ���� ����� ���Դ�.
        // �Ƹ� find�Լ��� ������ �� �ϴ�.
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
        // find�� ������� �ʱ� ���Ͽ� �迭�� ����Ͽ���.
        // char �迭�� ����� ������ stones�� �ִ� ũ�Ⱑ 50�̱� ������ 128�� ���� �� ������.
        // ������ ��� ��� n + m�̶� ó�� Ǯ�̺��� ���� ����� ���Դ�.
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