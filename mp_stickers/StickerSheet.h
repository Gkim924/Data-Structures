/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include <iostream>
#include "cs225/PNG.h"
#include "Image.h"
#include <cmath>
#include <vector>

namespace cs225 {

class StickerSheet {

public:
	
	//constructors and destructor
	StickerSheet(const Image & picture, unsigned max);
	~StickerSheet();
	StickerSheet(const StickerSheet & other);

	//assignment overload operator
	const StickerSheet & operator=(const StickerSheet & other);

	//functions
	void changeMaxStickers(unsigned max);
	int addSticker(Image & sticker, unsigned x, unsigned y);
	bool translate(unsigned index, unsigned x, unsigned y);
	void removeSticker(unsigned index);
	Image * getSticker(unsigned index);
	Image render() const;

	//additional functions
	void _delete();
	void _copy(const StickerSheet & other);

private:

	//pointer to base picture
	Image* basePic_;
	std::vector<Image*> * listPtr_;
	std::vector<double> * coordPtr_;
	int index_;
	int maxStickers_;
	int stickerAmount_;
	//pointer to array of pointers for stickers





	};
}