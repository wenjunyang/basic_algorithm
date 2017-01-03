//
// Created by wendale on 17/1/3.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 保证nums1的长度不大于nums2
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        if (n == 0) {
            return NULL;
        }
        int imin = 0;
        int imax = m;
        int i;
        int j;
        while (imin <= imax) {
            i = (imin + imax) / 2;
            j = (m + n + 1) / 2 - i;
            if ((i == 0 or j == n or nums1[i - 1] <= nums2[j]) and
                (j == 0 or i == m or nums2[j - 1] <= nums1[i] )) {
                break;
            } else if (nums2[j - 1] > nums1[i]) {
                imin = i + 1;
            } else {
                imax = i - 1;
            }
        }
        return median(nums1, nums2, i, j);
    }

private:
    double median(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        int m = nums1.size();
        int n = nums2.size();
        int left1 = i == 0 ? nums2[j - 1] : nums1[i - 1];
        int left2 = j == 0 ? nums1[i - 1] : nums2[j - 1];
        int max_left = max(left1, left2);
        if ((m + n) % 2 == 0) {
            int min_right = 0;
            if (i == m and j == n) {
                min_right = 0;
            } else if (i == m) {
                min_right = nums2[j];
            } else if (j == n) {
                min_right = nums1[i];
            } else {
                min_right = min(nums1[i], nums2[j]);
            }
            return (max_left + min_right) / 2.0;
        } else {
            return max_left;
        }
    }
};