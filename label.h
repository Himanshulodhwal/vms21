#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

class Label : public QLabel {
    Q_OBJECT
public:
    explicit Label(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void clicked();

};

#endif // LABEL_H
