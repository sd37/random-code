//Author : spandan Dutta
//Performance:
//time java -cp . PrintFactors 1000000 | wc -l
//1043
//real	0m0.188s
//user	0m0.256s
//sys	0m0.028s

public class PrintFactors {

	private void printDivisorList(int num,String solution_string,int left_over_number)
	{
		
		int tmp = left_over_number;
		
		for(int i = num / 2; i >= 2; i--)
		{
			if(tmp > i)
				tmp = i; //left_over
			
			if(num % i == 0 )
			{
				// i is the divisor of num
				
				if(num / i <= i && i <= left_over_number && num / i <= left_over_number)
				{
					System.out.println(solution_string + i + "*" + num / i);
					tmp = num / i; //left_over
				}
				
				if(i <= left_over_number)
					printDivisorList(num / i, solution_string + i + "*",tmp);
			}	
		}
	}
	
	public void printAllDivisorCombinations(int num)
	{
		//first print the obvious combination which is : num * 1
		
		System.out.println(num + "*" + "1");
		
		//print all the possible combinations of divisors one row at a time
		
		printDivisorList(num,"",num);
	}
	
	public static void main(String[] args) 
	{
		if(args.length < 1)
		{
			System.out.println("USAGE: java -cp . PrintFactors number");
			return;
		}	
		int num = Integer.parseInt(args[0]);
		
		//sanity check
		//assumption: number is +ve (as given in the problem statement)
		
		if (num == 0)
		{
			System.out.println("INPUT ERROR : Number is 0");
			return;
		}
		
		if (num < 0)
		{
			System.out.println("INPUT ERROR : Number is -ve");
			return;
		}
		
		//Compute the solution to the problem
		
		PrintFactors pf = new PrintFactors();
		pf.printAllDivisorCombinations(num);
			
	}

}
