#ifndef HANDEL_THREAD_H
#define HANDEL_THREAD_H

#include <QObject>
#include <QTimer>
#include <QDebug>
class Handel_Thread : public QObject
{
    Q_OBJECT
public:
    explicit Handel_Thread(int interval = 1000,QObject *parent = nullptr);
signals:
    void timeout();
public slots:
    void start() {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Handel_Thread::handleTimeout);
        timer->start(m_interval);
    }
private slots:
    void handleTimeout() {
        emit timeout();
    }
private:
    QTimer *timer;
 int m_interval;
};

#endif // HANDEL_THREAD_H
