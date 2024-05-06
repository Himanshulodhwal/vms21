#include "label.h"

Label::Label(QWidget *parent) : QLabel(parent) {}

void Label::mousePressEvent(QMouseEvent *event) {
Q_UNUSED(event);
    emit clicked();
}
