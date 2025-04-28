#include "Floor.hpp"

Floor::Floor() {}

int Floor::getNumPeople() const {
    return containedPeople.size();
}

const std::list<PersonPtr>& Floor::getContainedPeople() const {
    return containedPeople;
}

void Floor::addWaitingPerson(PersonPtr h) {
    containedPeople.push_back(h);
}

std::list<PersonPtr> Floor::removeAllPeople() {
    std::list<PersonPtr> people = containedPeople;
    containedPeople.clear();
    return people;
}
