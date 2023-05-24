public class CountingValleys {
    /*
     * Complete the 'countingValleys' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER steps
     *  2. STRING path
     */
    public static int countingValleys(int steps, String path) {
        // Write your code here
        int seaLevel = 0, valleysNumber = 0;
        for (int step = 0; step < steps; step++) {
            if (path.charAt(step) == 'D') {
                seaLevel--;
            } else {
                if (seaLevel == -1) {
                    valleysNumber++;
                }
                seaLevel++;
            }
        }
        return valleysNumber;
    }

    public static void main(String[] args) {
        System.out.println(countingValleys(8,"UDDDUDUU"));
    }
}
