/**
 * @file       EventPriorityQueue.cpp
 * @brief
 *
 * @details
 *
 * @author     Joseph Lan
 * @date       23 February 2021
 *
 * CSS 343 D
 * Program #3 E911 Discrete Simulation
 * Prof. Stiber
 */
#include "EventPriorityQueue.h"

EventPriorityQueue::EventPriorityQueue(int maxSize)
   : maxSize_(maxSize), numEvents_(0)
{}

/**
* @brief    Returns true is the queue is empty
*
* @pre      n/a
* @post     No state change. Returns bool
*
* @return   True is queue is empty
*
* Significant function calls:
* n/a
*/
bool EventPriorityQueue::isEmpty() const
{
   return (numEvents_ == 0);
}

/**
 * @brief   returns the max size of the priority queue
 *
 * @pre     n/a
 * @post    No state change. returns int
 *
 * @return  return max size of priority queue
 *
 * Significant Function Calls:
 * n/a
 */
int EventPriorityQueue::getMaxSize() const
{
   return maxSize_;
}

/**
* @brief    Adds an event to the priority queue and sorts it into the right
*           location by call time
*
* @pre      n/a
* @post     new Event is added to the PQ in the right location
*
* @param    Event to be pushed into PQ
*
* Significant function calls:
* getParentIndex()
*/
void EventPriorityQueue::push(Event inEvent)
{
   // first event added
   if (numEvents_ == 0) {
      minHeap_[0] = inEvent;
      ++numEvents_;
   } else {

      // keep track of where new element is added
      int newEventPosition = numEvents_;

      // add new event to heap
      minHeap_[newEventPosition] = inEvent;
      ++numEvents_; // update number of events

      int parentIndex = getParentIndex(newEventPosition);

      // loop bubble up new data to correct position
      // while index is not root and value is less than parent
      // invariant: 0 <= i < height of the tree
      while (newEventPosition != rootIndex_ &&
             minHeap_[newEventPosition] < minHeap_[parentIndex]) {

         // swaps index with parent to fix value
         swap(newEventPosition, parentIndex);

         // update newEventPosition to its parents after swap
         newEventPosition = parentIndex;

         // update parent index to new parent index
         parentIndex = getParentIndex(newEventPosition);
      }
   }
}

/**
* @brief    Pops the next item in the priority queue and updates the priority
*           queue for the next items
*
* @pre      priority queue is correctly sorted (minheap)
* @post     first item in the PQ is dequeued
*
* Significant function calls:
* rebuildHeap()
* swap()
*/
Event EventPriorityQueue::pop()
{
   // copy root, which is the element to pop
   Event nextPriority = minHeap_[numEvents_];

   // swap root with last element
   this->swap(rootIndex_, numEvents_);
   --numEvents_; // update last element
   rebuildHeap(rootIndex_); // rebuild heap to maintain structure
   return nextPriority;
}

/**
* @brief    Helper function returns left child index of given index
*
* @pre      assumes calling index is not a leaf
* @post     no state change. Returns integer
*
* @param    index index of the parent
*
* @return   index of left child
*
* Significant function calls:
* n/a
*/
int EventPriorityQueue::getLeftChildIndex(int index) const
{
   return (2 * index) + 1;
}

/**
* @brief    Helper function returns right child index of given index
*
* @pre      Assumes calling index is not a leaf
* @post     no state change. Returns integer
*
* @param    index index of the parent
*
* @return   index of right child
*
* Significant function calls:
* n/a
*/
int EventPriorityQueue::getRightChildIndex(int index) const
{
   return (2 * index) + 2;
}

/**
* @brief    Returns parent index of the child
*
* @pre      Assumes calling index is not the root
* @post     no state change. Returns integer
*
* @param    index index of this index obj you are looking for the parent of
*
* @return   index of the parent
*
* Significant function calls:
* n/a
*/
int EventPriorityQueue::getParentIndex(int index) const
{
   return (index - 1) / 2;
}

/**
* @brief    Returns true if the given index has no children (is a leaf)
*
* @pre      n/a
* @post     no state change. Returns bool
*
* @param    index of item to check
*
* @return   true if the given index position in the heap is a leaf
*
* Significant function calls:
* n/a
*/
bool EventPriorityQueue::isLeaf(int index) const
{
   return (2 * index) > numEvents_;
}

void EventPriorityQueue::rebuildHeap(int index)
{
   {
      // loop bubbles down root into correct position using child comparisons
      // left child = 2 * index + 1
      // right child = left child index + 1
      // bubble moves value to the left if smaller, to the right if bigger
      // once you reach a leaf or no child is larger, correct place
   }
}

/**
 * @brief   Switches the elements at the given index
 *
 * @pre     n/a
 * @post    Elements are swapped
 *
 * @param   indexOne element of first index to swap
 * @param   indexTwo element of second index to swap
 *
 * @return  true if both index exist in range of minHeap_
 *
 * Significant Function Calls:
 * n/a
 */
bool EventPriorityQueue::swap(int indexOne, int indexTwo)
{
   // if either index position is out of range
   if ((indexOne > numEvents_) || (indexTwo > numEvents_)) {
      return false;
   }

   // swap the two index elements
   Event temp = minHeap_[indexOne];
   minHeap_[indexOne] = minHeap_[indexTwo];
   minHeap_[indexTwo] = temp;
   return true;
}