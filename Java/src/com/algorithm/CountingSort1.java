package com.algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CountingSort1 {
    /*
     * Complete the 'countingSort' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static List<Integer> countingSort(List<Integer> arr) {
        // Write your code here
        List<Integer> result = new ArrayList<Integer>();
        int[] frequency = new int[100];
        for (Integer each : arr)
            frequency[each] += 1;
        for (int each : frequency)
            result.add(each);
        return result;
    }

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>();
        arr.add(1);
        arr.add(1);
        arr.add(1);
        arr.add(2);
        arr.add(3);
        System.out.println(countingSort(arr));
    }
}
