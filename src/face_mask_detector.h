#ifndef FACE_DETECTOR_H_
#define FACE_DETECTOR_H_

#include <opencv2/opencv.hpp>
#include <tensorflow/lite/interpreter.h>
#include <model_builder.h>

#include "data_structures.h"

class FaceMaskDetector {
public:
    FaceMaskDetector(const std::string& modelPath, int modelWidth, int modelHeight,
                     int modelChannels, float confidenceThreshold);
    InferenceResult process(cv::Mat& image);
private:
    std::unique_ptr<tflite::Interpreter> interpreter;
    std::unique_ptr<tflite::FlatBufferModel> model;
    int modelWidth;
    int modelHeight;
    int modelChannels;
    float confidenceThreshold;

    void preprocess(cv::Mat& image, float* out) const;
};

#endif // FACE_DETECTOR_H_