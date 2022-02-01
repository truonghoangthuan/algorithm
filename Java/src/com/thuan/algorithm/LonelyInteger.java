package com.thuan.algorithm;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LonelyInteger {
    /*
     * Complete the 'lonelyinteger' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY a as parameter.
     */

    public static int lonelyInteger(List<Integer> a) {
        // Write your code here
        int result = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (Integer i : a) {
            Integer count = map.get(i);
            if (count == null) {
                count = 0;
            }
            map.put(i, count + 1);
        }
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() == 1) {
                result = entry.getKey();
            }
        }
        return result;
    }

    public static void main(String[] args) {
        List<Integer> a = new ArrayList<>();
        a.add(1);
        a.add(1);
        a.add(4);
        a.add(2);
        a.add(2);
        System.out.println(lonelyInteger(a));
    }
}
