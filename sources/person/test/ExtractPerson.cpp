#include "ExtractPerson.h"


namespace person {

    ExtractPerson::ExtractPerson(const std::string &picturePerson) :
                              myPersonImage(cv::imread(picturePerson))
                              {


    }


    ExtractPerson::~ExtractPerson()
    {

    }
}