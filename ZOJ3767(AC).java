import java.util.Scanner;

public class ZOJ3767AC {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t, ti;
		int n, m;
		int a;
		int i;

		t = scanner.nextInt();
		for (ti = 0; ti < t; ++ti) {
			n = scanner.nextInt();
			m = scanner.nextInt();
			for (i = 0; i < n; ++i) {
				a = scanner.nextInt();
				m -= a;
			}
			if (m >= 0) {
				System.out.println("Safe");
			} else {
				System.out.println("Warning");
			}
		}
	}
}
