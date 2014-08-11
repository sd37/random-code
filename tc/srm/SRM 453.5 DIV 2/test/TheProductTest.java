import org.junit.Test;
import static org.junit.Assert.*;

public class TheProductTest {
	
	@Test(timeout=2000)
	public void test0() {
		int[] numbers = new int[] {7, 4, 7};
		int k = 2;
		int maxDist = 1;
		assertEquals(28L, new TheProduct().maxProduct(numbers, k, maxDist));
	}
	
	@Test(timeout=2000)
	public void test1() {
		int[] numbers = new int[] {7, 4, 7};
		int k = 2;
		int maxDist = 50;
		assertEquals(49L, new TheProduct().maxProduct(numbers, k, maxDist));
	}
	
	@Test(timeout=2000)
	public void test2() {
		int[] numbers = new int[] {-3, -5, -8, -9, -1, -2};
		int k = 3;
		int maxDist = 3;
		assertEquals(-10L, new TheProduct().maxProduct(numbers, k, maxDist));
	}
	
	@Test(timeout=2000)
	public void test3() {
		int[] numbers = new int[] {3, 0, -2, 10, 0, 0, 3, -8, 0, 2};
		int k = 2;
		int maxDist = 2;
		assertEquals(0L, new TheProduct().maxProduct(numbers, k, maxDist));
	}
}
