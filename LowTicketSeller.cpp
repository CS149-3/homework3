//
//  LowTicketSeller.cpp
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#include "LowTicketSeller.h"

LowTicketSeller::LowTicketSeller(string name, seat_matrix* seats) : TicketSeller(name, seats) {
	
}

int LowTicketSeller::sellTime() {
	return rand() % 4 + 4;
}

bool LowTicketSeller::assignSeat(string customerName) {
	
	// search seats for an open seat according to the priority
	
	
	// if an open seat is found, place the customer there (customerName)
	if (true) {
		cout << this->timer->currentTime() << " " << customerName << " was assigned a seat\n";
		return true;
	}
	else {
		// else sold out
		cout << timer->currentTime() << " " << customerName << " was told the concert is sold out\n";
		return false;
	}
}