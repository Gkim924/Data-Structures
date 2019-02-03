#include "Image.h"
#include "StickerSheet.h"

using std::cout;
using std::endl;
using namespace cs225;

int main() {

	//cs225::PNG png, png2, result;
	Image firstPic;
	PNG secondPic(450,300);

	//cout << "width: " << firstPic.width() << " height: " << firstPic.height() << endl;
	cout << "width: " << secondPic.width() << " height: " << secondPic.height() << endl;

  	firstPic.readFromFile("alma.png");
  	
  	//cout << "width: " << firstPic.width() << " height: " << firstPic.height() << endl;
  	firstPic.illinify();

  	firstPic.writeToFile("myImage.png");
  	secondPic.writeToFile("otherImage.png");

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  return 0;
}

