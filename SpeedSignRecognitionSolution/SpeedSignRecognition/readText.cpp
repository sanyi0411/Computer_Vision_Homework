#include "readText.h"

ReadText::ReadText(cv::Mat input)
    :_source(input)
{
}

int ReadText::readSpeedLimit()
{
    cvtColor(_source, _source, cv::COLOR_BGR2GRAY);
    cv::threshold(_source, _source, 150, 255, cv::THRESH_OTSU + cv::THRESH_BINARY);

    std::string text;
    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
    ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
    ocr->SetPageSegMode(tesseract::PSM_AUTO);
    ocr->SetImage(_source.data, _source.cols, _source.rows, 1, _source.step);
    text = std::string(ocr->GetUTF8Text());
    delete ocr;
    return std::stoi(text);
}

