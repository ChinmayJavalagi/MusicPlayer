//
// Created by Ani Hadagali on 13/09/23.
//

#ifndef MUSIC_PLAYER_SYSTEM_MUSICPLAYER_H
#define MUSIC_PLAYER_SYSTEM_MUSICPLAYER_H
#include "bits/stdc++.h"

using namespace std;


class MusicPlayer {
public:
    MusicPlayer(string name);
    bool Play(string name, int time);
    void Pause();
    void Next();
    void Previous();
    void Spotify();
private:
    bool stopped = false;
    bool paused = false;
    string playList_name;
};

#endif //MUSIC_PLAYER_SYSTEM_MUSICPLAYER_H
