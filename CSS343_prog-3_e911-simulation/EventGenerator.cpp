/**
 * @file       EventGenerator.cpp
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
#include "EventGenerator.h"

EventGenerator::EventGenerator(int averageRealCallsPerHour, int averageRealCallServiceTime, int numBots)
{}

std::vector<Event> EventGenerator::getEvents() const
{
   return std::vector<Event>();
}

void EventGenerator::generateEvents()
{
   {
      // For the number of bots (numBots)
      // Create bot with CPT from uniform distribution
      // Set service time to 6 seconds
      // validate time and place in vector
      // Start time at time t0
      // create first real event at time t0, with service time from distribution
      // while (time <= 3600)
      // Increment time by interval from distribution
      // Create event with current time, with service time from distribution
      // validate event and place in vector
   }
}

void EventGenerator::initializeDistributions(int averageRealCallsPerHour,
                                             int averageRealCallServiceTime,
                                             int numBots)
{}

bool EventGenerator::isValidEvent(Event& event) const
{
   return false;
}