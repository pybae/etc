import java.util.Arrays;

public class ThreeSum {

    static int[] findThreeSum(int[] a, int n) {
        Arrays.sort(a);

        for(int i = 0; i < a.length; i++) {
            int pivot = a[i];
            int x = i + 1;
            int y = a.length - 1;
            while (x < y) {
                int start = a[x];
                int end = a[y];
                if (start + end + pivot == n) {
                    return new int[]{start, end, pivot};
                } else if (start + end + pivot > n) {
                    y--;
                } else {
                    x++;
                }
            }
        }

        return new int[0];
    }

    public static void main(String[] args) {
        int[] test1 = new int[] {1, 2, 3, 4, 5, 6, 7, 8, 9};
        System.out.println(Arrays.toString(findThreeSum(test1, 10)));
        System.out.println(Arrays.toString(findThreeSum(test1, 12)));
        System.out.println(Arrays.toString(findThreeSum(test1, 19)));
        System.out.println(Arrays.toString(findThreeSum(test1, 50)));
        System.out.println(Arrays.toString(findThreeSum(test1, -1)));
    }
}
