#ifndef DETECTOR_H
#define DETECTOR_H

using namespace std;

#include "opencv2/opencv.hpp"
#include "lane.h"

#include <string>
#include <cmath>
#include <vector>

using namespace cv;

class Detector
{
private:
    int threshold;
    int row_step;
    int col_step;
    int l_start;
    int r_start;
    Mat matrix_transform_birdseye;
    Mat matrix_transform_fiperson;

    double cam_angle;
    int frame_width;
    int frame_height;
    double m_per_px;
    
    Mat getTransformMatrix(Mat frame, double angle, double perc_low, double perc_high, bool undo=false);

public:
    Detector(string config_path);
    void getLanes(const Mat &img, Lane &lane);
    void drawLane(Mat &img, Lane &lane);

    double getTurningRadius(Lane &lane);
    // std::vector<double> AckermannSteering();
    // std::vector<double> DifferentialSteering(double speed);
};

#endif