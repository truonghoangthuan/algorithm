public class RepeatedString {
    /*
     * Complete the 'repeatedString' function below.
     *
     * The function is expected to return a LONG_INTEGER.
     * The function accepts following parameters:
     *  1. STRING s
     *  2. LONG_INTEGER n
     */

    public static long repeatedString(String s, long n) {
        // Write your code here
        long count = 0;
        long stringLength = s.length();
        long repeatTime = n/stringLength;
        long left = n - (stringLength * repeatTime);
        long extra = 0;
        for (int i = 0; i < stringLength; i++) {
            if (s.charAt(i) == 'a') {
                count++;
            }
        }
        for (int i = 0; i < left; i++) {
            if (s.charAt(i) == 'a') {
                extra++;
            }
        }
        return ((repeatTime * count) + extra);
    }

    public static void main(String[] args) {
        System.out.println(repeatedString("aba", 10));
    }
}
