//#include "funset.hpp"
#include <string>
#include <fstream>
//#include <Windows.h>
//
//#include <zxing/LuminanceSource.h>
//#include <zxing/common/Counted.h>
//#include <zxing/Reader.h>
//#include <zxing/aztec/AztecReader.h>
//#include <zxing/common/GlobalHistogramBinarizer.h>
//#include <zxing/DecodeHints.h>
//#include <zxing/datamatrix/DataMatrixReader.h>
//#include <zxing/MultiFormatReader.h>
//#include <zxing/pdf417/PDF417Reader.h>

#include <opencv2/opencv.hpp>
//
//#include "zxing/MatSource.h"


#include "PDF/PDF417Reader.h"
#include "PDF/MatSource.h"
#include "PDF/common/GlobalHistogramBinarizer.h"
#include "PDF/LuminanceSource.h"
#include "PDF/common/Counted.h"
#include "PDF/common/GlobalHistogramBinarizer.h"
#include "PDF/DecodeHints.h"
#include "PDF/Detector.h"
//using zxing::pdf417::detector::Detector;

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

using namespace cv;


int test_PDF417_decode()
{
    std::string image_name = "/home/tao/workspace/YZhang/QR/zxing_pdf417/test_images/PDF417.png";
//    image_name = "/home/tao/workspace/YZhang/QR/PDF417/images/Pdf417BarcodeRotate10.png";
    cv::Mat matSrc = cv::imread(image_name, 1);
    if (!matSrc.data) {
        fprintf(stderr, "read image error: %s", image_name.c_str());
        return -1;
    }

//    float angelD=45;
//    Point center(matSrc.cols/2, matSrc.rows/2);
//    Mat rotMat = getRotationMatrix2D(center,angelD,1.0);
//    Mat imageSource = Mat::ones(matSrc.size(),CV_8UC3);
//    warpAffine(matSrc,imageSource,rotMat,matSrc.size(),1,0,Scalar(255,255,255));//仿射变换校正图像
//    imshow("rotate",imageSource);
//    waitKey();

    cv::Mat matGray;
    cv::cvtColor(matSrc, matGray, CV_BGR2GRAY);

    zxing::Ref<zxing::LuminanceSource> source = MatSource::create(matGray);
    int width = source->getWidth();
    int height = source->getHeight();
    fprintf(stderr, "image width: %d, height: %d\n", width, height);

    zxing::Ref<zxing::Reader> reader;
    reader.reset(new zxing::pdf417::PDF417Reader);

    zxing::Ref<zxing::Binarizer> binarizer(new zxing::GlobalHistogramBinarizer(source));
    zxing::Ref<zxing::BinaryBitmap> bitmap(new zxing::BinaryBitmap(binarizer));

    zxing::Ref<zxing::Result> result(reader->decode(bitmap, zxing::DecodeHints(zxing::DecodeHints::PDF_417_HINT)));


    std::string txt = "/home/tao/workspace/YZhang/QR/zxing_pdf417/test_images/PDF417.txt";
    std::ifstream in(txt);
    if (!in.is_open()) {
        fprintf(stderr, "fail to open file: %s\n", txt.c_str());
        return -1;
    }

    std::string str1;
    std::getline(in, str1);
    fprintf(stderr, "actual        result: %s\n", str1.c_str());
    std::string str2 = result->getText()->getText();
    fprintf(stdout, "recognization result: %s\n", str2.c_str());

    if (str1.compare(str2) == 0) {
        fprintf(stderr, "=====  recognition is correct  =====\n");
    }
    else {
        fprintf(stderr, "=====  recognition is wrong =====\n");
        return -1;
    }

    in.close();

    return 0;
}


int main() {
    std::cout << "PDF417 decode test !" << std::endl;
    test_PDF417_decode();
    return 0;
}