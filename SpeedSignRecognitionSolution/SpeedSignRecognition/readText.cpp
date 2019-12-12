#include "readText.h"

ReadText::ReadText()
{
}

void ReadText::setThresholdValue(int input)
{
    _thresholdValue = input;
}

void readTextCallback(int pos, void *userData)
{
    ReadText *instance = (ReadText*)userData;
    instance->setThresholdValue(pos);
}

std::string ReadText::readSpeedLimit(cv::Mat input)
{/*
    cv::Rect roi;
    roi.x = 0;
    roi.y = _source.rows / 4;
    roi.width = _source.cols;
    roi.height = _source.rows / 1.5;
    _source = _source(roi);
    */
    cv::createTrackbar("Threshold", "Webcam", &_thresholdValue, 255, readTextCallback, this);
    
    if (input.empty())
        return "";


    cv::threshold(input, input, _thresholdValue, 255, cv::THRESH_BINARY);

    int borderTopBottom = (int)(0.20 * input.rows); //Width of border in % of the original image
    int borderLeftRight = (int)(0.20 * input.cols);
    copyMakeBorder(input, input, borderTopBottom, borderTopBottom, borderLeftRight, borderLeftRight,
        cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255));
    cv::imshow("Circle", input);
/*
    std::string text;
    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
    ocr->Init(NULL, "eng", tesseract::OEM_DEFAULT);
    ocr->SetPageSegMode(tesseract::PSM_AUTO);
    ocr->SetImage(input.data, input.cols, input.rows, 1, input.step);
    text = std::string(ocr->GetUTF8Text());
    delete ocr;
    return text;
	*/
}

