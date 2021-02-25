/**
 * @file       Event.h
 * @brief      Defines
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

 /**
  * @brief
  */
class Event {
   public:
   // constructors

   /**
    * @brief
    *
    * @pre
    * @post
    * @param   isReal
    * @param   isCallEvent
    * @param   callTime
    * @param   serviceTime
    *
    * Significant Function Calls:
    * n/a
    */
   Event(bool isReal, bool isCallEvent, int callTime, int serviceTime);

   // actions

   /**
    * @brief
    *
    * @pre
    * @post
    *
    * @return
    *
    * Significant Function Calls:
    * n/a
    */
   bool isReal() const;

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
   bool isValid() const;

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
   bool isCallEvent() const;

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
   int getCallTime() const;

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
   int getWaitTime() const;

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
   int getServiceTime() const;

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
   int getTotalServiceTime() const;

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
   int getEndTime() const;

   /**
    * @brief
    *
    * @pre
    * @post
    * @param   time
    *
    * Significant Function Calls:
    * n/a
    */
   void setWaitTime(int time);

   /**
    * @brief
    *
    * @pre
    * @post
    * @param   time
    *
    * Significant Function Calls:
    * n/a
    */
   void setEndTime(int time);

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
   Event createEndEvent() const;

   private:

   // members
   bool isReal_;
   bool isCallPlaceEvent_;
   bool isValidTime_;
   int callTime_;
   int serviceTime_;
   int waitTime_;
   int endTime_;
   int totalServiceTime_;

   // helpers

   /**
    * @brief
    *
    * @pre
    * @post
    *
    * Significant Function Calls:
    * n/a
    */
   void setTotalServiceTime();

   /**
    * @brief
    *
    * @pre
    * @post
    *
    * Significant Function Calls:
    * n/a
    */
   void calculateValidity();
};