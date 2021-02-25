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

EventPriorityQueue::EventPriorityQueue(int maxSize) : maxSize_(maxSize)
{}

bool EventPriorityQueue::isEmpty() const
{
   return false;
}

int EventPriorityQueue::getMaxSize() const
{
   return 0;
}

void EventPriorityQueue::push(Event event)
{
   {
      // add data at next open position
      // update next open position
      // loop bubble up new data to correct position using parent index calculation
      // parent = (index – 1) / 2
   }
}

Event EventPriorityQueue::pop()
{
   {
      // Swaps the root index with the last used index
      // dequeues the last used index and decrements used indexes by one
      // rebuildHeap()
   }
   return Event(1, 1, 1, 1);
}

int EventPriorityQueue::getLeftChildIndex(int parentIndex) const
{
   return 0;
}

int EventPriorityQueue::getRightChildIndex(int parentIndex) const
{
   return 0;
}

int EventPriorityQueue::getParentIndex(int index) const
{
   return 0;
}

bool EventPriorityQueue::isLeaf() const
{
   return false;
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