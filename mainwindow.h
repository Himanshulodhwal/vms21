#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>
#include <QProgressBar>
#include <VLCQtCore/Common.h>
#include <VLCQtWidgets/WidgetVideo.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include "DraggableButton.h"
#include <sql_helper.h>
#include <QTreeWidgetItem>
#include <cardwidget.h>
#include <carddialog.h>
#include <handel_thread.h>
#include <overlay_widget.h>
#include <eventfilter.h>
#include<QQuickWidget>

Q_DECLARE_METATYPE(sql_helper::add_devices);

class DraggableButton;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ClickableVlcWidgetVideo : public VlcWidgetVideo {
    Q_OBJECT

public:
    explicit ClickableVlcWidgetVideo(int index, QWidget *parent = nullptr)
        : VlcWidgetVideo(parent), m_index(index) {}

    int getIndex() const { return m_index; }
signals:
    void clicked(int index);
    void doubleClicked(int index);
    void rightClicked(int index, const QPoint &pos);

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::RightButton) {
            emit rightClicked(m_index, event->pos());
        } else {
            emit clicked(m_index);
        }
    }

    void mouseDoubleClickEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            emit doubleClicked(m_index);
        }
    }

signals:
public:

private:
    int m_index;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QRect originalGeometry;

    void takeSnapshotAnimation();
    void vlc_load_in_thread();
    void vlc_in_separate_thread(int index);
    void ShowCard(QString camname,QString plateimgpath, QString vehicleimgpath,QString ocrnumber,QString datetime,QString vehicle_class);

private slots:
    void showMainWindow();
    void handleViewChange();
    // void handleCameraDrop(int cameraIndex, const QPoint &dropPosition);
    // int calculateSlotIndex(const QPoint &dropPosition);
    void calculateCellSize(const QString &viewOption, int &cellWidth, int &cellHeight);
    void handleDoubleClick(int index);

    void showContextMenu(int index, const QPoint &pos);
    void handleCloseView(int index);
    void closeFullscreenView();
    void resetErrorMessageLabel(int index);
    void updateGridLayoutForCurrentView();
    void getCurrentViewRowsCols(int &rows, int &cols);
    void takeSnapshot();

private:
    void restoreOriginalLayout();
    void goToFullscreen(int index);
    bool isInFullscreenMode = false;
    int fullscreenIndex = -1;
    QSet<int> droppedStreams;
    QList<QPushButton*> viewButtons;
    QPushButton* selectedViewButton = nullptr;

    int originalSlotIndex;
    void clearGridLayout();
    QMap<int, bool> wasPlayingBeforeFullscreen;
    bool shouldPlayStream[16];
    void setupInitialLayout();
    Ui::MainWindow *ui;
    // void createSidebar();
    void setupMediaPlayer();
    void updateGridLayout(int rows, int cols);
    ClickableVlcWidgetVideo *videoWidgets[16];
    VlcMedia *media[16];
    VlcMediaPlayer *mediaPlayers[16];
    VlcInstance *instance;
    DraggableButton *selectedLayoutButton;
    QLabel* cameraSlots[16];
    int selectedVideoIndex = -1;
    int cellWidth = 1;
    int cellHeight = 1;
    int selectedSlotIndex = -1;
    int lastClickedIndex;
    QString currentViewOption = "4x4";
    QGridLayout *gridLayout;

    QMetaObject::Connection playingConnection;
    VlcMedia* lastClickedMedia;
    VlcMedia *lastClickedMediaPerSlot[16];
    void toggleSidebar(bool visible);
    void switchStreamMode(int index, int streamMode);
    QString getUpdatedRtspUrl(int index, int streamMode);

    QString rtspUrls[16]  = {
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp",
        "rtsp://admin:admin123@192.168.1.204:554/avstream/channel=1/stream=1.sdp"
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171",
        // "rtsp://192.168.1.16:8554/secondary171"
    };

    // sql_helper sql_help;
    // sql_helper::server obj;
    // sql_helper::add_devices device_obj;
    // sql_helper::tbldata tbldata_obj;
    Cardwidget *cardWidget;
    CardDialog *cardDialog;
    sql_helper& sql_help = sql_helper::getInstance();


    int calculatedSlotIndex;
    void onItemClicked(QTreeWidgetItem *item,int column);
    void dropEvent(QDropEvent *event);
    void handleItemSelectionChanged();
    void clear_all_VLC();
    void handel_close_event(int x);
    QWidget *vlcWidget[16];
    QPushButton *cancel_btn[16];
    QLabel *camname[16];
    QListWidget *listWidget;
    void updateGridLayout_view_changes(int rows, int cols);
    void create_listwidget();
    Overlay_Widget *Overlay_Widget_obj;
    QVBoxLayout *overlayout[16];
    // EventFilter
    QQuickWidget *qmlWidget;
public slots:
    void createSidebar();
    void slot_loading_vlc();
signals:
    void signal_load_vlc();
protected:
    // // Override eventFilter function in MainWindow to handle events
    // bool eventFilter(QObject *obj, QEvent *event) {
    //     if (event->type() == QEvent::Enter) {
    //         // If the mouse enters a vlcWidget, show the qmlWidget
    //         for (int i = 0; i < 16; ++i) {
    //             if (obj == vlcWidget[i]) {
    //                 qmlWidget->show();
    //                 return true;
    //             }
    //         }
    //     } else if (event->type() == QEvent::Leave) {
    //         // If the mouse leaves a vlcWidget, hide the qmlWidget
    //         for (int i = 0; i < 16; ++i) {
    //             if (obj == vlcWidget[i]) {
    //                 qmlWidget->hide();
    //                 return true;
    //             }
    //         }
    //     }
    //     // If the event is not handled by this function, propagate to the base class
    //     return QMainWindow::eventFilter(obj, event);
    // }
};

#endif // MAINWINDOW_H
