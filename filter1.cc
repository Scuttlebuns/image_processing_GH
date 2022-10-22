//Student 1 Name:
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

const int RED = 0, GREEN = 1, BLUE = 2;

void color_temp (double set_temperature, double &r, double &g, double &b){

	double temperature = set_temperature / 100;

	if(temperature >= 66) b = 255;
	else if (temperature <= 19) b = 0;
	else {
		b = temperature - 10;
		b = 138.5177312231 * log(b) - 305.0447927307;
		if (b < 0) b = 0;
		if (b > 255) b = 255;
	}

	if(temperature <= 66){
		r = 255;
		g = temperature;
		g = 99.4708025861 * log(g) - 161.1195681661;
		if (g < 0) g = 0;
		if (g > 255) g = 255;
	}
	else{
		r = temperature;
		r = 329.698727446 * (pow(r,-0.1332047592));
		if (r < 0) r = 0;
		if (r > 255) r = 255;

		g = temperature - 60;
		g = 288.1221695283 * (pow(g, -0.0755148492));
		if (g < 0) g = 0;
		if (g > 255) g = 255;
	}

}

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

			double r = 0; //Bounds check with .at the first time
			double g = 0; //Skip bounds check for speed
			double b = 0;

			double set_temp2 = 6;

			color_temp(set_temp2, r, g, b);

			cout << "r: " << r << endl;
			cout << "g: " << g << endl;
			cout << "b: " << b << endl;

	//Do the image filtering on every row and column in this image...
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//	vec.at(i).at(j).at(RED) *= 0.5;
			//	vec.at(i).at(j).at(GREEN) *= 0.5;
			//	vec.at(i).at(j).at(BLUE) *= 0.5;

			//r is the red value at the current spot, g is the green, b is the blue
			double original_r = vec.at(i).at(j).at(RED); //Bounds check with .at the first time
			double original_g = vec[i][j][GREEN]; //Skip bounds check for speed
			double original_b = vec[i][j][BLUE];

			double scaleFactor_r = 0.0;
			double scaleFactor_g = 0.0;
			double scaleFactor_b = 0.0;

			double scaled_r = 0.0;
			double scaled_g = 0.0;
			double scaled_b = 0.0;

			scaleFactor_r = 1+((r - original_r) / 255);
			scaleFactor_g = 1+((g - original_g) / 255);
			scaleFactor_b = 1+((b - original_b) / 255);

			scaled_r = original_r * scaleFactor_r;
			scaled_g = original_g * scaleFactor_g;
			scaled_b = original_b * scaleFactor_b;

			vec.at(i).at(j).at(RED) = scaled_r;
			vec.at(i).at(j).at(GREEN) = scaled_g;
			vec.at(i).at(j).at(BLUE) = scaled_b;

			/*
			   if (j < 460){
			   if(b > 110 and r > 100 and g > 115){
			//	g *= 0.5;
			r *= 1.5;
			//	b *= 0.5;
			}
			}

			vec.at(i).at(j).at(RED) = r * 2;
			vec.at(i).at(j).at(GREEN) = g * 2;
			vec.at(i).at(j).at(BLUE) = b * 2;
			*/
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
