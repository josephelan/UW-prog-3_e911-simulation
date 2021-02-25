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
   * @brief    Constructor initializes a simulation with no events, simulating
   *           a 911 PSAP with no calls. Sets the number of call takers to input param.
   *
   * @pre      n/a
   * @post     Object Initialized
   *
   * @param    numCallTakers number of CTakers for scenario
   * @param    events events to enqueue into priority queue
   *
   * Significant function calls:
   * n/a
   */
   Simulation(int numCallTakers, std::vector<Event> events);

   // actions

   /**
   * @brief    Populates the simulations event queue from a vector of events
   *
   * @pre      Only allows this to be run once per simulation
   * @post     Simulation resizes the heap and adds all the events in order to
   *           the simulations priority queue
   *
   * @param    events vector of events for the scenario
   *
   * Significant function calls:
   * EventPriorityQueue::push()
   */
   void populateEventQueue(std::vector<Event> events);

   /**
   * @brief    Runs the simulation through all the events and calculating the
   *           average total service time for tpainthe scenario
   *
   * @pre      Events has been populated
   * @post     All events dequeued, waiting list empty, AverageTotalServiceTime
   *           is set
   *
   * Significant function calls:
   * handleCallEvent()
   * handleServiceEndEvent()
   * updateEvent()
   * updateTotalServiceTimes()
   */
   void runSimulation();

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
   int getAverageTotalServiceTime() const;

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
   void displayAverageTotalServiceTime() const;

   private:

   // members

   // The event queue for the simulation
   EventPriorityQueue eventQueue_;

   // The waiting list of events (normal queue) of all events waiting a call-taker
   std::queue<Event> waitingList_;

   // The current time in seconds
   int timeInSeconds_;

   // The number of call takers for the scenario
   int numCallTakers_;

   // The number of available call takers
   int numCallTakersAvailable_;

   // A vector of all (valid) service times calculated for the scenario
   std::vector<int> totalServiceTimes_;

   // The calculated average total service time for the scenario
   int averageTotalServiceTime_;

   // helpers

   /**
   * @brief    helper that handles a call-event dequeue situation by either
   *           creating a SE event and pushing it onto the priority queue or
   *           pushing it onto the the waitlist if no calltakers are available
   *
   * @pre      n/a
   * @post     Either creates a SE event for the given call or pushes it into
   *           the event queue or places the CE onto the waitlist.
   *
   * @param    event the event to handle
   *
   * Significant function calls:
   * handleAvailableCallTaker()
   * handleNoAvailableCallTaker()
   */
   void handleCallEvent(Event event);

   /**
   * @brief    Helper that handles the event that a CE is dequeued from event
   *           queue and a CTaker is available
   *
   * @pre      numCallTakersAvailable_ != 0
   * @post     numCallTakersAvailable_ decrement by one (busy server) service
   *           event is created and pushed onto priority queue
   *
   * @param    event the event to handle
   *
   *
   * Significant function calls:
   * Event::createEndEvent()
   */
   void handleAvailableCallTaker(Event event);

   /**
   * @brief    Helper that handles the event that a CE is dequeued from event
   *           queue and a CTaker is not available
   *
   * @pre      numCallTakersAvailable_ == 0
   * @post     Event is pushed onto waiting list
   *
   * @param    event the event to handle
   *
   * Significant function calls:
   * n/a
   */
   void handleNoAvailableCallTaker(Event event);

   /**
   * @brief    Helper that handles the event that SE is dequeued from the event
   *           queue
   *
   * @pre      Assume the event deq from event queue is a SE event
   * @post     Increment CallTaker and process even to add its data to the
   *           collected data used to calculate averageTotalServiceTime if
   *           deemed valid
   *
   * @param    event the event to handle
   *
   * Significant function calls:
   * UpdateEvent()
   */
   void handleServiceEndEvent(Event event);

   /**
   * @brief    Helper function that updates / validates trivial information
   *           about an event when it is a SE event being dequeued from event
   *           queue
   *
   * @pre      event has just been deq from event queue
   * @post     Event times are updated and validated
   *
   * @param    event the event to update and validate
   *
   * Significant function calls:
   * n/a
   */
   void updateEvent(Event event);

   /**
   * @brief    updates totalServiceTimes_ with data from the event
   *
   * @pre      Assumes the event has been determined to be valid
   * @post     totalServiceTimes_ adds integer value for TST to its vector
   *
   * @param    event to add TST to array of TSTs
   *
   * Significant function calls:
   * n/a
   */
   void updateTotalServiceTimes(Event event);

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
   void calculateAverageTotalServiceTimes();
};