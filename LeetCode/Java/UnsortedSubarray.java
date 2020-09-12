//Leetcode - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
//Author - Saumya Sachdev

import java.util.Arrays;

public class UnsortedSubarray {
    public static int findUnsortedSubarray(int[] nums) {
        int n = nums.length;
        int[] clone = nums.clone();
        Arrays.sort(clone);
        int start = 0, end = n - 1;

        while(start < n && clone[start] == nums[start])
            start++;
        while(end > start && clone[end] == nums[end])
            end--;

        return end - start + 1;
    }

    public static void main(String args[]) {
        int[] input = {1,2,6,4,8,10,9,15};
        System.out.println(findUnsortedSubarray(input));
    }
}
