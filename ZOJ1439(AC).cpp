#include <cstdio>
#include <cmath>
using namespace std;

class Point{
public:
	double x;
	double y;
	double z;

	Point(double vx = 0, double vy = 0, double vz = 0)
	{
		x = vx;
		y = vy;
		z = vz;
	}

};

double dist(Point &a, Point &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

int main()
{
	Point p[3];
	double a;
	double b;
	double c;
	double area;
	double perimeter;
	double r;
	double R;

	while(1)
	{
		if(
			scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",
				&p[0].x, &p[0].y, &p[0].z,
				&p[1].x, &p[1].y, &p[1].z,
				&p[2].x, &p[2].y, &p[2].z
			) == 9
		)
		{
			a = dist(p[0], p[1]);
			b = dist(p[1], p[2]);
			c = dist(p[2], p[0]);
			area = sqrt((+ a + b + c) * (- a + b + c) * (+ a - b + c) * (+ a + b - c)) / 4;
			perimeter = a + b + c;
			r = 2 * area / perimeter;
			R = a * b * c / 4 / area;
			printf("%0.3f\n", (r / R) * (r / R));
		}
		else
		{
			break;
		}
	}

	return 0;
}

