#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QDockWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Media.h>
#include <VLCQtWidgets/WidgetVideo.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/Error.h>
#include <QLabel>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include "DraggableButton.h"
#include <QMessageBox>
#include <QEventLoop>
#include <QRegularExpression>
#include <QThread>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QScreen>
#include <QWindow>
#include <QFileDialog>
#include <QDir>
#include <QLabel>
#include <QDialog>
#include <QVBoxLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QScreen>
#include <QGuiApplication>
#include <QWindow>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QDesktopWidget>
#include <QTabBar>
#include <QSplitter>
#include <QTreeWidget>
#include <QListWidget>
#include <QTimer>
#include <QtConcurrent>
#include <QFuture>
#include<QStackedLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer =new QTimer();
    setWindowTitle("Sparsh");
    setWindowIcon(QIcon(":/new/prefix1/Sparsh-Logo1.png"));

    VlcCommon::setPluginPath("/usr/lib/vlc/plugins");
    QStringList args;
    args << "--ffmpeg-hw";
    instance = new VlcInstance(args, this);
    QStatusBar *statusBar = this->statusBar();
    // Create the snapshot button
    QPushButton *snapshotButton = new QPushButton(tr("Take Snapshot"));
    snapshotButton->setStyleSheet(
        "QPushButton { "
        "background-color:#899499; "
        "color: white; "
        "border-style: outset; "
        "border-width: 2px; "
        "border-radius: 5px; "
        "border-color: beige; "
        "font: bold 14px; "
        "min-width: 10em; "
        "padding: 6px; "
        "}"
        "QPushButton:hover { "
        "background-color: #708090 "
        "}"
        );

    connect(snapshotButton, &QPushButton::clicked, this, &MainWindow::takeSnapshot);

    // Add the snapshot button to the left side of the status bar
    statusBar->addPermanentWidget(snapshotButton, 1);
    QWidget *centralWidget = new QWidget(this);
    gridLayout = new QGridLayout(centralWidget);
    centralWidget->setLayout(gridLayout);
    setCentralWidget(centralWidget);

    // for (int i = 0; i < 16; ++i) {
    //     // cameraSlots[i] = new QLabel(this);
    //     shouldPlayStream[i] = true;
    //     Overlay_Widget_obj = new Overlay_Widget(i,this);

    //     videoWidgets[i] = new ClickableVlcWidgetVideo(i, centralWidget);
    //     connect(videoWidgets[i], &ClickableVlcWidgetVideo::doubleClicked, this, &MainWindow::handleDoubleClick);
    //     connect(videoWidgets[i], &ClickableVlcWidgetVideo::rightClicked,
    //             this, [this, i](int, const QPoint& pos) { showContextMenu(i, pos); });

    //     // Get the video widget from the media player
    //     mediaPlayers[i] = new VlcMediaPlayer(instance);
    //     mediaPlayers[i]->setVideoWidget(videoWidgets[i]);

    //     qmlWidget = new QQuickWidget();
    //     qmlWidget->setSource(QUrl("qrc:/overlay.qml"));
    //     qmlWidget->setWindowOpacity(0.5);
    //     // QWidget* videoWidget =  qobject_cast<QWidget*>(mediaPlayers[i]);
    //     // Overlay_Widget_obj = new Overlay_Widget(i,this);
    //     // Create container widget for video and overlay
    //     // QWidget* containerWidget = new QWidget();
    //     // containerWidget->setLayout(new QVBoxLayout());
    //     // containerWidget->layout()->setContentsMargins(0, 0, 0, 0);
    //     // containerWidget->layout()->addWidget(videoWidgets[i]);
    //     // Overlay_Widget_obj = new Overlay_Widget(i,centralWidget);
    //     // Add overlay widget to container
    //     // containerWidget->layout()->addWidget(Overlay_Widget_obj);
    //     // Create OverlayWidget
    //     // Create a container widget for video and overlay
    //     // QWidget* containerWidget = new QWidget();
    //     // containerWidget->setLayout(new QVBoxLayout());
    //     // containerWidget->layout()->setContentsMargins(0, 0, 0, 0);
    //     // containerWidget->layout()->addWidget(videoWidgets[i]);
    //     // containerWidget->layout()->addWidget(Overlay_Widget_obj);        //sunny
    //     videoWidgets[i]->setStyleSheet("background-color:white;");
    //     // //sunny

    //     vlcWidget[i] = new QWidget();

    //     vlcWidget[i]->setStyleSheet("background-color:blue;");
    //     // Set overlay widget as a child of video widget
    //     vlcWidget[i]->setLayout(new QHBoxLayout()); // Set layout to prevent vertical stacking
    //     vlcWidget[i]->layout()->setContentsMargins(0, 0, 0, 0); // Remove layout margins
    //     vlcWidget[i]->layout()->addWidget(videoWidgets[i]);
    //     vlcWidget[i]->layout()->addWidget(qmlWidget);

    //     // Set the size policy of qmlWidget to expand to fill the available space
    //     // Overlay_Widget_obj ->setVisible(true);
    //     // Overlay_Widget_obj ->hide();
    //     // Overlay_Widget_obj->raise();
    //     vlcWidget[i]->setAttribute(Qt::WA_Hover,true);
    //     vlcWidget[i]->setMouseTracking(true);

    //     // EventFilter* eventFilter = new EventFilter(i,Overlay_Widget_obj );
    //     // // Install the event filter on the video widget
    //     // vlcWidget[i]->installEventFilter(eventFilter);
    //     // qDebug() << "Parent Widget: " << Overlay_Widget_obj ->parentWidget();

    //     // // Use HoverableWidget instead of QWidget
    //     // EventFilter *hoverableWidget = new EventFilter();
    //     // vlcWidget[i]->layout()->addWidget(hoverableWidget);

    //     // // Connect hover signals to slots
    //     // connect(hoverableWidget, &EventFilter::hovered, this, [=](bool entered) {
    //     //     if (entered) {
    //     //         qmlWidget->show();
    //     //     } else {
    //     //         qmlWidget->hide();
    //     //     }
    //     // });
    //     // media[i] = new VlcMedia(rtspUrls[i], instance);
    //     // mediaPlayers[i] = new VlcMediaPlayer(instance);
    //     // mediaPlayers[i]->setVideoWidget(videoWidgets[i]);
    //     vlcWidget[i]->hide();

    // }





    /////////////--------------//////////////
    for (int i = 0; i < 16; ++i) {
        // cameraSlots[i] = new QLabel(this);
        shouldPlayStream[i] = true;

        videoWidgets[i] = new ClickableVlcWidgetVideo(i, centralWidget);
        connect(videoWidgets[i], &ClickableVlcWidgetVideo::doubleClicked, this, &MainWindow::handleDoubleClick);
        connect(videoWidgets[i], &ClickableVlcWidgetVideo::rightClicked,
                this, [this, i](int, const QPoint& pos) { showContextMenu(i, pos); });


        Overlay_Widget_obj = new Overlay_Widget(i,videoWidgets[i]);

        Overlay_Widget_obj->move(0, 1); // Position overlay widget at (0, 0) within containerWidget
        Overlay_Widget_obj->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        Overlay_Widget_obj->setVisible(true);
        Overlay_Widget_obj->hide();
        videoWidgets[i]->setStyleSheet("background-color:white;");


        vlcWidget[i] = new QWidget();
        vlcWidget[i]->setLayout(new QHBoxLayout()); // Set layout to prevent vertical stacking
        vlcWidget[i]->layout()->setContentsMargins(0, 0, 0, 0); // Remove layout margins

        vlcWidget[i]->layout()->addWidget(videoWidgets[i]);

        gridLayout->addWidget(vlcWidget[i], i / 4, i % 4);
        //sunny

        gridLayout->addWidget(vlcWidget[i], i / 4, i % 4);

        vlcWidget[i]->setAttribute(Qt::WA_Hover,true);
        vlcWidget[i]->setMouseTracking(true);

        // Create the event filter instance with the index
        EventFilter* eventFilter = new EventFilter(i,Overlay_Widget_obj);
        // Install the event filter on the video widget
        vlcWidget[i]->installEventFilter(eventFilter);
        qDebug() << "Parent Widget: " << Overlay_Widget_obj->parentWidget();

        // media[i] = new VlcMedia(rtspUrls[i], instance);
        mediaPlayers[i] = new VlcMediaPlayer(instance);
        mediaPlayers[i]->setVideoWidget(videoWidgets[i]);
        vlcWidget[i]->hide();

    }

    this->setStyleSheet("background-color:yellow;");

    // QPushButton *close_btn =new QPushButton("Clear All",centralWidget);
    // close_btn->setStyleSheet("border: none;");
    // QHBoxLayout *layout = new QHBoxLayout(centralWidget);
    // // Add the QPushButton to the layout
    // layout->addWidget(close_btn);

    // // Add some stretch to push the button to the left
    // layout->addStretch();
    // // Set the layout for the central widget
    // centralWidget->sertLayout(layout);
    // int windowwidth = centralWidget->width();
    // int windowheight = centralWidget->height();
    // int buttonwidth = close_btn->sizeHint().width();
    // int buttonheight = close_btn->sizeHint().height();
    // int buttonwidth = 100;
    // int buttonheight = 20;

    // int buttonX = windowwidth - buttonwidth-0;
    // int buttonY=0;
    // close_btn->move(buttonX,buttonY);
    // centralWidget->layout()->addWidget(close_btn);
    // connect(close_btn, &QPushButton::clicked, this, &MainWindow::clear_all_VLC);
    // QDockWidget *dockWidget = new QDockWidget(tr("Sidebar"), this);

    connect(timer,SIGNAL(timeout()),&sql_help,SLOT(selectdata_from_tbldata()));
    timer->start(2000);

    connect(this, &MainWindow::signal_load_vlc, this, &MainWindow::slot_loading_vlc);
    createSidebar();
    updateGridLayout(4,4);
    // vlc_load_in_thread();

}

