//
//  Customer.cpp
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#include <pthread.h>
#include "Customer.h"

Customer::Customer(int arrivalTime, class TicketSeller* ticketSeller) {
	
	this->arrivalTime = arrivalTime;
	this->ticketSeller = ticketSeller;
	
	pthread_t thread;
	
	// wait until arrival
	pthread_create(&thread, NULL, Customer::wait, this);
	cout << "Customer thread started\n";
	
}

void* Customer::wait(void *customerptr) {
	
	Customer* customer = static_cast<Customer *>(customerptr);
	cout << "customer waiting...\n";
	// wait until arrival
	sleep(customer->arrivalTime);
	cout << "customer arrived!";
	// upon arrival join ticket seller queue
	customer->ticketSeller->queue.push_back(*customer);
	
	// return nullptr because the compiler said so
	return nullptr;
}