//
//  Timer.h
//  homework3
//
//  Created by Johnathon Ludeman on 2/26/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#pragma once
#include <iostream>
#include <unistd.h>

using namespace std;

class Timer {
	int time;
public:
	Timer();
	string currentTime();
	void increment();
};