#include <QWidget>
#include <QGridLayout>
#include "PictureWidget.h"

namespace person {

class Picture : public picture::PictureWidget
{
public:
    explicit Picture();
    ~Picture() final;


};

}
