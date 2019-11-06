#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;

int main()
{

    std::string inputDir = "/home/oscar/src/OpenCV/input/";
    std::string fileName = inputDir+"306005.jpg";

    cv::Mat image; //n-dimensional dense array class

    image = cv::imread(fileName);

    if ( !image.data )
    {
        std::cerr<<"No image data"<<std::endl;
        return -1;
    }


    //RGB to Lab color space

    cv::Mat lab;
    cv::cvtColor(image, lab, cv::COLOR_BGR2Lab);

    std::vector<cv::Mat> labChannels(3);
    cv::split(lab, labChannels);

    for(unsigned i=0;i<labChannels.size();++i)
    {
        labChannels[0] -= 50;

    }

    cv::Mat output;
    cv::merge(labChannels, lab);


    cv::cvtColor(lab, output, cv::COLOR_Lab2BGR);


    cv::imshow("Input Image", image);
    cv::imshow("Output Image", output);

    cv::waitKey(0);

    return 0;
}
