#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;

int main()
{

    std::string inputDir = "/home/oscar/src/OpenCV/input/";
    std::string fileName = inputDir+"306005.jpg";

    cv::Mat image; //n-dimensional dense array class

    image = cv::imread(fileName, cv::IMREAD_COLOR);

    if ( !image.data )
    {
        std::cerr<<"No image data"<<std::endl;
        return -1;
    }
    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);

    cv::imshow("Display Image", image);

    cv::waitKey(0);


    return 0;
}
