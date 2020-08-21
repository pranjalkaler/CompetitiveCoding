import java.util.HashSet;
import java.util.Set;

public class DistCandies {
    public static int distributeCandies(int[] candies) {
        Set<Integer> freq = new HashSet<Integer>();
        for(int n : candies) {
            freq.add(n);
        }
        return Math.min(freq.size(), candies.length/2);
    }
    
    public static void main(String args[]) {
        int[] candies = {1,2,3,3,4,5,2,3};
        int ans = distributeCandies(candies);
        System.out.println(ans);
    }
}
