//LeetCode question - https://leetcode.com/problems/unique-email-addresses/
//Author - Saumya Sachdev

import java.util.*;

public class UniqueEmail {
    public static int numUniqueEmails(String[] emails) {
      Set<String> unique = new HashSet<String>();
      for(int i=0; i<emails.length; i++) {
          String[] split = new String[2];
          split = emails[i].split("@");
          split[0] = split[0].replace(".", "");
          int plusIndex = split[0].indexOf('+');
          if(plusIndex != -1) {
              split[0] = split[0].substring(0, plusIndex);
          }
          unique.add(split[0] + '@' + split[1]);
      }
      return unique.size();
    }

    public static void main(String args[]) {
        String[] list = {"testemail@leetcode.com","testemail1@leetcode.com","testemail+david@lee.tcode.com"};
        int ans = numUniqueEmails(list);
        System.out.println(ans);
    }
}
