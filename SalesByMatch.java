import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class SalesByMatch {
    /*
     * Complete the 'sockMerchant' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. INTEGER_ARRAY ar
     */

    public static int sockMerchant(int n, List<Integer> ar) {
        // Write your code here
        HashSet<Integer> hashSet = new HashSet<>();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int element = ar.get(i);
            if (hashSet.contains(element)) {
                hashSet.remove(element);
                count++;
            } else {
                hashSet.add(element);
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int n = 9;
        int[] ar = {10, 20, 20, 10, 10, 30, 50, 10, 20};
        List<Integer> list = Arrays.stream(ar).boxed().toList();
        System.out.println(sockMerchant(n, list));
    }
}
