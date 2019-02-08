#include "StickerSheet.h"

namespace cs225 {

//constructors and destructor
	StickerSheet::StickerSheet(const Image & picture, unsigned max){

		//takes in image ref and an integer
		basePic_ = new Image(picture);
		
		//create a vector for storing the image pointers
		std::vector<Image*> * stickerList = new std::vector<Image*>();
		listPtr_ = stickerList;
		
		//create a vector for storing (x,y) coordinates
		std::vector<double> * coordList = new std::vector<double>();
		coordPtr_ = coordList;   

		
		maxStickers_ = max;
		stickerAmount_ = 0;
		index_ = 0;

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
		Image * stkPtr = &sticker;

		std::cout << "adding sticker ptr to vector" << std::endl;
		std::cout << "size of vector: " << listPtr_->size() << std::endl;
		listPtr_->push_back(stkPtr);
		std::cout << "size of vector: " << listPtr_->size() << std::endl;
		std::cout << "content of vector: " << listPtr_->at(0) << std::endl;

		//push coordinates to coordList
		std::cout << "adding coordinates to vector" << std::endl;
		std::cout << "size of vector: " << coordPtr_->size() << std::endl;
		//add x then y
		coordPtr_->push_back(x);
		coordPtr_->push_back(y);
		std::cout << "size of vector: " << coordPtr_->size() << std::endl;
		std::cout << "content of vector: " << coordPtr_->at(0) << std::endl;
		std::cout << "content of vector: " << coordPtr_->at(1) << std::endl;

		//update counters and indexes

		return 5;
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

		//needs implementation
		basePic_->writeToFile("stickerTest.png");
		Image * test = new Image();
		return *test;
	} 

	//additional functions
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