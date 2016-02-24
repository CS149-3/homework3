//
//  Customer.h
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#pragma once
#include <iostream>
#include <unistd.h>
#include "TicketSeller.h"

using namespace std;

class TicketSeller;

class Customer {
	int arrivalTime;
	class TicketSeller* ticketSeller;
public:
	Customer(int arrivalTime, class TicketSeller* ticketSeller);
private:
	static void* wait(void*);
};

