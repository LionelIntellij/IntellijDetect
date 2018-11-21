#ifndef UTILS_INTERFACE_H
#define UTILS_INTERFACE_H

#include <string>
#include <iostream>

namespace interface {
enum sizeObject: int {
    PANEL_BUTTON_HEIGHT = 100,
    PANEL_BUTTON_WITDH = 150
};

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

}




#endif // UTILS_INTERFACE_H
