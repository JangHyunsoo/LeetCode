#pragma once
/*
* Author : Hyunsoo Jang (Koreatech 2018136114 ������)
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
* Explanation : wfs�� ���Ͽ� ��ü ��θ� ����Ͽ� ���Ѵ�. �̶� left�� right�� ����� wfs�� �ݴ�� �ٲ��ֱ� ���Ͽ� wfs���� mirror ���ڸ�
* ���Ͽ� left�� right-left ������ Ž���Ͽ���, right�κ��� left-right ������ Ž���Ͽ���.
*/
public:
    bool static isSymmetric(TreeNode* root) {
        // �ּ� ũ�Ⱑ 1������ root�� nullptr�� ���� ����.
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
* Explanation : dfs�� ���Ͽ� ������ pathSum�� ��� �� �̰� targetSum�� ��ġ�Ѵٸ� true�� �����Ͽ���. �߰��� prev�� root->val�� ���� �̹� targetSum��
* �ѱ�� Ż���Ϸ������� tree�� ������ ���ԵǾ� �־� ������ �˻����� ������ �� �� ������.
*/
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkPathSum(root, targetSum, 0);
    }

private:
    bool checkPathSum(TreeNode* root, int targetSum, int prev) {
        if (!root) return false;
        // ������ ���ԵǾ� ������ ������ �� �� ����.
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