MainWindow::~MainWindow()
{
    // Cleanup
    // liveview_alert_db_updation->quit();
    // liveview_alert_db_updation->wait();
    // thread->quit();
    // thread->wait();
    // // Delete media players
    for (int i = 0; i < 16; ++i) {
        if (mediaPlayers[i]) {
            mediaPlayers[i]->stop();
            delete mediaPlayers[i];
            mediaPlayers[i] = nullptr;
        }
    }

    // Delete media objects
    for (int i = 0; i < 16; ++i) {
        delete media[i];  // It's safe to delete nullptr, so no need to check
        media[i] = nullptr;
    }

    // Delete video widgets
    for (int i = 0; i < 16; ++i) {
        delete videoWidgets[i];  // Similar to above, direct deletion is fine
        videoWidgets[i] = nullptr;
    }

    // Delete camera slot labels
    // for (int i = 0; i < 16; ++i) {
    //     delete cameraSlots[i];
    //     cameraSlots[i] = nullptr;
    // }

    // Delete the VLC instance
    delete instance;
    instance = nullptr;

    // Delete last clicked media per slot
    for (int i = 0; i < 16; ++i) {
        delete lastClickedMediaPerSlot[i];
        lastClickedMediaPerSlot[i] = nullptr;
    }

    // Delete the last clicked media if it is dynamically allocated
    delete lastClickedMedia;
    lastClickedMedia = nullptr;

    // Delete the grid layout
    delete gridLayout;
    gridLayout = nullptr;

    delete listWidget; // Clean up the list widget
    // Delete the UI
    delete ui;
}


