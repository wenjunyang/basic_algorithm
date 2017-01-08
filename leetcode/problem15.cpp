//
// Created by wendale on 2017/1/6.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int front = i + 1;
            int back = nums.size() - 1;
            int target = -nums[i];
            while (front < back) {
                if (nums[front] + nums[back] > target) {
                    back--;
                } else if (nums[front] + nums[back] < target) {
                    front++;
                } else {
                    vector<int> tmp(3, 0);
                    tmp[0] = nums[i];
                    tmp[1] = nums[front];
                    tmp[2] = nums[back];
                    result.push_back(tmp);
                    front++;
                    back--;
                    while (front < back && nums[front] == nums[front - 1]) {
                        front++;
                    }
                    while (back > front && nums[back] == nums[back + 1]) {
                        back--;
                    }
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i+1]) {
                i++;
            }
        }
        return result;
    }
};

vector<int> fromArray(int arr[], int len) {
    vector<int> result(len, 0);
    for (int i = 0; i < len; ++i) {
        result[i] = arr[i];
    }
    return result;
}
