#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
    Mat source, scaleDown, scaleUp;

    // Read source image
    source = imread("/home/anton/Documents/ProjectsCPlusPlus/NeuralNetwork/OpenCv/OpenCvMatInit/lena.jpg", IMREAD_COLOR);

    // Scaling factors
    double scaleX = 0.6;
    double scaleY = 0.6;
    cv::resize(source, scaleDown, Size(), scaleX, scaleY, INTER_LINEAR );
    cv::resize(source, scaleUp, Size(), scaleX*3, scaleY*3, INTER_LINEAR );

    //Cropped image
    Mat crop = source(cv::Range(50,150), cv::Range(20, 200));

    // Create Display windows for all three images
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Scaled Down", WINDOW_AUTOSIZE);
    namedWindow("Scaled Up", WINDOW_AUTOSIZE);
    namedWindow("Cropped Image", WINDOW_AUTOSIZE);

    // Show images
    imshow("Original", source);
    imshow("Scaled Down", scaleDown);
    imshow("Scaled Up", scaleUp);
    imshow("Cropped Image", crop);

    waitKey(0);

}
