#include "StickerSheet.h"

namespace cs225 {

//constructors and destructor
	StickerSheet::StickerSheet(const Image & picture, unsigned max){

		//takes in image ref and an integer
		basePic_ = new Image(picture);
		
		//create a vector for storing the image pointers
		//std::vector<Image*> * stickerList = new std::vector<Image*>();
		std::deque<Image*> * stickerList = new std::deque<Image*>();
		listPtr_ = stickerList;
		
		//create a vector for storing (x,y) coordinates
		//std::vector<int> * coordList = new std::vector<int>();
		std::deque<int> * coordList = new std::deque<int>();
		coordPtr_ = coordList;   

		
		maxStickers_ = max;
		stickerCount_ = 0;
		

	}
	StickerSheet::~StickerSheet(){
		_delete();

	}
	StickerSheet::StickerSheet(const StickerSheet & other){

	}

	//assignment overload operator
	//const StickerSheet & StickerSheet::operator=(const StickerSheet & other){
	
	//}

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

		//std::cout << "adding sticker ptr to vector" << std::endl;
		//std::cout << "addr of sticker: " << stkPtr << std::endl;
		//listPtr_->push_back(stkPtr);
		listPtr_->push_back(stkPtr);
		//std::cout << "size of vector: " << listPtr_->size() << std::endl;
		//std::cout << "content of vector: " << listPtr_->at(0) << std::endl;
		//std::cout << "removing from vector: " << std::endl;
		//Image * vectorRef = listPtr_->back();
		//std::cout << vectorRef << std::endl;
		//push coordinates to coordList
		//std::cout << "adding coordinates to vector" << std::endl;
		//std::cout << "size of vector: " << coordPtr_->size() << std::endl;
		//add x then y
		coordPtr_->push_back(x);
		coordPtr_->push_back(y);
		//std::cout << "elements in coordPtr_: " << coordPtr_->size() << std::endl;
		//std::cout << "size of vector: " << coordPtr_->size() << std::endl;
		//std::cout << "content of vector: " << coordPtr_->at(0) << std::endl;
		//std::cout << "content of vector: " << coordPtr_->at(1) << std::endl;

		//update counters and indexes

		//return index of added sticker
		return (stickerCount_ - 1);
	}
	bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
		return true;
	}
	void StickerSheet::removeSticker(unsigned index){

	}
	Image * StickerSheet::getSticker(unsigned index){
		//needs implementation
		Image * test1 = new Image();
		return test1;
	}
	Image StickerSheet::render() const {

		while(listPtr_->size()>0){
			printLayer();
		}

		return *basePic_;
	} 

	//additional functions
	void StickerSheet::printLayer() const{

		// !!!! might have to change it so elements are not deleted but only accessed

		Image * vectorRef = listPtr_->front();
		listPtr_->pop_front();

		//getting coordinates
		int coordRefX = coordPtr_->front();
		//std::cout << "X coord: " << coordRefX << std::endl;
		coordPtr_->pop_front();
		int coordRefY = coordPtr_->front();
		//std::cout << "Y coord: " << coordRefY << std::endl;
		coordPtr_->pop_front();
		//std::cout << "elements in coordPtr_: " << coordPtr_->size() << std::endl;

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

	}
	void StickerSheet::_copy(const StickerSheet & other){

	}





}