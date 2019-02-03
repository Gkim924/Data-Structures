#include "Image.h"

namespace cs225 {

void Image::lighten(){
for (unsigned x = 0; x < this->width(); x++) {
    	for (unsigned y = 0; y < this->height(); y++) {
      		HSLAPixel & pixel = this->getPixel(x, y);
      			if(pixel.l <= 1) {
      				pixel.l += 0.1;
      				if(pixel.l > 1){
      					pixel.l = 1;
      				}
      			}
		}
	}
}
void Image::lighten(double amount){
	for (unsigned x = 0; x < this->width(); x++) {
    	for (unsigned y = 0; y < this->height(); y++) {
      		HSLAPixel & pixel = this->getPixel(x, y);
      			if(pixel.l <= 1) {
      				pixel.l += amount;
      				if(pixel.l > 1){
      					pixel.l = 1;
      				}
      			}
		}
	}
	
}
void Image::darken(){
	
}
void Image::darken(double amount){
	
}
void Image::saturate(){
	
}
void Image::saturate(double amount){
	
}
void Image::desaturate(){
	
}
void Image::desaturate(double amount){
	
}
void Image::grayscale(){
	for (unsigned x = 0; x < this->width(); x++) {
    	for (unsigned y = 0; y < this->height(); y++) {
      		HSLAPixel & pixel = this->getPixel(x, y);
				pixel.s = 0;
		}
	}
}
void Image::rotateColor(double degrees){
	
}
void Image::illinify(){
	
}
void Image::scale(double factor){
	
}
void Image::scale(unsigned w, unsigned h){
	
}

}