/**
 * Created by spandan on 8/17/14.
 */
public class TreeNode {

    public int val;
    public TreeNode left;
    public TreeNode right;

    TreeNode(int val)
    {
        this.val    = val;
        this.left   = null;
        this.right  = null;
    }

    TreeNode(int val, TreeNode left, TreeNode right)
    {
        this.val    = val;
        this.left   = left;
        this.right  = right;
    }
}
