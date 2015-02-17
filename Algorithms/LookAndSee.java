import java.util.Arrays;
import java.util.Iterator;

public class LookAndSee {

    static String getNextNumber(String prev) {
        StringBuilder next = new StringBuilder();
        int count = 0;
        char current = prev.charAt(0);

        for (int i = 0; i < prev.length(); i++) {
            if (prev.charAt(i) == current) {
                count++;
            } else {
                next.append(count);
                next.append(current);
                count = 1;
                current = prev.charAt(i);
            }
        }

        next.append(count);
        next.append(current);

        return next.toString();
    }

    static String[] getNthSequence(int n) {
        String[] seq = new String[n];
        seq[0] = "1";
        for (int i = 1; i < n; i++) {
            seq[i] = getNextNumber(seq[i - 1]);
        }

        return seq;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(getNthSequence(10)));
    }
}
