
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Part.h"
// #include "defs.h"
#include "Array.h"


using namespace std;

class Aircraft {
	friend ostream& operator<<(ostream& out, Aircraft& a);
	public:
		//constructor
		Aircraft(const string& t, const string& reg);
		
		//getters
		string getRegistration();

		//other member functions
		void install(Part* p, Date& d);
		void takeFlight(int hours);
		void inspectionReport(Date d, Array<Part*>& pts);
		
	
	private:
		string type;
		string registration;
		int flightHours;
		Array<Part*> parts;
	
	
};
#endif