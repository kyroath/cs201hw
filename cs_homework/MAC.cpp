#include "MAC.h"



MAC::MAC() {

	noOfMusicAlbums = 0;
	arrSize = 10;

	musicAlbums = new MusicAlbum[arrSize];

}


MAC::~MAC() {

	delete[] musicAlbums;

}

MAC::MAC(const MAC &macToCopy) {

	noOfMusicAlbums = macToCopy.noOfMusicAlbums;
	arrSize = macToCopy.arrSize;

	MusicAlbum *orr = macToCopy.musicAlbums;
	musicAlbums = new MusicAlbum[arrSize];

	// Deep copy
	for (int i = 0; i < noOfMusicAlbums; i++) {
		musicAlbums[i] = orr[i];
	}

}

void MAC::operator=(const MAC & right) {

	noOfMusicAlbums = right.noOfMusicAlbums;
	arrSize = right.arrSize;

	MusicAlbum *orr = right.musicAlbums;

	delete[] musicAlbums;
	musicAlbums = new MusicAlbum[arrSize];

	// Deep copy
	for (int i = 0; i < noOfMusicAlbums; i++) {
		musicAlbums[i] = orr[i];
	}

}

bool MAC::addMusicAlbum(const string maArtist, const string maTitle, const int maYear) {
	
	for (int i = 0; i < noOfMusicAlbums; i++) {
		if (musicAlbums[i].getMusicAlbumArtist() == maArtist &&
			musicAlbums[i].getMusicAlbumTitle() == maTitle &&
			musicAlbums[i].getMusicAlbumYear() == maYear)
			return false;
	}

	MusicAlbum album(maArtist, maTitle, maYear);
	if (noOfMusicAlbums == arrSize)
		resizeArray();

	musicAlbums[noOfMusicAlbums] = album;
	noOfMusicAlbums++;

	return true;
}

bool MAC::removeMusicAlbum(const string maArtist, const string maTitle) {
	
	int cont = -1;
	for (int i = 0; i < noOfMusicAlbums; i++) {
		if (musicAlbums[i].getMusicAlbumArtist() == maArtist &&
			musicAlbums[i].getMusicAlbumTitle() == maTitle) {
			cont = i;
			break;
		}
	}

	if (cont != -1) {

		delete[] musicAlbums[cont].getSongs();

		for (int i = cont; i < noOfMusicAlbums; i++) {
			musicAlbums[i] = musicAlbums[i + 1];
		}

		noOfMusicAlbums--;
		return true;
	}

	return false;
}

int MAC::getMusicAlbums(MusicAlbum *& allMusicAlbums) {

	allMusicAlbums = musicAlbums;
	return noOfMusicAlbums;
}

bool MAC::addSong(const string maArtist, const string maTitle, const string sName, const int sMins, const int sSecs) {
	
	for (int i = 0; i < noOfMusicAlbums; i++) {
		if (musicAlbums[i].getMusicAlbumArtist() == maArtist && musicAlbums[i].getMusicAlbumTitle() == maTitle) {
			return musicAlbums[i].addSong(sName, sMins, sSecs);
		}
	}
	
	return false;
}

bool MAC::removeSongs(const string maArtist, const string maTitle) {
	
	for (int i = 0; i < noOfMusicAlbums; i++) {
		if (musicAlbums[i].getMusicAlbumArtist() == maArtist && musicAlbums[i].getMusicAlbumTitle() == maTitle) {
			return musicAlbums[i].removeSongs();
		}
	}
	
	return false;
}

void MAC::calculateAvgMusicAlbumLength(int &minutes, int &seconds) {

	int tSecs = 0;
	for (int i = 0; i < noOfMusicAlbums; i++) {
		
		int min, sec;
		musicAlbums[i].calculateMusicAlbumLength(min, sec);
		tSecs += sec;
		tSecs += 60 * min;

	}

	tSecs /= noOfMusicAlbums;
	minutes = tSecs / 60;
	seconds = tSecs % 60;

}

void MAC::resizeArray() {

	MusicAlbum *resized = new MusicAlbum[arrSize * 2];
	for (int i = 0; i < arrSize; i++) {
		resized[i] = musicAlbums[i];
	}

	delete[] musicAlbums;
	musicAlbums = resized;

	arrSize *= 2;

}
