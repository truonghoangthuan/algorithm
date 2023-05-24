import java.util.Scanner;

public class PalindromeIndex {
    static boolean isPalidrom(String s, int i, int j) {
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }
        return true;
    }

    public static int palindromeIndex(String s) {
        // Write your code here
        int result = 0;
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                if (isPalidrom(s, i, j - 1)) {
                    result = j;
                } else {
                    result = i;
                }
                break;
            }
            i++;
            j--;
        }
        if (i >= j) {
            result = -1;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(palindromeIndex(s));
    }
}
