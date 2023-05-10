//
// Created by Shizumu on 2022/3/15.
//
#include <windows.h>
#include <vector>
#include "DefineFilters.h"
#include<cmath>

using namespace std;

// Convert image to grayscale
void grayscale(vector<vector<RGBTRIPLE>>& image){

    int Ggray;
    for(int i = 0;i <image.size();i++){
        for(int j = 0;j<image[0].size();j++){
            Ggray = round(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0 ;


            image[i][j].rgbtRed = Ggray;
            image[i][j].rgbtBlue = Ggray;
            image[i][j].rgbtGreen = Ggray;


        }
    }


    return;

}

// Convert image to sepia
void sepia(vector<vector<RGBTRIPLE>>& image){
    for (int i = 0;i < image.size();i++){
        for (int j = 0;j<image[i].size();j++){
            int sepiared,sepiablue,sepiagreen;
            sepiared =( image[i][j].rgbtRed * 0.393 + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtBlue * 0.189 )+ 0.5; //+0.5是为了四舍五入
            sepiagreen = (image[i][j].rgbtRed * 0.349 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtBlue * 0.168 )+ 0.5;
            sepiablue = (image[i][j].rgbtRed * 0.272 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtBlue * 0.131 )+ 0.5;
            if(sepiared > 255){  //防止溢出
                sepiared = 255;
            }
            if(sepiagreen > 255){
                sepiagreen = 255;
            }
            if(sepiablue > 255){
                sepiablue = 255;
            }
            image[i][j].rgbtRed = sepiared;
            image[i][j].rgbtGreen = sepiagreen;
            image[i][j].rgbtBlue = sepiablue;

        }
    }

    return;
}

// Reflect image horizontally
void reflect(vector<vector<RGBTRIPLE>>& image){
    int rered,regreen,reblue;
    for (int i = 0;i < image.size();i++){
        for (int j = 0,k = image[i].size();j<k;j++,k--){
            rered  =  image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][k].rgbtRed;
            image[i][k].rgbtRed = rered;

            regreen =  image[i][j].rgbtGreen;
            image[i][j].rgbtGreen= image[i][k].rgbtGreen;
            image[i][k].rgbtGreen = regreen;

            reblue =  image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][k].rgbtBlue;
            image[i][k].rgbtBlue = reblue;
        }
    }
    return;
}

// Blur image
void blur(vector<vector<RGBTRIPLE>>& image){

    return;
}

