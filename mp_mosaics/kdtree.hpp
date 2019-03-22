/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */

    if(first[curDim]<second[curDim]){
      return true;
    }
    if(first[curDim]==second[curDim]){
      return first<second;
    }

    else return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */

    //check distance between target and potential
    double d1 = pow(target[0]-potential[0],2)+pow(target[1]-potential[1],2)+pow(target[2]-potential[2],2);

    //check distance between target and currentBest
    double d2 = pow(target[0]-currentBest[0],2)+pow(target[1]-currentBest[1],2)+pow(target[2]-currentBest[2],2);

    if(d1<d2){ //potential is closer to target
      return true;
    }
    if(d1==d2){
      return potential<currentBest;
    }

    else return false;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */

  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

    return Point<Dim>();
}

