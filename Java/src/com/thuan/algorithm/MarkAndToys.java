package com.thuan.algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class MarkAndToys {
    public static void swap(int x, int y) {
        int tmp = x;
        x = y;
        y = tmp;
    }

    public static int findPivot(List<Integer> list, int i, int j) {
        int firstKey = list.get(i);
        int k = i + 1;
        while ((k <= j) && (list.get(k) == firstKey)) {
            k++;
        }
        if (k > j) {
            return -1;
        }
        if (list.get(k) > firstKey) {
            return k;
        }
        return i;
    }

    public static int partition(List<Integer> list, int i, int j, int pivot) {
        int left = i;
        int right = j;
        while (left <= right) {
            while (list.get(left) < pivot) {
                left++;
            }
            while (list.get(right) >= pivot) {
                right--;
            }
            if (left < right) {
                int tmp = list.get(left);
                list.set(left, list.get(right));
                list.set(right, tmp);
            }
        }
        return left;
    }

    public static void quickSort(List<Integer> list, int i, int j) {
        int pivot, k;
        int pivotIndex = findPivot(list, i, j);
        if (pivotIndex != -1) {
            pivot = list.get(pivotIndex);
            k = partition(list, i, j, pivot);
            quickSort(list, 0, k - 1);
            quickSort(list, k, j);
        }
    }

    public static int maximumToys(List<Integer> prices, int k) {
        // Write your code here
        int maximumToys = 0;
        quickSort(prices, 0, prices.size() - 1);
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
