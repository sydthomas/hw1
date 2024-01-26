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

void ULListStr::push_back(const std::string& val){
  if(empty()){
    Item* newTemp = new Item;
    head_ = tail_ = newTemp;
    newTemp->first = 0;
    newTemp->last = 1;
    newTemp->prev = nullptr;
    newTemp->next = nullptr;
    newTemp->val[newTemp->first] = val;
    size_++;
  }
  else if(tail_->last  == ARRSIZE){
    Item* newTemp = new Item;
    tail_->next = newTemp;
    newTemp->prev = tail_;
    tail_ = newTemp;
    newTemp->first = 0;
    newTemp->last = 1;
    newTemp->val[newTemp->first] = val;
    size_++;
  }
  else{
    tail_->val[(tail_->last)] = val;
    tail_->last++;
    size_++; 
  }
}

void ULListStr::pop_back(){
  if(empty()){
    return;
  }
  else if(tail_->last == 1){
    if(tail_ == head_) {
      delete tail_;
      tail_ = nullptr; 
      head_ = nullptr; 
    } 
    else{
      Item* newTemp = tail_;
      tail_ = tail_->prev;
      delete newTemp;
      tail_->next = nullptr;
    }  
  }
  else{
    tail_->last--;
  }
  size_--;    
}

void ULListStr::push_front(const std::string& val){
  if(empty()){
    Item* newTemp = new Item;
    newTemp->last = ARRSIZE;
    newTemp->first = ARRSIZE-1;
    newTemp->val[newTemp->first] = val;
    newTemp->prev = nullptr;
    newTemp->next = nullptr;
    head_ = tail_ = newTemp; 
    size_++;
  }
  else if((head_->first == 0)){
    Item* newTemp = new Item;
    newTemp->val[ARRSIZE-1] = val;
    newTemp->last = ARRSIZE;
    newTemp->first = ARRSIZE-1;
    newTemp->next = head_;
    newTemp->prev = nullptr;
    head_->prev = newTemp;
    head_ = newTemp;
    size_++;
  }
  else{
    head_->val[--head_->first] = val;
    size_++;
  }
}

void ULListStr::pop_front(){
  if(empty()){
    return;
  }
  else if(head_->first == ARRSIZE-1){
   
    if(tail_ == head_) {
      delete head_;
      tail_ = nullptr; 
      head_ = nullptr; 
    }
    else{
      Item* newTemp = head_;
      head_ = head_->next;
      delete newTemp;
      head_->prev = nullptr;
    }
  }
  else{
    head_->first++; 
  }
  size_--;
}


std::string const& ULListStr::back() const{
  return tail_->val[tail_->last-1]; 
}


std::string const& ULListStr::front() const{
  return head_->val[head_->first];
}


std::string* ULListStr::getValAtLoc(size_t loc) const{
  size_t count = 0;
  Item* temp = head_;

  while (temp){
    size_t num_items = temp->last - temp->first;

    if(loc < (count+num_items)){

      //4 + 1 - 3 = 2
      size_t location_ = loc + temp->first - count;
      return &(temp->val[location_]);

    }
    count += num_items;
    temp = temp->next;     
  }
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
