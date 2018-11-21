#ifndef __SIMPLE_MAC_H
#define __SIMPLE_MAC_H

#include "SimpleMusicAlbum.h"

class MAC {
public:
	MAC();
	~MAC();
	MAC(const MAC &macToCopy);

	void operator=(const MAC &right);

	bool addMusicAlbum(const string maArtist, const string maTitle, const int maYear);
	bool removeMusicAlbum(const string maArtist, const string maTitle);

	int getMusicAlbums(MusicAlbum *&allMusicAlbums);
	int getArrSize();
	
private:
	MusicAlbum *musicAlbums;
	int noOfAlbums;

	void resizeArray();
	int arrSize;

};

#endif