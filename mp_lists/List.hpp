/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;

    length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  

  return List<T>::ListIterator(head_);
  //return List<T>::ListIterator(NULL);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1

  return List<T>::ListIterator(NULL);
  //return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  ListNode * curr = head_;
  ListNode * temp;

  head_= NULL;
  tail_ = NULL;
  
  while(curr!=NULL){
    temp = curr;
    curr = curr->next;
    
    delete temp;
    
  }
  
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  //ListNode * temp;

  //std::cout << "node added from front: " << std::endl;
  
  //case 1: list is empty
  if (length_==0) {
    head_ = newNode;
    tail_ = newNode;
    length_++;
    return;
    }

  //case 2: list not empty
  // temp = head_;
  // head_ = newNode;
  // head_->next = temp;
  // temp->prev = head_;


  newNode->next = head_;
  head_->prev = newNode;
  head_ = newNode;
  
  //***Given code
  // newNode -> next = head_;
  // newNode -> prev = NULL;
  
  // if (head_ != NULL) {
  //   head_ -> prev = newNode;
  // }
  // if (tail_ == NULL) {
  //   tail_ = newNode;
  // }
  

  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  ListNode * temp;

  //case 1: list is empty
  if (length_==0) {
    head_ = newNode;
    tail_ = newNode;
    length_++;
    return;
  }

  //case 2: list not empty
  temp = tail_;
  tail_ = newNode;
  tail_->prev = temp;
  temp->next = tail_;

  length_++;

}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  ListNode * curr = start;

  ListNode * temp;

  if(start==NULL){
    return NULL;
  }
  if(splitPoint==0){
    return start;
  }

  for (int i = 0; i < splitPoint && curr != NULL; i++) {
    curr = curr->next;
  }

  if (curr != NULL) {
      curr->prev->next = NULL;
      curr->prev = NULL;
  }

  // if (curr != NULL) {
  //     temp = curr->next;
  //     curr->next = NULL;
  //     // this->tail_ = curr;
  //     temp->prev = NULL;
  //     return temp;
  // }

  return curr;
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
  int count = this->size();

  //std::cout << "waterfall size: " << count << std::endl;

  //move to node at index 1
  ListNode * curr = head_->next;
  ListNode * temp;
  ListNode * next;
  ListNode * prev;

  //iterate through all indices until tail
  for(int i=1;i<count-1;i++){
    //swap
    //move current over to next even index
    prev = curr->prev;
    next = curr->next;
    //use temp to do the move
    temp = curr;
    curr = curr->next->next;
    prev->next = next;
    next->prev = prev;
    temp->prev = tail_;
    temp->next = NULL;
    tail_->next = temp;
    this->tail_ = temp;
    
  }

}

