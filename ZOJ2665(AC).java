import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int n;
		int i, j;
		int[] data;
		int[] idx;

		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNextInt()) {
			n = scanner.nextInt();

			if (n == 1) {
				System.out.println("1");
				continue;
			}

			data = new int[n];
			idx = new int[n];

			for (i = 0; i < n; ++i) {
				idx[i] = i;
			}
			data[0] = n;
			data[n - 1] = 1;

			int tmp1, tmp2;
			for (i = n - 2; i > 0; --i) {
				j = i;
				tmp1 = idx[j];
				while (j > 0) {
					tmp2 = idx[(j - 1) / 2];
					idx[(j - 1) / 2] = tmp1;
					tmp1 = tmp2;
					j = (j - 1) / 2;
				}
				data[idx[0]] = i + 1;
			}

			for (i = 0; i < n; ++i) {
				System.out.print(data[i] + (i == n - 1 ? "\n" : " "));
			}
		}
	}
}
