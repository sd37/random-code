package soln;

public class Solution
{
    public int lengthOfLastWord(String s)
    {
        String[] parts = s.trim().split("\\s+");

        return parts[parts.length - 1].length();
    }

    public static final void main(String[] args)
    {
        String s = "";

        Solution soln = new Solution();

        System.out.println(soln.lengthOfLastWord(s));
    }
}
