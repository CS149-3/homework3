//
//  TicketSeller.cpp
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#include <pthread.h>
#include "TicketSeller.h"

Timer* TicketSeller::timer = nullptr;

TicketSeller::TicketSeller(string name, seat_matrix* seats) {
	this->name = name;
	this->seats = seats;
	this->start();
}

void TicketSeller::setTimer(class Timer* timer) {
	TicketSeller::timer = timer;
}

void TicketSeller::start() {
	pthread_t thread;
	pthread_create(&thread, NULL, TicketSeller::sellTickets, this);
}

void* TicketSeller::sellTickets(void *ticketsellerptr) {
	TicketSeller* ticketSeller = static_cast<TicketSeller *>(ticketsellerptr);
	vector<Customer>* queue = &(ticketSeller->queue);
	seat_matrix* seats = ticketSeller->seats;
	Timer* timer = ticketSeller->timer;
	
	int time = 0;
	while (time < 60) {
		if (queue->empty()) {
			// if no one in queue, wait one minute
			sleep(1);
			time++;
		}
		else {
			Customer* currentCustomer = &(queue->front());
			
			// check for and attempt to assign customer to a seat
			bool seatAvailable = ticketSeller->assignSeat(currentCustomer->name);
			
			if (seatAvailable) {
				
				// spend time selling ticket (this will vary by subclass)
				sleep(ticketSeller->sellTime());
				time += ticketSeller->sellTime();
				cout << timer->currentTime() << " " << currentCustomer->name << " completed purchase\n";
			}
			
			// remove Customer from queue
			queue->erase(queue->begin());
			cout << timer->currentTime() << " " << currentCustomer->name << " left\n";
		}
	}
	// return nullptr because the compiler said so
	return nullptr;
	
}