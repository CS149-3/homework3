//
//  LowTicketSeller.h
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#pragma once
#include <iostream>
#include "TicketSeller.h"

class LowTicketSeller : public TicketSeller
{
public:
	LowTicketSeller();
private:
	void start();
	static void* sellTickets(void*);
};