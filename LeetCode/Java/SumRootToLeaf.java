
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

public class SumRootToLeaf {
    public static int sumRootToLeaf(TreeNode root) {
        return dfs(root, 0);
    }

    public static int dfs(TreeNode root, int val) {
        if(root == null)
            return 0;
        val = val * 2 + root.val;
        if(root.left == null && root.right == null)
            return val;
        else
            return dfs(root.left, val) + dfs(root.right, val);
    }

    public static void main(String args[]) {
      TreeNode t1 = new TreeNode(0);
      TreeNode t2 = new TreeNode(1);
      TreeNode t3 = new TreeNode(1, t1, t2);
      TreeNode t4 = new TreeNode(0);
      TreeNode t5 = new TreeNode(1, t3, t4);

      System.out.println(sumRootToLeaf(t5));
    }
}
