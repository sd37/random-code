import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by spandan on 8/24/14.
 * status = AC
 */
public class Solution {

    public static void main(String[] args) {

        Solution soln = new Solution();

        int[] digits = {9,9,9,9,9,9,9,9,9};

        int[] ans = soln.plusOne(digits);

        for (Integer i : ans)
            System.out.print(i);
    }

    public int[] plusOne(int[] digits) {

        List<Integer> lst_digits = new ArrayList<Integer>();

        for (Integer i : digits){
            lst_digits.add(i);
        }

        Collections.reverse(lst_digits);

        int carry = 0;

        for (int i = 0; i < lst_digits.size(); i++){

            int tmp_dig = lst_digits.get(i) + carry + (i == 0 ? 1 : 0);

            lst_digits.set(i, tmp_dig % 10);

            carry = tmp_dig / 10;
        }

        if (carry > 0)
            lst_digits.add(carry);

        Collections.reverse(lst_digits);

        int[] ans = new int[lst_digits.size()];

        for (int i = 0; i < lst_digits.size(); i++)
            ans[i] = lst_digits.get(i);

        return ans;
    }
}
