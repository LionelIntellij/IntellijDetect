#ifndef BARCODE_DECODE_CODE39
#define BARCODE_DECODE_CODE39

#include "decodeCode.h"
#include <vector>
#include <unordered_map>
#include <string>
namespace barcode {


    class decodeCode39 : public decodeCode {
    public:

        virtual void decodeBinary() = 0;

    private:

    };
}

#endif