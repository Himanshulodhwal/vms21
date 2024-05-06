#ifndef OVERLAY_WIDGET_H
#define OVERLAY_WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QPainter>
#include <QDebug>
#include<QGraphicsView>
namespace Ui {
class Overlay_Widget;
}

class Overlay_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Overlay_Widget(int index,QWidget *parent = nullptr);
    ~Overlay_Widget();
    // void addItem(QGraphicsItem* item) {
    //     scene.addItem(item);
    // }
// protected:
//     void mousePressEvent(QMouseEvent *event) override
//     {
//         // Get the widget at the mouse position
//         QWidget *bottomWidget = childAt(event->pos());

//         // If there is a bottom widget, forward the mouse event to it
//         if (bottomWidget) {
//             QMouseEvent mappedEvent(event->type(), bottomWidget->mapFromParent(event->pos()), event->button(), event->buttons(), event->modifiers());
//             QApplication::sendEvent(bottomWidget, &mappedEvent);
//         }

//         // Continue handling the event in the overlay widget if needed
//         QWidget::mousePressEvent(event);
//     }

//     void mouseReleaseEvent(QMouseEvent *event) override
//     {
//         // Get the widget at the mouse position
//         QWidget *bottomWidget = childAt(event->pos());

//         // If there is a bottom widget, forward the mouse event to it
//         if (bottomWidget) {
//             QMouseEvent mappedEvent(event->type(), bottomWidget->mapFromParent(event->pos()), event->button(), event->buttons(), event->modifiers());
//             QApplication::sendEvent(bottomWidget, &mappedEvent);
//         }

//         // Continue handling the event in the overlay widget if needed
//         QWidget::mouseReleaseEvent(event);
//     }

protected:
    // void paintEvent(QPaintEvent *event) override
    // {
    //     // Paint the widget with a transparent background
    //     qDebug()<<"=======transparent=background=======";
    //     // Paint the widget with a transparent background
    //     // QPainter painter(this);
    //     // painter.fillRect(rect(), Qt::transparent);
    //     QPainter painter(this);
    //     painter.setPen(Qt::NoPen);
    //     painter.setBrush(QColor(0,0,0,100)); // Same as the stylesheet
    //     painter.drawRect(rect());
    // }

private:
    Ui::Overlay_Widget *ui;
     int m_index;
     QGraphicsScene scene;
};

#endif // OVERLAY_WIDGET_H
