/**
 * Created by spandan on 8/17/14.
 */
public class Solution
{

    public int height(TreeNode root)
    {
        if (root == null)
            return 0;
        return 1 + Math.max(height(root.left),height(root.right));
    }

    public boolean isBalanced(TreeNode root)
    {
        if (root == null)
            return true;

        return (Math.abs(height(root.left) - height(root.right)) <= 1
                && isBalanced(root.left)
                && isBalanced(root.right));
    }

    public static void main(String[] args)
    {
        TreeNode tr = new TreeNode(1, new TreeNode(2), new TreeNode(3));

        Solution soln = new Solution();

        System.out.println(soln.isBalanced(tr));

    }
}
