#include "handel_thread.h"

Handel_Thread::Handel_Thread(int interval,QObject *parent)
    : QObject{parent},m_interval(interval)
{
    // timer = new QTimer(this);
    // // connect(timer, &QTimer::timeout, this, &Handel_Thread::timeout);
    //  connect(timer, &QTimer::timeout, this, &Handel_Thread::handleTimeout);
    // timer->start(m_interval); // Start timer to update the list every 1 second

}
