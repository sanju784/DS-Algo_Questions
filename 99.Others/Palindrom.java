/**
  Check for Palindrom Number and String
  Number or string which is same from both front and end
 */
import java.io.*;
import static java.lang.System.out;
class Palindrom
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		out.println("Enter a String ");
		String str = br.readLine();
		String newStr = "";
		for (int i=str.length()-1;i>=0;i--)
		{
			newStr = newStr + str.charAt(i);
		}
		if (str.equals(newStr))
		{
			out.println(str + " is Palindrom");
		} else {
			out.println(str + " is not Palindrom");
		}
		
		out.println("\nEnter a number ");
		int n = Integer.parseInt(br.readLine());
		int t = n, s=0;
		while (t > 0)
		{
			int r = t%10;
			t = t/10;
			s = s*10 + r;
		}
		if(n == s)
		{
			out.println(n + " is Palindrom");
		} else {
			out.println(n + " is not Palindrom");
		}
	}
}