package com.algorithm;

import java.util.ArrayList;
import java.util.List;

public class LeftRotation {
    public static List<Integer> rotLeft(List<Integer> a, int d) {
        // Write your code here
        for (int i = 0; i < d; i++) {
            rotateArray(a);
        }
        return a;
    }

    private static void rotateArray(List<Integer> arr) {
        int t = arr.get(0);
        for (int i = 0; i < arr.size() - 1; i++) {
            arr.set(i, arr.get(i + 1));
        }
        arr.set(arr.size() - 1, t);
    }

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>();
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(4);
        arr.add(5);
        System.out.println(rotLeft(arr, 4));
    }
}
