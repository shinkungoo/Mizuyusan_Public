//
// Created by Shizumu on 2022/6/24.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <cmath>

using std::fabs;

void lineDDA(int x0, int y0, int xEnd, int yEnd)
{
    int dx = xEnd - x0, dy = yEnd - y0, steps, k;
    double xIncrement, yIncrement, x = x0, y = y0;

    if(abs(dx) > abs(dy)){
        steps = abs(dx);
    }else{
        steps = abs(dy);
    }
    xIncrement = dx / static_cast<double>(steps);
    yIncrement = dy / static_cast<double>(steps);

}