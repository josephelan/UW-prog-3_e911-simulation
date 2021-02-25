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
    * @brief   
    * 
    * @pre     
    * @post    
    * @param   maxSize
    * 
    * Significant Function Calls:
    * n/a
    */
   EventPriorityQueue(int maxSize);

   // actions

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @return  
    * 
    * Significant Function Calls:
    * n/a
    */
   bool isEmpty() const;

   /**
    * @brief   
    * 
    * @pre  
    * @post 
    * 
    * @return  
    * 
    * Significant Function Calls:
    * 
    */
   int getMaxSize() const;

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @param   event
    * 
    * Significant Function Calls:
    * n/a
    */
   void push(Event event);

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @return  
    * 
    * Significant Function Calls:
    * n/a
    */
   Event pop();

   private:
   // members
   const int rootIndex_ = 0;
   int maxSize_;
   int numEvents_;
   std::unique_ptr<Event[]> minHeap_;

   // helpers

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @param   parentIndex
    * @return  
    * 
    * Significant Function Calls:
    * n/a
    */
   int getLeftChildIndex(int parentIndex) const;

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @param   parentIndex
    * @return  
    * 
    * Significant Function Calls:
    * n/a
    */
   int getRightChildIndex(int parentIndex) const;

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @param   index
    * @return  
    * 
    * Significant Function Calls:
    * n/a
    */
   int getParentIndex(int index) const;

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @return  
    * 
    * Significant Function Calls:
    * n/a
    */
   bool isLeaf() const;

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @param   index
    * 
    * Significant Function Calls:
    * n/a
    */
   void rebuildHeap(int index);
};