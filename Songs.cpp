//
// Created by Ani Hadagali on 13/09/23.
//

#include "Songs.h"
#include "bits/stdc++.h"

using namespace std;


const string &Songs::getTitle() const {
    return title;
}

void Songs::setTitle(const string &title) {
    Songs::title = title;
}

const string &Songs::getArtist() const {
    return artist;
}

void Songs::setArtist(const string &artist) {
    Songs::artist = artist;
}

const string &Songs::getGenre() const {
    return genre;
}

void Songs::setGenre(const string &genre) {
    Songs::genre = genre;
}

string Songs::getDur() const {
    return dur;
}

void Songs::setDur(string dur) {
    Songs::dur = dur;
}

