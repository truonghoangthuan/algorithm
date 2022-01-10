package com.algorithm;

import java.util.*;

public class HashTable_RansomNote {
    public static void checkMagazine(List<String> magazine, List<String> note) {
        // Write your code here
        HashMap<String, Integer> hashMap = new HashMap<>();
        for (String word : magazine) {
            word = word.replaceAll("\\s","");
            if (hashMap.containsKey(word)) {
                hashMap.put(word, hashMap.get(word) + 1);
            }
            hashMap.put(word, 1);
        }

        for (String word : note) {
            word = word.replaceAll("\\s","");
            if (!hashMap.containsKey(word)) {
                System.out.println("No");
                return;
            } else if (hashMap.get(word) <= 0) {
                System.out.println("No");
                return;
            }
            hashMap.put(word, hashMap.get(word) - 1);
        }
        System.out.println("Yes");
    }

    public static void main(String[] args) {
        List<String> magazine = new ArrayList<>(Arrays.asList(" two", "times", "three", "is", "not", "four"));
        List<String> note = new ArrayList<>(Arrays.asList("two", "times", "is", "four"));
        checkMagazine(magazine, note);
    }
}
