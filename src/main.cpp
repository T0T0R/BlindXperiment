#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

#include "main.h"
#include "group.h"




int main(){
	std::random_device rd {};

	int nbGroups {0};
	std::string nullvar{""};

	std::cout<<"How many groups do you want to conduct an experiment on ?"<<std::endl;
	std::cin>>nbGroups;

	std::vector<Group> groups;
	fillVector(groups, nbGroups);

	std::cout<<"Enter names of groups"<<std::endl;
	associateGroups(groups, rd);
	toText(groups);	//Saves correlation in a file, just in case...
	
	std::cout<<"\nHere are the new random labels"<<std::endl;
	std::cout<<"Make sure to ERASE or to FORGET (I dunno, just find a way) actual real names,"<<std::endl;
	std::cout<<"and replace them with these random numbers:\n"<<std::endl;

	displayCorrelation(groups,false);

	std::cout<<"When you are done, type any character and press enter"<<std::endl;
	std::cin>>nullvar;
	cls();


	std::cout<<"You can now do your experiment with meaningless labels for your groups."<<std::endl;
	std::cout<<"When you are done, type any character and press enter to see correlation again"<<std::endl;
	std::cin>>nullvar;
	displayCorrelation(groups, true);
}



void fillVector(std::vector<Group> &groups, int const nbGroups){
	//Fills Vector with empty Group objects
	for (int i{0}; i<nbGroups; i++){
		groups.push_back(Group());
	}
}


bool isIn(int number, std::vector<int> table){
	//Test if a number is present in a Vector
	for (unsigned int i{0}; i<table.size(); i++){
		if (number==table[i]){return true;}
	}
	return false;
}


void associateGroups(std::vector<Group> &groups, std::random_device &rd){
	//Associates the name given by the experimenter to a random number
	std::vector<int> numbersUsed;
	for (unsigned int i {0}; i<groups.size(); i++) {
		int tempNumber { randomIndex(1, groups.size()+1, rd)};
		if (i!=0){	//Check if this number is not already linked to another group
			while (isIn(tempNumber, numbersUsed)){
				tempNumber = randomIndex(1, groups.size()+1, rd);
			}
		}

		numbersUsed.push_back(tempNumber);
		groups[i].setNumber(tempNumber);

		std::string groupName {""};
		std::cin>>groupName;
		groups[i].setString(groupName);
	}
}


int randomIndex(int a, int b, std::random_device &rd){
	//Return a random in number between a (included) and b (excluded)
	return a+rd()%(b-a);
}


void toText(std::vector<Group> &groups){
	//Write correlation in a text file in case software crashes
	std::ofstream outputFile("groups.txt", std::ofstream::out|std::ofstream::trunc);
	outputFile << "Group number | Group name\n";

	for (unsigned int i{0}; i<groups.size(); i++){
		outputFile <<groups[i].getNumber()<<"\t"<<groups[i].getString()<<"\n";
	}
	outputFile.close();
}

void displayCorrelation(std::vector<Group> &groups, bool reverse){
	for (unsigned int i {0}; i<groups.size(); i++) {
		if (reverse){
			std::cout<<"NUMBER: "<<groups[i].getNumber()<<"\t=\t"<<groups[i].getString()<<"\n";
		}else{
			std::cout<<"NAME: "<<groups[i].getString()<<"\t=\t"<<groups[i].getNumber()<<"\n";
		}
	}
}


void cls(){
	for (int i{0}; i<100; i++){std::cout<<std::endl;}
}