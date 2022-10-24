//Student 2 Name: Voss
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

const int RED = 0, GREEN = 1, BLUE = 2;
//YOU: Write your own filter here - delete the demo code or modify it to suit your purposes
void filter2(vector<vector<vector<int>>> &vec) {
	size_t rows = vec.size();
	if (!rows) exit(1);
	size_t cols = vec.at(0).size();
	if (!cols) exit(1);
	size_t colors = vec.at(0).at(0).size();
	if (!colors) exit(1);

	bool stop = false;
	const int BOTTOMVAL = (2 * cols / 3);
	const int BOTTOMVAL2 = (2 * rows / 3);
	for (int i = 0; i < rows; i++) {
/*
		if (i == (2 * rows /3)) {
				stop = true;
			} else if (i > (2 * rows / 3)) break;
*/
			for (int j = 0; j < cols; j++) {
			//DEMO CODE BEGIN
			//How far are we from the center?
			/*
			const double diag_length = hypot(rows/2.0,cols/2.0); //How many pixels is the diagonal from the center of the image to a corner?
			double distance = hypot(i-(rows/2.0),j-(cols/2.0));
			double brightness = 2 - 2*(distance/diag_length); //0 brightness at corners, 200% brightness in middle
			//cout << "i: " << i << " j: " << j << " bright: " << brightness << endl;
			//cout << "diag_length: " << diag_length << " distance: " << distance << endl;
			for (int k = 0; k < colors; k++) {
				vec.at(i).at(j).at(k) *= brightness; //Lighten or darken each color by its distance from the center
			}
			*/
			//DEMO CODE END
			int r = vec.at(i).at(j).at(RED); //Bounds check with .at the first time
			int g = vec[i][j][GREEN]; //Skip bounds check for speed
			int b = vec[i][j][BLUE];
/*
			if (stop) {
				vec.at(i).at(j).at(RED) = 0;
				vec.at(i).at(j).at(GREEN) = 0;
				vec.at(i).at(j).at(BLUE) = 0;
			}
*/
			//Gray
			if (i > rows/3 and i < (2*rows/3) and j > cols/3 and j < (2*cols/3)) {
				int avg = (r+g+b)/3;
				vec[i][j][RED] = avg;
				vec[i][j][GREEN] = avg;
				vec[i][j][BLUE] = avg;
			}
			if (i > rows/3 and i < (2*rows/3) and j > cols/3 and j < (2*cols/3)) {
//				cout << "Row (i): " << i << "\t Col (j): " << j << endl;
//				swap(vec.at(i).at(j), vec.at(i).at(BOTTOMVAL - j));
			}

		}
	}
/*
	cout << "Rows / 3: " << rows/3 << endl;
	cout << "Cols / 3: " << cols/3 << endl;
	for (int i = rows / 3 + 1; i <= (2 * rows / 3); i++) {
		for (int j = cols / 3 + 1; j <= (2 * cols / 3); j++) {
		}
	}
*/
}

