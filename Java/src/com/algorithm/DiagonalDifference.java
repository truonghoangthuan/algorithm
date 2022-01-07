package com.algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DiagonalDifference {
    /*
     * Complete the 'diagonalDifference' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts 2D_INTEGER_ARRAY arr as parameter.
     */

    public static int diagonalDifference(List<List<Integer>> arr) {
        // Write your code here
        int leftToRight = 0;
        int rightToLeft = 0;
        for (int i = 0; i < arr.size(); i++) {
            leftToRight += arr.get(i).get(i);
            rightToLeft += arr.get(arr.size() - (i + 1)).get(i);
        }
        return Math.abs(leftToRight - rightToLeft);
    }

    public static void main(String[] args) {
        List<List<Integer>> arr = new ArrayList<>();
        arr.add(new ArrayList<>(Arrays.asList(11, 2, 4)));
        arr.add(new ArrayList<>(Arrays.asList(4, 5, 6)));
        arr.add(new ArrayList<>(Arrays.asList(10, 8, -12)));
        System.out.println(diagonalDifference(arr));
    }
}
