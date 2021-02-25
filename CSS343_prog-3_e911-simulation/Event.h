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
   * @brief    Constructor initializes object and defines whether the object is
   *           a legimimate call or a bot, is a call-event or service-end, and
   *           the Service time length of the event.
   *
   * @pre      Assumes the input parameters are correct. Assumes that service-time
   *           is less than 3600 seconds
   * @post     Event object initialized, values are by passed in parameter or
   *           initialized as follows:
   *              isReal_: By parameter
   *              isCallPlaceEvent_: By parameter
   *              isValidTime_: True
   *              callTime_: By
   *              serviceTime_: By
   *              waitTime_:
   *              endTime_: -
   *              totalServiceTime_: -1
   *
   * @param    isReal         true if legitimate caller
   * @param    isCallEvent    if call event (not service end)
   * @param    callTime       call place time of even
   * @param    serviceTime    service time length of the call
   *
   * Significant function calls:
   * n/a
   */
   Event(bool isReal, bool isCallEvent, int callTime, int serviceTime);

   // actions

   /**
   * @brief    Returns true is the call is from a legitimate call (not a bot)
   *
   * @pre      n/a
   * @post     No state change. Returns bool.
   *
   * @return   Returns true if the object is from a legitimate call.
   *
   * Significant function calls:
   * n/a
   */
   bool isReal() const;

   /**
   * @brief    Returns true if the event’s time metrics and data members
   *           consider it to be valid to include in the average total service
   *           time calculation
   *
   * @pre      n/a
   * @post     No state change. Returns bool
   *
   * @return   True if the object’s service time is less than 3600 and it starts
   *           and ends in (inclusive) time 0 to time 3600
   *
   * Significant function calls:
   * isReal()
   * getCallTime()
   * getServiceTime()
   * getEndTime()
   */
   bool isValid() const;

   /**
   * @brief    Returns true if the event is CE
   *
   * @pre      n/a
   * @post     No state change. Returns bool
   *
   * @return   True if event is a CE
   *
   * Significant function calls:
   * n/a
   */
   bool isCallEvent() const;

   /**
   * @brief    Returns the call time of the event
   *
   * @pre      n/a
   * @post     No state change. Returns integer.
   *
   * @return   Return the int representation of when the event is to occur
   *
   * Significant function calls:
   * n/a
   */
   int getCallTime() const;

   /**
   * @brief    Returns the wait time of the event
   *
   * @pre      n/a
   * @post     No state change. Returns integer.
   *
   * @return   Returns the int representation of how long the event has waited
   *           in the waiting
   *
   * Significant function calls:
   * n/a
   */
   int getWaitTime() const;

   /**
   * @brief    Returns the service length time of the event
   *
   * @pre      n/a
   * @post     No state change. Returns integer
   *
   * @return   Returns the int representation of how long the event will take
   *           once associated with a call-taker
   *
   * Significant function calls:
   * n/a
   */
   int getServiceTime() const;

   /**
   * @brief    Returns the total service time of the call, from call time to end
   *           time
   *
   * @pre      n/a
   * @post     No state change. Returns integer
   *
   * @return   The difference between the call time and the end time, that is
   *           the total time the call has been in the loop after the initial
   *           call event is dequeued from the priority queue.
   *
   * Significant function calls:
   * n/a
   */
   int getTotalServiceTime() const;

   /**
   * @brief    Returns the end time of the event, which is the when the
   *           service-end form of the event is dequeued from the priority queue
   *
   * @pre      n/a
   * @post     No state change. Returns integer
   *
   * @return   Returns the int representation of when the service-end form of
   *           the call is dequeued from the priority queue
   *
   * Significant function calls:
   * n/a
   */
   int getEndTime() const;

   /**
   * @brief    Sets the wait time of the event
   *
   * @pre      n/a
   * @post     Sets wait time of the event
   *
   * @param    time amount of time in waiting list
   *
   * Significant function calls:
   * n/a
   */
   void setWaitTime(int time);

   /**
   * @brief    Sets endTime_ of the event once service-end associated event is
   *           dequeued from priority queue. Also sets the total service time
   *           automatically and calculates whether time is valid within the
   *           scenario time limits of time 0 to time 3600 by calling
   *           setTotalServiceTime
   *
   * @pre      Assumes the event is over (deq from PQ)
   * @post     Sets the end time of the Event, and
   *
   * @param    time point in time service end deq from priority queue
   *
   * Significant function calls:
   * setTotalServiceTime()
   */
   void setEndTime(int time);

   /**
   * @brief    Creates the associated service-end event version of this call
   *           event
   *
   * @pre      Assumes the Event has just been associated with a call taker
   * @post     This Object goes out of scope and the event is now handled
   *           returned event, which is the service-end event
   *
   * @return   Event object initialized with values:
   *              isReal_: Same as this->
   *              isCallPlaceEvent_: false
   *              isValidTime_: True
   *              callTime_: Same as this->
   *              serviceTime_: Same as this->
   *              waitTime_: time from call place time to time now
   *              endTime_: -1
   *              totalServiceTime_: -1
   *
   * Significant function calls:
   * Event()
   */
   Event createEndEvent() const;

   private:

   // members

   // True if this is this is a legitimate call (not a bot call)
   bool isReal_;

   // True if this is a call event (not a service-end event)
   bool isCallPlaceEvent_;

   // True if the time metrics make this call within the time 0 to time 3600.
   bool isValidTime_;

   // Integer representation of the point int time when the call is placed
   int callTime_;

   // Integer representation of the length of the call in seconds after taken
   int serviceTime_;

   // Integer representation of the length of time this call has been in waiting
   int waitTime_;

   // Integer representation of the point in time, in seconds, this call was
   // completed. that is to say, when this call’s associated service-end time
   // event dequeues from the priority Queue
   int endTime_;

   // Integer representation of the total time, in seconds, from when the
   // call was placed to the call’s end time
   int totalServiceTime_;

   // helpers

   /**
   * @brief    Calculate and set the total service time of the event, equal to
   *           the end time – the call time, and validates data for isValidTime
   *
   * @pre      Assumes event end time has been set
   * @post     Sets total service time to end time – call time, sets
   *           isValidTime to true if the call time and end time both lie with
   *           time 0 to time 3600
   *
   * Significant function calls:
   * calculateValidity()
   */
   void setTotalServiceTime();

   /**
   * @brief    Sets isValidTime_ to true if the call time and end time are both
   *           within time 0 to time 3600
   *
   * @pre      n/a
   * @post     Sets isValidTime_ to true if call & end time both within time 0 to 3600
   *
   * Significant function calls:
   * n/a
   */
   void calculateValidity();
};