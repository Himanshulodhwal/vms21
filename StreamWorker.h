#ifndef STREAMWORKER_H
#define STREAMWORKER_H

#include <QObject>
#include <VLCQtCore/MediaPlayer.h>

class StreamWorker : public QObject {
    Q_OBJECT

public:
    explicit StreamWorker(QObject *parent = nullptr);
    void setMediaPlayer(VlcMediaPlayer *mediaPlayer);
    void setMedia(VlcMedia *media);

public slots:
    void playStream();
    void stopStream();

signals:
    void streamStarted();
    void streamStopped();
    void errorOccurred(QString error);

private:
    VlcMediaPlayer *m_mediaPlayer;
};

#endif // STREAMWORKER_H
