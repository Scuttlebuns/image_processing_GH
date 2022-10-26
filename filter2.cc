//Student 2 Name: Heins, Sayre, Voss
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

const int RED = 0, GREEN = 1, BLUE = 2;

void filter2(vector<vector<vector<int>>> &vec) {
	size_t rows = vec.size();
	if (!rows) exit(1);
	size_t cols = vec.at(0).size();
	if (!cols) exit(1);
	size_t colors = vec.at(0).at(0).size();
	if (!colors) exit(1);

	const int HORIZONTAL_OFFSET = cols / 3;
	const int VERTICAL_OFFSET = rows / 3;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			//Variable assignment
			int r = vec.at(i).at(j).at(RED); //Bounds check with .at the first time
			int g = vec[i][j][GREEN]; //Skip bounds check for speed
			int b = vec[i][j][BLUE];

			//Gray
			if (i > rows/3 and i < (2*rows/3) and j > cols/3 and j < (2*cols/3)) {
				int avg = (r+g+b)/3;
				vec[i][j][RED] = avg;
				vec[i][j][GREEN] = avg;
				vec[i][j][BLUE] = avg;
			}

			//Flip
			if (i > rows/3 and i < (2*rows/3) and j > cols/3 and j < (2*cols/3)) {
				swap(vec.at(i).at(j), vec.at(i).at((-1 * j) + (4 * HORIZONTAL_OFFSET)));
			}

		}
	}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			if (i > (rows/3) and i < (2*rows/3) and j > 0 and j < (1*cols/3)) {
			int r = vec.at(i).at(j).at(RED); //Bounds check with .at the first time
			int g = vec[i][j][GREEN]; //Skip bounds check for speed
			int b = vec[i][j][BLUE];
				int avg = (r+g+b)/3;
				vec[i][j][RED] = avg;
				vec[i][j][GREEN] = avg;
				vec[i][j][BLUE] = avg;
			}
		}
}

