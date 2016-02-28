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
	bool seatFound = false;
	// search seats for an open seat according to the priority
	int c = 19;
	
	for(int row = 4; 20%c > 0;)
	{
		if(seatFound)
			break;
			
		for(int col = 0; col < 10; col++)
		{
				if(seats[row][col].length() == 0)//empty
				{
					seats[row][col] = customerName; //add customer to matrix
					seatFound = true;
					break;
				}
		}
		
		if((20%c)%2 == 0)
		{
				row -= 20%c;
		}
		else
		{
				row += 20%c;
		}
		c--;
	}
	
	// if an open seat is found, place the customer there (customerName)
	if (seatFound) {
		cout << this->timer->currentTime() << " " << customerName << " was assigned a seat\n";
		return true;
	}
	else {
	// else sold out
		cout << timer->currentTime() << " " << customerName << " was told the concert is sold out\n";
		return false;
	}
}
