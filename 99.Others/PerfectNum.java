/**
  If sum of factors of a number is equal to number
  e.g. - 
   6 = 1+2+3
  28 = 1+2+4+7+14
 */
import java.io.*;
class PerfectNum
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter a number ");
		int n = Integer.parseInt(br.readLine());
		int s = 0;
		for(int i=1;i<=n/2;i++)
		{
			if(n%i == 0)
			{
				s = s+i;
			}
		}
		if(s == n)
			System.out.println(n + " is perfect number");
		else
			System.out.println(n + " is not perfect number");
	}
}