#include "Image.h"
#include "StickerSheet.h"
#include <vector>
#include <deque>

using std::cout;
using std::endl;
using namespace cs225;

int main() {


 	Image firstPic;

 	//639x550
 	firstPic.readFromFile("drakeMemeTemplate.png");

 	Image text1, text2, face, logo;

 	//664X192
 	text1.readFromFile("memeText1.png");
 	//645X191
 	text2.readFromFile("memeText2.png");
 	//429x626
 	face.readFromFile("memeFace.png");
 	//667x668
 	logo.readFromFile("CppLogo.png");

 	//text1.scale(100,100);
 	//text2.scale(100,100);
 	face.scale(1.2);
 	//logo.scale(.3);

 	StickerSheet memeSticker(firstPic,5);

 	memeSticker.addSticker(text1,350,110);
 	memeSticker.addSticker(text2,350,300);
 	memeSticker.addSticker(face,150,280);
 	memeSticker.addSticker(logo,390,360);

 	firstPic = memeSticker.render();

 	firstPic.writeToFile("myImage.png");





// Image firstPic, secondPic;
	
// 	firstPic.readFromFile("alma.png");

// 	StickerSheet firstStickerSheet(firstPic,5);

// 	Image sticker1;
// 	Image sticker2;
// 	Image sticker3;

// 	sticker1.readFromFile("i - Copy1.png");
// 	sticker2.readFromFile("i - Copy2.png");
// 	sticker3.readFromFile("i - Copy3.png");

// 	cout << firstStickerSheet.addSticker(sticker1,700,400) << endl;
// 	cout << firstStickerSheet.addSticker(sticker2,300,200) << endl;
// 	cout << firstStickerSheet.addSticker(sticker3,10,10) << endl;
	
// 	firstPic = firstStickerSheet.render();
// 	firstPic.writeToFile("rendertest.png");

// 	secondPic = firstPic;
// 	secondPic.writeToFile("assign overload test.png");


	// firstPic = firstStickerSheet.render();

	// firstPic.writeToFile("rendertest.png");

	// firstStickerSheet.removeSticker(1);

	// secondPic = firstStickerSheet.render();

	// secondPic.writeToFile("rendertestAfterRemove2.png");

	// firstStickerSheet.translate(1,100,100);

	// secondPic = firstStickerSheet.render();

	// secondPic.writeToFile("rendertestAfterTranslate.png");

	// StickerSheet secondStickerSheet(firstStickerSheet);

	// secondPic = secondStickerSheet.render();

	// secondPic.writeToFile("rendertestAfterTranslateCCTOR.png");



  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  return 0;
}

