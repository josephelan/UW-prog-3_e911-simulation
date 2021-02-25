/**
 * @file       EventGenerator.h
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
#include <string>
#include <random>
#include <cmath>

#include "Event.h"

/**
 * @brief   
 */
class EventGenerator {
   public:
   // constructors
   
   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @param   averageRealCallsPerHour
    * @param   averageRealCallServiceTime
    * @param   numBots
    * 
    * Significant Function Calls:
    * n/a
    */
   EventGenerator(int averageRealCallsPerHour,
                  int averageRealCallServiceTime,
                  int numBots);

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
   std::vector<Event> getEvents() const;

   private:
   // members
   std::vector<Event> events_;
   std::default_random_engine generator_;
   std::uniform_int_distribution<int> botCallTimeDistribution_;
   std::exponential_distribution<double> realCallTimeDistribution_;
   std::exponential_distribution<double> realCallServiceLengthDistribution_;

   //helpers
   
   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * 
    * Significant Function Calls:
    * n/a
    */
   void generateEvents();

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @param   averageRealCallsPerHour
    * @param   averageRealCallServiceTime
    * @param   numBots
    * 
    * Significant Function Calls:
    * n/a
    */
   void initializeDistributions(int averageRealCallsPerHour,
                                int averageRealCallServiceTime,
                                int numBots);

   /**
    * @brief   
    * 
    * @pre     
    * @post    
    * @param   event
    * @return  
    * 
    * Significant Function Calls:
    * n/a
    */
   bool isValidEvent(Event& event) const;
};