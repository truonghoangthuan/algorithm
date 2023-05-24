import java.util.Scanner;

public class CeasarCipher {
    /*
     * Complete the 'caesarCipher' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. STRING s
     *  2. INTEGER k
     */

    public static String caesarCipher(String s, int k) {
        // Write your code here
        StringBuilder ans = new StringBuilder();
        int t;
        for (char c : s.toCharArray()) {
            if (Character.isLetter(c)) {
                if (Character.isUpperCase(c)) {
                    t = (c + k - 65) % 26;
                    ans.append((char) (t + 65));
                } else {
                    if (Character.isLowerCase(c)) {
                        t = (c + k - 97) % 26;
                        ans.append((char) (t + 97));
                    }
                }
            } else {
                ans.append(c);
            }
        }
        return ans.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int k = sc.nextInt();
        System.out.println(caesarCipher(s, k));
    }
}
