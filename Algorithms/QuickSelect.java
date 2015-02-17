import java.util.Arrays;
public class QuickSelect {

    static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    static int partition(int[] a, int left, int right, int pivotIndex) {
        int pivotValue = a[pivotIndex];
        swap(a, pivotIndex, right);

        int current = left;
        for(int i = left; i < right; i++) {
            if (a[i] < pivotValue) {
                swap(a, i, current);
                current++;
            }
        }

        swap(a, right, current);
        return current;
    }

    static int quickSelect(int[] a, int n, int left, int right) {
        if (left == right) {
            return a[left];
        }

        // System.out.println(left + " " + right);
        int pivotIndex = left + (int) Math.floor(Math.random() * (right - left));
        // System.out.println(pivotIndex + " " + a[pivotIndex]);
        pivotIndex = partition(a, left, right, pivotIndex);
        // System.out.println(Arrays.toString(a));
        if (n  == pivotIndex) {
            return a[n];
        } else if (n < pivotIndex) {
            return quickSelect(a, n, left, pivotIndex - 1);
        } else {
            return quickSelect(a, n, pivotIndex + 1, right);
        }
    }

    public static void main(String[] args) {
        int[] test = new int[] {5, 3, 1, 2, 4, 6, 8, 7, 9, 10};

        System.out.println(quickSelect(test, 5, 0, test.length - 1));
        System.out.println(quickSelect(test, 3, 0, test.length - 1));
        System.out.println(quickSelect(test, 7, 0, test.length - 1));
        System.out.println(quickSelect(test, 1, 0, test.length - 1));
        System.out.println(quickSelect(test, 2, 0, test.length - 1));
    }
}
