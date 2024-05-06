// StreamPlayerWorker.h

#ifndef STREAMPLAYERWORKER_H
#define STREAMPLAYERWORKER_H

#include <QObject>
#include <VLCQtCore/MediaPlayer.h>

class StreamPlayerWorker : public QObject
{
    Q_OBJECT

public:
    explicit StreamPlayerWorker(QObject *parent = nullptr);

public slots:
    void playStream(VlcMediaPlayer *mediaPlayer);
    void playStream(VlcMediaPlayer *mediaPlayer, int index);  // Add this line
    private:
    QString rtspUrls[16]  = {
        "rtsp://192.168.1.98:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.11:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.15:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.213:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.208:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.23:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.15:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.15:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.13:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.14:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.25:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.208:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.11:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.14:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.11:554/avstream/channel=1/stream=0.sdp",
        "rtsp://192.168.1.42:554/avstream/channel=1/stream=0.sdp"
    };
};

#endif // STREAMPLAYERWORKER_H
