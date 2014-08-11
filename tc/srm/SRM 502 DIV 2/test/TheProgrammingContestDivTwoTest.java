import org.junit.Test;
import static org.junit.Assert.*;

public class TheProgrammingContestDivTwoTest {
	
	@Test(timeout=2000)
	public void test0() {
		int T = 74;
		int[] requiredTime = new int[] {47};
		assertArrayEquals(new int[] {1, 47 }, new TheProgrammingContestDivTwo().find(T, requiredTime));
	}
	
	@Test(timeout=2000)
	public void test1() {
		int T = 74;
		int[] requiredTime = new int[] {4747};
		assertArrayEquals(new int[] {0, 0 }, new TheProgrammingContestDivTwo().find(T, requiredTime));
	}
	
	@Test(timeout=2000)
	public void test2() {
		int T = 47;
		int[] requiredTime = new int[] {8, 5};
		assertArrayEquals(new int[] {2, 18 }, new TheProgrammingContestDivTwo().find(T, requiredTime));
	}
	
	@Test(timeout=2000)
	public void test3() {
		int T = 47;
		int[] requiredTime = new int[] {12, 3, 21, 6, 4, 13};
		assertArrayEquals(new int[] {5, 86 }, new TheProgrammingContestDivTwo().find(T, requiredTime));
	}
	
	@Test(timeout=2000)
	public void test4() {
		int T = 58;
		int[] requiredTime = new int[] {4, 5, 82, 3, 4, 65, 7, 6, 8, 7, 6, 4, 8, 7, 6, 37, 8};
		assertArrayEquals(new int[] {10, 249 }, new TheProgrammingContestDivTwo().find(T, requiredTime));
	}
	
	@Test(timeout=2000)
	public void test5() {
		int T = 100000;
		int[] requiredTime = new int[] {100000};
		assertArrayEquals(new int[] {1, 100000 }, new TheProgrammingContestDivTwo().find(T, requiredTime));
	}
}
