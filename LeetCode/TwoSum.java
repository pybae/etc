import java.util.Arrays;
import java.util.HashMap;

public class TwoSum {

    public static int[] twoSum (int[] numbers, int target) {

        // iterative solution
        // for (int i = 0; i < numbers.length; i++) {
        //     for (int j = 0; j < numbers.length; j++) {
        //         if (numbers[i] + numbers[j] == target) {
        //             return new int[] {i, j};
        //         }
        //     }
        // }

        // sorting solution
        // int i = 0;
        // int j = numbers.length - 1;
        // Arrays.sort(numbers);

        // while (i < j) {
        //     int sum = numbers[i] + numbers[j];

        //     if (sum == target) {
        //         return new int[] {i, j};
        //     } else if (sum < target) {
        //         i++;
        //     } else {
        //         j--;
        //     }
        // }

        // hash map solution
        HashMap<Integer, Integer> seen = new HashMap<Integer, Integer>();

        for (int i = 0; i < numbers.length; i++) {
            Integer value = seen.get(target - numbers[i]);

            if (value != null) {
                return new int [] { value, i };
            }

            seen.put(numbers[i], i);
        }
        return answer;
    }

    public static void main(String[] args) {
        int[] numbers = new int[] {1, 2, 3, 4};
        int[] answer = twoSum(numbers, 5);
        System.out.println(numbers[answer[0]] + " " + numbers[answer[1]]);

        numbers = new int[] {1, 2, 100, 101};
        answer = twoSum(numbers, 3);
        System.out.println(numbers[answer[0]] + " " + numbers[answer[1]]);

        numbers = new int[] {-9, 10, 100, 101, 134, -10};
        answer = twoSum(numbers, -19);
        System.out.println(numbers[answer[0]] + " " + numbers[answer[1]]);

        return;
    }
}
