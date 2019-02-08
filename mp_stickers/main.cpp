#include "Image.h"
#include "StickerSheet.h"
#include <vector>

using std::cout;
using std::endl;
using namespace cs225;

int main() {


 	Image firstPic;
	
	firstPic.readFromFile("alma.png");

	StickerSheet firstSticker(firstPic,5);

	//cout << &firstSticker << endl;

	Image sticker;

	sticker.readFromFile("i - Copy.png");

	cout << "addr of sticker: " << &sticker << endl;

	firstSticker.addSticker(sticker,7,12);

	sticker.writeToFile("stickercopytest.png");



















	// double x = 1.223;
	// double y = 2.344;

	// std::vector<double> coordVector;

	// coordVector.push_back(x);
	// coordVector.push_back(y);

	// cout << &coordVector << endl;

	// std::vector<double> * coordPtr = &coordVector;
	// cout << coordPtr << endl;

	// cout << coordPtr->at(0) << endl;
	// cout << coordPtr->at(1) << endl;


	// Image firstPic;

	// Image * imgPtr = &firstPic;

	// std::vector<Image*> * imagePtr2 = new std::vector<Image*>();

	// imagePtr2->push_back(imgPtr);

	// cout << "addr of firstPic: " << &firstPic << endl;
	// cout << "addr of imagePtr2: " << imagePtr2 << endl;
	// cout << "imagePtr2[0]: " << imagePtr2->at(0) << endl;

	// std::vector<Image*> * imagePtr3;
	// imagePtr3 = imagePtr2;



	//cs225::PNG png, png2, result;
	//Image firstPic;
	
	//firstPic.readFromFile("alma.png");

	//StickerSheet firstSticker(firstPic,5);

	//Image testPic;
	//testPic = firstSticker.render();
	//testPic.writeToFile("returnImage.png");

	
	//std::vector<Image*>second;
	//cout << "addr of vector: " << &first << endl;

	// int in = 3455;
	// Image * in1 = &firstPic;
	// cout << "addr of firstPic: " << in1 << endl;
	// cout << "addr of firstPic: " << &firstPic << endl;

	// first.push_back(in);
	// second.push_back(in1);

	// cout << "second pop: " << &(second.back()) << endl;


  	//cout << "width: " << firstPic.width() << " height: " << firstPic.height() << endl;
	//cout << "width: " << secondPic.width() << " height: " << secondPic.height() << endl;
  	
  	//cout << "width: " << firstPic.width() << " height: " << firstPic.height() << endl;
  	//firstPic.rotateColor(-180);

  	//firstPic.writeToFile("myImage.png");

  	//firstPic.scale(450,300);
  	//firstPic.scale(.3);
  	//firstPic.writeToFile("otherImage.png");

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  return 0;
}

