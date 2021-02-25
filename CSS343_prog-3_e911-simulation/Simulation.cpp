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
   : numCallTakers_(numCallTakers),
   eventQueue_(EventPriorityQueue(events.size()))
{}

void Simulation::populateEventQueue(std::vector<Event> events)
{}

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

int Simulation::getAverageTotalServiceTime() const
{
   return 0;
}

void Simulation::displayAverageTotalServiceTime() const
{}

void Simulation::handleCallEvent(Event event)
{
   {
      // if Call taker available
      // handleAvailableCallTaker
      // if no call taker available
      // handleNoAvailableCallTaker
   }
}

void Simulation::handleAvailableCallTaker(Event event)
{
   {
      //--numCallTakersAvailable
      // push service-end event created from this event onto priority stack
   }
}

void Simulation::handleNoAvailableCallTaker(Event event)
{}

void Simulation::handleServiceEndEvent(Event event)
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

void Simulation::updateEvent(Event event)
{}

void Simulation::updateTotalServiceTimes(Event event)
{}

void Simulation::calculateAverageTotalServiceTimes()
{}