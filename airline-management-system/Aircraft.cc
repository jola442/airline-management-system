
#include "Aircraft.h"

Aircraft::Aircraft(const string& t, const string& reg){
    registration = reg;
    type = t;
    flightHours = 0;
}

string Aircraft :: getRegistration(){return registration;}

void Aircraft ::install(Part* p, Date& d){
    if(parts.getSize() < MAX_ARR){
        p->install(d);
        parts.add(p);
    }
}

void Aircraft ::takeFlight(int hours){
    flightHours += hours;
    for(int i = 0; i < parts.getSize(); ++i){
        parts[i]->addFlightHours(hours);
    }
}
void Aircraft ::inspectionReport(Date d, Array<Part*>& pts){
    for(int i = 0; i < parts.getSize(); ++i){
        if(parts[i]->inspection(d)){
            pts.add(parts[i]);
        }
    }
}


ostream& operator<<(ostream& out, Aircraft& a){
    out << "Aircraft: " << a.type << endl;
    out << "Registration: " << a.registration << endl << endl;
    return out;
}