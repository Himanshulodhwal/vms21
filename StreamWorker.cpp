#include "StreamWorker.h"

StreamWorker::StreamWorker(QObject *parent)
    : QObject(parent), m_mediaPlayer(nullptr) {
}

void StreamWorker::setMediaPlayer(VlcMediaPlayer *mediaPlayer) {
    m_mediaPlayer = mediaPlayer;
}

void StreamWorker::playStream() {
    if (m_mediaPlayer) {
        m_mediaPlayer->play();
        emit streamStarted();
    } else {
        emit errorOccurred("Media player not set.");
    }
}

void StreamWorker::stopStream() {
    if (m_mediaPlayer) {
        m_mediaPlayer->stop();
        emit streamStopped();
    }
}
