import org.junit.Test;
import static org.junit.Assert.*;

public class ToolsBoxTest {
	
	@Test(timeout=2000)
	public void test0() {
		String[] need = new String[] {"SAW HAMMER SCREWDRIVER","SCREWDRIVER HAMMER KNIFE"};
		assertEquals(4, new ToolsBox().countTools(need));
	}
	
	@Test(timeout=2000)
	public void test1() {
		String[] need = new String[] {"SAW"};
		assertEquals(1, new ToolsBox().countTools(need));
	}
	
	@Test(timeout=2000)
	public void test2() {
		String[] need = new String[] {"SAW","SAW"};
		assertEquals(1, new ToolsBox().countTools(need));
	}
}
