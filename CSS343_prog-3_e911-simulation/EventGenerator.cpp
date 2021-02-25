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
{}

void EventGenerator::initializeDistributions(int averageRealCallsPerHour,
                                             int averageRealCallServiceTime,
                                             int numBots)
{}

bool EventGenerator::isValidEvent(Event & event) const
{
   return false;
}
