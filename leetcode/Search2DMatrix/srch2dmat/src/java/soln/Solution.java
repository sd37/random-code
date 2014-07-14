/* https://oj.leetcode.com/problems/search-a-2d-matrix/
 * Status AC
 */
package soln;

public class Solution
{
    private boolean isPresent(int[] arr, int target)
    {
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[i] == target)
                return true;
        }

        return false;
    }

    public boolean searchMatrix(int[][] matrix, int target)
    {
        int rows = matrix.length;
        assert rows != 0;
        int cols = matrix[0].length;
        assert cols !=0;

        for(int r = 0; r < rows; r++)
        {
            if( target < matrix[r][cols - 1])
                return isPresent(matrix[r],target);
            
            else if (target > matrix[r][cols - 1])
                continue;
            else
                return true;
        }
        
        return false;
    }

    public static final void main(String[] args)
    {
        int[][] matrix = new int[][]{
            
            new int[]  {1, 3, 5, 7},
            new int[]  {10, 11, 16, 20},
            new int[]  {23, 30, 34, 50},
        };

        Solution soln = new Solution();

        System.out.println(soln.searchMatrix(matrix, 17));
    }
}
