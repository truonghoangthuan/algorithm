package com.thuan.algorithm;

import java.util.ArrayList;
import java.util.List;

public class MiniMaxSum {
    /*
     * Complete the 'miniMaxSum' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void miniMaxSum(List<Integer> arr) {
        // Write your code here
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        long totalSum = 0;
        for (Integer integer : arr) {
            // found a new min
            if (min > integer) {
                min = integer;
            }
            // found a new max
            if (max < integer) {
                max = integer;
            }
            totalSum += integer;
        }
        System.out.println((totalSum - max) + " " + (totalSum - min));
    }

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>();
        arr.add(1);
        arr.add(5);
        arr.add(3);
        arr.add(2);
        arr.add(4);
        miniMaxSum(arr);
    }
}
