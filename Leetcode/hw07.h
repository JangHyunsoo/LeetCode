#pragma once
/*
* Author : Hyunsoo Jang (Koreatech 2018136114 장현수)
* GitHub : https://github.com/JangHyunsoo/LeetCode
*/
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Solution101 {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };
/*
* pass
* Runtime : 4ms, 79.07%
* Memory Usage : 17MB, 7.46%
* Explanation : wfs를 통하여 전체 경로를 계산하여 비교한다. 이때 left와 right의 경로의 wfs를 반대로 바꿔주기 위하여 wfs에서 mirror 인자를
* 통하여 left는 right-left 순서로 탐색하였고, right부부은 left-right 순서로 탐색하였다.
*/
public:
    bool static isSymmetric(TreeNode* root) {
        // 최소 크기가 1임으로 root가 nullptr일 경우는 없음.
        if (!root->left || !root->right) {
            if (root->left == root->right) return true;
            else return false;
        }
        else {
            vector<int> left_check;
            vector<int> right_check;
            wfs(root->left, true, left_check);
            wfs(root->right, false, right_check);

            if (left_check.size() != right_check.size()) return false;
            else {
                size_t check_size = left_check.size();
                for (int i = 0; i < check_size; ++i) {
                    if (left_check[i] != right_check[i]) return false;
                }
                return true;
            }
        }
    }

private:
    void static wfs(TreeNode* root, bool mirror, vector<int>& visitedOrder) {
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* curr{ queue.front() };
            queue.pop();
            if (curr) {
                visitedOrder.push_back(curr->val);
                if (mirror) {
                    queue.push(curr->right);
                    queue.push(curr->left);
                }
                else {
                    queue.push(curr->left);
                    queue.push(curr->right);
                }
            }
            else {
                visitedOrder.push_back(-102);
            }
        }
    }
};


class Solution112 {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };
/*
* pass
* Runtime : 8ms, 89.59%
* Memory Usage : 21.4MB, 37.98%
* Explanation : dfs를 통하여 끝까지 pathSum을 계산 후 이가 targetSum과 일치한다면 true를 리턴하였다. 중간에 prev와 root->val의 합이 이미 targetSum을
* 넘기면 탈출하려했지만 tree에 음수가 포함되어 있어 끝까지 검색하지 않으면 알 수 없었다.
*/
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkPathSum(root, targetSum, 0);
    }

private:
    bool checkPathSum(TreeNode* root, int targetSum, int prev) {
        if (!root) return false;
        // 음수가 포함되어 끝까지 가봐야 알 수 있음.
        // else if (abs(root->val + prev) > abs(targetSum)) return false;
        else {
            // is leaf
            if (!root->left && !root->right) return targetSum == (prev + root->val);
            else {
                return checkPathSum(root->left, targetSum, prev + root->val) ||
                    checkPathSum(root->right, targetSum, prev + root->val);
            }
        }
    }
};