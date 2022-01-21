package com.algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class MarkAndToys {
    public static int maximumToys(List<Integer> prices, int k) {
        // Write your code here
        int maximumToys = 0;
        Collections.sort(prices);
        int i = 0;
        while (k > 0) {
            if (prices.get(i) > k) {
                break;
            } else if (prices.get(i) < k) {
                maximumToys++;
                k -= prices.get(i);
            }
            i++;
        }
        return maximumToys;
    }

    public static void main(String[] args) {
        List<Integer> toys = new ArrayList<>(Arrays.asList(1, 12, 5, 111, 200, 1000, 10));
        System.out.println(maximumToys(toys, 50));
    }
}
