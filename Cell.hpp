#ifndef CELL_HPP
#define CELL_HPP
#include <QGraphicsItem>


class Cell:public QGraphicsItem
{
public:
    Cell();

    // QGraphicsItem interface
public:
    enum State {
        Statenothing,
        StateX,
        State0
    };

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    State state() {return m_state;}
    void setState(State stat);
    QString text(){return m_text;}
private:
    QString m_text;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    bool Finish();
    State m_state;
};

#endif // CELL_HPP
