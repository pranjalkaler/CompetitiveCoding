
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

public class SubtreeOrNot {
    public static boolean isSubtree(TreeNode s, TreeNode t) {
        if(s == null)
            return false;

        if(isIdentical(s, t))
            return true;

        return isSubtree(s.left, t) || isSubtree(s.right, t);
    }

    public static boolean isIdentical(TreeNode s, TreeNode t) {
        if(s == null && t == null)
            return true;
        if(s == null || t == null)
            return false;
        if(s.val != t.val)
            return false;
        return isIdentical(s.left, t.left) && isIdentical(s.right, t.right);
    }

    public static void main(String args[]) {
      TreeNode t1 = new TreeNode(3);
      TreeNode t2 = new TreeNode(2, t1, null);
      TreeNode t3 = new TreeNode(4);
      TreeNode t4 = new TreeNode(1, t3, t2);
      System.out.println(isSubtree(t4, t2));
    }
}
