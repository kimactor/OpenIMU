#include "customqmlscene.h"
#include <QQuickView>
#include <iostream>
#include <QQmlApplicationEngine>
#include <qboxlayout.h>

CustomQmlScene::CustomQmlScene(std::string filename, QWidget* parent = 0): QWidget(parent)
{
    filename = "qrc:/" + filename;
    QQuickView* view = new QQuickView();
    QWidget* widget = QWidget::createWindowContainer(view, this);
    view->setSource(QUrl((QString)filename.c_str()));

    if(view->status()!=QQuickView::Ready)
        qDebug("can't initialise view");
    widget->setMinimumSize(500,100);
    QQuickItem* container = view->rootObject();
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(widget);
    this->setLayout(mainLayout);
}