//
// Created by Ani Hadagali on 13/09/23.
//

#include "MusicPlayer.h"
#include "bits/stdc++.h"
#include <thread>
#include <chrono>

using namespace std;

string songName;
int dur;

MusicPlayer::MusicPlayer(string name) {
    playList_name = name;
    cout << "Playing in Spotify...\n";
}

void printDots(int time, string name) {
    cout << name;
    for (int i = 0; i < time; ++i) {
        cout << ".";
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl;
    return;
}
void MusicPlayer::Play(std::string name, int time) {
    cout << "-----------------------------------------" << endl;
    cout << "Current Song: " << name << endl;
    cout << "-----------------------------------------" << endl;

    for (int i = 0; i < time ; ++i) {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));// Sleep for 1 second
    }

//    if(!paused) {
//        cout << "Playing next\n";
//        currSong++;
//        stopped = true;
//    }
//
//    return !paused;
}

void MusicPlayer::Spotify() {
    string currPlaylist = playList_name;
    vector<pair<string,int>> songs;

    ifstream openplaylist_file;
    openplaylist_file.open(currPlaylist + ".txt");
    if(openplaylist_file.is_open()) {
        string line;
        while(getline(openplaylist_file,line)) {
            istringstream iss(line);
            string songName;
            string artist;
            string genre;
            string dur;
            iss >> songName >> artist >> genre >> dur;
            int time = stoi(dur);
            songs.emplace_back(songName,time);
        }
        openplaylist_file.close();
    }

    if(songs.empty()) {
        cout << "No songs in your in playlist...\n";
        return;
    }

    int currSong = 0;
    int remaining_time = 0;
    bool isPlaying = false;
    bool first = false;
    while(true) {

        if(first) {
            cout << "-----------------------------------------" << endl;
            cout << "Current Song: " << songs[currSong].first << endl;
            cout << "-----------------------------------------" << endl;

        }

//        if (isPlaying) {
//            cout << "Playing: ";
//            printDots(remaining_time * 2,"PLAYING");
//            remaining_time = 0;
//        }

        cout << "1. Play/Pause\n2. Next\n3. Prev\n4. Exit\n";
        cout << "Chose one " ;

        int ch;
        cin >> ch;

        switch (ch) {
            case 1: {
                isPlaying = ~isPlaying;
                first = true;
                if (!isPlaying) {
                    cout << "Paused" << endl;
                } else {
                    //cout << "Playing" << endl;
                    remaining_time = songs[currSong].second;
                    printDots(remaining_time,"PLAYING");
                }
                break;
            }
            case 2: {
                currSong = (currSong + 1) % songs.size();
                isPlaying = false;
                remaining_time = 0;
                break;
            }
            case 3: {
                currSong = (currSong - 1 + songs.size()) % songs.size();
                isPlaying = false;
                remaining_time = 0;
                break;
            }
            case 4: {
                cout << "-------------Exiting from spotify-------------\n";
                return;
            }
            default:
                return;
        }
    }
}
