import java.util.HashSet;

public class TwoStrings {
    public static String twoStrings(String s1, String s2) {
        // Write your code here
        HashSet<Character> hashSet = new HashSet<>();
        for (int i = 0; i < s1.length(); i++) {
            hashSet.add(s1.charAt(i));
        }

        boolean found = false;
        for (int i = 0; i < s2.length(); i++) {
            if (hashSet.contains(s2.charAt(i))) {
                found = true;
                break;
            }
        }

        return (found) ? "Yes" : "No";
    }

    public static void main(String[] args) {
        String s1 = "be";
        String s2 = "cet";
        System.out.println(twoStrings(s1, s2));
    }
}
