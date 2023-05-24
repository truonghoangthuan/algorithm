import java.util.HashMap;
import java.util.Map;

class RomanToInteger {
    public int romanToInt(String s) {
        int result = 0;

        Map<String, Integer> numberMap = new HashMap<>();
        numberMap.put("I", 1);
        numberMap.put("V", 5);
        numberMap.put("X", 10);
        numberMap.put("L", 50);
        numberMap.put("C", 100);
        numberMap.put("D", 500);
        numberMap.put("M", 1000);

        return result;
    }

    public static void main(String[] args) {

    }
}