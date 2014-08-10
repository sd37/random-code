import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class ToolsBox {
	
	public int countTools(String[] need) {

        Set<String> s = new HashSet<String>();

        for (int i = 0; i < need.length; i++)
        {
            String[] parts = need[i].trim().split("\\s+");

            for (int j = 0; j < parts.length; j++)
            {
                s.add(parts[j]);
            }
        }

		return s.size();
	}
}
