#pragma once

#include <vector>

#include "group.h"

void fillVector(std::vector<Group> &groups, int const nbGroups); 

bool isIn(int number, std::vector<int> table);

void associateGroups(std::vector<Group> &groups, std::random_device &rd);

int randomIndex(int a, int b, std::random_device &rd);

void toText(std::vector<Group> &groups);

void displayCorrelation(std::vector<Group> &groups, bool reverse);

void cls();