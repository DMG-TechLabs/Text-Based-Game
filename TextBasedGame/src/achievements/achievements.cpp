#include "achievements.h"

//Constructors
Achievements::Achievements(){}

Achievements::~Achievements(){}

//Setters getters
void Achievements::setName( string name ){ 
    this->name = name;}

std::string Achievements::getName(){
    return this->name;}