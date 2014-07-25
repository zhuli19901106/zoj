import java.util.Scanner;

public class ZOJ2006AC {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t, ti;
		String s;
		int i, j, k;
		int len;
		
		t = scanner.nextInt();
		for (ti = 0; ti < t; ++ti) {
			s = scanner.next();
			len = s.length();
			s = s + s;
			i = 0;
			j = 1;
			k = 0;
			while (i < len && j < len) {
				if (s.charAt(i + k) == s.charAt(j + k)) {
					++k;
					if (k == len) {
						break;
					}
				} else {
					if (s.charAt(i + k) < s.charAt(j + k)) {
						j += k + 1;
					} else {
						i += k + 1;
					}
					
					if (i == j) {
						++j;
					}
					k = 0;
				}
			}
			
			System.out.println(Math.min(i, j) + 1);
		}
	}
}
