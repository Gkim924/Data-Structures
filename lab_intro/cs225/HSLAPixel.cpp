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

	//Trying to send this from my pc through git to ews!

HSLAPixel::HSLAPixel(){
		h = 360;					
		s = 100;
		l = 100;
		a = 1.0;
	} 

	HSLAPixel::HSLAPixel(double hue, saturation, luminance){
		h = hue;
		s = saturation;
		l = luminance;
		a = 1.0;
	} 

	HSLAPixel::HSLAPixel(hue, saturation, luminance, alpha){
		h = hue;
		s = saturation;
		l = luminance;
		a = alpha;
	} 
}
