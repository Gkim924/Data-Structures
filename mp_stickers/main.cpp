#include "Image.h"
#include "StickerSheet.h"

using std::cout;
using std::endl;
using namespace cs225;

int main() {

	//cs225::PNG png, png2, result;
	Image firstPic;
	

	//cout << "width: " << firstPic.width() << " height: " << firstPic.height() << endl;
	//cout << "width: " << secondPic.width() << " height: " << secondPic.height() << endl;

  	firstPic.readFromFile("alma.png");
  	
  	//cout << "width: " << firstPic.width() << " height: " << firstPic.height() << endl;
  	//firstPic.rotateColor(-180);

  	//firstPic.writeToFile("myImage.png");

  	//firstPic.scale(450,300);
  	firstPic.scale(.3);
  	firstPic.writeToFile("otherImage.png");

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  return 0;
}

