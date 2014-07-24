import java.util.Scanner;

public class ZOJ2207AC {
	static int calcDiff(String s, char[] arr) {
		int diff = 0;
		int i, j;
		int[] m_Pos1, m_Pos2;
		
		m_Pos1 = new int[5];
		m_Pos2 = new int[5];

		for (i = 0; i < 5; ++i) {
			m_Pos1[s.charAt(i) - 'A'] = i;
			m_Pos2[arr[i] - 'A'] = i;
		}

		for (i = 0; i < 5; ++i) {
			for (j = i + 1; j < 5; ++j) {
				if ((m_Pos1[i] - m_Pos1[j]) * (m_Pos2[i] - m_Pos2[j]) < 0) {
					++diff;
				}
			}
		}

		return diff;
	}

	static void nextPermutation(char[] arr) {
		int i, j;

		for (i = arr.length - 2; i >= 0; --i) {
			if (arr[i] < arr[i + 1]) {
				break;
			}
		}
		if (i < 0) {
			return;
		}

		for (j = 4; j > i; --j) {
			if (arr[j] > arr[i]) {
				break;
			}
		}

		char tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;

		reverseArray(arr, i + 1, 4);
	}
	
	static void reverseArray(char[] arr, int left, int right) {
		int i;
		char tmp;

		for (i = left; i < left + right - i; ++i) {
			tmp = arr[i];
			arr[i] = arr[left + right - i];
			arr[left + right - i] = tmp;
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n;
		int i, j;
		int diff;
		int diffSum;
		int minDiffSum;
		String[] rank;
		char[] arr;
		String ans;

		while (scanner.hasNextInt()) {
			n = scanner.nextInt();
			if (n == 0) {
				break;
			}
			rank = new String[n];
			for (i = 0; i < n; ++i) {
				rank[i] = scanner.next();
			}

			ans = null;
			minDiffSum = Integer.MAX_VALUE;
			arr = "ABCDE".toCharArray();
			for (i = 0; i < 120; ++i) {
				diffSum = 0;
				for (j = 0; j < n; ++j) {
					diff = calcDiff(rank[j], arr);
					diffSum += diff;
				}

				if (diffSum < minDiffSum) {
					minDiffSum = diffSum;
					ans = String.copyValueOf(arr);
				}

				nextPermutation(arr);
			}

			System.out.println(ans + " is the median ranking with value "
					+ minDiffSum + ".");
		}
	}
}
