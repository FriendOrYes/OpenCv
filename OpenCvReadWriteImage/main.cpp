#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    Mat image = imread("/src/OpenCvMatInit/lena.jpg");
    cout << "Hello World!" << endl;

    // Check for invalid input
    if(image.empty())
    {
        cout <<  "Could not open or find the image" << endl;
        return EXIT_FAILURE;
    }

    // Convert color image to gray
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    imwrite("imageGray.jpg", grayImage);

    // Create a window for display.
    namedWindow("image", WINDOW_AUTOSIZE);
    namedWindow("gray image", WINDOW_AUTOSIZE);

    // Display image
    imshow("image", image);
    imshow("gray image", grayImage);


    // Wait for a keystroke in the window
    waitKey(0);
    destroyAllWindows();

    return EXIT_SUCCESS;

    return 0;
}
