// Devon VanNote
// Analysis of Algorithms
// Program: Convex Hull

#include <iostream>
using namespace std;

struct point {
	int x;
	int y;
};

void convexHull(point p[], point result[], int n);

int main() {
	point p[100] = {}, result[100] = {};
	int x, y, i;
	char choice;
	
	cout << "Press E to enter in at least 3 points. Press Q to stop entering in points" << endl;
	cin >> choice;

	while (choice != 'q' || i < 3) {
		cin >> x;
		cin >> y;
		p[i].x == x;
		p[i].y == y;
		i++;
		cout << endl << "Press E or Q" << endl;
		cin >> choice;
	}
	convexHull(p, result, i);
	
	return 0;
}

void convexHull(point p[],point result[], int n) {
	int leftMost = 0, i=0;
	point result[100] = {};

	//get left-most point
	for(i = 0; i < n-1; i++) {
		if (p[i].x < p[i + 1].x) {
			leftMost = i;
		}
	}

};

