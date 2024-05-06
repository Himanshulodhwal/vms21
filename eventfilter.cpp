#include "eventfilter.h"

EventFilter::EventFilter(int index,Overlay_Widget* overlayWidget,QObject *parent)
    : QObject{parent},m_index(index),m_overlayWidget(overlayWidget)
{

}

// EventFilter::EventFilter(QWidget *parent) : QWidget(parent) {}

// void EventFilter::enterEvent(QEvent *event) {
//     QWidget::enterEvent(event);
//     emit hovered(true);
// }

// void EventFilter::leaveEvent(QEvent *event) {
//     QWidget::leaveEvent(event);
//     emit hovered(false);
// }
