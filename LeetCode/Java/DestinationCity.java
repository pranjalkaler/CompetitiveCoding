import java.util.*;

public class DestinationCity {
    public static String destCity(List<List<String>> paths) {
        HashMap<String, Integer> freqOrigin = new HashMap<String, Integer>();
        HashMap<String, Integer> freqDest = new HashMap<String, Integer>();

        for(List<String> path : paths) {
            String origin = path.get(0);

            if(freqOrigin.containsKey(origin))
                freqOrigin.put(origin, freqOrigin.get(origin) + 1);
            else
                freqOrigin.put(origin, 1);
        }

        for(List<String> path : paths) {
            String destination = path.get(1);

            if(!freqOrigin.containsKey(destination)) {
                if(freqDest.containsKey(destination))
                    freqDest.put(destination, freqDest.get(destination) + 1);
                else
                    freqDest.put(destination, 1);
            }
        }

        Map.Entry<String, Integer> entry = freqDest.entrySet().iterator().next();
        return entry.getKey();
    }

    public static void main(String args[]) {
      List<List<String>> paths = new ArrayList<>();
      List<String> path1 = new ArrayList<>();
      path1.add("Aligarh");
      path1.add("Bangalore");
      List<String> path2 = new ArrayList<>();
      path2.add("Bangalore");
      path2.add("Chennai");
      paths.add(path1);
      paths.add(path2);
      String destination = destCity(paths);
      System.out.println(destination);
    }
}
