// Devon VanNote
// Analysis of Algorithms
// Program: Convex Hull 
// Due: Oct-20-2016

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
	int x;
	int y;
};

void convexHull(point p[], int n);
int crossProduct(int ax, int ay, int bx, int by, int cx, int cy);

int main() {
	point p[10] = {};
	int x = 0, y = 0, i = 0;
	char choice;
	
	cout << "Welcome to the Convex Hull Calculator (For Right-Handed Coordinate System)" << endl;
	cout << "Press any character to enter in up to 50 coordinates (positive integer values)." << endl;
	cin >> choice;

	while (choice != 'q' && i < 50 && x >= 0 && y >= 0) {
		cout << "X: ";
		cin >> x;
		cout << "Y: ";
		cin >> y;
		p[i].x = x;
		p[i].y = y;
		i++;
		cout << endl << "Press any character to continue or q to quit" << endl;
		cin >> choice;
	}
	if (i < 3 || x < 0 || y < 0) {
		//invalid input
		cout << "Invalid input (negative coordinate || less than 3 coordinates). Cannot compute Convex Hull." << endl;
	}
	else {
		//perform convexHull
		convexHull(p, i);
	}
	
	return 0;
}

void convexHull(point p[], int n) {
	int leftMost = 0, i = 0, j = 0, k =0;
	bool firstRun = true;
	vector<point> result;
	
	//get left-most point (lowest x value)
	for(i = 0; i < n; i++) {
		if (p[i].x <= p[leftMost].x) {
			leftMost = i;
		}
	}

	cout << "Left-most point is: " << p[leftMost].x << " , " << p[leftMost].y << endl;
	result.push_back(p[leftMost]); //pushing leftmost onto vector

	//Starting with leftMost point, start calculating cross-product
	//to determine if points lie on other side of line of next chosen point.
	//If all points are on other side, add point to result vector.

	while (j != leftMost) {
		k = (j + 1) % n; //next point to check segment with
		if (firstRun == true) {
			j = leftMost;
			firstRun = false;
		}
		for (i = 0; i < n; i++) {
			if (crossProduct(p[j].x, p[j].y, p[i].x, p[i].y, p[k].x, p[k].y) == 2) {
				k = i; //next point that satisfies cross product
			}
		} //sets j to be next point checked on run though of do-while loop
		cout << "Point added to Convex Hull: " << p[k].x << " , " << p[k].y << endl;
		j = k;
		result.push_back(p[j]); //adding new point to vector
	}

	//print result
	cout << endl << "Convex Hull Result: " << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i].x << " , " << result[i].y << endl;
	}
};

int crossProduct(int ax, int ay, int bx, int by, int cx, int cy) {
	int ans = 0, retval;
	
	ans = (((bx - ax)*(cy - ay)) - ((by - ay)*(cx - ax)));

	if (ans == 0) {
		retval = 0;  // colinear - lies in current line segment

	}
	else if(ans > 0){
		retval = 1; //clockwise
	}
	else {
		retval = 2; //counter-clockwise - this is what is needed to advance
	}
	
	return retval;
};
