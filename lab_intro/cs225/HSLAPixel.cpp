/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace cs225 {

HSLAPixel::HSLAPixel(){
		h_ = 360;					
		s_ = 100;
		l_ = 100;
		a_ = 1.0;
	} 

	HSLAPixel::HSLAPixel(hue, saturation, luminance){
		h_ = hue;
		s_ = saturation;
		l_ = luminance;
		a_ = 1.0;
	} 

	HSLAPixel::HSLAPixel(hue, saturation, luminance, alpha){
		h_ = hue;
		s_ = saturation;
		l_ = luminance;
		a_ = alpha;
	} 
}
