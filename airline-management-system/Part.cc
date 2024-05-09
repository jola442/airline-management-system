
#include "Part.h"

Part::Part(const string& name){
    this->name = name;
    flightHours = 0;
}

Part :: ~Part(){}

string Part :: getName(){return name;}

void Part :: addFlightHours(int h){flightHours += h;}

void Part :: install (Date& d){
    installationDate = d;
}

void Part::print(ostream& output){
    output << "Name:          "   << name << endl;
    output << "Flight Hours:  "  <<  flightHours  <<endl;
    output << "Installed on:  "  <<  installationDate;
}   


FH_Part::FH_Part(const string& name, int hours): Part(name){
    fh_inspect = hours;
}

// FH_Part :: ~FH_Part(){}



bool FH_Part:: inspection(Date& inspDate){return flightHours >= fh_inspect;}

void FH_Part::print(ostream& output){
    Part::print(output);
    output << "Inspect every: " << fh_inspect << " flight hours" << endl;
}

IT_Part::IT_Part(const string& name, int days): Part(name){
    it_inspect = days;
}

// IT_Part :: ~IT_Part(){}

bool IT_Part:: inspection(Date& inspDate){
    return (inspDate.toDays()-installationDate.toDays()) >= it_inspect;
}

void IT_Part::print(ostream& output){
  Part::print(output);
  output << "Inspect every: " << it_inspect << " days installed" << endl;
}

FHIT_Part::FHIT_Part(const string& name, int fHours, int itHours): Part(name), FH_Part(name, fHours), IT_Part(name, itHours){
}

// FHIT_Part :: ~FHIT_Part(){}

bool FHIT_Part:: inspection(Date& inspDate){
    return IT_Part :: inspection(inspDate) || FH_Part :: inspection(inspDate);
}

void FHIT_Part::print(ostream& output){
    IT_Part::print(output);
    output << "Inspect every: " << fh_inspect << " flight hours" << endl;
}

ostream& operator<<(ostream& output, Part& p){
    p.print(output);
    return output << endl;
}



