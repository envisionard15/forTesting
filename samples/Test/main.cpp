#include <caffe/caffe.hpp>
#include <caffe/layers/memory_data_layer.hpp>
using namespace caffe;
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <NetConfig.h>
using namespace cv;

//FIXME: Without this, it will throw LNK2019: unresolved external symbol "void __cdecl boost::throw_exception(class std::exception const &)" 
namespace boost
{
#ifdef BOOST_NO_EXCEPTIONS
void throw_exception( std::exception const & e ){
    throw 11; // or whatever
};
#endif
}

int main(int argc, char** argv) {
    cv::Mat image = imread(DEEP_DRIVE_TEST_IMAGE);   // Read the file
    if(!image.data)
    {
        std::cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    Caffe::SetDevice(0);
    Caffe::set_mode(Caffe::GPU);
    shared_ptr<Net<float> > net_;
    net_.reset(new Net<float>(DEEP_DRIVE_NET, TEST));
    net_->CopyTrainedLayersFrom(DEEP_DRIVE_WEIGHT);
    shared_ptr<caffe::MemoryDataLayer<float>> frames_input_layer_;
    frames_input_layer_ = boost::dynamic_pointer_cast<caffe::MemoryDataLayer<float>>(
				net_->layer_by_name("gta_frames_input_layer"));
    std::vector<cv::Mat> frames;
    frames.push_back(image);
    std::vector<int> labels(frames.size());
    frames_input_layer_->AddMatVector(frames, labels);
    net_->Forward();
    return 0;
}
