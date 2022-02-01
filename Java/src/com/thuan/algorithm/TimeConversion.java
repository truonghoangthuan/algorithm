package com.thuan.algorithm;

import java.util.Scanner;

public class TimeConversion {
    /*
     * Complete the 'timeConversion' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String timeConversion(String str) {
        // Write your code here
        String result = "";
        char ap = str.charAt(str.length() - 2);
        str = str.substring(0, str.length() - 2);
        if (ap == 'A') {
            int hh = Integer.parseInt(str.substring(0, 2));
            if (hh == 12) {
                hh = 0;
            }
            String s = Integer.toString(hh);
            if (s.length() == 1) {
                s = "0" + s;
            }
            result = s + str.substring(2);
        } else {
            int hh = Integer.parseInt(str.substring(0, 2));
            if (hh != 12) {
                hh += 12;
            }
            String s = Integer.toString(hh);
            if (s.length() == 1) {
                s = "0" + s;
            }
            result = hh + str.substring(2);
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(timeConversion("07:05:45PM"));
    }
}
