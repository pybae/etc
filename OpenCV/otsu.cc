#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace cv;

int main(int argc, const char *argv[])
{
    if (argc > 1) {
        Mat im = imread(argv[1], 1);
        imshow("image", im);
        waitKey(0);
    }
    else {
        std::cout << "Please specify a filename" << std::endl;
    }
    return 0;
}
