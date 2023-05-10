//
// Created by Shizumu on 2022/3/15.
//

#ifndef FILTERS_DEFINEFILTERS_H
#define FILTERS_DEFINEFILTERS_H

#include <windows.h>
#include <vector>
using namespace std;

// Convert image to grayscale
void grayscale(vector<vector<RGBTRIPLE>>& image);

// Convert image to sepia
void sepia(vector<vector<RGBTRIPLE>>& image);

// Reflect image horizontally
void reflect(vector<vector<RGBTRIPLE>>& image);

// Blur image
void blur(vector<vector<RGBTRIPLE>>& image);

#endif //FILTERS_DEFINEFILTERS_H
