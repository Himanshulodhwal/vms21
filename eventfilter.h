#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QObject>
#include <overlay_widget.h>
#include <QEvent>
#include <QDebug>
class EventFilter : public QObject
{
    Q_OBJECT
public:
    explicit EventFilter(int index,Overlay_Widget* overlayWidget,QObject *parent = nullptr);

signals:
// public:
//     EventFilter(int index) : m_index(index) {}

protected:
    bool eventFilter(QObject* watched, QEvent* event) override
    {
        if (event->type() == QEvent::HoverMove)
        {
            qDebug() << "Mouse hovered on" << watched->objectName();
            qDebug() << "Geometry:" << m_overlayWidget->geometry();
            qDebug() << "Visible:" << m_overlayWidget->isVisible();

            // Show overlay widget when mouse hovers over watched widget
            m_overlayWidget->show();
            m_overlayWidget->raise();
            return true; // Event handled, stop propagation
        }
        else if (event->type() == QEvent::HoverLeave)
        {
            qDebug() << "Mouse left" << watched->objectName();
            // Hide overlay widget when mouse leaves watched widget
            m_overlayWidget->hide();
            return true; // Event handled, stop propagation
        }

        // Let other types of events pass through
        return QObject::eventFilter(watched, event);
    }

private:
    int m_index;
Overlay_Widget* m_overlayWidget;
};

//////
// class EventFilter : public QWidget {
//     Q_OBJECT
// public:
//     EventFilter(QWidget *parent = nullptr);
// signals:
//     void hovered(bool entered);
// protected:
//     void enterEvent(QEvent *event) override;
//     void leaveEvent(QEvent *event) override;
// };
#endif // EVENTFILTER_H
