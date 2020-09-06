//Question Easy - https://leetcode.com/problems/word-pattern/
//Author - Saumya Sachdev

import java.util.*;

public class WordPattern {
    public static boolean wordPattern(String pattern, String str) {
        Map<Character, String> map1 = new HashMap<>();
        Map<String, Character> map2 = new HashMap<>();
        String[] split = str.split(" ");

        if(split.length != pattern.length())
            return false;

        for(int i=0; i<split.length; i++) {
            char c = pattern.charAt(i);
            String word = split[i];
            if(!map1.containsKey(c)) {
                if(map2.containsKey(word))
                    return false;
                else {
                    map1.put(c, word);
                    map2.put(word, c);
                }
            } else {
                String mapped = map1.get(c);
                if(!mapped.equals(word))
                    return false;
            }
        }
        return true;
    }

    public static void main(String args[]) {
        String pattern = "abba";
        String str = "dog cat cat dog";
        System.out.println(wordPattern(pattern, str));
    }
}