/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2

  //calcuate how many nodes should be reversed
  ListNode * begin = endPoint;
  ListNode * end = startPoint;
  ListNode * curr = begin;
  ListNode * temp = begin;
  ListNode * swap;

  //reassign head and tail in case of full reversal
  if(startPoint==this->head_ && endPoint==this->tail_){
    for(int i=0;i<this->size()-2;i++){
    swap = begin->prev;
    begin->prev = swap->prev;
    swap->prev->next = begin;
    swap->prev = curr;
    curr->next = swap;
    swap->next = NULL;
    curr = swap;
    }

  swap = begin->prev;
  begin->prev = NULL;
  swap->next = NULL;
  swap->prev = curr;
  curr->next = swap;

  this->head_ = begin;
  this->tail_ = swap;

  return;
  }

  //for reverse Nth
  //calculate range
  int range = 1;
  ListNode * count = startPoint;
  while(count!=endPoint){
    count = count->next;
    range++;
  }


  if(endPoint==this->tail_){
    // std::cout << "reversetail section!" << std::endl;
    // std::cout << "head: " << this->head_->data << std::endl;
    // std::cout << "tail: " << this->tail_->data << std::endl;
    // std::cout << "startPt: " << startPoint->data << std::endl;
    // std::cout << "endPt: " << endPoint->data << std::endl;
    // ListNode * pos = this->head_;
    // while(pos!=NULL){
    //   std::cout << pos->data << "/";
    //   pos = pos->next;
    // }
    // std::cout << std::endl;
    for(int i=0;i<range-1;i++){
      swap = begin->prev;
      curr = swap->prev;
      begin->prev = curr;
      curr->next = begin;
      temp->next = swap;
      swap->prev = temp;
      swap->next = NULL;
      curr = curr->prev;
      temp = swap;
      swap = begin->prev;
    }
    //last swap
    // begin->prev = curr;
    // curr->next = begin;
    // temp->next = swap;
    // swap->prev = temp;
    // swap->next = NULL;


    //go in both directions to find new head and tail using temp and swap
    while(curr->prev!=NULL){
      
      curr = curr->prev;
    }
    while(begin->next!=NULL){

      begin = begin->next;
    }
    this->head_ = curr;
    this->tail_ = temp;
    //std::cout << "tail: " << this->tail_->data << std::endl;
    
    return;
  }

  //std::cout << "Block reverse" << std::endl;
  for(int i=0;i<range-1;i++){
    swap = begin->prev;
    //reverse around the tail
    // if(temp==this->tail_){
    //   curr = swap->prev;
    //   curr->next = begin;
    //   begin->prev = curr;
    //   begin->next = swap;
    //   swap->prev = begin;
    //   swap->next = NULL;
    //   break;
    // }
    curr = temp->next;
    if(swap==this->head_){
      begin->prev = NULL;
      swap->prev = temp;
      temp->next = swap;
      swap->next = curr;
      curr->prev = swap;
      break;
    }
    begin->prev = swap->prev;
    swap->prev->next = begin;

    temp->next = swap;
    swap->prev = temp;
    swap->next = curr;
    curr->prev = swap;
    temp = swap;
    }

  //go in both directions to find new head and tail using temp and swap
  while(temp->prev!=NULL){
    temp = temp->prev;
  }
  while(begin->next!=NULL){
    begin = begin->next;
  }
  this->head_ = temp;
  this->tail_ = begin;


  // for(int i=0;i<range-1;i++){
  //   swap = begin->prev;
  //   //reverse around the tail
  //   if(temp==this->tail_){
  //     curr = swap->prev;
  //     curr->next = begin;
  //     begin->prev = curr;
  //     begin->next = swap;
  //     swap->prev = begin;
  //     swap->next = NULL;
  //     break;
  //   }
  //   curr = temp->next;
  //   if(swap==this->head_){
  //     begin->prev = NULL;
  //     swap->prev = temp;
  //     temp->next = swap;
  //     swap->next = curr;
  //     curr->prev = swap;
  //     break;
  //   }
  //   begin->prev = swap->prev;
  //   swap->prev->next = begin;

  //   temp->next = swap;
  //   swap->prev = temp;
  //   swap->next = curr;
  //   curr->prev = swap;
  //   temp = swap;
  //   }


}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
    ListNode * startPt = this->head_;
    ListNode * endPt = this->head_;
    
    //std::cout << "reverseNth(" << n << ")" << std::endl;
    int count = this->size() / n;
    int remain = this->size() % n;
    //std::cout << "blocks of (" << n << "): " << count << std::endl;

    //get startPt and endPt
    for(int i=0;i<count;i++){
      
      for(int j=0;j<n-1;j++){
        endPt = endPt->next;
      }
      //save start and end point and move
      //std::cout << "startPt: " << startPt->data << std::endl;
      //std::cout << "endPt: " << endPt->data << std::endl;
      reverse(startPt,endPt);
      startPt = startPt->next;
      endPt = startPt;
    }
    //reverse remaining entries
    // if(remain>=0){
    // for(int k=0;k<remain;k++){
    //   endPt = endPt->next;
    // }
    // reverse(startPt,endPt);
    // }
    if(remain == 1){
      return;
    }
    if(remain>0){
    while(endPt->next!=NULL){
      endPt = endPt->next;
    }
    // std::cout << "raminRev" << std::endl;
    // std::cout << "startPt: " << startPt->data << std::endl;
    // std::cout << "endPt: " << endPt->data << std::endl;
    // std::cout << "tail: " << this->tail_->data << std::endl;

    reverse(startPt,endPt);
    }
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  ListNode * main = first;
  ListNode * insert = second;
  

  //merge into list with lower starting value - can add to the right
  if(first->data<second->data){
    //std::cout << "mering into first" << std::endl;
    main = first;
    insert = second;
  }
  else {
    //std::cout << "merging into second" << std::endl;
    main = second;
    insert = first;
  }


  ListNode * swap;
  ListNode * mainCurr;
  //iterate over both lists
  while(insert!=NULL){

    if(insert->data==main->data && main->prev==NULL){ //insert on right
      swap = insert;
      insert = insert->next;
      if(insert!=NULL){
        insert->prev = NULL;
      }
      mainCurr = main->next;
      main->next = swap;
      swap->prev = main;
      swap->next = mainCurr;
      mainCurr->prev = swap;
      main = swap;
      if(insert==NULL){
        while(swap->prev!=NULL){
        swap = swap->prev;
      }
      return swap;
      }
    }

    if(insert->data<main->data){  //insert on the left
      swap = insert;
      mainCurr = main->prev;
      insert = insert->next;
      if(insert!=NULL){
      insert->prev = NULL;
      }
      swap->prev = mainCurr;
      mainCurr->next = swap;
      main->prev = swap;
      swap->next = main;
      main = swap;
    }
    swap = main;
    main = main->next;
    if(main==NULL){ // rest of numbers in insert are greater just add rest of list
      //main = swap->next;
      main = swap;
      main->next = insert;
      insert->prev = main;
      //return to head 
      while(swap->prev!=NULL){
        swap = swap->prev;
      }
      return swap;
    }

  }


  while(swap->prev!=NULL){
        swap = swap->prev;
      }
  return swap;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  ListNode * orig;
  ListNode * split;

  if(chainLength==1){
    return start;
  }
  split = List<T>::split(start,chainLength/2);
  orig = start; 
  split = mergesort(split,(chainLength-(chainLength/2)));
  orig = mergesort(orig,(chainLength/2));


  return merge(orig,split);
}
