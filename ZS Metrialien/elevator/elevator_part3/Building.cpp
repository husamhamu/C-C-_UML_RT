#include "Building.hpp"

Building::Building(int numberOfFloors) {
    // add given number of floors
    while (numberOfFloors-- > 0) {
        floors.push_back(Floor());
    }
}

int Building::getNumberOfFLoors() const {
    return floors.size();
}

const Floor& Building::getFloor(int floor) const {
    return floors.at(floor);
}


const Elevator& Building::getElevator() const {
    return elevator;
}

void Building::letPeopleIn() {
    elevator.addPeople(floors.at(elevator.getFloor()).removeAllPeople());
}

std::list<PersonPtr> Building::removeArrivedPeople() {
    return elevator.removeArrivedPeople();
}

void Building::moveElevatorToFloor(int i) {
    elevator.moveToFloor(i);
}

void Building::addWaitingPerson(int floor, PersonPtr p) {
    floors.at(floor).addWaitingPerson(p);
}

bool Building::containsPeople() const {
    if (elevator.getContainedPeople().size() > 0) {
        return true;
    }
    for (int i = 0; i < getNumberOfFLoors(); ++i) {
        if (floors.at(i).getContainedPeople().size() > 0) {
            return true;
        }
    }
    return false;
}
