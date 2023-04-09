#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "../../../lsMisc/stdosd/stdosd.h"
#pragma comment(lib, "Shlwapi.lib")

using namespace Ambiesoft::stdosd;
using namespace cv;

int main()
{
    std::string fullimagepath = stdCombinePath(stdGetParentDirectory(stdGetModuleFileName<char>()),
        "../../../../opencv\\opencv\\samples\\data\\starry_night.jpg");
    std::string image_path = samples::findFile(fullimagepath);
    Mat img = imread(image_path, IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if (k == 's')
    {
        imwrite("starry_night.png", img);
    }
    return 0;
}