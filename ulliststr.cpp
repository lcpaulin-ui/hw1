#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& newstr) {
  bool done = false; 
  // check if list is empty 
  if (head_ == NULL){
    head_ = new Item();
    tail_ = head_;
    done = true; 
  }

  // if there's no space to push back, have to alloc new item
  else if (tail_->last == ARRSIZE){
    Item* newNode = new Item(); 
    // change tail
    Item* temp = tail_;
    temp->next = newNode; 
    newNode->prev = tail_; 
    tail_ = newNode; 
    done = true; 
  }
  // now i have created a new node for the value
  // for both previous cases: push to the front of the list (index 0) 
  if (done){
    tail_->val[0] = newstr; 
    tail_->first = 0; 
    tail_->last = 1; 
    size_++; 
    return; 
  }
 

  // if i got here, then there's space on the list. 
  else{
    tail_->val[tail_->last] = newstr; 
    tail_->last++; 
    size_++; 
  }
  return; 
}

void ULListStr::push_front(const std::string& newstr) {
  bool done = false; 
  // check if list is empty 
  if (head_ == NULL){
    head_ = new Item();
    tail_ = head_;  
    done = true; 
  }

  // if there's no space to push front, have to alloc new item
  else if (head_->first == 0){
    Item* newNode = new Item(); 
    // change head
    //Item* temp = head_;
    head_->prev = newNode;
    newNode->next = head_;
    head_ = newNode; 
    done = true; 
  }
  // now i have created a new node for the value
  // for both previous cases: push to the BACK of the list (index arrsize-1) 
  if (done){
  head_->val[ARRSIZE-1] = newstr;
  head_->last = ARRSIZE;
  head_->first = ARRSIZE-1; 
  size_++;
  return; 
  }

  // if i got here, then there's space on the list AND first isnt 0 
  else {
    head_->first--;
    head_->val[head_->first] = newstr;
    size_++;  
  }

  return; 
}

void ULListStr::pop_back() {
  if (size_ == 0){
    return; 
  }

  if(tail_ == NULL || tail_->last == 0){
   //std::cout << "empty list?" << endl;
    return; 
  }


  tail_->val[tail_->last-1] = ""; 
  tail_->last--; 
  size_--;

  if (tail_->first == tail_->last){
    // item is EMPTY: deallocate
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(tail_ != NULL){ // still NODE on list  
      tail_->next = NULL;
      // return; 
    }
    else{ // this means that tail is null, aka the list is now empty...
      head_ = NULL;
    }
    delete temp; 
  }
}

void ULListStr::pop_front() {
  // update list size
  // take it out i guess delete pointer
  if (size_ == 0){
    return; 
  }
  if(head_ == NULL ){
    //std::cout << "empty list?" << endl;
    return; 
  }
  head_->val[head_->first] = ""; 
  head_->first++; 
  size_--;

  if(head_->first == head_->last) { // if the list is empty
    Item* temp = head_;
    head_ = head_->next; 
    if (head_ != NULL){ // still nodes on list
      head_->prev = NULL; 
    }

    else{ // this means that head is null, aka the list is now empty...
      tail_ = NULL;
    }
    delete temp; 
  } 
}
/*Returns a const reference to the back element
*   - MUST RUN in O(1)*/ 

const std::string& ULListStr::back() const {
  if(tail_ == NULL || tail_->first == tail_->last ){
    throw std::invalid_argument("out of range!");
  }
  std::string& backstr = tail_->val[tail_->last -1];
  return backstr;
}

const std::string& ULListStr::front() const {
  if(head_ == NULL || head_->first == head_->last ){
    throw std::invalid_argument("out of range!");
  }
  std::string& frtstr = head_->val[head_->first];
  return frtstr;
  
}

 /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const {
     // traverse the list until you reach that location... 

    // first check if its less than the size of the occupied spots:
    /*if (head_ == NULL){
      //std::cout << "here" << std::endl;
      return NULL; 
    }

    size_t idx = loc % 10;
    size_t node = loc / 10 + 1;

    // check its in first-last range
    if (loc < head_-> first || loc >= tail_->last){
      return NULL; 
    }

    // now its in the range, go to node
    Item* curr = head_;  

    if (loc != 1){
      for (int i=0; i < node; i++){
        curr = curr->next; 
      }
    }
    // now at the node. Just return the loc now 
    return &curr->val[idx]; 
    */

    if (head_ == NULL) {
      return NULL; 
    }

    Item* curr = head_;
    while(curr != NULL) {
      size_t filled = curr->last - curr->first;
      size_t idx = curr->first;

      if (loc < filled){
        // found the node i want 
        // just return 
        return &curr->val[idx + loc]; 
      }

      else{
        curr = curr->next; 
        loc = loc - filled; 
      }
    }
      return NULL; 
  }



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
