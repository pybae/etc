import java.util.*;

public class LargestPalindrome {

    static String expandPalindrome (String input, int pivot) {
        int gap = 0;
        int count = 1;

        while (pivot - gap >= 0 && pivot + gap < input.length()) {
            if (input[pivot - gap] != input[pivot + gap]) {
                break;
            }
        }

        return input.substring(pivot - gap, pivot + gap);
    }

    static String findLargestPalindrome (String input) {
        HashSet<String> palindromes;

        int index = 0;
        while (index < input.length()) {
            palindromes.add(expandPalindrome(input, index));
            index++;
        }
    }
}
