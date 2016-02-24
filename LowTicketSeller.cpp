//
//  LowTicketSeller.cpp
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#include <pthread.h>
#include "LowTicketSeller.h"

LowTicketSeller::LowTicketSeller() {
	
}

void LowTicketSeller::start() {
	pthread_t thread;
	pthread_create(&thread, NULL, LowTicketSeller::sellTickets, this);
}

void* LowTicketSeller::sellTickets(void *ticketsellerptr) {
	
	vector<Customer> queue = static_cast<TicketSeller *>(ticketsellerptr)->queue;
	
	// example from here down, we need to have this run for 60 sleep cycles total, not get null from start of queue, etc.
	
	Customer* currentCustomer = &queue.front();
	
	// spend time selling ticket (this will vary by subclass)
	sleep(1);
	
	// assign seat to Customer
	
	
	// remove Customer from queue
	queue.erase(queue.begin());
	
	// return nullptr because the compiler said so
	return nullptr;
}