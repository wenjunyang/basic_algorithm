//
// Created by wendale on 17/1/3.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = s.length() > 0 ? 1 : 0;
        int last = 1;
        for (int i = 1; i < s.length(); ++i) {
            int cnt = 1;
            for (int j = i - 1; j >= i - last; --j) {
                if (s.at(i) == s.at(j)) {
                    break;
                }
                cnt++;
            }
            last = cnt;
            max = cnt > max ? cnt : max;
        }
        return max;
    }
};