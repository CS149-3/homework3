//
//  main.cpp
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <ctype.h>

#include "TicketSeller.h"
#include "Customer.h"

using namespace std;

int main(int argc, const char * argv[]) {
	
	// get command line arg for customers per seller
	int customersPerSeller = argc >= 2 && isdigit(*argv[1]) ? strtol(argv[1], nullptr, 10) : 5;
	// debug print
	cout << "Hello, World! customersPerSeller=" << to_string(customersPerSeller) << "\n";
	
	// initialize ticket sellers
	
	
	// initialize customers, whose number should be based on customers per seller
	for (int i = 0; i < customersPerSeller; i++) {
		
	}
	
	// PROOF OF CONCEPTish EXAMPLE
	
	cout << "building customer...\n";
	Customer* test = new Customer(3, new TicketSeller());
	for (int i = 1; i < 6; i++) {
		cout << "\n";
		sleep(1);
	}
	
	// END EXAMPLE
	
    return 0;
}