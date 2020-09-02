//https://leetcode.com/problems/find-pivot-index/submissions/
//Author - Saumya Sachdev

public class PivotIndex {
    public static int pivotIndex(int[] nums) {
      int sum = 0, left = 0;
      for(int i=0; i<nums.length; i++) {
          sum += nums[i];
      }

      for(int i=0; i<nums.length; i++) {
          if(2 * left == sum - nums[i])
              return i;
          left += nums[i];
      }
      return -1;
    }

    public static void main(String args[]) {
      int[] array = {-1,-1,-1,0,1,1};
      System.out.println(pivotIndex(array));
    }
}
