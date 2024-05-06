#ifndef CLICKABLE_REPORT_LABEL_H
#define CLICKABLE_REPORT_LABEL_H

#include <QLabel>
#include <QObject>
#include <QMouseEvent>

class Clickable_report_label : public QLabel
{
    Q_OBJECT
public:
    explicit Clickable_report_label(QWidget* parent = nullptr);

signals:
    void clicked();
// public:
//     Clickable_report_label();
protected:
    void mousePressEvent(QMouseEvent* event) override {
        if (event->button() == Qt::LeftButton) {
            emit clicked();
        }
        QLabel::mousePressEvent(event);
    }
};

#endif // CLICKABLE_REPORT_LABEL_H
