import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class HourGlassSum {
    /*
     * Complete the 'hourglassSum' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts 2D_INTEGER_ARRAY arr as parameter.
     */

    public static int hourGlassSum(List<List<Integer>> arr) {
        // Write your code here
        int sum = 0;
        int max = -999999;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int arr00 = arr.get(i).get(j);
                int arr01 = arr.get(i).get(j + 1);
                int arr02 = arr.get(i).get(j + 2);
                int arr11 = arr.get(i + 1).get(j + 1);
                int arr20 = arr.get(i + 2).get(j);
                int arr21 = arr.get(i + 2).get(j + 1);
                int arr22 = arr.get(i + 2).get(j + 2);
                sum = arr00 + arr01 + arr02 + arr11 + arr20 + arr21 + arr22;
                System.out.println("sum " + i + j + ": " + sum);
                if (sum > max) {
                    max = sum;
                }
            }
        }
        return max;
    }

    public static void main(String[] args) {
        List<List<Integer>> arr = new ArrayList<>();
        arr.add(new ArrayList<Integer>(Arrays.asList(1, 1, 1, 0, 0, 0)));
        arr.add(new ArrayList<Integer>(Arrays.asList(0, 1, 0, 0, 0, 0)));
        arr.add(new ArrayList<Integer>(Arrays.asList(1, 1, 1, 0, 0, 0)));
        arr.add(new ArrayList<Integer>(Arrays.asList(0, 0, 2, 4, 4, 0)));
        arr.add(new ArrayList<Integer>(Arrays.asList(0, 0, 0, 2, 0, 0)));
        arr.add(new ArrayList<Integer>(Arrays.asList(0, 0, 1, 2, 4, 0)));
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.get(i).size(); j++) {
                // do stuff
                System.out.print(arr.get(i).get(j) + " ");
            }
            System.out.println();
        }
        System.out.println("hourGlassSum: " + hourGlassSum(arr));
    }
}
