//Question - Easy - https://leetcode.com/problems/cousins-in-binary-tree/
//Author - Saumya Sachdev

class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
     TreeNode() {}
     TreeNode(int val) { this.val = val; }
     TreeNode(int val, TreeNode left, TreeNode right) {
         this.val = val;
         this.left = left;
          this.right = right;
    }
 }

public class CousinsOrNot {
    static int levelX, levelY;
    static TreeNode parentX, parentY;
    public static boolean isCousins(TreeNode root, int x, int y) {
        getLevel(root, x, y, 0, null);
        if(levelX == levelY) {
            if(parentX == parentY)
                return false;
            else
                return true;
        }
        return false;
    }

    public static void getLevel(TreeNode root, int x, int y, int level, TreeNode parent) {
        if(root == null)
            return;
        if(root.val == x) {
            levelX = level;
            parentX = parent;
        }
        if(root.val == y) {
            levelY = level;
            parentY = parent;
        }
        getLevel(root.left, x, y, level + 1, root);
        getLevel(root.right, x, y, level + 1, root);
    }

    public static void main(String agrs[]) {
        TreeNode t1 = new TreeNode(3);
        TreeNode t2 = new TreeNode(2, t1, null);
        TreeNode t3 = new TreeNode(4);
        TreeNode t4 = new TreeNode(1, t3, t2);
        System.out.println(isCousins(t4, 2, 4));
    }
}
