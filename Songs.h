//
// Created by Ani Hadagali on 13/09/23.
//

#ifndef MUSIC_PLAYER_SYSTEM_SONGS_H
#define MUSIC_PLAYER_SYSTEM_SONGS_H
#include "bits/stdc++.h"

using namespace std;

class Songs {
private:
    string title, artist, genre,dur;
public:

    const string &getTitle() const;

    void setTitle(const string &title);

    const string &getArtist() const;

    void setArtist(const string &artist);

    const string &getGenre() const;

    void setGenre(const string &genre);

    string getDur() const;

    void setDur(string dur);

};


#endif //MUSIC_PLAYER_SYSTEM_SONGS_H
