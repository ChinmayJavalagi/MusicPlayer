//
// Created by Ani Hadagali on 13/09/23.
//

#ifndef MUSIC_PLAYER_SYSTEM_PLAYLIST_H
#define MUSIC_PLAYER_SYSTEM_PLAYLIST_H

#include "Songs.h"
#include "bits/stdc++.h"

using namespace std;

class Playlist {
private:
    string name;
    queue<Songs> songs;
    fstream playlistFile;
public:
    Playlist(string name);
    void addSong();
    void removeSong();
};

#endif //MUSIC_PLAYER_SYSTEM_PLAYLIST_H
