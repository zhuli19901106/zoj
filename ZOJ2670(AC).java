import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n;
		int i, j;
		int value;
		
		while (scanner.hasNextInt()) {
			n = scanner.nextInt();
			for (i = 0; i < n; ++i) {
				for (j = 0; j < n; ++j) {
					value = i < j ? 1 : i > j ? 0 : i == n - 1 ? 100 : 0;
					System.out.print(value + (j == n - 1 ? "\n" : " "));
				}
			}
			System.out.println();
		}
	}
}
