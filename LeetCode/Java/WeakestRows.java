//Question link - https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
//Author - Saumya Sachdev

public class WeakestRows {
    public static int[] kWeakestRows(int[][] mat, int k) {
        int[][] soldiers = new int[mat.length][2];
        for(int i=0; i<mat.length; i++) {
            soldiers[i][0] = i;
            for(int j=0; j<mat[0].length; j++) {
                if(mat[i][j] == 1)
                  soldiers[i][1]++;
            }
        }

        for(int i=0; i<soldiers.length; i++) {
            for(int j=1; j<(soldiers.length-i); j++) {
                if(soldiers[j-1][1] > soldiers[j][1]) {
                    int temp1 = soldiers[j][1];
                    int temp2 = soldiers[j][0];
                    soldiers[j][1] = soldiers[j-1][1];
                    soldiers[j][0] = soldiers[j-1][0];
                    soldiers[j-1][1] = temp1;
                    soldiers[j-1][0] = temp2;
                }
            }
        }

        int[] result = new int[k];
        for(int i=0; i<k; i++)
            result[i] = soldiers[i][0];

        return result;
    }

    public static void main(String args[]) {
        int[][] input = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
        int[] result = kWeakestRows(input, 3);
        for(int i=0; i<3; i++)
          System.out.println(result[i]);
    }
}
