#ifndef CELL_HPP
#define CELL_HPP
#include <QGraphicsObject>


class Cell:public QGraphicsObject
{
    Q_OBJECT
public:
    Cell();

    // QGraphicsItem interface
public:
    enum State {
        Statenothing,
        StateX,
        State0,
        StateWinX,
        StateWin0
    };

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    State state() {return m_state;}
    void setState(State stat);
    QString text(){return m_text;}

signals:
    void clicked(Cell *cell);

private:
    QString m_text;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    bool Finish();
    State m_state;
};

#endif // CELL_HPP
