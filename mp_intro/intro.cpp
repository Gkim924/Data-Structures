#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <math.h>
#include <cmath>

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


  	//h: 0-360	s: 0-1	l: 0-1 a: 0-1

  	cs225::HSLAPixel *myPixel = new cs225::HSLAPixel(247,0.23,0.5,0.5);

  	for(unsigned x = 0; x < 800; x++ ) {
		for(unsigned y = 0; y < 800; y++ ) {

		double centerX = 20.0;
		double centerY = 20.0;
	   	double distanceX = ((double (centerX)) - x);
       	double distanceY = ((double (centerY)) - y);
       	double totalDistance = (std::sqrt ((distanceX * distanceX) + (distanceY * distanceY)));

		cs225::HSLAPixel & inPixel = png.getPixel(x, y);
  		inPixel = *myPixel;

  		double scaleFactor = 0;

  		scaleFactor = (1 - ((totalDistance * (0.5))/100));
  		inPixel.h *= scaleFactor; //changes the pixel
        inPixel.l *= scaleFactor; 
        inPixel.a *= scaleFactor;
  		
  		
  		}
	}

	

  return png;
}
