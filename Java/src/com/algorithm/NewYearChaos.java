package com.algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class NewYearChaos {
    /*
     * Complete the 'minimumBribes' function below.
     *
     * The function accepts INTEGER_ARRAY q as parameter.
     */

    public static void minimumBribes(List<Integer> q) {
        // Write your code here
        int cnt = 0;
        int cntBride = 0;
        boolean chaos = false;
        for (int i = 0; i < q.size(); i++) {
            int val = q.get(i);
            int index = i + 1;
            if (val > index) {
                if ((val - index) > 2) {
                    return;
                } else {
                    cnt += (val - index);
                    cntBride += (val - index);
                    if (cntBride > 2) {
                        chaos = true;
                    }
                }
            }
            cntBride = 0;
        }
        System.out.println(cnt);
        if (!chaos) {
            System.out.println("Too chaotic");
        }
    }

    public static void main(String[] args) {
        List<Integer> q = new ArrayList<>(Arrays.asList(2, 1, 5, 3, 4));
        minimumBribes(q);
    }
}
