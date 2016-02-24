//
//  MediumTicketSeller.h
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#pragma once
#include <iostream>
#include "TicketSeller.h"

class MediumTicketSeller : public TicketSeller
{
public:
	MediumTicketSeller();
private:
	void start();
	static void* sellTickets(void*);
};