void MainWindow::createSidebar() {
    // Creating the dock widget to hold the sidebar
    QDockWidget *dockWidget = new QDockWidget(tr("Sidebar"), this);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // // Setting a fixed width for the dock widget to avoid covering the title bar
    dockWidget->setFixedWidth(310);
    QRect screenGeometry = QApplication::desktop()->screenGeometry();

    // Calculate the desired height as a percentage of the screen height
    int desiredHeight = screenGeometry.height() * 0.8;     // Adjust the height as needed
    dockWidget->setFixedHeight(desiredHeight); // Adjust the height as needed

    // // Creating the main widget for the sidebar
    QWidget *sidebarWidget = new QWidget();
    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebarWidget);

    // // Creating a group box for IP cameras
    // QGroupBox *cameraGroup = new QGroupBox(tr("IP cameras"));
    // QVBoxLayout *cameraLayout = new QVBoxLayout(cameraGroup);

    // // Adding draggable buttons for each camera
    // for (int i = 1; i <= 16; ++i) {
    //     DraggableButton *cameraButton = new DraggableButton(tr("Camera %1").arg(i), i, this);
    //     cameraButton->setObjectName(QString("CameraButton%1").arg(i));
    //     cameraButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    //     cameraButton->setFixedHeight(30);
    //     cameraLayout->addWidget(cameraButton);

    // // Connecting the dropped signal to handleCameraDrop function
    // connect(cameraButton, &DraggableButton::dropped, this, [=](int cameraIndex, const QPoint &dropPosition) {
    //     // Handle the camera drop here
    // handleCameraDrop(cameraIndex, dropPosition);
    // });

    // // Connecting the dragged signal to a slot or lambda function
    // connect(cameraButton, &DraggableButton::dragged, this, [=](int cameraIndex, const QPoint &dragPosition) {
    //     qDebug() << "Camera" << cameraIndex << "is being dragged at position:" << dragPosition;

    //     // Example: Change the button's appearance while dragging
    //     cameraButton->setText(QString("Dragging Camera %1").arg(cameraIndex));
    //     cameraButton->move(dragPosition - QPoint(cameraButton->width() / 2, cameraButton->height() / 2));

    //     });
    // }

    // cameraGroup->setLayout(cameraLayout);
    // sidebarLayout->addWidget(cameraGroup);


    // Create a tab widget
    // QWidget *centralWidget = new QWidget(this);
    QTabWidget *tabWidget = new QTabWidget();
    // Set the size hint of the tab widget to match the width of the dock widget
    tabWidget->setMinimumWidth(dockWidget->sizeHint().width());
    QVBoxLayout *mainLayout = new QVBoxLayout(tabWidget);
    mainLayout->addWidget(tabWidget);

    // Set the size policy of the tab widget to preferred for both width and height
    tabWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);    // Create and add tabs to the tab widget
    QWidget *tab1 = new QWidget();
    QWidget *tab2 = new QWidget();
    tabWidget->setStyleSheet("QTabBar::tab { width: 150px; }");
    tabWidget->setMinimumWidth(300);

    QTreeWidget *treeWidget = new QTreeWidget();
    treeWidget->setDragEnabled(true); // Enable drag operations
    treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    treeWidget->setHeaderLabel("Devices");
    QStringList list;

    for (const sql_helper::server &item : sql_help.serverlist) {

        QTreeWidgetItem *serverItem = new QTreeWidgetItem(treeWidget);
        serverItem->setText(0, item.server_name);

        for (const sql_helper::add_devices &itemdevice : sql_help.add_devices_list)
        {
            if(itemdevice.server_id == item.id){
                QTreeWidgetItem *childItem0 = new QTreeWidgetItem(serverItem);

                childItem0->setText(0, itemdevice.device_name);
                QVariant myvarient = QVariant::fromValue(itemdevice);
                childItem0->setData(0,Qt::UserRole +1,myvarient);
            }
        }
    }
    calculatedSlotIndex = 0;
    connect(treeWidget,&QTreeWidget::itemClicked,this,&MainWindow::onItemClicked);
        // connect(treeWidget,&QTreeWidget::itemSelectionChanged, this, &MainWindow::handleItemSelectionChanged);
    //[=](int cameraIndex, const QPoint &dropPosition) {
    // Handle the camera drop here
    // handleCameraDrop(cameraIndex, dropPosition);
    // });
    listWidget =new QListWidget();

    connect(&sql_help, &sql_helper::signal_to_anpr4_db_updated, this, &MainWindow::create_listwidget);


    // // // Creating a group box for view options
    QGroupBox *viewGroup = new QGroupBox(tr("View"));
    QVBoxLayout *viewLayout = new QVBoxLayout(viewGroup);

    // Adding buttons for different view options
    QStringList viewOptions = {"1x1", "2x2", "3x3", "4x4"};
    foreach (const QString &option, viewOptions) {
        QPushButton *button = new QPushButton(option);
        viewLayout->addWidget(button);
        viewButtons.append(button); // Store a reference to the button
        connect(button, &QPushButton::clicked, this, &MainWindow::handleViewChange);
    }

    viewGroup->setLayout(viewLayout);
    // sidebarLayout->addWidget(viewGroup);
    // sidebarLayout->addStretch(1);
    QVBoxLayout *tab_Layout = new QVBoxLayout();
    tab_Layout->addWidget(treeWidget);
    tab_Layout->addWidget(viewGroup);
    QWidget *centre_widget = new QWidget();
    centre_widget->setLayout(tab_Layout);

    tabWidget->addTab(listWidget, "Alert");
    tabWidget->addTab(centre_widget, "Devices");
    sidebarLayout->addWidget(tabWidget);

    // Setting up the sidebar widget within the dock widget
    dockWidget->setWidget(sidebarWidget);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
    dockWidget->show();
}
void MainWindow::takeSnapshot() {
    // Take a snapshot of the entire window
    QScreen *screen = QGuiApplication::primaryScreen();
    QPixmap snapshot;
    if (const QWindow *window = windowHandle()) {
        screen = window->screen();
    }
    if (!screen) {
        QMessageBox::warning(this, tr("Error"), tr("Unable to access screen for snapshot."));
        return;
    }
    snapshot = screen->grabWindow(this->winId());
    takeSnapshotAnimation();
    // Create a new dialog to show the snapshot
    QDialog snapshotDialog(this);
    snapshotDialog.setWindowTitle(tr("Snapshot"));

    // Set a reasonable size for the dialog
    QSize dialogSize = QSize(screen->size().width() * 0.8, screen->size().height() * 0.8);
    snapshotDialog.resize(dialogSize);

    // Scale the snapshot to fit the dialog size while maintaining aspect ratio
    QPixmap scaledSnapshot = snapshot.scaled(dialogSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Create a label to display the snapshot
    QLabel *snapshotLabel = new QLabel(&snapshotDialog);
    snapshotLabel->setPixmap(scaledSnapshot);
    snapshotLabel->setAlignment(Qt::AlignCenter);  // Center the image in the dialog

    QVBoxLayout *dialogLayout = new QVBoxLayout(&snapshotDialog);
    dialogLayout->addWidget(snapshotLabel);

    // Create a button box for Save and Cancel
    QDialogButtonBox *buttonBox = new QDialogButtonBox(&snapshotDialog);
    buttonBox->setStandardButtons(QDialogButtonBox::Save | QDialogButtonBox::Cancel);
    dialogLayout->addWidget(buttonBox);

    // Connect the Save button
    QObject::connect(buttonBox, &QDialogButtonBox::accepted, [&snapshotDialog, scaledSnapshot]() {
        QString defaultPath = QDir::homePath() + "/img.png";  // Default filename and path
        QString filename = QFileDialog::getSaveFileName(&snapshotDialog, QObject::tr("Save Snapshot"), defaultPath, QObject::tr("PNG Image (*.png);;JPEG Image (*.jpg)"));

        if (!filename.isEmpty()) {
            // Ensure the filename has the correct extension
            if (QFileInfo(filename).suffix().isEmpty()) {
                filename.append(".png");  // Default to ".png" if no extension is provided
            }

            if (!scaledSnapshot.save(filename)) {
                QMessageBox::warning(&snapshotDialog, QObject::tr("Save Error"), QObject::tr("Failed to save snapshot."));
            } else {
                // Provide feedback that the image was saved successfully
                QMessageBox::information(&snapshotDialog, QObject::tr("Success"), QObject::tr("Snapshot saved successfully."));
                snapshotDialog.accept();  // Close the snapshot dialog
            }
        }
    });

    // Connect the Cancel button
    QObject::connect(buttonBox, &QDialogButtonBox::rejected, &snapshotDialog, &QDialog::reject);

    // Show the dialog
    snapshotDialog.exec();
}


// Inside MainWindow::handleViewChange
void MainWindow::handleViewChange() {
    qDebug() << "Button clicked!"; // Check if this is logged when a button is clicked

    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString viewOption = button->text();
    currentViewOption = viewOption; // Update the current view option
    qDebug() << "View option updated: " << currentViewOption;
    for (QPushButton* viewButton : qAsConst(viewButtons)) {
        viewButton->setStyleSheet("");
    }
    button->setStyleSheet("border: 2px solid #99A3A4 ;"); // Green border for example
    int rows, cols;

    if (viewOption == "1x1") {
        rows = cols = 1;
    } else if (viewOption == "2x2") {
        rows = cols = 2;
    } else if (viewOption == "3x3") {
        rows = cols = 3;
    } else if (viewOption == "4x4") {
        rows = cols = 4;
    } else {
        return;  // MORE option
    }

    qDebug()<<"=====updateGridLayout_view_changes=====";
    // updateGridLayout(rows, cols);
    updateGridLayout_view_changes(rows,cols);
    int cellWidth, cellHeight;
    calculateCellSize(currentViewOption, cellWidth, cellHeight);

    // Debug prints to check the shouldPlayStream array
    for (int i = 0; i < 16; ++i) {
        qDebug() << "shouldPlayStream[" << i << "]:" << shouldPlayStream[i];
    }
}


void MainWindow::updateGridLayout(int rows, int cols) {
    QGridLayout *gridLayout = qobject_cast<QGridLayout *>(centralWidget()->layout());

    // Stop all streams before rearranging
    for (int i = 0; i < 16; ++i) {
        // Stop the stream
        mediaPlayers[i]->stop();
        // Hide the widget
        videoWidgets[i]->hide();
        vlcWidget[i]->hide();

    }

    qDebug()<<"---333-333"<<rows<<"    =="<<cols;

    qDebug()<<"---4444-44";
    // Add video widgets to the grid layout as per rows and cols
    int count = 0;
    for (int i = 0; i<16 && count < rows * cols; ++i) {
        // Ensure media player and video widget are not null before accessing
        qDebug()<<"---555-44";
        qDebug()<<"---555-44================"<<mediaPlayers[i];

        if (mediaPlayers[i] && videoWidgets[i]) {
            qDebug()<<"---666-44======"<<i;
            // qDebug()<<"---777---"<<mediaPlayers[i];
            gridLayout->addWidget(vlcWidget[i], count / cols, count % cols);
            // connect(cancel_btn[i], &QPushButton::clicked, this, [this,i](){
            //     handel_close_event(i);
            // });

            videoWidgets[i]->show();
            vlcWidget[i]->show();
            // overlayout
            // Only play the stream if shouldPlayStream is true for this index
            if (shouldPlayStream[i]) {
                mediaPlayers[i]->play();
            }
        }
        count++;
    }
}


void MainWindow::showMainWindow() {
    show(); // Show the MainWindow
}
// void MainWindow::handleCameraDrop(int cameraIndex, const QPoint &dropPosition) {
//     int calculatedSlotIndex = calculateSlotIndex(dropPosition);
//     selectedSlotIndex = calculatedSlotIndex;  // Update selectedSlotIndex

//     if (calculatedSlotIndex >= 0 && calculatedSlotIndex < 16) {
//         ClickableVlcWidgetVideo *videoWidget = videoWidgets[calculatedSlotIndex];

//         if (videoWidget) {
//             // Create a QLabel for error message display
//             QLabel *errorMessageLabel = new QLabel(videoWidget);
//             errorMessageLabel->setObjectName("errorMessageLabel");  // Set an object name for later retrieval
//             errorMessageLabel->setText("Invalid stream! Please drop another.");
//             errorMessageLabel->setStyleSheet("QLabel { color: red; }");
//             errorMessageLabel->setAlignment(Qt::AlignCenter);
//             errorMessageLabel->setGeometry(0, 0, videoWidget->width(), videoWidget->height());
//             errorMessageLabel->setVisible(false); // Initially hide the error message

//             mediaPlayers[calculatedSlotIndex]->stop();
//             shouldPlayStream[calculatedSlotIndex] = true;
//             // Update the last clicked media for the specific slot
//             lastClickedMediaPerSlot[calculatedSlotIndex] = media[cameraIndex];
//             qDebug() << "Dropped Camera" << cameraIndex << "into Slot" << calculatedSlotIndex;
//             qDebug() << "Media URL for Slot" << calculatedSlotIndex << ":" << lastClickedMediaPerSlot[calculatedSlotIndex]->currentLocation();
//             mediaPlayers[calculatedSlotIndex]->open(lastClickedMediaPerSlot[calculatedSlotIndex]);

//             mediaPlayers[calculatedSlotIndex]->play();

//             if (cameraSlots[calculatedSlotIndex]) {
//                 cameraSlots[calculatedSlotIndex]->setText(QString("Camera %1").arg(cameraIndex));
//             }

//             // Use QEventLoop to wait for the stream to start playing or the timeout
//             QEventLoop eventLoop;
//             connect(mediaPlayers[calculatedSlotIndex], &VlcMediaPlayer::playing, &eventLoop, &QEventLoop::quit);
//             QTimer::singleShot(5000, &eventLoop, &QEventLoop::quit); // 5000 milliseconds timeout

//             eventLoop.exec(); // This will pause the execution until the timeout or the stream starts playing

//             // Check if the stream is not playing
//             if (mediaPlayers[calculatedSlotIndex]->state() != Vlc::State::Playing) {
//                 // If the stream doesn't start playing, show the error message
//                 errorMessageLabel->setVisible(true);
//                 videoWidget->setStyleSheet("background-color: black;"); // Set black background
//                 mediaPlayers[calculatedSlotIndex]->stop();
//             } else {
//                 // Clear the previous error message if the stream starts playing successfully
//                 QLabel *previousErrorMessageLabel = videoWidget->findChild<QLabel*>("errorMessageLabel");
//                 if (previousErrorMessageLabel) {
//                     previousErrorMessageLabel->clear();
//                     previousErrorMessageLabel->setVisible(false);
//                 }
//             }
//         }
//     } else {
//         qDebug() << "Invalid slot index or out of bounds";
//     }

//     // Manage the sidebar visibility based on fullscreen mode
//     if (isInFullscreenMode) {
//         toggleSidebar(false);
//     } else {
//         toggleSidebar(true);
//     }
// }

void MainWindow::takeSnapshotAnimation() {
    // Assuming this function is triggered when you want to show the snapshot animation

    // Create a new QWidget to cover the MainWindow
    QWidget *flashOverlay = new QWidget(this);
    flashOverlay->setAutoFillBackground(true);
    QPalette palette = flashOverlay->palette();
    palette.setColor(QPalette::Window, Qt::white);
    flashOverlay->setPalette(palette);
    flashOverlay->setGeometry(this->rect());  // Cover the entire window

    // Set up the semi-transparency effect
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    effect->setOpacity(0.8);  // Start with 80% opacity
    flashOverlay->setGraphicsEffect(effect);
    flashOverlay->show();

    // Create the animation to fade out
    QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(1000);  // 1 second duration
    animation->setStartValue(0.8);
    animation->setEndValue(0.0);  // Fade to fully transparent
    animation->setEasingCurve(QEasingCurve::InQuad);

    // Automatically delete the overlay and animation once it's done
    connect(animation, &QPropertyAnimation::finished, flashOverlay, &QWidget::deleteLater);
    connect(animation, &QPropertyAnimation::finished, animation, &QPropertyAnimation::deleteLater);

    // Start the animation
    animation->start();
}
void MainWindow::handleDoubleClick(int index) {
    if (index < 0 || index >= 16) {
        qDebug() << "Invalid index.";
        return;
    }

    if (isInFullscreenMode) {
        if (fullscreenIndex == index) {
            // Exiting fullscreen mode
            restoreOriginalLayout();
            isInFullscreenMode = false;
            fullscreenIndex = -1;
        }
    } else {
        // Entering fullscreen mode
        goToFullscreen(index);
        isInFullscreenMode = true;
        fullscreenIndex = index;
    }
}

void MainWindow::restoreOriginalLayout() {
    // Clear the grid layout first to remove any residual widgets
    clearGridLayout();

    // Show all widgets and update the grid layout to match the current view mode
    for (int i = 0; i < 16; ++i) {
        if (shouldPlayStream[i]) {
            mediaPlayers[i]->play();
        } else {
            videoWidgets[i]->hide(); // Make sure to hide widgets that should not be visible
        }
    }

    // Update the layout based on the current view option
    updateGridLayoutForCurrentView();

    // Restore the sidebar visibility
    toggleSidebar(true);
}



void MainWindow::goToFullscreen(int index) {
    // Hide the sidebar
    toggleSidebar(false);

    // Hide all video widgets in the grid layout
    for (int i = 0; i < 16; ++i) {
        if (i != index) {  // Keep the selected video visible
            videoWidgets[i]->hide();
            vlcWidget[i]->hide();
        }
    }
    vlcWidget[index]->setGeometry(0, 0, centralWidget()->width(), centralWidget()->height());
    vlcWidget[index]->show();

    // // Adjust the selected video widget to take the whole MainWindow area
    // videoWidgets[index]->setGeometry(0, 0, centralWidget()->width(), centralWidget()->height());
    // videoWidgets[index]->show();
}

void MainWindow::toggleSidebar(bool visible) {
    QDockWidget *dockWidget = findChild<QDockWidget *>();
    if (dockWidget) {
        dockWidget->setVisible(visible);
    }

}

// int MainWindow::calculateSlotIndex(const QPoint &dropPosition) {
//     int cellWidth, cellHeight;
//     calculateCellSize(currentViewOption, cellWidth, cellHeight);

//     QWidget *central = centralWidget();
//     QGridLayout *gridLayout = qobject_cast<QGridLayout *>(central->layout());

//     if (!gridLayout) {
//         qDebug() << "Layout is not a QGridLayout!";
//         return -1;
//     }

//     int cols = 0;
//     int rows = 0;

//     if (currentViewOption == "1x1") {
//         cols = rows = 1;
//     } else if (currentViewOption == "2x2") {
//         cols = rows = 2;
//     } else if (currentViewOption == "3x3") {
//         cols = rows = 3;
//     } else if (currentViewOption == "4x4") {
//         cols = rows = 4;
//     } else {
//         qDebug() << "Invalid view option!";
//         return -1;
//     }

//     int colWidth = gridLayout->geometry().width() / cols;
//     int rowHeight = gridLayout->geometry().height() / rows;

//     int colIndex = dropPosition.x() / colWidth;
//     int rowIndex = dropPosition.y() / rowHeight;

//     int slotIndex = rowIndex * cols + colIndex;

//     if (slotIndex >= 0 && slotIndex < (cols * rows)) {
//         return slotIndex;
//     }

//     qDebug() << "Invalid slot index or out of bounds";
//     return -1;
// }

void MainWindow::calculateCellSize(const QString &viewOption, int &cellWidth, int &cellHeight) {
    QSize widgetSize;

    // if (videoWidgets[0] && videoWidgets[0]->isVisible() && !videoWidgets[0]->size().isEmpty()) {
    if (vlcWidget[0] && vlcWidget[0]->isVisible() && !vlcWidget[0]->size().isEmpty()) {

        // widgetSize = videoWidgets[0]->size();
        widgetSize = vlcWidget[0]->size();

    } else {
        cellWidth = 1;
        cellHeight = 1;
        qDebug() << "Widget not visible or has no size!";
        return;
    }

    if (viewOption == "1x1") {
        cellWidth = widgetSize.width();
        cellHeight = widgetSize.height();
    } else if (viewOption == "2x2") {
        cellWidth = widgetSize.width() / 2;
        cellHeight = widgetSize.height() / 2;
    } else if (viewOption == "3x3") {
        cellWidth = widgetSize.width() / 3;
        cellHeight = widgetSize.height() / 3;
    } else if (viewOption == "4x4") {
        cellWidth = widgetSize.width() / 4;
        cellHeight = widgetSize.height() / 4;
    } else {
        cellWidth = widgetSize.width();
        cellHeight = widgetSize.height();
    }

    qDebug() << "Widget Size - Width:" << cellWidth << ", Height:" << cellHeight;
}

void MainWindow::showContextMenu(int index, const QPoint &pos) {
    QMenu contextMenu(tr("Context Menu"), this);
    qDebug() << "Context menu shown for index" << index;
    qDebug() << "Global position:" << pos;
    qDebug() << "Actions:" << contextMenu.actions().count();
    // Create actions for the context menu
    QAction *primaryModeAction = contextMenu.addAction("Primary Mode");
    QAction *secondaryModeAction = contextMenu.addAction("Secondary Mode");
    QAction *closeViewAction = contextMenu.addAction("Close View");

    // Use QCursor::pos() to get the cursor position
    QPoint globalPos = QCursor::pos();

    // Show the context menu at the cursor position
    QAction *selectedAction = contextMenu.exec(globalPos);

    // Handle the selected action
    if (selectedAction == primaryModeAction) {
        // Handle Primary Mode action
        switchStreamMode(index, 1);  // 1 indicates primary mode
    } else if (selectedAction == secondaryModeAction) {
        // Handle Secondary Mode action
        switchStreamMode(index, 0);  // 0 indicates secondary mode
    } else if (selectedAction == closeViewAction) {
        // Handle Close View action
        handleCloseView(index);


    }
}

void MainWindow::switchStreamMode(int index, int streamMode) {
    if (index < 0 || index >= 16 || !mediaPlayers[index] || !videoWidgets[index]) {
        qDebug() << "Invalid index or media player/video widget not properly configured.";
        return;
    }
    // Update the stream mode in the RTSP URL
    QString updatedRtspUrl = getUpdatedRtspUrl(index, streamMode);
    qDebug() << "Base RTSP URL: " << rtspUrls[index];
    qDebug() << "Before switchStreamMode - Current RTSP URL: " << media[index]->currentLocation();

    // Stop the current stream
    mediaPlayers[index]->stop();

    // Set a black background to the video widget
    videoWidgets[index]->setStyleSheet("background-color: black;");

    // Create a new VlcMedia instance with the updated MRL
    VlcMedia *newMedia = new VlcMedia(updatedRtspUrl, instance);
    qDebug() << "After switchStreamMode - Updated RTSP URL: " << updatedRtspUrl;

    // Configure and play the new stream
    mediaPlayers[index]->open(newMedia);
    mediaPlayers[index]->setVideoWidget(videoWidgets[index]);
    mediaPlayers[index]->play();

    // Optionally, connect the playing signal to ensure that the new stream is playing
    connect(mediaPlayers[index], &VlcMediaPlayer::playing, [this, index]() {
        qDebug() << "New stream is playing for index" << index;
        // Handle any further actions after the new stream starts playing, if needed.
        // For example, update UI, show a success message, etc.
    });

}

QString MainWindow::getUpdatedRtspUrl(int index, int streamMode) {
    // Assuming lastClickedMediaPerSlot is a global array of VlcMedia pointers
    VlcMedia *baseMedia = lastClickedMediaPerSlot[index];

    if (!baseMedia) {
        qDebug() << "Error: No base media for the selected slot.";
        return "";
    }

    QString baseRtspUrl = baseMedia->currentLocation();  // Get the current RTSP URL

    // Update the stream mode in the URL
    QString updatedRtspUrl = baseRtspUrl;
    updatedRtspUrl.replace("stream=0", "stream=" + QString::number(streamMode));

    return updatedRtspUrl;
}

void MainWindow::handleCloseView(int index) {
    if (index < 0 || index >= 16) {
        qDebug() << "Invalid index for closing view";
        return;
    }

    // Ensure we're not in fullscreen mode anymore
    isInFullscreenMode = false;
    fullscreenIndex = -1;

    // Stop the media player if needed and reset the stylesheet
    shouldPlayStream[index] = false;
    mediaPlayers[index]->stop();
    videoWidgets[index]->setStyleSheet("background-color: black;");

    // Reset the error message label if present
    resetErrorMessageLabel(index);

    // Update the layout to reflect the changes
    updateGridLayoutForCurrentView();

    // Make sure the sidebar is visible again
    toggleSidebar(true);

    // Refresh the application window to update the UI
    this->repaint();  // This forces the application to repaint the UI
}

void MainWindow::closeFullscreenView() {

    lastClickedIndex = -1;

    // After closing the full-screen view, refresh the grid layout
    updateGridLayoutForCurrentView();  // This is the new addition
}
void MainWindow::resetErrorMessageLabel(int index) {
    QLabel *errorMessageLabel = videoWidgets[index]->findChild<QLabel*>("errorMessageLabel");
    if (errorMessageLabel) {
        errorMessageLabel->clear();
        errorMessageLabel->setVisible(false);
    }
}

void MainWindow::updateGridLayoutForCurrentView() {
    clearGridLayout();  // Clear the existing layout first

    int rows, cols;
    getCurrentViewRowsCols(rows, cols);
    qDebug()<<"==rows==="<<rows<<"    "<<"===cols===="<<cols;
    // Add widgets back to the grid layout
    for (int i = 0, count = 0; i < 16 && count < rows * cols; ++i) {
        videoWidgets[i]->setVisible(true);
        gridLayout->addWidget(vlcWidget[i], count / cols, count % cols);

        // gridLayout->addWidget(videoWidgets[i], count / cols, count % cols);
        count++;
    }
    // Ensure that the central widget's layout is properly set after updates
    centralWidget()->setLayout(gridLayout);

    // If the sidebar should be visible, ensure it's not covered by any widgets
    if (!isInFullscreenMode) {
        toggleSidebar(true);
    }
}

void MainWindow::clearGridLayout() {
    while (QLayoutItem *item = gridLayout->takeAt(0)) {
        QWidget *widget = item->widget();
        if (widget) {
            widget->setVisible(true);  // Widgets should be visible, so don't hide them here
        }
        delete item;  // Only delete the layout item, not the widget itself
    }
    qDebug() << "Cleared grid layout.";
}

void MainWindow::getCurrentViewRowsCols(int &rows, int &cols) {
    if (currentViewOption == "1x1") {
        rows = cols = 1;
    } else if (currentViewOption == "2x2") {
        rows = cols = 2;
    } else if (currentViewOption == "3x3") {
        rows = cols = 3;
    } else if (currentViewOption == "4x4") {
        rows = cols = 4;
    } else {
        // Handle any other possible view options or set a default
        rows = cols = 4; // Default to 4x4
    }
}

void MainWindow::onItemClicked(QTreeWidgetItem *item,int column)
{
    qDebug()<<"===========onItemClicked========";
    QVariant variant = item->data(0,Qt::UserRole+1);
    if (variant.isValid())
    {
        sql_helper::add_devices retrievedObj = variant.value<sql_helper::add_devices>();
        int server_id = retrievedObj.server_id;
        QString secondary_url = retrievedObj.secondary_url;
        QString name =retrievedObj.device_name;
        qDebug()<<"=====calculatedSlotIndex-====="<<calculatedSlotIndex;
        selectedSlotIndex = calculatedSlotIndex;  // Update selectedSlotIndex
        if(calculatedSlotIndex>=16)
        {
            qDebug()<<"======calculatedSlotIndex== greater than 16===="<<calculatedSlotIndex;
            for (int i=0;i<16;i++)
            {
                if(shouldPlayStream[i]==false)
                {
                    qDebug()<<"======shouldPlayStream[i]==is false at index===="<<shouldPlayStream[i]<<"========"<<i;
                    ClickableVlcWidgetVideo *videoWidget = videoWidgets[i];

                    if (videoWidget) {
                        // Create a QLabel for error message display
                        QLabel *errorMessageLabel = new QLabel(videoWidget);
                        errorMessageLabel->setObjectName("errorMessageLabel");  // Set an object name for later retrieval
                        errorMessageLabel->setText("Invalid stream! Please drop another.");
                        errorMessageLabel->setStyleSheet("QLabel { color: red; }");
                        errorMessageLabel->setAlignment(Qt::AlignCenter);
                        errorMessageLabel->setGeometry(0, 0, videoWidget->width(), videoWidget->height());
                        errorMessageLabel->setVisible(false); // Initially hide the error message

                        mediaPlayers[i]->stop();
                        shouldPlayStream[i] = true;

                        QStringList option_list;
                        option_list.append(":network-caching=100");
                        option_list.append(":clock-jitter=0");
                        option_list.append(":clock-synchro=0");
                        // Update the last clicked media for the specific slot
                        media[i] = new VlcMedia(secondary_url,false, instance);
                        media[i]->setOptions(option_list);
                        // camname[i]->setText(name);
                        qDebug()<<"-----media[calculatedSlotIndex]-------"<<media[i];
                        lastClickedMediaPerSlot[i] = media[i];
                        qDebug() << "Dropped Camera" << media[i] << "into Slot" << calculatedSlotIndex;
                        qDebug() << "Media URL for Slot" << i << ":" << lastClickedMediaPerSlot[i]->currentLocation();
                        mediaPlayers[i]->open(lastClickedMediaPerSlot[i]);

                        mediaPlayers[i]->play();

                        // if (cameraSlots[calculatedSlotIndex]) {
                        //     cameraSlots[calculatedSlotIndex]->setText(QString("Camera %1").arg(name));
                        // }

                        // Use QEventLoop to wait for the stream to start playing or the timeout
                        QEventLoop eventLoop;
                        connect(mediaPlayers[i], &VlcMediaPlayer::playing, &eventLoop, &QEventLoop::quit);
                        QTimer::singleShot(5000, &eventLoop, &QEventLoop::quit); // 5000 milliseconds timeout

                        eventLoop.exec(); // This will pause the execution until the timeout or the stream starts playing

                        // Check if the stream is not playing
                        if (mediaPlayers[i]->state() != Vlc::State::Playing) {
                            // If the stream doesn't start playing, show the error message
                            errorMessageLabel->setVisible(true);
                            videoWidget->setStyleSheet("background-color: black;"); // Set black background
                            mediaPlayers[i]->stop();
                        } else {
                            // Clear the previous error message if the stream starts playing successfully
                            QLabel *previousErrorMessageLabel = videoWidget->findChild<QLabel*>("errorMessageLabel");
                            if (previousErrorMessageLabel) {
                                previousErrorMessageLabel->clear();
                                previousErrorMessageLabel->setVisible(false);
                            }
                        }
                    }

                }
                else{
                    qDebug()<<"======slot is full no widget is available to play vedio====";

                }
            }
            // calculatedSlotIndex++;
        }
        if (calculatedSlotIndex >= 0 && calculatedSlotIndex < 16) {
            qDebug()<<"-----media[calculatedSlotIndex]--sunny-----";//<<media[calculatedSlotIndex];

            ClickableVlcWidgetVideo *videoWidget = videoWidgets[calculatedSlotIndex];

            if (videoWidget) {
                // Create a QLabel for error message display
                QLabel *errorMessageLabel = new QLabel(videoWidget);
                errorMessageLabel->setObjectName("errorMessageLabel");  // Set an object name for later retrieval
                errorMessageLabel->setText("Invalid stream! Please drop another.");
                errorMessageLabel->setStyleSheet("QLabel { color: red; }");
                errorMessageLabel->setAlignment(Qt::AlignCenter);
                errorMessageLabel->setGeometry(0, 0, videoWidget->width(), videoWidget->height());
                errorMessageLabel->setVisible(false); // Initially hide the error message

                mediaPlayers[calculatedSlotIndex]->stop();
                shouldPlayStream[calculatedSlotIndex] = true;

                QStringList option_list;
                option_list.append(":network-caching=100");
                option_list.append(":clock-jitter=0");
                option_list.append(":clock-synchro=0");
                // Update the last clicked media for the specific slot
                media[calculatedSlotIndex] = new VlcMedia(secondary_url,false, instance);
                media[calculatedSlotIndex]->setOptions(option_list);
                // camname[calculatedSlotIndex]->setText(name);
                qDebug()<<"-----media[calculatedSlotIndex]-------"<<media[calculatedSlotIndex];
                lastClickedMediaPerSlot[calculatedSlotIndex] = media[calculatedSlotIndex];
                qDebug() << "Dropped Camera" << media[calculatedSlotIndex] << "into Slot" << calculatedSlotIndex;
                qDebug() << "Media URL for Slot" << calculatedSlotIndex << ":" << lastClickedMediaPerSlot[calculatedSlotIndex]->currentLocation();
                mediaPlayers[calculatedSlotIndex]->open(lastClickedMediaPerSlot[calculatedSlotIndex]);
                qDebug()<<"======mediaPlayers playing=====";
                mediaPlayers[calculatedSlotIndex]->play();
                qDebug()<<"======mediaPlayers playing==111111===";

                // if (cameraSlots[calculatedSlotIndex]) {
                //     cameraSlots[calculatedSlotIndex]->setText(QString("Camera %1").arg(name));
                // }

                // Use QEventLoop to wait for the stream to start playing or the timeout
                QEventLoop eventLoop;
                connect(mediaPlayers[calculatedSlotIndex], &VlcMediaPlayer::playing, &eventLoop, &QEventLoop::quit);
                QTimer::singleShot(5000, &eventLoop, &QEventLoop::quit); // 5000 milliseconds timeout

                eventLoop.exec(); // This will pause the execution until the timeout or the stream starts playing

                // Check if the stream is not playing
                if (mediaPlayers[calculatedSlotIndex]->state() != Vlc::State::Playing) {
                    // If the stream doesn't start playing, show the error message
                    errorMessageLabel->setVisible(true);
                    videoWidget->setStyleSheet("background-color: black;"); // Set black background
                    mediaPlayers[calculatedSlotIndex]->stop();
                } else {
                    // Clear the previous error message if the stream starts playing successfully
                    QLabel *previousErrorMessageLabel = videoWidget->findChild<QLabel*>("errorMessageLabel");
                    if (previousErrorMessageLabel) {
                        previousErrorMessageLabel->clear();
                        previousErrorMessageLabel->setVisible(false);
                    }
                }
            }
            calculatedSlotIndex++;

        } else {
            qDebug() << "Invalid slot index or out of bounds";
        }
    }

    // Manage the sidebar visibility based on fullscreen mode
    if (isInFullscreenMode) {
        toggleSidebar(false);
    } else {
        toggleSidebar(true);
    }

}
void MainWindow::dropEvent(QDropEvent *event)  {
    qDebug()<<"===dropEvent======";
    // if (event->mimeData()->hasFormat("application/x-qtreewidget-itemdata")) {
    //     QByteArray itemData = event->mimeData()->data("application/x-qtreewidget-itemdata");
    //     QDataStream dataStream(&itemData, QIODevice::ReadOnly);
    //     QString text;
    //     dataStream >> text;

    //     QLabel *label = new QLabel(text);
    //     // gridLayout->addWidget(videoWidgets[i], event->pos().y() / 50, event->pos().x() / 50);

    //     event->setDropAction(Qt::MoveAction);
    //     event->accept();
    // } else {
    //     event->ignore();
    // }
}
void MainWindow::handleItemSelectionChanged() {
    // QList<QTreeWidgetItem *> selectedItems = treeWidget->selectedItems();
    // if (!selectedItems.isEmpty()) {
    //     // Initiate drag operation based on the selected item
    //     QTreeWidgetItem *selectedItem = selectedItems.first();
    //     QDrag *drag = new QDrag(treeWidget);
    //     QMimeData *mimeData = new QMimeData;
    //     mimeData->setText(selectedItem->text(0));
    //     drag->setMimeData(mimeData);
    //     drag->exec(Qt::MoveAction);
    // }
}
// void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
//     QStyledItemDelegate::paint(painter, option, index);

//     if (index.row() > 0) { // Draw the line for items after the first one
//         painter->setPen(QPen(Qt::black, 1, Qt::SolidLine));
//         painter->drawLine(option.rect.topLeft(), option.rect.topRight());
//     }
// }
void MainWindow::ShowCard(QString camname,QString plateimgpath, QString vehicleimgpath,QString ocrnumber,QString datetime,QString vehicle_class)
{
    cardDialog = new CardDialog(camname,plateimgpath,vehicleimgpath,ocrnumber,datetime,vehicle_class);
}
void MainWindow::clear_all_VLC()
{
    // // // Delete media players
    for (int i = 0; i < 16; ++i) {
        // Ensure we're not in fullscreen mode anymore
        isInFullscreenMode = false;
        fullscreenIndex = -1;

        // Stop the media player if needed and reset the stylesheet
        shouldPlayStream[i] = false;
        mediaPlayers[i]->stop();
        mediaPlayers[i]->destroyed();
        videoWidgets[i]->setStyleSheet("background-color: black;");
        // camname[index]->text().clear();
        // camname[i]->clear();

        // Reset the error message label if present
        resetErrorMessageLabel(i);

        // Update the layout to reflect the changes
        updateGridLayoutForCurrentView();

        // Make sure the sidebar is visible again
        toggleSidebar(true);

        // Refresh the application window to update the UI
        this->repaint();  // This forces the application to repaint the UI

    }

}
void MainWindow::handel_close_event(int index)
{
    qDebug()<<"=====close_event===="<<index;
    // ClickableVlcWidgetVideo *videoWidget = videoWidgets[x];

    if (index < 0 || index >= 16) {
        qDebug() << "Invalid index for closing view";
        return;
    }

    // Ensure we're not in fullscreen mode anymore
    isInFullscreenMode = false;
    fullscreenIndex = -1;

    // Stop the media player if needed and reset the stylesheet
    shouldPlayStream[index] = false;
    mediaPlayers[index]->stop();
    mediaPlayers[index]->destroyed();
    videoWidgets[index]->setStyleSheet("background-color: black;");
    // camname[index]->text().clear();
    // camname[index]->clear();

    // Reset the error message label if present
    resetErrorMessageLabel(index);

    // Update the layout to reflect the changes
    updateGridLayoutForCurrentView();

    // Make sure the sidebar is visible again
    toggleSidebar(true);

    // Refresh the application window to update the UI
    this->repaint();  // This forces the application to repaint the UI
    // videoWidgets[index]->close();
}
void MainWindow::updateGridLayout_view_changes(int rows, int cols) {
    QGridLayout *gridLayout = qobject_cast<QGridLayout *>(centralWidget()->layout());

    // Stop all streams before rearranging
    for (int i = 0; i < 16; ++i) {
        // Stop the stream
        mediaPlayers[i]->stop();
        qDebug()<<"====hide===="<<i;
        // Hide the widget
        videoWidgets[i]->hide();
        vlcWidget[i]->hide();
    }
    // Clear existing layout
    QLayoutItem *child;
    while ((child = gridLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            QWidget *widget = qobject_cast<QWidget*>(child->widget());
            if (widget) {
                // It's a QWidget, remove it from the layout
                gridLayout->removeWidget(widget);
                // Optionally, you can hide the widget instead of removing it from the layout
                // widget->hide();
            }
        }
        // Delete the layout item after you're done with it
        delete child;
    }

    // Add video widgets to the grid layout as per rows and cols
    int count = 0;
    for (int i = 0;i < rows * cols; ++i) {
        // Ensure media player and video widget are not null before accessing
        if (mediaPlayers[i] && videoWidgets[i]) {
            gridLayout->addWidget(vlcWidget[i], count / cols, count % cols);

            // connect(cancel_btn[i], &QPushButton::clicked, this, [this,i](){
            //     handel_close_event(i);
            // });
            videoWidgets[i]->show();
            vlcWidget[i]->show();
            // Only play the stream if shouldPlayStream is true for this index
            if (shouldPlayStream[i]) {
                mediaPlayers[i]->play();
            }
        }
        count++;
    }
}
void MainWindow::create_listwidget()
{   
    const int maxItems = 100; // Maximum number of items to keep in the list widget
    // Remove the last item if the count exceeds the maximum limit
    while (listWidget->count() >= maxItems) {
        delete listWidget->takeItem(listWidget->count() - 1);
    }
    // Add new items to the beginning of the list
    for(int ii = sql_help.datalist.size() - 1; ii >= 0; ii--) {
        const sql_helper::tbldata &data_obj = sql_help.datalist[ii];
        if (!(data_obj.plateimgpath.isEmpty())) {
            cardWidget = new Cardwidget(data_obj.camname, data_obj.plateimgpath, data_obj.vehicleImagePath, data_obj.ocrnumber, data_obj.datetime, data_obj.vehicleclass);
            connect(cardWidget, &Cardwidget::cardClicked, this, &MainWindow::ShowCard);
        } else {
            cardWidget = new Cardwidget(data_obj.camname, "/home/sunny/Downloads/edit_icon.png", data_obj.vehicleImagePath, data_obj.ocrnumber, data_obj.datetime, data_obj.vehicleclass);
            connect(cardWidget, &Cardwidget::cardClicked, this, &MainWindow::ShowCard);
        }
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setSizeHint(cardWidget->sizeHint());
        // Insert the QListWidgetItem at the beginning of the QListWidget
        listWidget->insertItem(0, newItem);

        // Set the cardWidget as the item widget
        listWidget->setItemWidget(newItem, cardWidget);
    }

    // Clear the data list after adding new items
    sql_help.datalist.clear();
}
// void MainWindow::vlc_load_in_thread(VlcInstance *vlcInstance)
// {
//     QStringList rtsp_list=sql_help.get_rtsp_url(sql_help.add_devices_list);
//     // foreach (QString secondary_rtsp_url, rtsp_list) {
//     //     qDebug()<<"rtsp_url=========="<<secondary_rtsp_url;
//     // }

//     while (calculatedSlotIndex >= 0 && calculatedSlotIndex < 16) {
//         ClickableVlcWidgetVideo *videoWidget = videoWidgets[calculatedSlotIndex];
//         foreach (QString secondary_rtsp_url, rtsp_list) {
//             qDebug()<<"rtsp_url=========="<<secondary_rtsp_url;

//         if (videoWidget) {
//             // Create a QLabel for error message display
//             QLabel *errorMessageLabel = new QLabel(videoWidget);
//             errorMessageLabel->setObjectName("errorMessageLabel");  // Set an object name for later retrieval
//             errorMessageLabel->setText("Invalid stream! Please drop another.");
//             errorMessageLabel->setStyleSheet("QLabel { color: red; }");
//             errorMessageLabel->setAlignment(Qt::AlignCenter);
//             errorMessageLabel->setGeometry(0, 0, videoWidget->width(), videoWidget->height());
//             errorMessageLabel->setVisible(false); // Initially hide the error message

//             mediaPlayers[calculatedSlotIndex]->stop();
//             shouldPlayStream[calculatedSlotIndex] = true;

//             qDebug()<<"rtsp_url======1111===="<<secondary_rtsp_url<< "========"<<calculatedSlotIndex;

//             // Create media instance inside the lambda function
//             // int slotIndex= calculatedSlotIndex;
//             // QFuture<void> future = QtConcurrent::run([this, secondary_rtsp_url,slotIndex]() {
//             //     media[slotIndex] = new VlcMedia(secondary_rtsp_url, instance);
//             //     qDebug() << "-----media[calculatedSlotIndex]-------" << media[slotIndex];

//             // });
//             media[calculatedSlotIndex] = new VlcMedia(secondary_rtsp_url, vlcInstance);
//             qDebug()<<"-----media[calculatedSlotIndex]-------"<<media[calculatedSlotIndex];
//             lastClickedMediaPerSlot[calculatedSlotIndex] = media[calculatedSlotIndex];
//             qDebug() << "Dropped Camera" << media[calculatedSlotIndex] << "into Slot" << calculatedSlotIndex;
//             qDebug() << "Media URL for Slot" << calculatedSlotIndex << ":" << lastClickedMediaPerSlot[calculatedSlotIndex]->currentLocation();
//             mediaPlayers[calculatedSlotIndex]->open(lastClickedMediaPerSlot[calculatedSlotIndex]);
//             qDebug()<<"======mediaPlayers playing=====";
//             mediaPlayers[calculatedSlotIndex]->play();
//             qDebug()<<"======mediaPlayers playing==111111===";

//             // if (cameraSlots[calculatedSlotIndex]) {
//             //     cameraSlots[calculatedSlotIndex]->setText(QString("Camera %1").arg(name));
//             // }

//             // Use QEventLoop to wait for the stream to start playing or the timeout
//             QEventLoop eventLoop;
//             qDebug()<<"======mediaPlayers playing==222222===";

//             connect(mediaPlayers[calculatedSlotIndex], &VlcMediaPlayer::playing, &eventLoop, &QEventLoop::quit);
//             qDebug()<<"======mediaPlayers playing==33333===";

//             QTimer::singleShot(5000, &eventLoop, &QEventLoop::quit); // 5000 milliseconds timeout
//             qDebug()<<"======mediaPlayers playing==44444===";

//             eventLoop.exec(); // This will pause the execution until the timeout or the stream starts playing
//             qDebug()<<"======mediaPlayers playing==5555===";

//             // Check if the stream is not playing
//             if (mediaPlayers[calculatedSlotIndex]->state() != Vlc::State::Playing) {
//                 // If the stream doesn't start playing, show the error message
//                 qDebug()<<"======mediaPlayers playing==66666===";

//                 // errorMessageLabel->setVisible(true);
//                 qDebug()<<"======mediaPlayers playing==77777===";
//                 videoWidget->setStyleSheet("background-color: black;"); // Set black background

//                 mediaPlayers[calculatedSlotIndex]->stop();
//                 qDebug()<<"======mediaPlayers playing==8888===";

//             } else {
//                 // Clear the previous error message if the stream starts playing successfully
//                 QLabel *previousErrorMessageLabel = videoWidget->findChild<QLabel*>("errorMessageLabel");
//                 if (previousErrorMessageLabel) {
//                     previousErrorMessageLabel->clear();
//                     previousErrorMessageLabel->setVisible(false);
//                 }
//             }
//         }
//         calculatedSlotIndex++;

//     }
//     }
//     // else {
//     //     qDebug() << "Invalid slot index or out of bounds";
//     // }
//     // }
//     // qDebug()<<"Invalid slot index or out of bounds=========";

// }
void MainWindow::vlc_load_in_thread()
{
    // Emit a signal with the error message
    if (QThread::currentThread() != QCoreApplication::instance()->thread()) {
        qDebug() <<"=======vlc_load_in_thread========="<< "myFunction is running in a separate thread.";
    } else {
        qDebug() << "myFunction is running in the main thread.";
    }

    emit signal_load_vlc();

}
void MainWindow::slot_loading_vlc()
{
    ///
    /// brief rtsp_list
    if (QThread::currentThread() != QCoreApplication::instance()->thread()) {
        qDebug() << "myFunction is running in a separate thread.";
    } else {
        qDebug() << "myFunction is running in the main thread.";
    }
    QStringList rtsp_list = sql_help.get_rtsp_url(sql_help.add_devices_list);
    int index = 0;

    // Process each RTSP URL in the list
    for (const QString &secondary_rtsp_url : rtsp_list) {
        qDebug() << "rtsp_url========== " << secondary_rtsp_url;
        // Check if the index is within the valid range
        if (index >= 0 && index < 16) {
            ClickableVlcWidgetVideo *videoWidget = videoWidgets[index];
            if(shouldPlayStream[index]==false)
            {
                if (videoWidget) {
                    // Create a QLabel for error message display
                    QLabel *errorMessageLabel = new QLabel(videoWidget);
                    errorMessageLabel->setObjectName("errorMessageLabel");
                    errorMessageLabel->setText("Invalid stream! Please drop another.");
                    errorMessageLabel->setStyleSheet("QLabel { color: red; }");
                    errorMessageLabel->setAlignment(Qt::AlignCenter);
                    errorMessageLabel->setGeometry(0, 0, videoWidget->width(), videoWidget->height());
                    errorMessageLabel->setVisible(false);

                    mediaPlayers[index]->stop();
                    shouldPlayStream[index] = true;

                    // Create media instance and set it to the media player
                    media[index] = new VlcMedia(secondary_rtsp_url, instance);
                    lastClickedMediaPerSlot[index] = media[index];
                    qDebug() << "Dropped Camera" << media[index] << "into Slot" << index;
                    qDebug() << "Media URL for Slot" << index << ":" << lastClickedMediaPerSlot[index]->currentLocation();
                    mediaPlayers[index]->open(lastClickedMediaPerSlot[index]);
                    mediaPlayers[index]->play();

                    QFuture<void> future = QtConcurrent::run([this, index]() { vlc_in_separate_thread(index); });
                    future.waitForFinished();


                    if (mediaPlayers[index]->state() != Vlc::State::Playing) {
                        // If the stream doesn't start playing, show the error message
                        qDebug() << "Stream playback failed";
                        errorMessageLabel->setVisible(true);
                        videoWidget->setStyleSheet("background-color: black;");
                        mediaPlayers[index]->stop();
                    } else {
                        // Clear the previous error message if the stream starts playing successfully
                        QLabel *previousErrorMessageLabel = videoWidget->findChild<QLabel*>("errorMessageLabel");
                        if (previousErrorMessageLabel) {
                            previousErrorMessageLabel->clear();
                            previousErrorMessageLabel->setVisible(false);
                        }
                    }
                }
            }
            else {
                qDebug() << "Invalid video widget at index" << index;
            }
        } else {
            qDebug() << "Invalid slot index or out of bounds";
        }

        index++;
    }

}

void MainWindow::vlc_in_separate_thread(int index)
{
    qDebug()<<"========vlc_in_separate_thread========="<<index;
    QTimer timer;
    timer.setSingleShot(true);
    QEventLoop eventLoop;

    connect(&timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);
    connect(mediaPlayers[index], &VlcMediaPlayer::playing, &eventLoop, &QEventLoop::quit);

    timer.start(5000); // Set a timeout of 5000 milliseconds
    eventLoop.exec();

}
