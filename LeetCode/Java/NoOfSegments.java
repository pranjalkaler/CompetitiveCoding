//Problem link -- https://leetcode.com/problems/number-of-segments-in-a-string/
//Author - Saumya Sachdev

public class NoOfSegments {
    public static int countSegments(String s) {
        String trimmed = s.trim();
        if(trimmed.length()>0) {
            String[] splitted = trimmed.split("\\s+");
            return splitted.length;
        } else
            return 0;
    }

    public static void main(String args[]) {
        int ans = countSegments("   hello, world  ");
        System.out.println(ans);
    }
}
