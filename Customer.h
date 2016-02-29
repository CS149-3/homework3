//
//  Customer.h
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#pragma once
#include <iostream>
#include <unistd.h>
#include "TicketSeller.h"

using namespace std;

class TicketSeller;

class Customer {
	int arrivalTime;
	class TicketSeller* ticketSeller;
	static pthread_mutex_t* cout_mutex;
	static class Timer* timer;
public:
	string name;
	static void setCoutMutex(pthread_mutex_t* cout_mutex);
	static void setTimer(class Timer* timer);
	Customer(string name, int arrivalTime, class TicketSeller* ticketSeller);
	bool operator==(const Customer &other);
	pthread_t waitThread;
private:
	static void* wait(void*);
	static void* checkWait(void*);
};

