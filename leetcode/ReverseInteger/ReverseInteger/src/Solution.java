/**
 * Created by spandan on 8/24/14.
 * status = AC
 */

public class Solution {

    private boolean addOvf(int x, int y) {

        if (x > 0 && y > Integer.MAX_VALUE - x)
            return true;

        else if (x < 0 && y < Integer.MIN_VALUE - x)
            return true;

        else
            return false;
    }

    private boolean mulOvf(int x, int y){

        if (x == 0 || y == 0)
            return false;

        if (x > 0 && y > 0 && y > Integer.MAX_VALUE / x)
            return true;

        else if (x < 0 && y < 0 && Math.abs(y) > Integer.MAX_VALUE / Math.abs(x))
            return true;

        else if (x > 0 && y < Integer.MIN_VALUE / x)
            return true;

        else if (x < 0 && x < Integer.MIN_VALUE / y)
            return true;

        else
            return false;
    }

    private boolean OverFlow(int res, int num){

        if (mulOvf(res,10))
            return true;
        else
            return addOvf(10*res, num);
    }

    public int reverse(int x){

        int rev_num = 0;
        int sign = x > 0 ? 1 : -1;

        x = Math.abs(x);

        while (x > 0) {

            if (OverFlow(rev_num, sign * (x % 10))) {
                if(sign < 0)
                    return Integer.MIN_VALUE;
                else
                    return Integer.MAX_VALUE;
            }

            rev_num = 10 * rev_num + sign * (x % 10);
            x /= 10;
        }

        return rev_num;
    }

    public static void main(String[] args) {

        Solution soln = new Solution();

        int x = 1000000003;
        System.out.println(soln.reverse(x));
    }
}
