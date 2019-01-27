#include <QDialog>
#include <QFileSystemModel>
#include <QTreeView>
#include <QtWidgets/QGridLayout>
#include <QDialogButtonBox>

class DialogFileSystem : public QDialog {

  Q_OBJECT

 public:
    DialogFileSystem();
    ~DialogFileSystem();

 private:
    QFileSystemModel * myModel;
    QTreeView * myViewTree;
    QGridLayout * myMainLayout;
    QDialogButtonBox * myButtonBox;


};