#ifndef UTILS_FILEPATH_H
#define UTILS_FILEPATH_H

#include <string>
#include <iostream>
#include <cstdlib>


class UtilsFilePath {

public:

    UtilsFilePath() {
        try {
            myPathProject = std::getenv("INTELLIJ_PATH");
        }
        catch (std::exception &e) {
            std::cerr << "INTELLIJ_PATH" << " not found " << std::endl;
            throw e;
        }
    }
    enum typePath{
        ICONS,
        IMAGE
    };


    ~UtilsFilePath(){};

    void getPath(const typePath type , std::string & path) {

            if (type == ICONS)
                path = myPathProject + "/data/icons/";

            if (type== IMAGE)
                path = myPathProject + "/data/image/";
        }

private:
    std::string myPathProject;
};
#endif // UTILS_FILEPATH_H
