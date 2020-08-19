public class APOrNot {
    public static boolean canMakeArithmeticProgression(int[] arr) {
        java.util.Arrays.sort(arr);
        int diff = arr[1] - arr[0];
        for(int i=0; i < arr.length-1; i++) {
            int temp = arr[i+1] - arr[i];
            if(temp != diff) {
                return false;
            }
        }
        return true;
    }
    
    public static void main(String args[]) {
        int arr[] = {2,4,6,0,10,8};
        boolean result = canMakeArithmeticProgression(arr);
        System.out.println(result);
    }
}
