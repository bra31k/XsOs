#include "Cell.hpp"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include "MainWindow.hpp"
Cell::Cell():QGraphicsItem()

{
    m_state=StateX;
}

QRectF Cell::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->drawRect(0,0,50,50);
   //if (state==Statenothing){
   //    m_text
   //}
   painter->drawText(25,25,m_text);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event->accept();
}

//void Cell::blabla()
//{
//    switch(m_state)
//    {
//    case Statenothing:
//        m_state=StateX;
//        m_text=' ';
//        break;
//    case StateX:
//        m_state=State0;
//        m_text='x';
//        break;
//    case State0:
//        m_state=StateX;
//        m_text='0';
//        break;
//    }

//}
void Cell::setState(State stat)
{
    if (m_state == stat)
    {
        return;
    }
    m_state=stat;
}

void Cell::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
        if (event->button() == Qt::LeftButton) {
            m_text="x";
        }
        if (event->button() == Qt::RightButton) {
            m_text="o";
        }



    update();
}

