/* https://oj.leetcode.com/problems/valid-palindrome/
 * Status = AC     
 */

package soln;

public class Solution
{
    public boolean isPalindrome(String s)
    {
        String new_s = s.replaceAll("[^a-zA-Z0-9]","");
        new_s = new_s.toLowerCase();
        
        return new_s.equals( (new StringBuilder(new_s)).reverse().toString() );
    }

    public static final void main(String[] args)
    {
        String s = "A man, a plan, a canal: Panama";

        Solution soln = new Solution();

        System.out.println(soln.isPalindrome(s));
    }
}
