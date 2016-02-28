//
//  Customer.cpp
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#include <pthread.h>
#include "Customer.h"

Timer* Customer::timer = nullptr;
pthread_mutex_t* Customer::cout_mutex = nullptr;

Customer::Customer(string name, int arrivalTime, class TicketSeller* ticketSeller) {
	this->name = name;
	this->arrivalTime = arrivalTime;
	this->ticketSeller = ticketSeller;
	this->timer = timer;
	
	pthread_t thread;
	
	// wait until arrival
	pthread_create(&thread, NULL, Customer::wait, this);
	
}

void Customer::setCoutMutex(pthread_mutex_t *cout_mutex) {
	Customer::cout_mutex = cout_mutex;
}

void Customer::setTimer(class Timer* timer) {
	Customer::timer = timer;
}

void* Customer::wait(void *customerptr) {
	
	Customer* customer = static_cast<Customer *>(customerptr);
	Timer* timer = customer->timer;
	
	// wait until arrival
	sleep(customer->arrivalTime);
	
	// upon arrival join ticket seller queue
	customer->ticketSeller->queue.push_back(*customer);
	pthread_mutex_lock(cout_mutex);
	cout << timer->currentTime() << " " << customer->name << " arrived\n";
	pthread_mutex_unlock(cout_mutex);
	
	// return nullptr because the compiler said so
	return nullptr;
}