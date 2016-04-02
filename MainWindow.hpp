#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class QGraphicsScene;
class Cell;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Cell *m_cells[9];
    int i=0;
    void Finish();

private:
    QGraphicsScene *m_scene;
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_HPP
