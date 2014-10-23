#include <cv.h>
#include <highgui.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace cv;

int main(int argc, const char *argv[])
{
    if (argc > 1) {
        Mat im = imread(argv[1], 1);
    }
    else {
        std::cout << "Please specify a filename" << std::endl;
    }
    return 0;
}
