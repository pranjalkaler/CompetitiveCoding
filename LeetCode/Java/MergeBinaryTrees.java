//Easy - https://leetcode.com/problems/merge-two-binary-trees/
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

public class MergeBinaryTrees {
    public static TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if(t1 == null)
            return t2;
        if(t2 == null)
            return t1;

        t1.val += t2.val;
        t1.left = mergeTrees(t1.left, t2.left);
        t1.right = mergeTrees(t1.right, t2.right);

        return t1;
    }

    public static void main(String args[]) {
      TreeNode t1 = new TreeNode(3);
      TreeNode t2 = new TreeNode(2, t1, null);
      TreeNode t3 = new TreeNode(4);
      TreeNode t4 = new TreeNode(1, t3, t2);

      TreeNode t5 = new TreeNode(6);
      TreeNode t6 = new TreeNode(5);
      TreeNode t7 = new TreeNode(4, t5, t6);

      TreeNode result = mergeTrees(t4, t7);
    }
}
