#include "ground_tracker.h"
#include "dataset_utils.hpp"
#include "simple_compensation.hpp"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
        cerr << endl
             << "Usage: track_dataset path_yaml path_dataset path_stamp path_odom"
             << endl;
        return 1;
	}
	std::string path_yaml(argv[1]);
	std::string path_img(argv[2]);


	gv::CameraConfig config(path_yaml);

    shared_ptr<gv::IPMProcesser> ipmproc = shared_ptr<gv::IPMProcesser>(new gv::IPMProcesser(config, gv::IPMType::NORMAL));

    // main feature tracking
    cv::Mat img = cv::imread(path_img);
    // cv::Mat img_undist = ipmproc->genUndistortedImage(img);


    cv::Mat img_ipm;
	img_ipm = ipmproc->genIPM(img, false);
    cv::imshow("img", img);
    cv::imshow("img_ipm", img_ipm);
    cv::waitKey(0);

	return 0;
}

