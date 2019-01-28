#ifndef UTILS_INTERFACE_H
#define UTILS_INTERFACE_H

#include <string>
#include <iostream>
#include <cstdlib>

namespace utils {
    enum sizeObject : int {
        PANEL_BUTTON_HEIGHT = 100,
        PANEL_BUTTON_WITDH = 180,
        CONTROL_BUTTON_HEIGHT = 80,
        CONTROL_BUTTON_WITDH = 100,
        ICONS_SIZE = 50
    };
inline const std::string &pathFile(const char * envVariable) {
        try {
            const static std::string path = std::getenv(envVariable);
            std::cerr<<path<<std::endl;
            return path;
        }
        catch (std::exception &e) {
            std::cerr << envVariable << " not found " << std::endl;
            throw e;
        }
    }


  const std::string pathIntellij(pathFile("INTELLIJ_PATH"));
  const  static std::string pathIcons(pathIntellij + "/data/icons/");


}


#endif // UTILS_INTERFACE_H
