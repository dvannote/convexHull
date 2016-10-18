// Devon VanNote
// Analysis of Algorithms
// Program: Convex Hull -Jarvis's March algorithm method

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
	
	cout << "Welcome to the Convex Hull Calculator" << endl;
	cout << "Press any character to enter in up to 10 coordinates." << endl;
	cin >> choice;

	while (choice != 'q' && i < 10) {
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
	if (i < 3) {
		//invalid input
		cout << "Any number of points less than three only forms one or no line segment. Cannot compute Convex Hull." << endl;
	}
	else {
		//perform convexHull
		convexHull(p, i);
	}
	
	return 0;
}

void convexHull(point p[], int n) {
	int leftMost = 0, i = 0, j = 0, k =0;
	vector<point> result;
	
	//get left-most point (lowest x value)
	for(i = 0; i < n-1; i++) {
		if (p[i].x <= p[i + 1].x) {
			leftMost = i;
		}
	}

	//Starting with leftMost point, start calculating cross-product
	//to determine if points lie on other side of line of next chosen point.
	//If all points are on other side, add point to result vector.

	j = leftMost;
	do {
		result.push_back(p[j]); //adding new point to vector (in first case, its the left-most point)
		cout << "Point added to Convex Hull Set: {" << p[j].x << "," << p[j].y << "}" << endl;

		k = (j + 1) % n; //remainder of points to check

		for (i = 0; i < n; i++) {
			if (crossProduct(p[j].x, p[j].y, p[i].x, p[i].y, p[k].x, p[k].y) == 2) {
				k = i; //next point that satisfies cross product
			}
		}

		j = k; //sets j to be next point checked on run though of do-while loop

	} while (j != leftMost); 
	
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
