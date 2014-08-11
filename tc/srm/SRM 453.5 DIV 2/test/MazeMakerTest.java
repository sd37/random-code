import org.junit.Test;
import static org.junit.Assert.*;

public class MazeMakerTest {
	
	@Test(timeout=2000)
	public void test0() {
		String[] maze = new String[] {"...",
 "...",
 "..."};
		int startRow = 0;
		int startCol = 1;
		int[] moveRow = new int[] {1,0,-1,0};
		int[] moveCol = new int[] {0,1,0,-1};
		assertEquals(3, new MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol));
	}
	
	@Test(timeout=2000)
	public void test1() {
		String[] maze = new String[] {"...",
 "...",
 "..."};
		int startRow = 0;
		int startCol = 1;
		int[] moveRow = new int[] {1, 0, -1, 0, 1, 1, -1, -1};
		int[] moveCol = new int[] {0, 1, 0, -1, 1, -1, 1, -1};
		assertEquals(2, new MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol));
	}
	
	@Test(timeout=2000)
	public void test2() {
		String[] maze = new String[] {"X.X",
 "...",
 "XXX",
 "X.X"};
		int startRow = 0;
		int startCol = 1;
		int[] moveRow = new int[] {1, 0, -1, 0};
		int[] moveCol = new int[] {0, 1, 0, -1};
		assertEquals(-1, new MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol));
	}
	
	@Test(timeout=2000)
	public void test3() {
		String[] maze = new String[] {".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."};
		int startRow = 5;
		int startCol = 0;
		int[] moveRow = new int[] {1, 0, -1, 0,-2, 1};
		int[] moveCol = new int[] {0, -1, 0, 1, 3, 0};
		assertEquals(7, new MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol));
	}
	
	@Test(timeout=2000)
	public void test4() {
		String[] maze = new String[] {"......."};
		int startRow = 0;
		int startCol = 0;
		int[] moveRow = new int[] {1, 0, 1, 0, 1, 0};
		int[] moveCol = new int[] {0, 1, 0, 1, 0, 1};
		assertEquals(6, new MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol));
	}
	
	@Test(timeout=2000)
	public void test5() {
		String[] maze = new String[] {"..X.X.X.X.X.X."};
		int startRow = 0;
		int startCol = 0;
		int[] moveRow = new int[] {2,0,-2,0};
		int[] moveCol = new int[] {0,2,0,-2};
		assertEquals(-1, new MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol));
	}
}
