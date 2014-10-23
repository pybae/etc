#include <cv.h>
#include <highgui.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace cv;

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        std::cout << "Please specify one filename" << std::endl;
        return -1;
    }
    
    Mat im = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    Mat output;
    threshold(im, output, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    imshow("Threshold: ", output);
    waitKey(0);
    return 0;
}
