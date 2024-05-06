// DraggableButton.h
#ifndef DRAGGABLEBUTTON_H
#define DRAGGABLEBUTTON_H

#include <QPushButton>
#include <QMimeData>
#include <QMouseEvent>

class DraggableButton : public QPushButton {
    Q_OBJECT

public:
    DraggableButton(const QString &text, int index, QWidget *parent = nullptr);

signals:
    void dropped(int cameraIndex, const QPoint &dropPosition);
    void dragged(int cameraIndex, const QPoint &pos);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int cameraIndex;
    QPoint startPos;
    bool isBeingDragged;
};

#endif // DRAGGABLEBUTTON_H
