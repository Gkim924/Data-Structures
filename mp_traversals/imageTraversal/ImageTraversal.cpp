#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 * 
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );    
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
}

//custom ctor
ImageTraversal::Iterator::Iterator(const PNG & png, const Point & start, double tolerance,ImageTraversal * type) {
  /** @todo [Part 1] */

    tolerance_ = tolerance;
    currPt_ = start;
    startPt_ = start;
    origImage_ = png;
    traversal_ = type;
    finished_ = false;
    
    //create vector of true false to represent if the coordinates have been visited
    for(int i=0;i<(int)(png.height()*png.width());i++){
      visited_.push_back(false);
    }
  
}


/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  
  //Possible next points
  int x = (int)currPt_.x;
  int y = (int)currPt_.y;

  if(finished_==true){
    return *this;
  }

  //get pixel to the right
  if(x+1<(int)origImage_.width()){
    Point pR = Point(currPt_.x+1,currPt_.y);
      if(!checkVisited(pR) && checkTolerance(currPt_, pR)){
        traversal_->add(pR);
    }
  }
  
  //get pixel below
  if(y+1<(int)origImage_.height()){
    Point pB = Point(currPt_.x,currPt_.y+1);
      if(!checkVisited(pB) && checkTolerance(currPt_, pB)){
        traversal_->add(pB);
    }
  }
  
  //get pixel to the left
  if(x-1>=0){
    Point pL = Point(currPt_.x-1,currPt_.y);
      if(!checkVisited(pL) && checkTolerance(currPt_, pL)){
        traversal_->add(pL);
    }
  }
  
  //get pixel above
  if(y-1>=0){
    Point pA = Point(currPt_.x,currPt_.y-1);
      if(!checkVisited(pA) && checkTolerance(currPt_, pA)){
        traversal_->add(pA);
    }
  }
  
  if(traversal_->empty()){
    finished_ = true;
    return *this;
  }

  //update visited vector
  visited_[currPt_.x + currPt_.y * (int)origImage_.width()] = true;
  Point temp;
  while(!traversal_->empty()){
    temp = traversal_->peek();
    if(!checkVisited(temp)){
      currPt_ = traversal_->peek();
      //currPt_ = traversal_->pop();
      break;
    }
    traversal_->pop();
  }

  if(traversal_->empty()){
    finished_ = true;
    return *this;
  }

  return *this;
}

/**
 * Iterator accessor opreator.
 * 
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */

  return currPt_;
}

/**
 * Iterator inequality operator.
 * 
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */

  // if(this->currPt_==other.currPt_){
  //   return false;
  // }

  if(this->finished_==other.finished_){
    return false;
  }

  else return true;

}


//helper functions I wrote
bool ImageTraversal::Iterator::checkVisited(Point & point){

  //x + (y*width)
  if(visited_[point.x + point.y * (int)origImage_.width()]==true){
    return true;
  }

  else return false;
}


bool ImageTraversal::Iterator::checkTolerance(Point & currPt, Point & newPt){

  HSLAPixel curr = origImage_.getPixel(currPt.x, currPt.y); 
  HSLAPixel next = origImage_.getPixel(newPt.x, newPt.y); 

  double delta = calculateDelta(curr,next);

  if(delta<tolerance_){
    return true;
  }

  else return false;
}

