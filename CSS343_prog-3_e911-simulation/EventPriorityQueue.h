/**
 * @file       EventPriorityQueue.h
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
#pragma once

#include <iostream>

#include "Event.h"

class EventPriorityQueue {
   public:

   // constructors

   /**
   * @brief    Initialize empty priority queue with maxSize_ set to input param
   *
   * @pre      n/a
   * @post     Object initialized to empty priority queue with max size
   *
   * @param    maxSize max expected element in PQ
   *
   * Significant function calls:
   * n/a
   */
   EventPriorityQueue(int maxSize);

   // actions

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
   bool isEmpty() const;

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
   int getMaxSize() const;

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
   void push(Event event);

   /**
   * @brief    Pops the next item in the priority queue and updates the priority
   *           queue for the next items
   *
   * @pre      priority queue is correctly sorted (minheap)
   * @post     first item in the PQ is dequeued
   *
   * Significant function calls:
   * rebuildHeap()
   */
   Event pop();

   private:

   // members

   // for readability, root index always 0
   const int rootIndex_ = 0;

   // max size of the priority queue used to build the heap
   int maxSize_;

   // number of events in the heap
   int numEvents_;

   // the heap used to implement the priority queue
   std::unique_ptr<Event[]> minHeap_;

   // helpers

   /**
   * @brief    Helper function returns left child index of given index
   *
   * @pre      assumes calling index is not a leaf
   * @post     no state change. Returns integer
   *
   * @param    parentIndex index of the parent
   *
   * @return   index of left child
   *
   * Significant function calls:
   * n/a
   */
   int getLeftChildIndex(int parentIndex) const;

   /**
   * @brief    Helper function returns right child index of given index
   *
   * @pre      Assumes calling index is not a leaf
   * @post     no state change. Returns integer
   *
   * @param    parentIndex index of the parent
   *
   * @return   index of right child
   *
   * Significant function calls:
   * n/a
   */
   int getRightChildIndex(int parentIndex) const;

   /**
   * @brief    Returns parent index of the child
   *
   * @pre      Assumes calling index is not the root
   * @post     no state change. Returns integer
   *
   * @param    index index of this index obj you are looking for the parent of
   * @return   index of the parent
   *
   * Significant function calls:
   * n/a
   */
   int getParentIndex(int index) const;

   /**
   * @brief    Returns true if the given index has no children (is a leaf)
   *
   * @pre      n/a
   * @post     no state change. Returns bool
   *
   * @return   true if the given index position in the heap is a leaf
   *
   * Significant function calls:
   * n/a
   */
   bool isLeaf() const;

   /**
   * @brief    Helper functions that fixes an unorganized heap
   *
   * @pre      n/a
   * @post     Heap is fixed into minheap
   *
   * @param    index index to fix the heap from (starting at root)
   *
   * Significant function calls:
   * getLeftChildIndex()
   * getRightChildIndex()
   */
   void rebuildHeap(int index);
};