package com.thuan.algorithm;

import java.util.ArrayList;
import java.util.List;

public class PlusMinus {
    /*
     * Complete the 'plusMinus' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void plusMinus(List<Integer> arr) {
        // Write your code here
        double positiveCount = 0;
        double negativeCount = 0;
        double zeroCount = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i) == 0) {
                zeroCount++;
            } else if (arr.get(i) > 0) {
                positiveCount++;
            } else {
                negativeCount++;
            }
        }

        System.out.println(String.format("%.6f", positiveCount/arr.size()));
        System.out.println(String.format("%.6f", negativeCount/arr.size()));
        System.out.println(String.format("%.6f", zeroCount/arr.size()));
    }

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>();
        arr.add(1);
        arr.add(1);
        arr.add(0);
        arr.add(-1);
        arr.add(-1);
        plusMinus(arr);
    }
}
