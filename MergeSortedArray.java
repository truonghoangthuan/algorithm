public class MergeSortedArray {
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int maxLength = m + n;
        while (n > 0) {
            if (m > 0 && nums1[m - 1] > nums2[n - 1]) {
                nums1[maxLength - 1] = nums1[m - 1];
                m -= 1;
                maxLength -= 1;
            } else {
                nums1[maxLength - 1] = nums2[n - 1];
                n -= 1;
                maxLength -= 1;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr1 = { 1, 2, 3, 0, 0, 0 };
        int m = 3;
        int[] arr2 = { 2, 5, 6 };
        int n = 3;

        merge(arr1, m, arr2, n);

        for (int i : arr1) {
            System.out.println("Num " + i);
        }
    }
}
