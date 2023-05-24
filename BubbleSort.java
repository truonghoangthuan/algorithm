import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BubbleSort {
    public static void countSwaps(List<Integer> a) {
        // Write your code here
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                if (a.get(i) > a.get(j)) {
                    count++;
                    int tmp = a.get(i);
                    a.set(i, a.get(j));
                    a.set(j, tmp);
                }
            }
        }
        System.out.printf("Array is sorted in %d swaps\n", count);
        System.out.printf("First Element: %d\n", a.get(0));
        System.out.printf("Last Element: %d\n", a.get(a.size() - 1));
    }

    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>(Arrays.asList(6, 4, 1));
        countSwaps(list);
    }
}
