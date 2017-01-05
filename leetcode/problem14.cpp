//
// Created by wendale on 2017/1/5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return string("");
        }
        int i = 0;
        while (i < strs[0].size()) {
            char first = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size()) {
                    goto next;
                }
                if (first != strs[j][i]) {
                    goto next;
                }
            }
            i++;
        }
        next:
        return strs[0].substr(0, i);
    }
};

int main() {
    Solution s;
    vector<string> strs(0);
    strs.push_back("a");
    strs.push_back("b");
    cout << s.longestCommonPrefix(strs);
}