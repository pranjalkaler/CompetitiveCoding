//Question - https://leetcode.com/problems/single-number-iii/
//Author - Saumya Sachdev
//Dumb, easy solution. Smarter ones involve bit manupialtion.

import java.util.*;

public class SingleNumberIII {
    public static int[] singleNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int i : nums) {
            if(set.contains(i)) {
                set.remove(i);
            } else {
                set.add(i);
            }
        }
        int[] ans = new int[2];
        int i = 0;
        for(int j : set) {
            ans[i] = j;
            i++;
        }
        return ans;
    }

    public static void main(String args[]) {
        int[] input = {1,2,3,4,1,2};
        int[] ans = singleNumber(input);
        for(int i=0; i<2; i++)
          System.out.println(ans[i]);
    }
}
