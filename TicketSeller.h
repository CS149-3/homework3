//
//  TicketSeller.h
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#pragma once
#include <iostream>
#include <vector>
#include <unistd.h>
#include <pthread.h>
#include "Customer.h"
#include "Timer.h"

using namespace std;

typedef string seat_matrix[10];

class Customer;

class TicketSeller {
protected:
	static class Timer* timer;
	static pthread_mutex_t seats_mutex;
public:
	string name;
	seat_matrix* seats;
	vector<Customer> queue;
	TicketSeller(string name, seat_matrix* seats);
	virtual void start();
	virtual int sellTime() = 0;
	virtual bool assignSeat(string customerName) = 0;
	static void setTimer(class Timer* timer);
	static void initSeatsMutex();
	static void destroySeatsMutex();
private:
	static void* sellTickets(void*);
};