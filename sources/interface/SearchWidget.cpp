#include "SearchWidget.h"
#include <QPalette>


    SearchWidget::SearchWidget(QWidget *parent) :
            QWidget(parent) {
        createGuiComponents();
        myMainLayout = new QGridLayout;
        myMainLayout->addLayout(myPanel, 0, 0, 4, 2);
        myMainLayout->addWidget(myGraphicsView, 0, 3, 3, 5);
        setLayout(myMainLayout);
        createConnection();
    }

    void SearchWidget::createGuiComponents() {
        QPalette palette;
        palette.setColor(QPalette::Base, Qt::white);
        palette.setColor(QPalette::Text, Qt::black);

        myGraphicsView = new QGraphicsView;
        myGraphicsView->setPalette(palette);

        myTextSearch = new QLineEdit;
        myTextSearch->setPalette(palette);

        myTextInfo = new QTextEdit;
        myTextInfo->setPalette(palette);

        myButtonSearch = new QToolButton;
        myButtonSearch->setMinimumSize(100, 80);
        myButtonSearch->setText("Search");

        myPanel = new QVBoxLayout;
        myPanel->addStretch();
        myPanel->addWidget(myButtonSearch);
        myPanel->addStretch();
        myPanel->addWidget(myTextSearch);
        myPanel->addStretch();
        myPanel->addWidget(myTextInfo);
        myPanel->addStretch();
    }

    void SearchWidget::setListCompleter() {

    }

    void SearchWidget::createConnection() {

    }


    void SearchWidget::setTextInfo(const QString &info) {
        myTextInfo->setText(info);
    }

    SearchWidget::~SearchWidget() {
        delete myButtonSearch;
        delete myPanel;
        delete myGraphicsView;
        delete myTextSearch;
        delete myTextInfo;
        delete myMainLayout;
    }

