//
//  LowTicketSeller.h
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#pragma once
#include "TicketSeller.h"

class LowTicketSeller : public TicketSeller
{
public:
	static int ticketsSold;
	LowTicketSeller(string name, seat_matrix* seats);
	virtual int sellTime();
	virtual bool assignSeat(string customerName);
};