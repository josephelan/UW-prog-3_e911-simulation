/**
 * @file       Event.cpp
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
#include "Event.h"

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
 *              callTime_: By parameter
 *              serviceTime_: By parameter
 *              waitTime_: -1
 *              endTime_: -1
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
Event::Event(bool isReal, bool isCallPlaceEvent, int callTime, int serviceTime)
   : isReal_(isReal),
   isCallPlaceEvent_(isCallPlaceEvent),
   callTime_(callTime),
   serviceTime_(serviceTime),
   isValidTime_(true),
   waitTime_(-1),
   endTime_(-1),
   totalServiceTime_(-1)
{}

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
bool Event::isReal() const
{
   return isReal_;
}

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
bool Event::isValid() const
{
   return isValidTime_;
}

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
bool Event::isCallPlaceEvent() const
{
   return isCallPlaceEvent_;
}

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
int Event::getCallTime() const
{
   return callTime_;
}

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
int Event::getWaitTime() const
{
   return waitTime_;
}

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
int Event::getServiceTime() const
{
   return serviceTime_;
}

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
int Event::getTotalServiceTime() const
{
   return totalServiceTime_;
}

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
int Event::getEndTime() const
{
   return endTime_;
}

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
void Event::setWaitTime(int time)
{
   waitTime_ = time;
}

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
void Event::setEndTime(int time)
{
   endTime_ = time;
}

/**
 * @brief   sets new call time for service end event
 *
 * @pre     n/a
 * @post    new call time set for service end event creation
 *
 * @param   time of new call time
 *
 * Significant Function Calls:
 * n/a
 */
void Event::setNewCallTime(int time)
{
   callTime_ = time;
}

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
*              isValidTime_: true
*              callTime_: Same as this->
*              serviceTime_: Same as this->
*              waitTime_: time from call place time to time now
*              endTime_: -1
*              totalServiceTime_: -1
*
* Significant function calls:
* Event()
*/
Event Event::createEndEvent() const
{
   Event serviceEndEvent(isReal_, false, callTime_, serviceTime_);
   return serviceEndEvent;
}

/**
 * @brief   return true if Event callTime is less than  is less than
 *          call time of rhs Event
 *
 * @pre     n/a
 * @post    no state change. Returns bool
 *
 * @param   rhs compared event object
 * @return  true if rhs callTime is later than calling object
 *
 * Significant Function Calls:
 * n/a
 */
bool Event::operator<(const Event& rhs) const
{
   return (this->callTime_ < rhs.getCallTime());
}

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
void Event::setTotalServiceTime(int totalServiceTime)
{
   totalServiceTime_ = totalServiceTime;
}

/**
* @brief    Sets isValidTime_ to true if the call time and end time are both
*           within time 0 to time 3600
*
* @pre      n/a
* @post     Sets isValidTime_ to true if end time within time 0 to 3600
*
* Significant function calls:
* n/a
*/
void Event::calculateValidity()
{
   isValidTime_ = endTime_ <= 3600;
}