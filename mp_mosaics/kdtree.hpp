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

    return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */

    double d1=0;
    double d2=0;
    for(int i=0;i<Dim;i++){
      //check distance between target and potential
      d1 += pow(target[i]-potential[i],2);
      //std::cout<<target[i]<<" "<<potential[i]<<" "<<currentBest[i]<<std::endl;
      //check distance between target and currentBest
      d2 += pow(target[i]-currentBest[i],2);
    }
    

    if(d1<d2){ //potential is closer to target
      //std::cout<<"something"<<std::endl;
      //std::cout<<"D1:"<<d1<<std::endl;
      //std::cout<<"D2:"<<d2<<std::endl;
      return true;
    }
    if(d1==d2){
      return potential<currentBest;
    }

    return false;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
  size = newPoints.size();
  //first copy all the newPoints into the new tree
  for (int i=0;i<(int)newPoints.size();i++){
    point_vector_.push_back(newPoints[i]);
  } 

  if(newPoints.empty()){
    root = new KDTreeNode();
    return;
  }

  root = _assemble(0,point_vector_.size()-1,0);

}

//helper function for recursively assembling the tree
template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::_assemble(int left, int right, int dim){

  if(left>right){
    return nullptr;
  }

  int mid_idx = (left+right)/2;
  _quickSelect(point_vector_,left,right,mid_idx,dim);

  KDTreeNode * temp = new KDTreeNode(point_vector_[mid_idx]);

  temp->left = _assemble(left,mid_idx-1,(dim+1)%Dim);
  temp->right = _assemble(mid_idx+1,right,(dim+1)%Dim);

  return temp;

}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
  size = other->size;

  root = new KDTreeNode();
  _copy(root, other->root);

}

//copy helper function
template <int Dim>
void KDTree<Dim>::_copy(KDTree<Dim>::KDTreeNode * subRoot1, KDTree<Dim>::KDTreeNode * subRoot2){

  subRoot1->point = subRoot2->point;
  if (subRoot2->left) {
    subRoot1->left= new KDTreeNode();
    _copy(subRoot1->left,subRoot2->left);
  }
  if (subRoot2->right) {
    subRoot1->right= new KDTreeNode();
    _copy(subRoot1->right,subRoot2->right);
  }

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
    _destroy(root);
    size = 0;
}

template <int Dim>
void KDTree<Dim>::_destroy(KDTree<Dim>::KDTreeNode * subRoot){

  if(!subRoot){
    return;
  }

  _destroy(subRoot->left);
  _destroy(subRoot->right);

  delete subRoot;
  subRoot = nullptr;

}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
  
    if(root){
      Point<Dim> origBest = root->point;
      return _findNearestNeighbor(root,query,origBest,0);
    }
    return query;
    
    //return Point<Dim>();
}

template <int Dim>
Point<Dim> KDTree<Dim>::_findNearestNeighbor(KDTree<Dim>::KDTreeNode * subRoot, Point<Dim> query,Point<Dim> currBest, int dim) const {

  if(!subRoot){
    return currBest;
  }


  if(smallerDimVal(subRoot->point,query,dim)){ //go right
    Point<Dim> temp = _findNearestNeighbor(subRoot->right,query,currBest,(dim+1)%Dim);
    if(shouldReplace(query,currBest,temp)){
      currBest = temp;
    }
  }

  else { //go left
    Point<Dim> temp = _findNearestNeighbor(subRoot->left,query,currBest,(dim+1)%Dim);
    if(shouldReplace(query,currBest,temp)){
      currBest = temp;
    }
  }

  if(shouldReplace(query,currBest,subRoot->point)){
    currBest = subRoot->point;
  }

  if(pow(subRoot->point[dim]-query[dim],2)<=pow(query[dim]-currBest[dim],2)){
     if(smallerDimVal(subRoot->point,query,dim)){ 
        Point<Dim> temp = _findNearestNeighbor(subRoot->left,query,currBest,(dim+1)%Dim);
          if(shouldReplace(query,currBest,temp)){
            currBest = temp;
          }
      }
      else { 
        Point<Dim> temp = _findNearestNeighbor(subRoot->right,query,currBest,(dim+1)%Dim);
          if(shouldReplace(query,currBest,temp)){
            currBest = temp;
      }
    }
  }
  return currBest;

}


//my additional helper functions
template <int Dim>
int KDTree<Dim>::_quickSelect(vector<Point<Dim>> &points, int left, int right, int mid, int dim){
  
    int index = _partition(points,left,right,dim);

    if(left>right){
      return 0;
    }

    if(index==mid){
      return index;
    }

    if(index>mid){
      return _quickSelect(points,left,index-1,mid,dim);
    }
    return _quickSelect(points, index + 1, right, mid - index + left - 1,dim);

}
 

template <int Dim>
int KDTree<Dim>::_partition(vector<Point<Dim>> &points, int left, int right, int dim){


  Point<Dim> x(points[right]);
  int i = left;
  int j;
  for(j=left;j<=right-1;j++){
    if(smallerDimVal(points[j],x,dim)){
      swap(points[i],points[j]);
      i++;
    }
  }
  swap(points[i],points[j]);
  return i;

}
