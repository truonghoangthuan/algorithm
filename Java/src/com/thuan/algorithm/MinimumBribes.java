package com.thuan.algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MinimumBribes {
    /*
     * Complete the 'minimumBribes' function below.
     *
     * The function accepts INTEGER_ARRAY q as parameter.
     */

    public static void minimumBribes(List<Integer> q) {
        // Write your code here
        int cnt = 0;
        for (int i = 0; i < q.size(); i++) {
            int val = q.get(i);
            int index = i + 1;
            if (val > index) {
                cnt += (val - index);
                System.out.println((val - index));
                if ((val - index) > 2) {
                    System.out.println("Too Chaotic");
                    return;
                }
            }
        }
        System.out.println(cnt);
    }

    public static void main(String[] args) {
        List<Integer> q = new ArrayList<>(Arrays.asList(1, 2, 5, 3, 4, 7, 8, 6));
        List<Integer> q2 = new ArrayList<>(Arrays.asList(2, 1, 5, 3, 4));
        List<Integer> q3 = new ArrayList<>(Arrays.asList(1, 2, 5, 3, 7, 8, 6, 4));
        minimumBribes(q3);
    }
}
