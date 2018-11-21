#include "MusicAlbum.h"


MusicAlbum::MusicAlbum(const string maArtist, const string maTitle, const int maYear) {

	artist = maArtist;
	title = maTitle;
	year = maYear;

	arrSize = 10;
	songs = new Song[arrSize];

}

MusicAlbum::~MusicAlbum() {
	delete[] songs;
}

MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy) {

	artist = maToCopy.artist;
	title = maToCopy.title;
	year = maToCopy.year;

	noSongs = maToCopy.noSongs;
	arrSize = maToCopy.arrSize;

	Song* orr = maToCopy.songs;
	songs = new Song[arrSize];

	// Deep copy
	for (int i = 0; i < noSongs; i++) {
		songs[i] = orr[i];
	}

}

void MusicAlbum::operator=(const MusicAlbum &right) {

	artist = right.artist;
	title = right.title;
	year = right.year;

	noSongs = right.noSongs;
	arrSize = right.arrSize;

	Song* orr = right.songs;
	songs = new Song[arrSize];

	// Deep copy
	for (int i = 0; i < noSongs; i++) {
		songs[i] = orr[i];
	}


}

string MusicAlbum::getMusicAlbumArtist() {
	return artist;
}

string MusicAlbum::getMusicAlbumTitle() {
	return title;
}

int MusicAlbum::getMusicAlbumYear() {
	return year;
}

void MusicAlbum::calculateMusicAlbumLength(int &minutes, int &seconds) {

	minutes = 0;
	seconds = 0;

	for (int i = 0; i < noSongs; i++) {
		minutes += songs[i].getMins();
		seconds += songs[i].getSecs();
	}

	minutes += (seconds / 60);
	seconds %= 60;

}

bool MusicAlbum::addSong(const string sName, const int sMins, const int sSecs) {
	
	for (int i = 0; i < noSongs; i++) {
		if (songs[i].getName() == sName && songs[i].getMins() == sMins && songs[i].getSecs() == sSecs)
			return false;
	}

	Song song(sName, sMins, sSecs);
	if (noSongs == arrSize)
		resizeArray();

	songs[noSongs] = song;
	noSongs++;

	return true;

}

bool MusicAlbum::removeSongs() {

	arrSize = 10;

	delete[] songs;
	songs = new Song[arrSize];

	return true;
}

Song * MusicAlbum::getSongs() {
	return songs;
}

void MusicAlbum::resizeArray() {

	Song *resized = new Song[arrSize * 2];
	for (int i = 0; i < arrSize; i++) {
		resized[i] = songs[i];
	}

	delete[] songs;
	songs = resized;

	arrSize *= 2;

}
