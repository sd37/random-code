/**
 * Created by spandan on 8/17/14.
 */
public class Solution {

    public int singleNumber(int[] A)
    {
        int ans = 0;

        for (int i = 0; i < A.length; i++)
        {
            ans = ans ^ A[i];
        }

        return ans;
    }

    public static void main(String[] args) {
        int[] A = {1,2,2,3,3};
        Solution soln = new Solution();
        System.out.println(soln.singleNumber(A));
    }
}
