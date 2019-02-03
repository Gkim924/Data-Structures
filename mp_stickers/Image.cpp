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
	for (unsigned x = 0; x < this->width(); x++) {
    	for (unsigned y = 0; y < this->height(); y++) {
      		HSLAPixel & pixel = this->getPixel(x, y);
      			if(pixel.l >= 0) {
      				pixel.l -= 0.1;
      				if(pixel.l < 0){
      					pixel.l = 0;
      				}
      			}
		}
	}
}
void Image::darken(double amount){
	for (unsigned x = 0; x < this->width(); x++) {
    	for (unsigned y = 0; y < this->height(); y++) {
      		HSLAPixel & pixel = this->getPixel(x, y);
      			if(pixel.l >= 0) {
      				pixel.l -= amount;
      				if(pixel.l < 0){
      					pixel.l = 0;
      				}
      			}
		}
	}
}
void Image::saturate(){
for (unsigned x = 0; x < this->width(); x++) {
    	for (unsigned y = 0; y < this->height(); y++) {
      		HSLAPixel & pixel = this->getPixel(x, y);
      			if(pixel.s <= 1) {
      				pixel.s += 0.1;
      				if(pixel.s > 1){
      					pixel.s = 1;
      				}
      			}
		}
	}	
}
void Image::saturate(double amount){
	for (unsigned x = 0; x < this->width(); x++) {
    	for (unsigned y = 0; y < this->height(); y++) {
      		HSLAPixel & pixel = this->getPixel(x, y);
      			if(pixel.s <= 1) {
      				pixel.s += amount;
      				if(pixel.s > 1){
      					pixel.s = 1;
      				}
      			}
		}
	}
}
void Image::desaturate(){
for (unsigned x = 0; x < this->width(); x++) {
    	for (unsigned y = 0; y < this->height(); y++) {
      		HSLAPixel & pixel = this->getPixel(x, y);
      			if(pixel.s >= 0) {
      				pixel.s -= 0.1;
      				if(pixel.s < 0){
      					pixel.s = 0;
      				}
      			}
		}
	}	
}
void Image::desaturate(double amount){
	for (unsigned x = 0; x < this->width(); x++) {
    	for (unsigned y = 0; y < this->height(); y++) {
      		HSLAPixel & pixel = this->getPixel(x, y);
      			if(pixel.s >= 0) {
      				pixel.s -= amount;
      				if(pixel.s < 0){
      					pixel.s = 0;
      				}
      			}
		}
	}
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
	double orange = 11.0;
  	double blue = 216.0;

  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      
      HSLAPixel & pixel = this->getPixel(x, y);
      
    
        if((std::abs (pixel.h - orange)) <= (std::abs (pixel.h - blue))){ 
          pixel.h = 11.0;
        } 
        else if((371 - pixel.h) <= (std::abs (pixel.h - blue))){
          pixel.h = 11.0;
        }
        else {
          pixel.h = 216.0;
        }
      }
  }
  
  //orange 11
  //blue 216
}
void Image::scale(double factor){
	
}
void Image::scale(unsigned w, unsigned h){
	
}

}