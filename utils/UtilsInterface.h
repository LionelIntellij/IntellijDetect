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
//

//static std::string pathIntellij(std::getenv("INTELLIJ_PATH"));
  const  static std::string pathIntellij("/home/lionel/Projects/IntellijDetect");
  const  static std::string pathIcons(pathIntellij + "/icons/");


}


#endif // UTILS_INTERFACE_H
