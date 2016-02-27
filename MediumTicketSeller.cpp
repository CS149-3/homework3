//
//  MediumTicketSeller.cpp
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#include "MediumTicketSeller.h"

MediumTicketSeller::MediumTicketSeller(string name, seat_matrix* seats) : TicketSeller(name, seats) {
	
}

int MediumTicketSeller::sellTime() {
	return rand() % 3 + 2;
}

bool MediumTicketSeller::assignSeat(string customerName) {
	
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