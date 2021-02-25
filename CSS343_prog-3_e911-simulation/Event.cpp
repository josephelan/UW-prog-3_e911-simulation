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

Event::Event(bool isReal, bool isCallEvent, int callTime, int serviceTime)
{}

bool Event::isReal() const
{
   return false;
}

bool Event::isValid() const
{
   return false;
}

bool Event::isCallEvent() const
{
   return false;
}

int Event::getCallTime() const
{
   return 0;
}

int Event::getWaitTime() const
{
   return 0;
}

int Event::getServiceTime() const
{
   return 0;
}

int Event::getTotalServiceTime() const
{
   return 0;
}

int Event::getEndTime() const
{
   return 0;
}

void Event::setWaitTime(int time)
{}

void Event::setEndTime(int time)
{}

Event Event::createEndEvent() const
{
   return Event(1, 1, 1, 1);
}

void Event::setTotalServiceTime()
{}

void Event::calculateValidity()
{}
