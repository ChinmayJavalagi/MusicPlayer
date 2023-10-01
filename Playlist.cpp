//
// Created by Ani Hadagali on 13/09/23.
//

#include "Playlist.h"
#include "bits/stdc++.h"
#include "fstream"

using namespace std;

Playlist ::Playlist(std::string name) {
    this->name = name;
    name = name + ".txt";
    this->playlistFile.open(name,ios::app);
}
void Playlist::addSong() {
    Songs songs;
    cout << "Enter the Song details\n ->";
    cout <<"1. Song name :";
    string s; cin >> s;
    songs.setTitle(s);
    cout <<"2. Song Artist :";
    cin >> s;
    songs.setArtist(s);
    cout << "3. Genre :";
    cin >> s;
    songs.setGenre(s);
    cout << "4. Duration in mins:";
    cin >> s;
    songs.setDur(s);
    this->songs.push(songs);
    ofstream playListFile;
    string playListName = this->name;
    playListFile.open(playListName + ".txt",ios::app);

    if(playListFile.is_open()) {
        playListFile << songs.getTitle() << " " << songs.getArtist() << " " << songs.getGenre() << " " << songs.getDur() << endl;
        playListFile.close();
        cout << "---Song added successfully---" << endl;
    }
    else {
        cout << "Error";
        exit(0);
    }
}