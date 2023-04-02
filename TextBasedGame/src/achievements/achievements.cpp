#include "achievements.h"

Achievements::Achievements(){}
Achievements::~Achievements(){}

void Achievements::setName( string name ){ 
    this->name = name;}

std::string Achievements::getName(){
    return this->name;}