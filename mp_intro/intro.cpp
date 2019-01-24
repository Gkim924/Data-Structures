#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <math.h>

#include <string>



void rotate(std::string inputFile, std::string outputFile) {
  
	cs225::PNG* input = new cs225::PNG();
	input->readFromFile(inputFile);

	//using pointer because we need to place things inside the PNG

	unsigned int width = input->width();
	unsigned int height = input->height();

	cs225::PNG* output = new cs225::PNG(width, height);

	for(unsigned x = 0; x < width; x++ ) {
		for(unsigned y = 0; y < height; y++ ) {
			cs225::HSLAPixel & inPixel = input->getPixel(x, y);
			cs225::HSLAPixel & outPixel = output->getPixel((width - x) -1 ,(height - y) - 1);

			outPixel = inPixel; 
		}
	}

	output->writeToFile(outputFile);


}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3

  	for(unsigned x = 0; x < 800; x++ ) {
		for(unsigned y = 0; y < 800; y++ ) {

  		cs225::HSLAPixel & inPixel = png.getPixel(x, y);
  		inPixel.h = 222;
  		inPixel.s = 0.5;
  		inPixel.l = 0.5;
  		inPixel.a = 0.5;
  		}
	}
  		


 

  return png;
}
