#include "DialogFileSystem.h"



DialogFileSystem::DialogFileSystem() {
  myModel->setRootPath(QDir::homePath());
  myViewTree->setModel(myModel);
  myMainLayout->addWidget(myViewTree ,0,0,4,4);
  myMainLayout->addWidget(myButtonBox,4,0,1,2);
  setLayout(myMainLayout);

}

DialogFileSystem::~DialogFileSystem() {
 delete myButtonBox;
 delete myModel;
 delete myViewTree;
 delete myMainLayout;
}