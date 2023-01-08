package com.thuan.algorithm;

public class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];

        for (int i = 0; i <= nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    res[0] = i;
                    res[1] = j;
                }
            }
        }
        return res;
    }
}
