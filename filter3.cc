//Student 3 Name:
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

const int RED = 0, GREEN = 1, BLUE = 2;

//YOU: Write your own filter here - delete the demo code or modify it to your purposes
//void filter3(vector<vector<vector<int>>> &vec){
void filter3(vector<vector<vector<int>>> &vec, vector<vector<vector<int>>> &vec2, vector<vector<vector<int>>> &vec3) {
	size_t rows = vec.size();
	if (!rows) exit(1);
	size_t rows2 = vec2.size();
	if (!rows2) exit(1);
	size_t rows3 = vec3.size();
	if (!rows3) exit(1);

	size_t cols = vec.at(0).size();
	if (!cols) exit(1);
	size_t cols2 = vec2.at(0).size();
	if (!cols2) exit(1);
	size_t cols3 = vec3.at(0).size();
	if (!cols3) exit(1);

	size_t colors = vec.at(0).at(0).size();
	if (!colors) exit(1);
	size_t colors2 = vec2.at(0).at(0).size();
	if (!colors2) exit(1);
	size_t colors3 = vec3.at(0).at(0).size();
	if (!colors3) exit(1);


	int blurOffset = 100;
	int blurRange = 30;
	for (int i = blurOffset; i < rows/3 + 1; i++) {
		for (int j = blurOffset; j < cols-blurOffset; j++) {
			int r = vec.at(i).at(j).at(RED); 	
			int g = vec.at(i).at(j).at(GREEN); 	
			int b = vec.at(i).at(j).at(BLUE); 	

			int total_r = 0;
			int total_g = 0;
			int total_b = 0;

			int count = 0;
			for (int k = i-blurRange; k < i+blurRange; k++){
				for (int l = j-blurRange; l < j+blurRange; l++){
					total_r += vec.at(k).at(l).at(RED);	
					total_g += vec.at(k).at(l).at(GREEN);	
					total_b += vec.at(k).at(l).at(BLUE);	
					count++;
				}
			}

			vec.at(i).at(j).at(RED) = total_r / count;
			vec.at(i).at(j).at(GREEN) = total_g / count;
			vec.at(i).at(j).at(BLUE) = total_b / count;
		}
	}


	for (int i = (2 * rows/3) + 1; i < rows-blurOffset; i++) {
		for (int j = blurOffset; j < cols-blurOffset; j++) {
			int r = vec.at(i).at(j).at(RED); 	
			int g = vec.at(i).at(j).at(GREEN); 	
			int b = vec.at(i).at(j).at(BLUE); 	

			int total_r = 0;
			int total_g = 0;
			int total_b = 0;

			int count = 0;
			for (int k = i-blurRange; k < i+blurRange; k++){
				for (int l = j-blurRange; l < j+blurRange; l++){
					total_r += vec.at(k).at(l).at(RED);	
					total_g += vec.at(k).at(l).at(GREEN);	
					total_b += vec.at(k).at(l).at(BLUE);	
					count++;
				}
			}

			vec.at(i).at(j).at(RED) = total_r / count;
			vec.at(i).at(j).at(GREEN) = total_g / count;
			vec.at(i).at(j).at(BLUE) = total_b / count;
		}
	}


	int watermarkOffset_i = rows-(rows2 + blurOffset);
	int watermarkOffset_j = cols-(cols2 + blurOffset);
	for (int i = 0; i < rows2; i++){
		for (int j = 0; j < cols2; j++ ){
			if(vec2.at(i).at(j).at(RED) < 100) {
				vec.at(watermarkOffset_i + i).at(watermarkOffset_j + j).at(RED) = 0;
				vec.at(watermarkOffset_i + i).at(watermarkOffset_j + j).at(GREEN) = 0;
				vec.at(watermarkOffset_i + i).at(watermarkOffset_j + j).at(BLUE) = 0;
			}
		}
	}


	int hashtagOffset_i = 0 + blurOffset;
	int hashtagOffset_j = cols-(cols3 + blurOffset);
	for (int i = 0; i < rows3; i++){
		for (int j = 0; j < cols3; j++ ){
			if(vec3.at(i).at(j).at(RED) < 100) {
				vec.at(hashtagOffset_i + i).at(hashtagOffset_j + j).at(RED) = 0;
				vec.at(hashtagOffset_i + i).at(hashtagOffset_j + j).at(GREEN) = 0;
				vec.at(hashtagOffset_i + i).at(hashtagOffset_j + j).at(BLUE) = 0;
			}
		}
	}
}
