#include "DraggableButton.h"
#include <QApplication>
#include <QDrag>
#include <QMouseEvent>

DraggableButton::DraggableButton(const QString &text, int index, QWidget *parent)
    : QPushButton(text, parent), cameraIndex(index), isBeingDragged(false) {
    setAcceptDrops(true);
}
void DraggableButton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        startPos = event->pos();
    }
    QPushButton::mousePressEvent(event);
}

void DraggableButton::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance()) {
            isBeingDragged = true;
            QPixmap pixmap(size());
            render(&pixmap);

            // Set the pixmap as the cursor
            QCursor cursor(pixmap);
            setCursor(cursor);
        }
    }
    QPushButton::mouseMoveEvent(event);
}

void DraggableButton::mouseReleaseEvent(QMouseEvent *event) {
    QPushButton::mouseReleaseEvent(event);
    if (event->button() == Qt::LeftButton && isBeingDragged) {
        emit dropped(cameraIndex, mapToParent(event->pos()));
        isBeingDragged = false;
         setCursor(Qt::ArrowCursor);
    }
}


