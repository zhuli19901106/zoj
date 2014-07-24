import java.util.Scanner;

public class ZOJ2240AC {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String string;
		StringBuilder sb1 = new StringBuilder();
		StringBuilder sb2 = new StringBuilder();
		int i, j;
		int repeatLen;

		while (scanner.hasNextLine()) {
			string = scanner.nextLine();

			sb1.setLength(0);
			sb2.setLength(0);

			i = 0;
			while (i < string.length()) {
				repeatLen = 1;
				while (i + repeatLen < string.length()
						&& string.charAt(i) == string.charAt(i + repeatLen) && repeatLen < 9) {
					++repeatLen;
				}
				if (repeatLen > 1) {
					if (sb2.length() > 0) {
						sb1.append('1');
						for (j = 0; j < sb2.length(); ++j) {
							if (sb2.charAt(j) == '1') {
								sb1.append("11");
							} else {
								sb1.append(sb2.charAt(j));
							}
						}
						sb2.setLength(0);
						sb1.append('1');
					}
					sb1.append(repeatLen);
					sb1.append(string.charAt(i));
				} else {
					sb2.append(string.charAt(i));
				}

				i += repeatLen;
			}
			if (sb2.length() > 0) {
				sb1.append('1');
				for (j = 0; j < sb2.length(); ++j) {
					if (sb2.charAt(j) == '1') {
						sb1.append("11");
					} else {
						sb1.append(sb2.charAt(j));
					}
				}
				sb2.setLength(0);
				sb1.append('1');
			}

			System.out.println(sb1);
		}
	}
}
