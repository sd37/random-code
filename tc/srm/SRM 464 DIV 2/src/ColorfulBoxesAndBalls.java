import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class ColorfulBoxesAndBalls {
	
	public int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {

        int max_score = Integer.MIN_VALUE;

        int UBx = min(numRed,numBlue);

        for (int x = 0; x <= UBx; x++)
        {
            max_score = max(max_score, (2*x)*bothColors + onlyRed*(numRed - x) + onlyBlue*(numBlue - x));
        }

        return max_score;
	}
}