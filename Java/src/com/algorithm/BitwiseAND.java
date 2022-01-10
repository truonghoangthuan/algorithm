package com.algorithm;

import java.util.ArrayList;
import java.util.List;

public class BitwiseAND {
    // Function to check if
    // x is power of 2
    static boolean isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
        while (n != 1) {
            if (n % 2 != 0)
                return false;
            n = n / 2;
        }
        return true;
    }

    public static long countPairs(List<Integer> arr) {
        // Write your code here
        long count = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                boolean isPowerOfTwo = isPowerOfTwo(arr.get(i) & arr.get(j));
                if (isPowerOfTwo) {
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<Integer>();
        arr.add(1);
        arr.add(2);
        arr.add(1);
        arr.add(3);
        System.out.println(countPairs(arr));
    }
}
