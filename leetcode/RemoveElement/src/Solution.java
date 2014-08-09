import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by spandan on 8/8/14.
 */

public class Solution {

    public int removeElement(int[] A,int elem)
    {
        List<Integer> alist = new ArrayList<Integer>();

        for (int i = 0; i < A.length; i++)
        {
            if (A[i] == elem)
                continue;

            alist.add(A[i]);
        }

        for(int i = 0; i < alist.size(); i++)
        {
            A[i] = alist.get(i);
        }

        return alist.size();
    }

    public static void main(String[] args)
    {
        Solution soln = new Solution();
        int[] A = {4,5};
        System.out.println("remainder = " + soln.removeElement(A,4));
    }
}
