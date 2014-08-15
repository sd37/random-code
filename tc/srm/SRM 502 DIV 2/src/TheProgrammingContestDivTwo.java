import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class TheProgrammingContestDivTwo {
	
	public int[] find(int T, int[] requiredTime) {

        int[] score = new int[2];

        score[0] = 0; // solved
        score[1] = 0; // penalty

        Arrays.sort(requiredTime);

        int curr_time = 0;

        for (int i = 0; i < requiredTime.length; i++)
        {
            if (requiredTime[i] <= T)
            {
                score[0]++;
                curr_time += requiredTime[i];
                score[1]+= curr_time;
                T -= requiredTime[i];
            }
            else
                break;
        }

		return score;
	}
}
