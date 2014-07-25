import java.util.Scanner;

public class ZOJ3654AC {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String str;
		String[] nums;
		char[] ops;
		long x, y;
		long op;
		long res;
		int i, j;

		while (scanner.hasNext()) {
			str = scanner.next();
			x = scanner.nextLong();
			y = scanner.nextLong();

			if (x == 9) {
				System.out.println("A");
				continue;
			} else if (y == 9) {
				System.out.println("B");
				continue;
			}

			if (str.charAt(0) >= '0' && str.charAt(0) <= '9') {
				str = "+" + str;
			}
			nums = str.split("\\+|\\-");
			ops = new char[nums.length];
			j = 1;
			for (i = 0; i < str.length(); ++i) {
				if (str.charAt(i) == '+' || str.charAt(i) == '-') {
					ops[j++] = str.charAt(i);
				}
			}
			
			res = 0;
			for (i = 1; i < nums.length; ++i) {
				op = Long.parseLong(nums[i]);
				res += op * (ops[i] == '+' ? +1 : -1);
			}
			
			System.out.println(res == x ? "B" : "A");
		}
	}
}
