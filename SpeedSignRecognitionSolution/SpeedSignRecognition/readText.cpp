#include "readText.h"

ReadText::ReadText()
{
}

std::vector<std::string> ReadText::readSpeedLimit(std::vector<cv::Mat> input, bool show)
{    
    std::vector<std::string> results;

    for (auto image : input) {
        if (image.empty()) {
            continue;
        }

        if (show) {
            cv::imshow("Cropped image", image);
        }

        int borderTopBottom = (int)(0.20 * image.rows); //Width of border in % of the original image
        int borderLeftRight = (int)(0.20 * image.cols);
        copyMakeBorder(image, image, borderTopBottom, borderTopBottom, borderLeftRight, borderLeftRight,
            cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255));

        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
        if (show) {
            cv::imshow("Grayscaled image", image);
        }

        cv::threshold(image, image, 30, 255, cv::THRESH_BINARY);

        if (show) {
            cv::imshow("Thresholded image", image);
            cv::waitKey(0);
        }

        tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
        ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
        ocr->SetVariable("debug_file", "/dev/null"); //This line supresses warning messages logged on console
        ocr->SetPageSegMode(tesseract::PSM_AUTO);
        ocr->SetImage(image.data, image.cols, image.rows, 1, image.step);
        std::string text = std::string(ocr->GetUTF8Text());
        delete ocr;
        if ((text != "" || text != "\n") && show) {
            std::cout << text << std::endl;
        }
        results.push_back(text);
    }
    return results;
}

