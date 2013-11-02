import java.util.Scanner;
 public class Main {

     static double vs = 0;
     static double c = 0;
     static double r = 0;
     static double w = 0;
     static int times = 0;

     public static void main(String[] args) {
         Scanner scan = new Scanner(System.in);
         vs = scan.nextDouble();
         r = scan.nextDouble();
         double r2 = r * r;
         double vsr = vs * r;
         c = scan.nextDouble();
         double c2 = c * c;
         times = scan.nextInt();
         for (int i = 0; i < times; i++) {
             w = scan.nextDouble();
             System.out.printf("%.3f\n", vsr / Math.sqrt(r2 + 1 / (w * w * c2)));
         }
     } 
}

