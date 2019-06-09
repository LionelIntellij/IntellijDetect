#ifndef UTILS_FILEPATH_H
#define UTILS_FILEPATH_H

#include <string>
#include <iostream>
#include <cstdlib>


enum sizeObject : int {
    PANEL_BUTTON_HEIGHT = 100,
    PANEL_BUTTON_WITDH = 180
    CONTROL_BUTTON_HEIGHT = 80,
    CONTROL_BUTTON_WITDH = 100,
    ICONS_SIZE = 50
}


class utilsFilePath {

public:
    enum typePath : int {
        ICONS
        IMAGE
        }

public:
    utilsFilePath(){
            try
            {
                    myPathProject = std::getenv(envVariable);
            }
            catch (std::exception &e)
            {
                    std::cerr << envVariable << " not found " << std::endl;
                    throw e;
            }
    }

    ~utilsFilePath()=default;

    const std::string &getFilePath(typePath type ) const
    {
        switch (type){
            case ICONS:
                return myPathProject + "/data/icons/";
            case IMAGE:
                return myPathProject + "/data/image/";
            default:
                catch (std::exception &error)
                {
                    std::cerr<<" "<<std::endl;
                    throw error;
                }
        }


    }

private:
    std::string myPathProject;
};

/*
static inline const std::string &pathFile(const char *envVariable) {
    try {
        const static std::string path = std::getenv(envVariable);
        std::cerr << path << std::endl;
        return path;
    }
    catch (std::exception &e) {
        std::cerr << envVariable << " not found " << std::endl;
        throw e;
    }
}


const static std::string
        pathIntellij(pathFile("INTELLIJ_PATH"));
const static std::string
        pathIcons(pathIntellij + "/data/icons/");
const static std::string
        pathImage(pathIntellij + "/data/image/");

}
*/

#endif // UTILS_INTERFACE_H
