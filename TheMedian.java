import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TheMedian {
    /*
     * Complete the 'findMedian' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static int findMedian(List<Integer> arr) {
        // Write your code here
        Collections.sort(arr);
        int length = arr.size();
        return arr.get(length/2);
    }

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>();
        arr.add(5);
        arr.add(7);
        arr.add(2);
        arr.add(3);
        System.out.println(findMedian(arr));
    }
}
