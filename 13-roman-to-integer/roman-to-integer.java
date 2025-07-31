import java.util.*;

public class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> roman = new HashMap<>();
        roman.put('I', 1);
        roman.put('V', 5);
        roman.put('X', 10);
        roman.put('L', 50);
        roman.put('C', 100);
        roman.put('D', 500);
        roman.put('M', 1000);

        int total = 0;
        int prevValue = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int current = roman.get(s.charAt(i));
            if (current < prevValue) {
                total -= current;
            } else {
                total += current;
            }
            prevValue = current;
        }

        return total;
    }
}
