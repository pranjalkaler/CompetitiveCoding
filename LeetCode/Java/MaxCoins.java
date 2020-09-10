//Medium - https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
//Author - Saumya Sachdev

import java.util.*;

public class MaxCoins {
    public static int maxCoins(int[] piles) {
        Arrays.sort(piles);
        int n = piles.length;
        int max = 0;
        for(int i=n/3; i<n; i+=2) {
            max += piles[i];
        }
        return max;
    }

    public static void main(String args[]) {
        int[] input = {2,4,1,2,7,8};
        System.out.println(maxCoins(input));
    }
}
