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

            connect(m_cells[i+3*j], SIGNAL(clicked(Cell*)), this, SLOT(onCellClicked(Cell*)));
        }
    }
    m_scene->update();
//    std::cout >> m_cells[0]->text();

}

int MainWindow::check()
{
    for (int i=1; i < 3; i++)
        if ((m_cells[0]->state() == Cell::State(i) and m_cells[0]->state() == m_cells[1]->state() and m_cells[1]->state() == m_cells[2]->state()) ||
            (m_cells[0]->state() == Cell::State(i) and m_cells[0]->state() == m_cells[4]->state() and m_cells[4]->state() == m_cells[8]->state()) ||
            (m_cells[0]->state() == Cell::State(i) and m_cells[0]->state() == m_cells[3]->state() and m_cells[3]->state() == m_cells[6]->state()) ||
            (m_cells[6]->state() == Cell::State(i) and m_cells[6]->state() == m_cells[7]->state() and m_cells[7]->state() == m_cells[8]->state()) ||
            (m_cells[2]->state() == Cell::State(i) and m_cells[2]->state() == m_cells[5]->state() and m_cells[5]->state() == m_cells[8]->state()) ||
            (m_cells[2]->state() == Cell::State(i) and m_cells[2]->state() == m_cells[4]->state() and m_cells[4]->state() == m_cells[6]->state()) ||
            (m_cells[1]->state() == Cell::State(i) and m_cells[1]->state() == m_cells[4]->state() and m_cells[4]->state() == m_cells[5]->state()) ||
            (m_cells[3]->state() == Cell::State(i) and m_cells[3]->state() == m_cells[4]->state() and m_cells[4]->state() == m_cells[5]->state()) )
            return i;

}

void MainWindow::color1(int i)
{
    if (m_cells[0]->state() == m_cells[1]->state() and m_cells[1]->state() == m_cells[2]->state()){
        m_cells[0]->setState(Cell::State(i));
        m_cells[1]->setState(Cell::State(i));
        m_cells[2]->setState(Cell::State(i));
    }
    if (m_cells[0]->state() == m_cells[4]->state() and m_cells[4]->state() == m_cells[8]->state()){
        m_cells[0]->setState(Cell::State(i));
        m_cells[4]->setState(Cell::State(i));
        m_cells[8]->setState(Cell::State(i));
    }
    if (m_cells[0]->state() == m_cells[3]->state() and m_cells[3]->state() == m_cells[6]->state()){
        m_cells[0]->setState(Cell::State(i));
        m_cells[3]->setState(Cell::State(i));
        m_cells[6]->setState(Cell::State(i));
    }
    if (m_cells[6]->state() == m_cells[7]->state() and m_cells[7]->state() == m_cells[8]->state()){
        m_cells[6]->setState(Cell::State(i));
        m_cells[7]->setState(Cell::State(i));
        m_cells[8]->setState(Cell::State(i));
    }
    if (m_cells[2]->state() == m_cells[5]->state() and m_cells[5]->state() == m_cells[8]->state()){
        m_cells[2]->setState(Cell::State(i));
        m_cells[5]->setState(Cell::State(i));
        m_cells[8]->setState(Cell::State(i));
    }
    if (m_cells[2]->state() == m_cells[4]->state() and m_cells[4]->state() == m_cells[6]->state()){
        m_cells[2]->setState(Cell::State(i));
        m_cells[4]->setState(Cell::State(i));
        m_cells[6]->setState(Cell::State(i));
    }
    if (m_cells[1]->state() == m_cells[4]->state() and m_cells[4]->state() == m_cells[5]->state()){
        m_cells[1]->setState(Cell::State(i));
        m_cells[4]->setState(Cell::State(i));
        m_cells[5]->setState(Cell::State(i));
    }
    if (m_cells[3]->state() == m_cells[4]->state() and m_cells[4]->state() == m_cells[5]->state()){
        m_cells[3]->setState(Cell::State(i));
        m_cells[4]->setState(Cell::State(i));
        m_cells[5]->setState(Cell::State(i));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCellClicked(Cell *cell)
{
    static bool PlayerMove = false;
    static int moveCounter = 0;
    
    if(cell->state() != Cell::State(0)) {
        return;
    }

    
    if (PlayerMove) {
        cell->setState(Cell::State0);
        PlayerMove = false;
    } else {
        cell->setState(Cell::StateX);
        PlayerMove = true;
    }
    
    moveCounter++;

    if (check()==1 || check()==2 || moveCounter == 9){
       if (check()==1){
            color1(3);
    }
       if (check()==2){
            color1(4);
    }
}
}
