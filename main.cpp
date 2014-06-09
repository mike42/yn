#include <iostream>
#include <cv.h>
#include <highgui.h>

using namespace std;

/**
 * Load a file, and wait for the user to press a key.
 *
 * If the pressed key is 'y', print the filename.
 */
bool yn(string fn) {
    cv::Mat img;
    char key = 0;

    img = cv::imread(fn);
    if(!img.data) {
        cerr << "Failed to load " << fn << endl;
    } else {
        cv::namedWindow(fn);
        cv::imshow(fn, img);
        key = cv::waitKey(0);
        cv::destroyWindow(fn);
        if(key == 'y') {
            cout << fn << endl; // 'y' pressed
        } else if(key == 0x1B) {
            return false; // ESC pressed
        }
    }
    return true;

}

/**
 * Get list of files from command-line arguments and display them in turn
 */
int main(int argc, char** argv) {
    int i;

    /* Command-line arguments given */
    for(i = 1; i < argc; i++) {
        if(yn(string(argv[i])) == false) {
            cerr << "Quitting.\n";
            break;
        }
    }

    return 0;
}
