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
{}

Event EventPriorityQueue::pop()
{
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
{}
