package soln;

public class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder(s);

        sb.reverse();

        String[] parts = sb.toString().split("\\s+");
        
        String new_s = "";


        for(String it : parts)
        {
            StringBuilder temp_sb = new StringBuilder(it);
            temp_sb.reverse();
            new_s += temp_sb + " ";
        }
       
        String ans_s = null;

        if(new_s.charAt(new_s.length() -1) == ' ')
            ans_s = new_s.substring(0, new_s.length() - 1);
        else 
            ans_s = new_s;
        
        return ans_s;
    }

    public static final void main(String[] args) {
        String s = "   the   sky is   blue";

        Solution soln = new Solution();

        String ans_s = soln.reverseWords(s);

        System.out.println(ans_s);
    }
}
