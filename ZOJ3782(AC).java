import java.util.Scanner;

public class ZOJ3782AC {
	static int type(char op) {
		if (op == '+' || op == '-') {
			return 1;
		} else if (op == '*' || op == '/' || op == '%') {
			return 2;
		} else {
			return 0;
		}
	}
	
	static int calc(int op1, int op2, char op) {
		switch (op) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		case '%':
			return op1 % op2;
		default:
			return Integer.MIN_VALUE;
		}
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t, ti;
		int a, b, c;
		String str;
		char op1, op2;
		int type1, type2;
		int result;
		
		t = scanner.nextInt();
		for (ti = 0; ti < t; ++ti) {
			a = scanner.nextInt();
			str = scanner.next();
			op1 = str.charAt(0);
			b = scanner.nextInt();
			str = scanner.next();
			op2 = str.charAt(0);
			c = scanner.nextInt();
			
			type1 = type(op1);
			type2 = type(op2);
			
			if (type1 == type2 || type1 == 2) {
				result = calc(calc(a, b, op1), c, op2);
			} else {
				result = calc(a, calc(b, c, op2), op1);
			}
			System.out.println(result);
		}
	}
}
