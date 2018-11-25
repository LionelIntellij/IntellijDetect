#ifndef UTILS_INTERFACE_H
#define UTILS_INTERFACE_H

#include <string>
#include <iostream>
#include <cstdlib>

namespace interface {
enum sizeObject: int {
    PANEL_BUTTON_HEIGHT = 100,
    PANEL_BUTTON_WITDH = 180,
    CONTROL_BUTTON_HEIGHT = 80,
    CONTROL_BUTTON_WITDH = 100,
    ICONS_SIZE = 50
};
//
inline const std::string &pathFile(std::string const &envVariable) {
    std::cerr<<std::string(envVariable.c_str())<<std::endl;
    const char * pat1 = std::getenv(envVariable.c_str());
    std::cerr<<" scvsqvc "<<std::string(pat1)<<std::endl;
   std::string pat = std::string(pat1);

    std::cerr<<pat<<std::endl;
   try {
        const static std::string path(std::getenv(envVariable.c_str()));
        return path;
    }
    catch (std::exception &e) {
        std::cerr << envVariable + " not found " << std::endl;
        throw e;
    }
}
//static std::string pathIntellij(std::getenv("INTELLIJ_PATH"));
static std::string pathIntellij("/home/lionel/Projects/IntellijDetect");
static std::string pathIcons(pathIntellij+"/icons/");


}




#endif // UTILS_INTERFACE_H
