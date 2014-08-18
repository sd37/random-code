/**
 * Created by spandan on 8/17/14.
 */
public class Solution {

    public boolean isSameTree(TreeNode p, TreeNode q)
    {
        if(p == null && q == null)
            return true;

        if (p == null || q == null)
            return false;

        return (p.val == q.val
                && isSameTree(p.left,q.left)
                && isSameTree(p.right,q.right));
    }

    public static void main(String[] args) {

        Solution soln = new Solution();

        TreeNode p = new TreeNode(1,new TreeNode(2), new TreeNode(3));
        TreeNode q = new TreeNode(1,new TreeNode(2), new TreeNode(3));

        System.out.println(soln.isSameTree(p,q));
    }
}
