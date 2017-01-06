//
// Created by wendale on 2017/1/6.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                int num = nums[i] + nums[front] + nums[back];
                if (abs(num - target) < abs(result - target)) {
                    result = num;
                }
                if (num < target) {
                    front++;
                } else if (num > target) {
                    back--;
                } else {
                    return num;
                }
            }
        }
        return result;
    }
};