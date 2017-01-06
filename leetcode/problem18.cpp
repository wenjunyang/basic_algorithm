//
// Created by wendale on 2017/1/6.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int front = j + 1;
                int rear = nums.size() - 1;
                int new_target = target - (nums[i] + nums[j]);
                while (front < rear) {
                    if (nums[front] + nums[rear] < new_target) {
                        front++;
                    } else if (nums[front] + nums[rear] > new_target) {
                        rear--;
                    } else {
                        vector<int> tmp(4, 0);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[front];
                        tmp[3] = nums[rear];
                        result.push_back(tmp);
                        front++;
                        rear--;
                        while (front < rear && nums[front] == nums[front - 1]) {
                            front++;
                        }
                        while (front < rear && nums[rear] == nums[rear + 1]) {
                            rear--;
                        }
                    }
                }
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return result;
    }
};
