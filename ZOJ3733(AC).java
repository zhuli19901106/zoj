import java.util.Scanner;

public class ZOJ3733AC {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		final int A_BIG_INTEGER = 1000000000;

		double rBig, rSmall;
		double h;
		int f;
		double s;

		int sideNum;
		double sideLen;
		int ll, rr, mm;
		double r;
		double hLevel;
		double minSideLen;
		double totalArea;

		while (scanner.hasNext()) {
			rBig = scanner.nextDouble();
			rSmall = scanner.nextDouble();
			h = scanner.nextDouble();
			f = scanner.nextInt();
			s = scanner.nextDouble();

			hLevel = h / f;
			minSideLen = s / hLevel;

			totalArea = 0.0;
			for (int i = 0; i < f; ++i) {
				r = rSmall + (rBig - rSmall) / f * i;
				ll = 3;
				rr = A_BIG_INTEGER;
				while (rr - ll > 1) {
					mm = (ll + rr) / 2;
					sideLen = 2 * r * Math.tan(Math.PI / mm);
					if (sideLen < minSideLen) {
						rr = mm;
					} else {
						ll = mm;
					}
				}
				sideNum = ll;
				sideLen = r * Math.tan(Math.PI / sideNum);
				totalArea += 2 * sideLen * hLevel * sideNum;
			}
			System.out.printf("%.3f\n", totalArea);
		}
	}
}
