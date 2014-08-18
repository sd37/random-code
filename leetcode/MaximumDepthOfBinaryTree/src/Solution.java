/**
 * Created by spandan on 8/17/14.
 */
public class Solution {

    public int maxDepth(TreeNode root)
    {
        if(root == null)
            return 0;

        return 1 + Math.max(maxDepth(root.getLeft()), maxDepth(root.getRight()));
    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(3,new TreeNode(1), new TreeNode(2));

        Solution soln = new Solution();
        System.out.println(soln.maxDepth(root));
    }
}
