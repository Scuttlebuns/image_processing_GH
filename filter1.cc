//Student 1 Name:
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

const int RED = 0, GREEN = 1, BLUE = 2;

void make_rect(vector<vector<vector<int>>> &vec, int x_min, int x_max, int y_min, int y_max) {
	for (int i = y_min; i <= y_max; i++) {
		for (int j = x_min; j <= x_max; j++) {
			vec[i][j][RED] = 0;
			vec[i][j][GREEN] = 0;
			vec[i][j][BLUE] = 0;
		}
	}
}
//YOU: Write your own filter here - delete the demo code or modify it to suit your purposes
void filter1(vector<vector<vector<int>>> &vec) {
	//Get the number of rows, columns, and colors in this 3D vector
	size_t rows = vec.size();
	if (!rows) exit(1);
	size_t cols = vec.at(0).size();
	if (!cols) exit(1);
	size_t colors = vec.at(0).at(0).size();
	if (!colors) exit(1);

	//make_rect(vec, 50, 200, 50, 60); 
	//make_rect(vec, 50, 200, 100, 110); 

	//Do the image filtering on every row and column in this image...
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			vec.at(i).at(j).at(RED) *= 0.5;
			vec.at(i).at(j).at(GREEN) *= 0.5;
			vec.at(i).at(j).at(BLUE) *= 0.5;

			//r is the red value at the current spot, g is the green, b is the blue
			int r = vec.at(i).at(j).at(RED); //Bounds check with .at the first time
			int g = vec[i][j][GREEN]; //Skip bounds check for speed
			int b = vec[i][j][BLUE];

			if (j < 460){
				if(b > 110 and r > 100 and g > 115){
				g *= 0.5;
				r *= 2.0;
				b *= 0.5;
				}
			}

			vec.at(i).at(j).at(RED) = r * 2;
			vec.at(i).at(j).at(GREEN) = g * 2;
			vec.at(i).at(j).at(BLUE) = b * 2;

			//DEMO CODE BEGIN
			/*
			//The demo code here will either sepia tone or yellowize the image, depending on which one you comment out
			//Simple Example - Make the image more yellowish
			vec.at(i).at(j).at(RED) *= 1.3; //Increase red value at every point by 50%
            vec.at(i).at(j).at(GREEN) *= 1.2; //Increase green at every point by 20%
            vec.at(i).at(j).at(BLUE) *= 0.8; //Reduce blue by 20%
			*/

		/*	//Add a rainbow pattern 
			if (r > 150 and g < 150) {
				int avg = (r+g+b)/3;
				vec[i][j][RED] = avg + 128*cos(i/20.0);
				vec[i][j][GREEN] = avg + 128*sin(i/50.0);;
				vec[i][j][BLUE] = avg + 128*cos(i/40.0 + 3);
			}
*/
			/*
			//Complex Example - Do sepia toning
			//Get the red, green and blue values at row i, col j:
			//These magic numbers do sepia toning
			vec[i][j][RED]   = r*0.393 + g*0.769 + b*0.189;
			vec[i][j][GREEN] = r*0.349 + g*0.686 + b*0.168;
			vec[i][j][BLUE]  = r*0.272 + g*0.534 + b*0.131;
			*/
			//DEMO CODE END
		}
	}
}
