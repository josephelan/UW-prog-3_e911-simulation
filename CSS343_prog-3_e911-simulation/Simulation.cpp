/**
 * @file       Simulation.cpp
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
#include "Simulation.h"

Simulation::Simulation(int numCallTakers, std::vector<Event> events)
   : eventQueue_(EventPriorityQueue(events.size())),
   timeInSeconds_(0),
   numCallTakers_(numCallTakers),
   numCallTakersAvailable_(numCallTakers),
   averageTotalServiceTime_(0)
{
   populateEventQueue(events);
}

void Simulation::runSimulation()
{
   {
      // while priority queue is not empty
      // dequeue next event
      // set current time to event time
      // determine event type
      // if CE
      // handleCallEvent
      // if SE
      // handle ServiceEndEvent
      // priority queue is empty here
      // update totalServiceTimes
      // calculate averageTotalServiceTime
      // displayaverageTotalServiceTime
   }
}

/**
* @brief    Return the average total service time
*
* @pre      Assumes the total time has been calculated
* @post     No state change. returns int
*
* @return   Returns integer representing average total service time in sec
*
* Significant function calls:
* n/a
*/
int Simulation::getAverageTotalServiceTime() const
{
   return averageTotalServiceTime_;
}

/**
* @brief    Displays the calculated average total service time of the
*           simulation to cout
*
* @pre      Assumes the simulation has been run and the value has been calculated
* @post     No state change. Prints to cout
*
* Significant function calls:
* n/a
*/
void Simulation::displayAverageTotalServiceTime() const
{
   std::cout << "Average Total service Time: " << averageTotalServiceTime_ <<
      std::endl;
}

// todo:
void Simulation::populateEventQueue(std::vector<Event> events)
{}

/**
* @brief    helper that handles a call-event dequeue situation by either
*           creating a SE event and pushing it onto the priority queue or
*           pushing it onto the the waitlist if no calltakers are available
*
* @pre      n/a
* @post     Either creates a SE event for the given call or pushes it into
*           the event queue or places the CE onto the waitlist.
*
* @param    inEvent the event to handle
*
* Significant function calls:
* handleAvailableCallTaker()
* handleNoAvailableCallTaker()
*/
void Simulation::handleCallEvent(Event inEvent)
{
   // if Call taker available, handleAvailableCallTaker
   if (numCallTakersAvailable_ != 0) {
      handleAvailableCallTaker(inEvent);

      // no call taker available
   } else {
      handleNoAvailableCallTaker(inEvent);
   }
}

/**
* @brief    Helper that handles the event that a CE is dequeued from event
*           queue and a CTaker is available
*
* @pre      numCallTakersAvailable_ != 0
* @post     numCallTakersAvailable_ decrement by one (busy server) service
*           event is created and pushed onto priority queue
*
* @param    inEvent the event to handle
*
*
* Significant function calls:
* Event::createEndEvent()
*/
void Simulation::handleAvailableCallTaker(Event inEvent)
{
   --numCallTakersAvailable_;

   // set how long the event waited for in wait queue
   int waitTime = this->timeInSeconds_ - inEvent.getCallTime();

   // set the new calling time (which is end time)
   // of service end event
   int endTime = this->timeInSeconds_ + inEvent.getServiceTime();
   inEvent.setNewCallTime(endTime);

   // create the service end event
   Event endEvent = inEvent.createEndEvent();

   // set end event wait time and end time
   endEvent.setEndTime(endTime);
   endEvent.setWaitTime(waitTime);

   //push service-end event created from this event onto priority stack
   eventQueue_.push(endEvent);
}

/**
* @brief    Helper that handles the event that a CE is dequeued from event
*           queue and a CTaker is not available
*
* @pre      numCallTakersAvailable_ == 0
* @post     Event is pushed onto waiting list
*
* @param    inEvent the event to handle
*
* Significant function calls:
* n/a
*/
void Simulation::handleNoAvailableCallTaker(Event inEvent)
{
   waitingList_.push(inEvent);
}

// todo:
void Simulation::handleServiceEndEvent(Event inEvent)
{
   {
      //Calculate the updated times for the SE event (end time, total service, etc)
      //If times are statistically valid, add update totalServicesTimes_
      //++numCallTakersAvailable
      //If waiting list has event
      // Dequeue from waiting list and run handleAvailableCallTaker()
      //If waiting list has no event
      // End this loop iteration
   }
}

void Simulation::updateEvent(Event inEvent)
{}

/**
* @brief    updates totalServiceTimes_ with data from the event
*
* @pre      Assumes the event has been determined to be valid
* @post     totalServiceTimes_ adds integer value for TST to its vector
*
* @param    inEvent to add TST to array of TSTs
*
* Significant function calls:
* n/a
*/
void Simulation::updateTotalServiceTimes(Event inEvent)
{
   totalServiceTimes_.push_back(inEvent.getTotalServiceTime());
}

/**
* @brief    calculates the average total service time based on data in
*           totalServiceTimes_
*
* @pre      Assumes all events have been dequeued and simulation loop has
*           been completed
* @post     AverageTotalServiceTimes_ updated
*
* Significant function calls:
* n/a
*/
void Simulation::calculateAverageTotalServiceTimes()
{
   // variable holding calculated average total service time which is
   // all average total service times / number of valid events
   int calculatedTime = 0;

   // add up all valid time
   // invariant: 0 <= i < number of valid events
   for (int i = 0; i < totalServiceTimes_.size(); ++i) {
      calculatedTime += totalServiceTimes_.at(i);
   }

   // divide by number of times
   calculatedTime /= totalServiceTimes_.size();
   averageTotalServiceTime_ = calculatedTime;
}