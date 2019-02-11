#include "StickerSheet.h"

namespace cs225 {

//constructors and destructor
	StickerSheet::StickerSheet(const Image & picture, unsigned max){

		//takes in image ref and an integer
		basePic_ = new Image(picture);
		originalPic_ = new Image(picture);

		std::deque<Image*> * stickerList = new std::deque<Image*>();
		listPtr_ = stickerList;

		std::deque<int> * coordList = new std::deque<int>();
		coordPtr_ = coordList;

		maxStickers_ = max;
		stickerCount_ = 0;


	}
	StickerSheet::~StickerSheet(){
		_delete();

	}
	StickerSheet::StickerSheet(const StickerSheet & other){
		//copy constructor
		_copy(other);
	}

	//assignment overload operator
	const StickerSheet & StickerSheet::operator=(const StickerSheet & other){

		if (this == &other) {
	       return *this;
      	} else {
      	_delete();

      	_copy(other);
      	return *this;
		}

	}

	//functions
	void StickerSheet::changeMaxStickers(unsigned max){
		maxStickers_ = max;

	}
	int StickerSheet::addSticker(Image & sticker, unsigned x, unsigned y){

		//check if sticker can be added
		stickerCount_++;
		if(stickerCount_>maxStickers_){
			return -1;
		}

		Image * stkPtr = &sticker;

		listPtr_->push_back(stkPtr);

		coordPtr_->push_back(x);
		coordPtr_->push_back(y);

		return (stickerCount_ - 1);
	}
	bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){

		if(index <=listPtr_->size()){
			coordPtr_->at(2*index) = x;
			coordPtr_->at(2*index+1) = y;

			return true;
		}
		else {
			return false;
		}


	}
	void StickerSheet::removeSticker(unsigned index){

		listPtr_->erase(listPtr_->begin()+index);

		//update coordinates
		coordPtr_->erase(coordPtr_->begin()+(index+1));
		coordPtr_->erase(coordPtr_->begin()+(index+1));

		stickerCount_--;

	}
	Image * StickerSheet::getSticker(unsigned index){

		if(index > 0 && index <=listPtr_->size()){
			Image * returnPtr;
			returnPtr = listPtr_->at(index);

			return returnPtr;
		} else {
			return NULL;
		}

	}
	Image StickerSheet::render() const {

		//need to clear base pic
		for (unsigned x = 0; x < originalPic_->width(); x++) {
    		for (unsigned y = 0; y < originalPic_->height(); y++) {

      				HSLAPixel & basePixel = basePic_->getPixel(x, y);
      				HSLAPixel & origPixel = originalPic_->getPixel(x, y);

      				basePixel.h = origPixel.h;
      				basePixel.s = origPixel.s;
      				basePixel.l = origPixel.l;
      				basePixel.a = origPixel.a;
      		}
      	}


		int limit = listPtr_->size();


		for(int i = 0; i<limit ;i++){

			printLayer(i);

		}

		return *basePic_;
	}

	//additional functions
	void StickerSheet::printLayer(int index) const{


		Image * vectorRef = listPtr_->at(index);

		int coordRefX = coordPtr_->at(2*index);

		int coordRefY = coordPtr_->at(2*index + 1);

		//resize base pic to accomodate stickers that go outside the edge
		int diffW = (vectorRef->width()) - (basePic_->width() - coordRefX);
		int diffH = (vectorRef->height()) - (basePic_->height() - coordRefY);

		if(diffW > 0 || diffH > 0){
			basePic_->resize(basePic_->width() + diffW, basePic_->height() + diffH);
		}

		for (unsigned x = 0; x < vectorRef->width(); x++) {
    		for (unsigned y = 0; y < vectorRef->height(); y++) {

      				if(x + coordRefX < vectorRef->width() +coordRefX && y + coordRefY < vectorRef->height() + coordRefY){
      				HSLAPixel & basePixel = basePic_->getPixel(x + coordRefX, y + coordRefY);
      				HSLAPixel & stickerPixel = vectorRef->getPixel(x, y);
      				if(stickerPixel.a != 0){
      				basePixel = stickerPixel;
      				}
      			}

      		}
      	}
	}


	void StickerSheet::_delete(){

		delete basePic_;
		basePic_ = NULL;
		delete listPtr_;
		listPtr_ = NULL;
		delete coordPtr_;
		coordPtr_ = NULL;
		delete originalPic_;
		originalPic_ = NULL;

	}
	void StickerSheet::_copy(const StickerSheet & other){

		basePic_ = new Image(*other.basePic_);
		originalPic_ = new Image(*other.originalPic_);

		listPtr_ = new std::deque<Image*>(*other.listPtr_);
		coordPtr_ = new std::deque<int>(*other.coordPtr_);

		maxStickers_ = other.maxStickers_;
		stickerCount_ = other.stickerCount_;

	}

}
