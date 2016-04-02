#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QGraphicsScene>

#include "Cell.hpp"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_scene = new QGraphicsScene();

    ui->setupUi(this);
    ui->graphicsView->setScene(m_scene);

    for (int j=0; j<3; j++) {
        for(int i=0; i<3; i++) {
            m_cells[i+3*j] = new Cell();
            m_scene->addItem(m_cells[i+3*j]);
            m_cells[i+3*j]->setPos(i*50,j*50);
        }
    }
    m_scene->update();
    std::cout >> m_cells[0]->text();

}

//void MainWindow:: Finish(){
//    if (m_cells[0]->text()==m_cells[1]->text()==m_cells[2]->text() or m_cells[0]->text()==m_cells[4]->text()==m_cells[8]->text()){
//        i=1;}
//}

MainWindow::~MainWindow()
{
    delete ui;
}
