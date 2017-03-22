import java.io.*;
import java.util.*;

class Prime{
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter a number");
    int n = sc.nextInt();
    boolean isPrime = true;
    for(int i = 2; i <= Math.sqrt(n); i++) {
      if(n%i == 0) {
        isPrime = false;
        break;
      }
    }
    if(isPrime) {
      System.out.println(n + " is Prime.");
    } else {
      System.out.println(n + " is not Prime.");
    }
  }
}