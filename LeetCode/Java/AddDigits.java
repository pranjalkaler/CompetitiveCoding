import java.util.*;

public class AddDigits {
    public static int addDigits(int num) {
        int sum = 0;
        List<Integer> digits = new ArrayList<Integer>();
        while(num > 0) {
            digits.add(num % 10);
            num = num / 10;
        }
        
        for(int i=0; i<digits.size(); i++) {
            sum = sum + digits.get(i); 
        }
        
        if(sum%10 == sum)
            return sum;
        else
            return addDigits(sum);
    }
    
    public static void main(String args[]) {
        int sum = addDigits(654);
        System.out.println(sum);
    }
}
