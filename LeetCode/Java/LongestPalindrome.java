import java.util.HashSet;

public class LongestPalindrome {
    public static int longestPalindrome(String s) {
        if(s == null || s.length() == 0)
            return 0;
        HashSet<Character> set = new HashSet<Character>();
        int count = 0;

        for(int i=0; i<s.length(); i++) {
            if(set.contains(s.charAt(i))) {
                count++;
                set.remove(s.charAt(i));
            } else
                set.add(s.charAt(i));
        }

        if(set.isEmpty())
            return count * 2;
        else
            return count * 2 + 1;
    }

    public static void main(String args[]) {
        int value = longestPalindrome("aaaaabbcbccd");
        System.out.println(value);
    }
}
