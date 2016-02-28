//
//  main.cpp
//  homework3
//
//  Created by Johnathon Ludeman on 2/23/16.
//  Copyright (c) 2016 Group 3. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>

#include "LowTicketSeller.h"
#include "MediumTicketSeller.h"
#include "HighTicketSeller.h"
#include "Customer.h"
#include "Timer.h"

using namespace std;

//typedef string seat_array[10][10];

int main(int argc, const char * argv[]) {
	// randomizer for random int generation
	srand (time(NULL));
	
	// mutex for output
	pthread_mutex_t cout_mutex;
	pthread_mutex_init(&cout_mutex, 0);
	
	// initialize empty array of seats
	string seats[10][10] = {};
	
	// get command line arg for customers per seller
	int customersPerSeller = argc >= 2 && isdigit(*argv[1]) ? strtol(argv[1], nullptr, 10) : 5;
	
	// create timer
	Timer* timer = new Timer();
	
	// initialize ticket sellers
	TicketSeller::setCoutMutex(&cout_mutex);
	TicketSeller::setTimer(timer);
	
	TicketSeller* H = new HighTicketSeller("H", seats);
	
	TicketSeller* M1 = new MediumTicketSeller("M1", seats);
	TicketSeller* M2 = new MediumTicketSeller("M2", seats);
	TicketSeller* M3 = new MediumTicketSeller("M3", seats);
	
	TicketSeller* L1 = new LowTicketSeller("L1", seats);
	TicketSeller* L2 = new LowTicketSeller("L2", seats);
	TicketSeller* L3 = new LowTicketSeller("L3", seats);
	TicketSeller* L4 = new LowTicketSeller("L4", seats);
	TicketSeller* L5 = new LowTicketSeller("L5", seats);
	TicketSeller* L6 = new LowTicketSeller("L6", seats);
	
	// initialize customers, whose number should be based on customers per seller
	for (int i = 1; i < customersPerSeller; i++) {
		string current_count_str = i <= 10 ? string("0") + to_string(i) : to_string(i);
		
		Customer::setCoutMutex(&cout_mutex);
		Customer::setTimer(timer);
		
		new Customer("H0" + current_count_str, rand() % 60, H);
		
		new Customer("M1" + current_count_str, rand() % 60, M1);
		new Customer("M2" + current_count_str, rand() % 60, M2);
		new Customer("M3" + current_count_str, rand() % 60, M3);
		
		new Customer("L1" + current_count_str, rand() % 60, L1);
		new Customer("L2" + current_count_str, rand() % 60, L2);
		new Customer("L3" + current_count_str, rand() % 60, L3);
		new Customer("L4" + current_count_str, rand() % 60, L4);
		new Customer("L5" + current_count_str, rand() % 60, L5);
		new Customer("L6" + current_count_str, rand() % 60, L6);
	}
	
	// run main thread for 60 seconds, print new line each second (for testing)
	for (int i = 1; i < 60; i++) {
		pthread_mutex_lock(&cout_mutex);
		cout << "\n";
		pthread_mutex_unlock(&cout_mutex);
		sleep(1);
		timer->increment();
	}
	
	// output seats
	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			cout << "row " << i << ",col " << j << "  "<< seats[i][j] << endl;
		}
	}
	
	// clean up
	pthread_mutex_destroy(&cout_mutex);
	
    return 0;
}
