import java.util.Scanner;

public class ZOJ2067AC {
	public static void main(String[] args) {
		final int MAXN = 100;
		int[][] rightDP = new int[MAXN][MAXN];
		int[][] downDP = new int[MAXN][MAXN];
		int[][] arr = new int[MAXN][MAXN];
		int n;
		Scanner scanner = new Scanner(System.in);
		String str;
		int i, j, k;
		int minValue;
		int result;

		while (scanner.hasNextInt()) {
			n = scanner.nextInt();
			for (i = 0; i < n; ++i) {
				str = scanner.next();
				for (j = 0; j < n; ++j) {
					arr[i][j] = str.charAt(j) == '.' ? 1 : 0;
				}
			}

			for (i = 0; i < n; ++i) {
				rightDP[i][n - 1] = arr[i][n - 1] == 1 ? 1 : 0;
				for (j = n - 2; j >= 0; --j) {
					rightDP[i][j] = arr[i][j] == 1 ? rightDP[i][j + 1] + 1 : 0;
				}
			}

			for (j = 0; j < n; ++j) {
				downDP[n - 1][j] = arr[n - 1][j] == 1 ? 1 : 0;
				for (i = n - 2; i >= 0; --i) {
					downDP[i][j] = arr[i][j] == 1 ? downDP[i + 1][j] + 1 : 0;
				}
			}

			result = 0;
			for (i = 0; i < n; ++i) {
				for (j = 0; j < n; ++j) {
					if (arr[i][j] == 0) {
						continue;
					}
					minValue = Integer.MAX_VALUE;
					for (k = 0; k < rightDP[i][j]; ++k) {
						minValue = Math.min(minValue, downDP[i][j + k]);
						result += minValue;
					}
				}
			}
			
			System.out.println(result);
		}
	}
}
