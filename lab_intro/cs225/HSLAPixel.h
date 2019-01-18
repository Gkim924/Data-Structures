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

	class HSLApixel {

	public: 									 

		HSLApixel();
		HSLApixel(double hue, double saturation, double luminance);
		HSLApixel(double hue, double saturation, double luminance, double alpha);

		double h_; // [0,360]
		double s_; // [0,1]
		double l_; // [0,1]
		double a_; // [0,1]
	};
}
