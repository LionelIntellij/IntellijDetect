#ifndef UTILS_INTERFACE_H
#define UTILS_INTERFACE_H

#include <string>
#include <iostream>

namespace interface {
enum sizeObject: int {
    PANEL_BUTTON_HEIGHT = 100,
    PANEL_BUTTON_WITDH = 180
};
//
inline const std::string &pathFile(std::string const &envVariable) {
    try {
        const static std::string path = std::getenv(envVariable.c_str());
        return path;
    }
    catch (std::exception &e) {
        std::cerr << envVariable + " not found " << std::endl;
        throw e;
    }
}
static std::string pathIntellij(std::getenv("INTELLIJ_PATH"));

static std::string pathIcons(pathIntellij+"/icons/");


}




#endif // UTILS_INTERFACE_H
