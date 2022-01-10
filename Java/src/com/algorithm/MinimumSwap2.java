package com.algorithm;

public class MinimumSwap2 {
    // Complete the minimumSwaps function below.
    static int minimumSwaps(int[] arr) {
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == i + 1) continue;
            count++;
            int tmp = arr[i];
            arr[i] = arr[tmp - 1];
            arr[tmp - 1] = tmp;
            i--;
        }
        return count;
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 1, 5};
        System.out.println(minimumSwaps(arr));
    }
}
