package com.algorithm;

public class AlternatingCharacters {
    public static int alternatingCharacters(String s) {
        // Write your code here
        int sum = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == (s.charAt(i + 1))) {
                sum++;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        String s = "BBBBB";
        System.out.println(alternatingCharacters(s));
    }
}
