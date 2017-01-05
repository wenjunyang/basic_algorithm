//
// Created by wendale on 17/1/4.
//
#include <iostream>
#include <vector>

using namespace std;

class StringWrapper {
private:
    string src;

public:
    StringWrapper(string s) : src(s){};

    int size() {
        return 2 * src.size() + 1;
    }

    bool compare(int idx1, int idx2) {
            return (idx1 % 2 == idx2 % 2) and
                    ((idx1 % 2 == 0) or (src[(idx1 - 1) / 2] == src[(idx2 - 1) / 2]));
    }

    string realPalindrome(int idx, int len) {
        return src.substr((idx - len + 1) / 2, len - 1);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) {
            return s;
        }
        StringWrapper wrapper(s);
        vector<int> halfLen(wrapper.size());
        int pos = 0;
        int maxRight = 0;
        halfLen[0] = 1;
        int maxLen = 1;
        int maxPos = 0;
        for (int i = 1; i < wrapper.size(); ++i) {
            int curLen = 1;
            if (i < maxRight) {
                curLen = min(halfLen[2 * pos - i], maxRight - i + 1);
            }
            while (i + curLen < wrapper.size() and i - curLen >= 0) {
                if (wrapper.compare(i + curLen, i - curLen)) {
                    curLen++;
                } else {
                    break;
                }
            }
            if (i + curLen - 1 > maxLen) {
                maxRight = i + curLen - 1;
                pos = i;
            }

            halfLen[i] = curLen;
            if (curLen > maxLen) {
                maxLen = curLen;
                maxPos = i;
            }

        }
        return wrapper.realPalindrome(maxPos, maxLen);

    }
};