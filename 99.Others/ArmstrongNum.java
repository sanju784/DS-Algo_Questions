/**
  If sum of cube of each digit of a number is equal to number
  e.g. - 
  153 = 1*1*1 + 5*5*5 + 3*3*3
 */
import java.io.*;
import java.lang.*;

class ArmstrongNum
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter a number ");
		int n = Integer.parseInt(br.readLine());
		int s = 0;
		int t = n, r;
		while(t > 0)
		{
			r = t%10;
			t=t/10;
			s = s + (int)Math.pow(r,3);
		}
		
		if(n == s)
		{
			System.out.println(n + " is armstrong number ");
		} else {
			System.out.println(n + " is not armstrong number ");
		}
	}
}