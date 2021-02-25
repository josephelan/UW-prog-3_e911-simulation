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
{}

int Simulation::getAverageTotalServiceTime() const
{
   return 0;
}

void Simulation::displayAverageTotalServiceTime() const
{}

void Simulation::handleCallEvent(Event event)
{}

void Simulation::handleAvailableCallTaker(Event event)
{}

void Simulation::handleNoAvailableCallTaker(Event event)
{}

void Simulation::handleServiceEndEvent(Event event)
{}

void Simulation::updateEvent(Event event)
{}

void Simulation::updateTotalServiceTimes(Event event)
{}

void Simulation::calculateAverageTotalServiceTimes()
{}
