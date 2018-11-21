#include "SimpleMAC.h"

#include <iostream>
using namespace std;

MAC::MAC() {
	arrSize = 10;
	musicAlbums = new MusicAlbum[arrSize];
}


MAC::~MAC() {
	delete[] musicAlbums;
}

MAC::MAC(const MAC &macToCopy) {

	noOfAlbums = macToCopy.noOfAlbums;
	arrSize = macToCopy.arrSize;

	MusicAlbum *orr = macToCopy.musicAlbums;
	musicAlbums = new MusicAlbum[arrSize];

	// Deep copy
	for (int i = 0; i < arrSize; i++) {
		musicAlbums[i] = orr[i];
	}
}

void MAC::operator=(const MAC &right) {

	noOfAlbums = right.noOfAlbums;
	arrSize = right.arrSize;
	
	MusicAlbum *orr = right.musicAlbums;

	delete[] musicAlbums;
	musicAlbums = new MusicAlbum[arrSize];

	// Deep copy
	for (int i = 0; i < noOfAlbums; i++) {
		musicAlbums[i] = orr[i];
	}

}

bool MAC::addMusicAlbum(const string maArtist, const string maTitle, const int maYear) {

	for (int i = 0; i < noOfAlbums; i++) {
		if (musicAlbums[i].getMusicAlbumArtist() == maArtist &&
			musicAlbums[i].getMusicAlbumTitle() == maTitle &&
			musicAlbums[i].getMusicAlbumYear() == maYear)
			return false;
	}

	MusicAlbum album(maArtist, maTitle, maYear);
	if (noOfAlbums == arrSize)
		resizeArray();

	musicAlbums[noOfAlbums] = album;
	noOfAlbums++;

	return true;
}

bool MAC::removeMusicAlbum(const string maArtist, const string maTitle) {
	
	int cont = -1;
	for (int i = 0; i < noOfAlbums; i++) {
		if (musicAlbums[i].getMusicAlbumArtist() == maArtist &&
			musicAlbums[i].getMusicAlbumTitle() == maTitle) {
			cont = i;
			break;
		}
	}

	if (cont != -1) {
		for (int i = cont; i < noOfAlbums; i++) {
			musicAlbums[i] = musicAlbums[i + 1];
		}

		noOfAlbums--;
		return true;
	}
	
	return false;
}

int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums) {
	
	allMusicAlbums = musicAlbums;
	return noOfAlbums;
}

int MAC::getArrSize() {
	return arrSize;
}

void MAC::resizeArray() {

	MusicAlbum *resized = new MusicAlbum[arrSize * 2];
	for (int i = 0; i < arrSize; i++) {
		resized[i] = musicAlbums[i];
	}
	
	delete[] musicAlbums;
	musicAlbums = resized;
}

