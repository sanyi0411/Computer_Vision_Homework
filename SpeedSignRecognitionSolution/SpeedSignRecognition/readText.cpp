#include "readText.h"

ReadText::ReadText()
{
}

std::vector<std::string> ReadText::readSpeedLimit(std::vector<cv::Mat> input)
{/*
    cv::Rect roi;
    roi.x = 0;
    roi.y = _source.rows / 4;
    roi.width = _source.cols;
    roi.height = _source.rows / 1.5;
    _source = _source(roi);
    */
    //cv::createTrackbar("Threshold", "Webcam", &_thresholdValue, 255, readTextCallback, this);
    
    std::vector<std::string> results;

    for (auto image : input) {
        if (image.empty()) {
            continue;
        }

        int borderTopBottom = (int)(0.20 * image.rows); //Width of border in % of the original image
        int borderLeftRight = (int)(0.20 * image.cols);
        copyMakeBorder(image, image, borderTopBottom, borderTopBottom, borderLeftRight, borderLeftRight,
            cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255));
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
        cv::threshold(image, image, 90, 255, cv::THRESH_BINARY);
        //cv::imshow("image", image);
        //cv::waitKey(0);


        tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
        ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
        ocr->SetVariable("debug_file", "/dev/null"); //This line supresses warning messages loged on console
        ocr->SetPageSegMode(tesseract::PSM_AUTO);
        ocr->SetImage(image.data, image.cols, image.rows, 1, image.step);
        std::string text = std::string(ocr->GetUTF8Text());
        delete ocr;
        if (text != "" || text != "\n") {
            std::cout << text << std::endl;
        }
        results.push_back(text);
    }
    return results;
}

