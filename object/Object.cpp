#include "Object.h"
#include "UtilsInterface.h"

namespace object {

Object::Object():TableWidget(this){

   myPictureWindow = new Picture;
   myStatisticalWindow = new Statistical ;
   myTable->addTab(myPictureWindow ,tr("Picture"));
   myTable->addTab(myStatisticalWindow , tr("Statistical"));

}


    Object::~Object() {
   delete myPictureWindow;
   delete myStatisticalWindow;

    }


}
