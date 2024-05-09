
#ifndef PART_H
#define PART_H

#include "Date.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Part{
		
	friend ostream& operator<<(ostream& output, Part&);
	public:
		//constructor
		Part(const string& name);
		
		//destructor
		virtual ~Part();

		//getters
		string getName();

		//setters
		void setName(const string& name);

		//other member functions
		void addFlightHours(int h);
		void install(Date& d);

		//virtual functions
		virtual void print(ostream& output);
		virtual bool inspection(Date& inspDate) = 0;
	
	protected:
		string name;
		int flightHours;
		Date installationDate;
};

class FH_Part : public virtual Part{
	public:
		//constructor
		FH_Part(const string& name, int hours);
		// virtual ~FH_Part();


		//virtual functions
		virtual bool inspection(Date& inspDate);
		virtual void print(ostream& output);
	protected:
		int fh_inspect;


};

class IT_Part : virtual public Part{
	public:
		//constructor
		IT_Part(const string& name, int days);
		// virtual ~IT_Part();
		//virtual functions
		virtual bool inspection(Date& inspDate);
		virtual void print(ostream& output);
	protected:
		int it_inspect;


};

class FHIT_Part : public FH_Part, IT_Part{
	public:
		//constructor
		FHIT_Part(const string& name, int fHours, int itHours);
		// virtual ~FHIT_Part();

		//virtual functions
		virtual bool inspection(Date& inspDate);
		virtual void print(ostream& output);

};
#endif