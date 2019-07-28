// Builder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <iomanip>

#include "json.hpp"

#include <vector>

#include <string>

#include <unordered_map>

#include <map>

#include <algorithm>

#include <sstream>

#include <iterator>

#include <iostream>

#include <fstream>

using namespace std;
using json = nlohmann::json;

std::string vecToStr(std::vector < int > Builds) {
	std::ostringstream vts;

	if (!Builds.empty()) {
		std::copy(Builds.begin(), Builds.end() - 1,
			std::ostream_iterator < int >(vts, ", "));

		vts << Builds.back();
	}

	std::cout << vts.str() << std::endl;
	return vts.str();
}

int main() {

	std::ifstream ifs("CArray.json");
	std::cout << "1" << "\n";
	json j = json::parse(ifs);
	std::cout << "2" << "\n";
	vector < vector < int > > Gear;
	std::cout << "3" << "\n";
//	vector < int > HH = j["Head"].get();
	std::cout << "4" << "\n";
	//vecToStr(HH);
	std::cout << "5" << "\n";
	std::cout << "Testyyy" << "\n";
	for (auto it = j["IDs"].begin(); it != j["IDs"].end(); ++it) {
		vector < int > test = {
		  it.value()["1"],
		  it.value()["2"],
		  it.value()["3"]
		};
		//        std::cout <<   << "\n";
		//        vecToStr(test);
		Gear.push_back(test);
		//strfunct(test);
		//        std::string itt = vecToStr(test);
	 /*    for (vector < int > & GG: Gear) {
		  vecToStr(GG);
		  std::cout << j["Head"];
		}*/
	}

	//  vector < vector < int > > Builds;
	/*             cout << Weapon[1] << endl;
				for (int & He: Head) {
					for (int & Ch: Chest) {
						for (int & Le: Legs) {
							for (int & Ha: Hands) {
								for (int & We: Weapon) {
									vector < int > ASet = {
										He,
										Ch,
										Le,
										Ha,
										We
									};
									Builds.push_back(ASet);
									//                        cout << "Head: " << He << "Chest: " << Ch << "Legs: " << Le << "Hands: " << Ha << "Weapon: " << We << endl;
								}
							}
						}
					}
				}
	 */
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
