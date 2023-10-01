#include "bits/stdc++.h"
#include <thread>
#include <chrono>
#include "User.h"
#include "Playlist.h"
#include "MusicPlayer.h"
#include "Songs.h"

using namespace std;

void waiting_animation(int n,string s) {
    cout << s;

    for (int i = 0; i < n; ++i) {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleep for 1 second
    }
    cout << endl;
}

void displayPlayLists(set<string> playlists) {

    if(playlists.empty()) {
        cout << "No playlists created yet...\n";
    }

    for(string it : playlists) {
        cout <<"1. " <<it << endl;
    }
}


int main(int argc, char const *argv[]) {
    int i;
    i = 1;
    bool logged_in = false;
    string curr_user = "---Not Logged in---";
    string s;
    set<string> playlLists;
   while(i) {
       cout << "1: To login\n2: To Register\n3: Press any other key to exit\n";
       cin >> i;
       if(i == 1) {
           cout << "Enter user name: ";
           string username;
           cin >> username;
           cout << "Enter the password: ";
           string password;
           cin >> password;
           User user1(username,password);
           bool flag = user1.Login(username,password);
           if(!flag)
               cout << "Username dose not  exist\n";
           else {
               cout << "Successfully logged in\n";
               curr_user = username;
               logged_in = true;
               break;
           }
       }
       else if(i == 2) {
           cout << "Chose an username: ";
           string username;
           cin >> username;
           cout << "Chose a strong password: ";
           string password;
           cin >> password;
           User user(username,password);
           bool flag = user.Register();
           if(!flag)
               cout << "Username already exist---Choose a different username---\n";
           else
               cout << "Successfully registered.\n----Login----\n";
       }
       else  {
           cout << "OK";
           break;
       }
   }
   if(!logged_in) {
       cout << "---Please Log in and try again---\n";
       exit(0);
   }

   cout << "\n--------------Welcome " + curr_user << "---------------------\n"<<  endl;

   ifstream myPlayLists;
   myPlayLists.open("allPlayLists.txt");

   if(myPlayLists.is_open()) {
       string line;

       while (getline(myPlayLists,line)) {
           playlLists.insert(line);
       }

       myPlayLists.close();
   }
   else {
       cout << "Playlist file is not created...\n";
   }

   int op = 1;

   while(op) {
       cout << "Chose--->\n";
       cout << "1. Create Playlist\n2. Play Playlist\n3. Add songs to existing playlist\n4. Exit\n";

       cin >> op;

       if(op == 1) {
           cout << "Enter a playlist name :";
           string playlistName;
           cin >> playlistName;
           ofstream allPlayLists;
           allPlayLists.open("allPlayLists.txt");

           if(allPlayLists.is_open()) {
               allPlayLists << playlistName << endl;
           }

           playlLists.insert(playlistName);
           Playlist new_playlist(playlistName);
           new_playlist.addSong();
       }
       else if(op == 2) {
           if(playlLists.empty()) {
               cout << "You have not created any playlists yet.\n";
           } else {
               cout << "Which playlist you want to play :\n";
               displayPlayLists(playlLists);
               string chose_playlist;
               int xx;
               cin >> xx;
               auto it = next(playlLists.begin(),xx - 1);
               chose_playlist = *it;

               if(playlLists.find(chose_playlist) == playlLists.end()) {
                   cout << "No such Playlists...\n Create one? (Y/N)";
                   char x;
                   cin >> x;
                   if(x == 'y' || x == 'Y')
                       op == 1;
                   else {
                       cout << "You are being redirected...\n";
                       waiting_animation(3,"Waiting");
                   }
               }
               else {
                   cout << "Loading " + chose_playlist << endl;
                   waiting_animation(3,"");
                   MusicPlayer spotify(chose_playlist);
                   spotify.Spotify();
               }
           }
       }
       else if(op == 3) {
           cout << "Which playlist you want to add songs to :\n";
           displayPlayLists(playlLists);
           string chose_playlist;
           int xx;
           cin >> xx;
           auto it = next(playlLists.begin(),xx - 1);
           chose_playlist = *it;
           if(playlLists.find(chose_playlist) == playlLists.end()) {
               cout << "No such Playlists...\n Create one? (Y/N)";
               char x;
               cin >> x;
               if(x == 'y' || x == 'Y')
                   op == 1;
               else {
                   cout << "You are being redirected...\n";
                   waiting_animation(3,"Waiting");
               }
           } else {
               Playlist newplaylist(chose_playlist);
               newplaylist.addSong();
           }
       }
       else {
           cout << "Thank you for choosing spotify...\n";
           exit(0);
       }
   }

}
