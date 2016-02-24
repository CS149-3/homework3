//
//  TicketSeller.h
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#pragma once
#include <iostream>
#include <vector>
#include "Customer.h"

using namespace std;

class Customer;

class TicketSeller {
public:
	vector<Customer> queue;
	TicketSeller();
private:
	virtual void start();
	static void* sellTickets(void*);
};