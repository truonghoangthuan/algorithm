package com.thuan.algorithm;

import java.util.Arrays;
import java.util.List;

public class JumpingOnTheClouds {
    /*
     * Complete the 'jumpingOnClouds' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY c as parameter.
     */

    public static int jumpingOnClouds(List<Integer> c) {
        // Write your code here
        int totalJumps = 0;
        int listSize = c.size();
        System.out.println(listSize);
        int jump = 0;
        while (jump < listSize - 1) {
            if (jump + 2 < listSize && c.get(jump + 2) == 0) {
                jump += 2;
            } else {
                jump++;
            }
            totalJumps++;
        }
        return totalJumps;
    }

    public static void main(String[] args) {
        int[] arr = {0, 0, 0, 0, 1, 0};
        List<Integer> list = Arrays.stream(arr).boxed().toList();
        System.out.println(jumpingOnClouds(list));
    }
}
