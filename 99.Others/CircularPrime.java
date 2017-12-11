/**
	Program to check for circular Prime number
	Eg. 113, 1193, 19937
*/
import java.io.*;
import java.util.*;

class CPrime {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number ");
		int n = sc.nextInt();
		if(checkCircular(n))
			System.out.printf("%d is circular Prime.", n);
		else
			System.out.printf("%d is not circular Prime.", n);
	}
	
	static boolean checkCircular(int n) {
		int count = 0;
		int temp = n;
		while(temp > 0) {
			count++;
			temp = temp/10;
		}
		int num = n;
		while(isPrime(num)) {
			int rem = num%10;
			int div = num/10;
			num = (int)(Math.pow(10,count-1)*rem) + div;
			if(num == n)
			return true;
		}
		return false;
	}
	
	static boolean isPrime(int n) {
		for(int i=2;i <= Math.sqrt(n);i++) {
			if(n % i == 0) {
				return false;
			}
		}
		return true;
	}
}