import java.util.*;

public class UncommonWords {
    public static String[] uncommonFromSentences(String A, String B) {
        Map<String, Integer> freq = new HashMap<>();
        for(String s : (A + " " + B).split(" ")) {
            freq.put(s, freq.getOrDefault(s,0) + 1);
        }
        List<String> result = new ArrayList<>();
        Set<Map.Entry<String, Integer>> set = freq.entrySet();

        for(Map.Entry<String, Integer> it : set) {
            if(it.getValue() == 1)
                result.add(it.getKey());
        }
        String[] array = new String[result.size()];
        result.toArray(array);
        return array;
    }

    public static void main(String args[]) {
        String[] uncommon = uncommonFromSentences("apple apple", "orange");
        System.out.println(Arrays.toString(uncommon));
    }
}
