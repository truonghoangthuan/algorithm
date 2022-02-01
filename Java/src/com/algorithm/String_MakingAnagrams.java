package com.algorithm;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class String_MakingAnagrams {
    public static int makeAnagram(String a, String b) {
        // Write your code here
        int sum = 0;

        Map<Character, Integer> map = new HashMap<>();
        for (Character character : a.toCharArray()) {
            int contain = map.getOrDefault(character, 0);
            map.put(character, contain + 1);
        }

        for (Character character : b.toCharArray()) {
            int contain = map.getOrDefault(character, 0);
            map.put(character, contain - 1);
        }

        for (Integer value : map.values()) {
            sum += Math.abs(value);
        }

        return sum;
    }

    public static void main(String[] args) {
        String a = "cde";
        String b = "abc";
        System.out.println(makeAnagram(a, b));
    }
}
