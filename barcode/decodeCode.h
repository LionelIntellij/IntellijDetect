#ifndef BARCODE_DECODE_CODE39
#define BARCODE_DECODE_CODE39

#include "decodeCode.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <opencv2/core.hpp>

namespace barcode {

    class decodeCode {
    public:
        void decodeCode(cv:Mat image)
        virtual void decodeBinary() = 0;

    protected:
        //attribut
        cv::Mat m_image = nullptr;

        //method
        void getContours()
    };
}

#endif