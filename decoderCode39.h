#ifndef BARCODE_DECODE_CODE39
#define BARCODE_DECODE_CODE39

#include "decodeCode.h"

namespace barcode{

    static const char C39_SENTINEL = '*';
    static const int C39_NCHARACTERS = 44;
    static const int C39_BARS_PER_CHAR = 9;
    static const char C39_SENTINEL_STRING[] = "nwnnwnwnn";

    static const char C39_Characters[C39_NCHARACTERS] = {
            '0','1','2','3','4','5','6','7',
            '8','9','A','B','C','D','E','F',
            'G','H','I','J','K','L','M','N',
            'O','P','Q','R','S','T','U','V',
            'W','X','Y','Z','-','.',' ','$',
            '/','+','%', C39_SENTINEL
    };

    static const char* C39_Strings[C39_NCHARACTERS] = {
            "nnnwwnwnn", "wnnwnnnnw", "nnwwnnnnw",
            "wnwwnnnnn", "nnnwwnnnw", "wnnwwnnnn",
            "nnwwwnnnn", "nnnwnnwnw", "wnnwnnwnn",
            "nnwwnnwnn", "wnnnnwnnw", "nnwnnwnnw",
            "wnwnnwnnn", "nnnnwwnnw", "wnnnwwnnn",
            "nnwnwwnnn", "nnnnnwwnw", "wnnnnwwnn",
            "nnwnnwwnn", "nnnnwwwnn", "wnnnnnnww",
            "nnwnnnnww", "wnwnnnnwn", "nnnnwnnww",
            "wnnnwnnwn", "nnwnwnnwn", "nnnnnnwww",
            "wnnnnnwwn", "nnwnnnwwn", "nnnnwnwwn",
            "wwnnnnnnw", "nwwnnnnnw", "wwwnnnnnn",
            "nwnnwnnnw", "wwnnwnnnn", "nwwnwnnnn",
            "nwnnnnwnw", "wwnnnnwnn", "nwwnnnwnn",
            "nwnwnwnnn", "nwnwnnnwn", "nwnnnwnwn",
            "nnnwnwnwn", C39_SENTINEL_STRING
    };



    class decodeCode39 : public decodeCode{
    public:


    private:

    };
}






#endif