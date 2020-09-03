//Question - https://leetcode.com/problems/robot-return-to-origin/
//Author - Saumya Sachdev

public class RobotOrigin {
    public static boolean judgeCircle(String moves) {
        int positionX = 0, positionY = 0;

        for(char c : moves.toCharArray()) {
            if(c == 'U')
                positionY++;
            else if(c == 'D')
                positionY--;
            else if(c == 'L')
                positionX--;
            else
                positionX++;
        }

        return (positionX == 0 && positionY == 0) ? true : false;
    }

    public static void main(String args[]) {
      String input = "UDRLLRDU";
      System.out.println(judgeCircle(input));
    }
}
