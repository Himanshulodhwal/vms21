// StreamPlayerWorker.cpp

#include "StreamPlayerWorker.h"

StreamPlayerWorker::StreamPlayerWorker(QObject *parent) : QObject(parent)
{
   instance = new VlcInstance(VlcCommon::args(), parent);
}

void StreamPlayerWorker::playStream(VlcMediaPlayer *mediaPlayer)
{
    // Implement the single-parameter playStream function
    // ...
}

void StreamPlayerWorker::playStream(VlcMediaPlayer *mediaPlayer, int index)
{
    if (mediaPlayer && index >= 0 && index < 16)
    {
        // Create a new VlcMedia instance and set the MRL
        VlcMedia *media = new VlcMedia(rtspUrls[index], true, instance);

        // Open the media in the player
        mediaPlayer->open(media);

        // Play the media
        mediaPlayer->play();
        // Additional logic as needed
    }
}
