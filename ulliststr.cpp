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
  tail_->val[first] = newstr; 

  // first = 0, last = 1
  tail_->last = 1; 
  size_++; 

  if(done)
  {return;} 

  // if i got here, then there's space on the list. 
  else{
    tail_->val[tail_->last] = newstr; 
    tail_->last++; 
    size_++; 
  }
  return; 
}

void ULListStr::push_front(std::string& val) {
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
    Item* temp = head_;
    temp->next = newNode; 
    newNode->prev = head_; 
    head_ = newNode; 
    done = true; 
  }
  // now i have created a new node for the value
  // for both previous cases: push to the BACK of the list (index arrsize-1) 
  tail_->val[ARRSIZE-1] = newstr; 

  
  head_->last = 10; 
  head_->first = 9; 
  size_++; 

  if(done)
  {return;} 

  // if i got here, then there's space on the list. 
  else{
    head_->val[head_->first] = newstr; 
  }
  head_->first--; 

  return; 
}

void ULListStr::pop_back(const std::string& val) {

  if(tail_ == null){
    cout << "empty list?" << endl;
    return; 
  }

  tail_->val[last-1] = ""; 
  tail_->last--; 
  size_--;

  if (tail_->first == tail_->last == 0){
    // item is EMPTY: deallocate
    Item* temp = tail_;
    tail_ = tail_->prev;
    tail_->next = NULL; 
    delete temp; 
  }
}

void ULListStr::pop_front(std::string& val) {
  // update list size
  // take it out i guess delete pointer

  if(head_ == null){
    cout << "empty list?" << endl;
    return; 
  }

  head_->val[first] = ""; 
  head_->first++; 
  size_--;

  if (head_->first == head_->last == 0){
    // item is EMPTY: deallocate
    Item* temp = head_;
    head_ = head_->next; 
    head_->prev = NULL; 
    delete temp; 
  }
  
}
/*Returns a const reference to the back element
*   - MUST RUN in O(1)*/ 

const std::string& ULListStr::back() {

  return string* backstr = tail_->val[tail_->last-1];
  
}

const std::string& ULListStr::front() {
  return string* backstr = head_->val[head_->first];
  
}

 /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* getValAtLoc(size_t loc) const{
    // traverse the list until you reach that location... 

    // first check if its less than the size of the occupied spots:
    if (head_ == NULL){
      return NULL; 
    }

    // find which node it's on 
    int node = loc % 10 + 1; 

    // go to node
    Item* curr = head_;  
    for (int i=0; i < node; i++){
      curr = curr->next; 
    }

    // now at the node. traverse it until you find the loc. 
    int idx = loc / 10; 
    return curr->val[idx]; 
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
