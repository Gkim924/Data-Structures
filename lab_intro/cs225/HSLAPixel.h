/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#pragma once

#include <iostream>
#include <sstream>

namespace cs225 {

	//trying to send this from my pc though git to ews **sucess now sending back to pc

	class HSLAPixel {

	public: 									 

		HSLAPixel();
		HSLAPixel(double hue, double saturation, double luminance);
		HSLAPixel(double hue, double saturation, double luminance, double alpha);

		double h; // [0,360]
		double s; // [0,1]
		double l; // [0,1]
		double a; // [0,1]
	};
}
