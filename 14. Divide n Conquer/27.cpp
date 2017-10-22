/**
 * Find Closest pair of points in 2D
 */
#include <bits/stdc++.h>

using namespace std;

typedef struct Point
{
	int x;
	int y;
} Point;

int compareX(const void *a, const void *b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}

int compareY(const void *a, const void *b)
{
	Point *p1 = (Point*)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}

float dist(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
	            (p1.y - p2.y)*(p1.y - p2.y));
}

float bruteForce(Point P[], int n)
{
	float min = FLT_MAX;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
	return min;
}

float min(float x, float y)
{
	return (x<y)?x:y;
}

float stripClosest(Point strip[], int size, float d)
{
	float min = d;
	
	for(int i=0;i<size;i++)
		for(int j=i+1;j<size && (strip[j].y - strip[i].y) < min;j++)
			if(dist(strip[i], strip[j]) < min)
				min = dist(strip[i], strip[j]);
			
	return min;
}

float closestUtil(Point Px[], Point Py[], int n)
{
	if(n<3)
		return bruteForce(Px, n);
	
	int mid = n/2;
	Point midPoint = Px[mid];
	
	Point Pyl[mid+1];
	Point Pyr[n-mid-1];
	
	int li = 0, ri = 0;
	for(int i = 0;i < n;i++)
	{
		if(Py[i].x <= midPoint.x)
			Pyl[li++] = Py[i];
		else
			Pyr[ri++] = Py[i];
	}
	
	float dl = closestUtil(Px, Pyl, mid);
	float dr = closestUtil(Px+mid, Pyr, n=mid);
	
	float d = min(dl, dr);
	
	Point strip[n];
	int j = 0;
	for(int i =0;i<n;i++)
		if(abs(Py[i].x - midPoint.x) < d)
			strip[j] = Py[i], j++;
	
	return min(d, stripClosest(strip, j, d));
}

float closest(Point P[], int n)
{
	Point Px[n];
	Point Py[n];
	for(int i=0;i<n;i++)
	{
		Px[i] = P[i];
		Py[i] = P[i];
	}
	
	qsort(Px, n, sizeof(Point), compareX);
	qsort(Py, n, sizeof(Point), compareY);
	
	return closestUtil(Px, Py, n);
}

int main()
{
	Point p0, p1, p2, p3, p4, p5;
	p0.x=2,p0.y=3,p1.x=12,p1.y=30,p2.x=40,p2.y=50,
	p3.x=5,p3.y=1,p4.x=12,p4.y=10,p5.x=3,p5.y=4;
	
	Point p[] = {p0,p1,p2,p3,p4,p5};
	int n = sizeof(p)/sizeof(p[0]);
	cout<<"Smallest distance = "<<closest(p, n);
}