public class MinimumTime {
    public static int minTimeToVisitAllPoints(int[][] points) {
        int time = 0;
        for(int i=1; i<points.length; ++i) {
            time += Math.max(Math.abs(points[i][0] - points[i-1][0]), Math.abs(points[i][1] - points[i-1][1]));
        }
        return time;
    }

    public static void main(String args[]) {
        int[][] input = {{1,1},{3,4},{-1,0}};
        System.out.println(minTimeToVisitAllPoints(input));
    }
}
