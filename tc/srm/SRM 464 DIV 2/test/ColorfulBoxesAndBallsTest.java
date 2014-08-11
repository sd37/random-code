import org.junit.Test;
import static org.junit.Assert.*;

public class ColorfulBoxesAndBallsTest {
	
	@Test(timeout=2000)
	public void test0() {
		int numRed = 2;
		int numBlue = 3;
		int onlyRed = 100;
		int onlyBlue = 400;
		int bothColors = 200;
		assertEquals(1400, new ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors));
	}
	
	@Test(timeout=2000)
	public void test1() {
		int numRed = 2;
		int numBlue = 3;
		int onlyRed = 100;
		int onlyBlue = 400;
		int bothColors = 300;
		assertEquals(1600, new ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors));
	}
	
	@Test(timeout=2000)
	public void test2() {
		int numRed = 5;
		int numBlue = 5;
		int onlyRed = 464;
		int onlyBlue = 464;
		int bothColors = 464;
		assertEquals(4640, new ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors));
	}
	
	@Test(timeout=2000)
	public void test3() {
		int numRed = 1;
		int numBlue = 4;
		int onlyRed = 20;
		int onlyBlue = -30;
		int bothColors = -10;
		assertEquals(-100, new ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors));
	}
	
	@Test(timeout=2000)
	public void test4() {
		int numRed = 9;
		int numBlue = 1;
		int onlyRed = -1;
		int onlyBlue = -10;
		int bothColors = 4;
		assertEquals(0, new ColorfulBoxesAndBalls().getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors));
	}
}
