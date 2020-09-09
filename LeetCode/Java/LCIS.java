//Easy - https://leetcode.com/problems/longest-continuous-increasing-subsequence/
//Saumya Sachdev

public class LCIS {
    public static int findLengthOfLCIS(int[] nums) {
        if(nums.length == 0)
            return 0;
        int count = 1, longest = 1;
        for(int i=0; i<nums.length-1; i++) {
            if(nums[i+1] > nums[i])
                count++;
            else
                count = 1;
             longest = Math.max(count, longest);
        }
        return longest;
    }

    public static void main(String args[]) {
        int[] input = {1,3,5,4,7};
        System.out.println(findLengthOfLCIS(input));
    }
}
