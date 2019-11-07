#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>


void light(cv::Mat rgbImage)
{
    cv::Mat labImage;
    cv::cvtColor(rgbImage, labImage, cv::COLOR_BGR2Lab);
    std::vector<cv::Mat> labChannels(3);
    cv::split(labImage, labChannels);

    //light
    labChannels[0] += 50;

    cv::merge(labChannels, labImage);

    cv::Mat outputL;
    cv::cvtColor(labImage, outputL, cv::COLOR_Lab2BGR);
    cv::imshow("Input Image", rgbImage);
    cv::imshow("Input Light", outputL);
    cv::waitKey(0);


}

void redObjectDetection(cv::Mat rgbImage, double threshold)
{
    cv::Mat labImage;
    cv::cvtColor(rgbImage, labImage, cv::COLOR_BGR2Lab);

    std::vector<cv::Mat> labChannels(3);
    cv::split(labImage, labChannels);

    double minL, maxL;
    double minA, maxA;
    double minB, maxB;

    cv::minMaxLoc(labChannels[0], &minL, &maxL);
    cv::minMaxLoc(labChannels[1], &minA, &maxA);
    cv::minMaxLoc(labChannels[2], &minB, &maxB);


    cv::Mat mask;

    std::vector<double> min={minL, minA, minB};
    std::vector<double> max={maxL, maxA-threshold, maxB};
    cv::inRange(labImage, min, max, mask);

    cv::Mat outputA;
    cv::cvtColor(labImage, outputA, cv::COLOR_Lab2BGR);
    cv::imshow("Input Image", rgbImage);
    cv::imshow("Output Threshold", mask);
    cv::waitKey(0);

}


int main()
{

    std::string inputDir = "/home/oscar/src/OpenCV/input/";
    std::string fileName = inputDir+"86000.jpg";

    cv::Mat image; //n-dimensional dense array class

    image = cv::imread(fileName);

    if ( !image.data )
    {
        std::cerr<<"No image data"<<std::endl;
        return -1;
    }


   //light(image);
   redObjectDetection(image, 40);





    return 0;
}
