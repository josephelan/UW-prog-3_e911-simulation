/**
 * @file       Simulation.h
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
#include <vector>
#include <queue>

#include "EventPriorityQueue.h"
#include "Event.h"

/**
 * @brief   
 */
class Simulation {
   public:
   // constructors

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @param   numCallTakers
    * @param   events
    * 
    * Significant Function Calls:
    * n/a
    */
   Simulation(int numCallTakers, std::vector<Event> events);

   // actions

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @param   events
    * 
    * Significant Function Calls:
    * n/a
    */
   void populateEventQueue(std::vector<Event> events);

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * 
    * Significant Function Calls:
    * n/a
    */
   void runSimulation();

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
   int getAverageTotalServiceTime() const;

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * 
    * Significant Function Calls:
    * n/a
    */
   void displayAverageTotalServiceTime() const;

   private:
   // members
   EventPriorityQueue eventQueue_;
   std::queue<Event> waitingList_;
   int timeInSeconds_;
   int numCallTakers_;
   int numCallTakersAvailable_;
   std::vector<int> totalServiceTimes_;
   int averageTotalServiceTime_;

   // helpers

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
   void handleCallEvent(Event event);

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
   void handleAvailableCallTaker(Event event);

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
   void handleNoAvailableCallTaker(Event event);

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
   void handleServiceEndEvent(Event event);

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
   void updateEvent(Event event);

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
   void updateTotalServiceTimes(Event event);

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * 
    * Significant Function Calls:
    * n/a
    */
   void calculateAverageTotalServiceTimes();
};