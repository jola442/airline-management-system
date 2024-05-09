
#include "Airline.h"

Airline::Airline(const string& n){
    name = n;
}

Airline::~Airline(){
    for(int i = 0; i < parts.getSize(); ++i){
        delete parts[i];
    }
    // printParts();

    for(int i = 0; i < aircraftArr.getSize(); ++i){
        delete aircraftArr[i];
    }

    


}

void Airline :: addAircraft(const string& t, const string& reg){
    Aircraft* newAircraft = new Aircraft(t, reg);
    aircraftArr.add(newAircraft);
}


void Airline :: addPart(const string& part, int fh_inspect, int it_inspect){
    Part* newPart;
    if(fh_inspect == 0){
        newPart = new IT_Part(part, it_inspect);
    }

    else if(it_inspect == 0){
        newPart = new FH_Part(part, fh_inspect);
    }

    else{
        newPart = new FHIT_Part(part, fh_inspect, it_inspect);
    }
    parts.add(newPart);



}

Aircraft* Airline ::getAircraft(string reg){
    for(int i = 0; i < aircraftArr.getSize(); ++i){
        if(aircraftArr[i]->getRegistration() == reg){
            return aircraftArr[i];
        }
    }
    return NULL;
}


Part* Airline ::getPart(string name){
    for(int i = 0; i < parts.getSize(); ++i){
        if(parts[i]->getName() == name){
            return parts[i];
        }
    }
    return NULL;
}

void Airline :: takeFlight(const string& reg, int hours){
    Aircraft* aircraft = getAircraft(reg);
    if(aircraft != NULL){aircraft->takeFlight(hours);}
}

void Airline :: printAircraft(){
    for(int i = 0; i < aircraftArr.getSize(); ++i){
        cout << *(aircraftArr[i]);
    }
}

void Airline :: printParts(){
    for(int i = 0; i < parts.getSize(); ++i){
        cout << *(parts[i]);
    }
}

void Airline :: inspectionReport(const string& reg, Date& d){
    Aircraft* aircraft = getAircraft(reg);
    Array<Part*> forInspection;
    if(aircraft != NULL){
        cout << "Registration: " << aircraft->getRegistration() << endl;
        aircraft->inspectionReport(d, forInspection);
        if(!forInspection.isEmpty()){
            cout << forInspection;
        }
    }
}

bool Airline :: install(const string& reg, const string& partName, Date& d){
    Aircraft* aircraft = getAircraft(reg);
    Part* part = getPart(partName);
    if(aircraft != NULL && part != NULL){
        aircraft->install(part, d);
        return true;
    }
    return false;
}