/*********************************************************************
* ISensor.h
*
* Copyright (C)    2017   [DFRobot](http://www.dfrobot.com),
* GitHub Link :https://github.com/DFRobot/watermonitor
* This Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Description:
*Explanation: Runtime polymorphism is achieved only through a pointer (or reference) of base class type
*A virtual function is a member function in the base class that we expect to redefine in derived classes.
*Basically, a virtual function is used in the base class in order to ensure that the function is overridden.
*https://www.geeksforgeeks.org/virtual-function-cpp/
*They are mainly used to achieve Runtime polymorphism
*https://www.geeksforgeeks.org/polymorphism-in-c/
*
* author  :  Jason(jason.ling@dfrobot.com)
* version :  V1.0
* date    :  2017-04-06
**********************************************************************/
#pragma once
class ISensor
{
public:
	virtual void setup()		= 0;
	virtual void update()		= 0;
	virtual double getValue()	= 0;
};
