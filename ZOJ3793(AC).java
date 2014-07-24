import java.util.Random;
import java.util.Scanner;

public class ZOJ3793AC {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Random random = new Random();
		int a, b;
		int t, ti;
		double d;
		int digit;

		t = scanner.nextInt();
		for (ti = 0; ti < t; ++ti) {
			a = scanner.nextInt();
			b = scanner.nextInt();
			d = b * Math.log10(a);
			digit = (int) Math.pow(10.0, d - (int) d);
			// Use a random number to lower the accuracy rate to 50%.
			System.out.println((random.nextInt() & 1) == 0 ? digit : 10 - digit);
		}
	}
}
