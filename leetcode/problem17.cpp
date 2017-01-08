//
// Created by wendale on 2017/1/8.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    map<char, string> digit_map;

    Solution() {
        digit_map.insert(pair<char, string>('2', "abc"));
        digit_map.insert(pair<char, string>('3', "def"));
        digit_map.insert(pair<char, string>('4', "ghi"));
        digit_map.insert(pair<char, string>('5', "jkl"));
        digit_map.insert(pair<char, string>('6', "mno"));
        digit_map.insert(pair<char, string>('7', "pqrs"));
        digit_map.insert(pair<char, string>('8', "tuv"));
        digit_map.insert(pair<char, string>('9', "wxyz"));
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) {
            return result;
        }

        stack<int> idx_stack;
        idx_stack.push(0);
        char* tmp = new char[digits.length()];
        int tmp_len = 0;
        do {
            if (tmp_len == digits.size()) {
                tmp[tmp_len] = '\0';
                string one(tmp);
                result.push_back(one);
                while (not idx_stack.empty()) {
                    int next = idx_stack.top() + 1;
                    idx_stack.pop();
                    tmp_len--;
                    if (next >= digit_map[digits[tmp_len]].size()) {
                        continue;
                    } else {
                        tmp[tmp_len++] = digit_map[digits[tmp_len - 1]][next];
                        idx_stack.push(next);
                        break;
                    }
                }
            } else {
                idx_stack.push(0);
                tmp[tmp_len++] = digit_map[digits[tmp_len - 1]][0];
            }
        } while (not idx_stack.empty());
        delete[] tmp;
        return result;
    }
};
