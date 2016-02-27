//
//  HighTicketSeller.cpp
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#include "HighTicketSeller.h"


HighTicketSeller::HighTicketSeller(string name, seat_matrix* seats) : TicketSeller(name, seats) {
	
}

int HighTicketSeller::sellTime() {
	return rand() % 2 + 1;
}

bool HighTicketSeller::assignSeat(string customerName) {
	bool foundSeat = false;
	
	// search seats for an open seat according to the priority
	for(int row = 0; row < 10; row++)
	{
		if(foundSeat)
			break;
		for(int col = 0; col < 10; col++)
		{
			if(seats[row][col].length() == 0)//empty
			{
				seats[row][col] = customerName;//add customer to matrix
				foundSeat = true;
				break;
			}
			
		}
	}
		
	// if an open seat is found, place the customer there (customerName)
	if (foundSeat) {
		cout << this->timer->currentTime() << " " << customerName << " was assigned a seat\n";
		return true;
	}
	else {
		// else sold out
		cout << timer->currentTime() << " " << customerName << " was told the concert is sold out\n";
		return false;
	}
}
