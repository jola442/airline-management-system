
#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Array.h"
#include "Aircraft.h"

using namespace std;

class Airline {
		
	public:
		//constructor
		Airline(const string& n);
		
		//destructor
		~Airline();

		//other member functions
		void addAircraft(const string& t, const string& reg);
		void addPart(const string& part, int fh_inspect, int it_inspect);
		void takeFlight(const string& reg, int hours);
		void printAircraft();
		void printParts();
		void inspectionReport(const string& reg, Date& d);
		bool install(const string& reg, const string& partName, Date& d);
	
	private:
		string name;
		Array<Part*> parts;
		Array<Aircraft*> aircraftArr;
		Aircraft* getAircraft(string reg);
		Part* getPart(string name);
	
};
#endif