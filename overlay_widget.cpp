#include "overlay_widget.h"
#include "ui_overlay_widget.h"
#include <QGraphicsOpacityEffect>
Overlay_Widget::Overlay_Widget(int index, QWidget *parent)
    : QWidget(parent),ui(new Ui::Overlay_Widget)
    , m_index(index)
{
    ui->setupUi(this);
    // unsigned int flags =Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::WA_TranslucentBackground;
    // setWindowFlags(static_cast<Qt::WindowFlags>(flags));
    // Ensure overlay does not interfere with video visibility
    //setWindowFlags(Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_TransparentForMouseEvents);
   // ui->label->setStyleSheet("color: red;");
    // ui->label->setStyleSheet("background-color:rgba(0, 0, 0, 127);");
    // Position and size the overlay
    // setGeometry(0, 0, parent->width(), parent->height());
    // setStyleSheet("background-color: rgba(0, 0, 0, 127);");
    setStyleSheet("background-color: rgba(0,0,0,100);"); // Yellow background with opacity

/////////////////////QGraphic ///////
    // setScene(&scene);
    // setStyleSheet("background: transparent; border: none;"); // Set transparent background and no border
    // setWindowFlags(Qt::FramelessWindowHint); // No window frame
    // setViewportUpdateMode(QGraphicsView::FullViewportUpdate); // Update the entire viewport
    // setRenderHint(QPainter::Antialiasing); // Enable antialiasing for smoother rendering
    // setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Disable horizontal scrollbar
    // setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Disable vertical scrollbar
    // // setFixedSize(400, 300); // Set fixed size
    // setAlignment(Qt::AlignTop | Qt::AlignLeft); // Align top-left corner
}

Overlay_Widget::~Overlay_Widget()
{
    delete ui;
}
// QRect rect = m_pFloatWidget->geometry();

// if (!rect.contains(QCursor::pos()))
// {
//     m_pFloatWidget->hide();
// }
// void VideoWidget::resizeEvent(QResizeEvent * event)
// {
//     if (m_pFloatWidget)
//     {
//         QRect rect = ui.widgetVideo->geometry();
//         QPoint pt = mapToGlobal(rect.topLeft());

//         m_pFloatWidget->setGeometry(pt.x(), pt.y(), ui.widgetVideo->width(), ui.widgetVideo->height());
//     }
// }
