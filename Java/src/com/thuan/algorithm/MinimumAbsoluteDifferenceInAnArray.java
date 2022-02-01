package com.thuan.algorithm;

import java.util.*;

public class MinimumAbsoluteDifferenceInAnArray {
    public static int minimumAbsoluteDifference(List<Integer> arr) {
        // Write your code here
        int minimum = 9999999;

        Collections.sort(arr);
        for (int i = 0; i < arr.size() - 1; i++) {
            int abs = Math.abs(arr.get(i) - arr.get(i + 1));
            if (abs < minimum) {
                minimum = abs;
            }
        }

        return minimum;
    }

    public static void main(String[] args) {
//        List<Integer> list = new ArrayList<>(Arrays.asList(-59, -36, -13, 1, -53, -92, -2, -96, -54, 75));
        List<Integer> list = new ArrayList<>(Arrays.asList(1, -3, 71, 68, 17));
        System.out.println(minimumAbsoluteDifference(list));
    }
}
