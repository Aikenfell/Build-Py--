#include <iomanip>

#include "json.hpp"

#include <vector>

#include <string>

#include <time.h>

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
      std::ostream_iterator < int > (vts, ", "));

    vts << Builds.back();
  }

  std::cout << vts.str() << std::endl;
  return vts.str();
}

int main() {
  clock_t t;
  t = clock();
  std::ifstream ifs("CARR.json");
  std::cout << "1" << "\n";
  json j = json::parse(ifs);
  //for (json::iterator it = j["Head"].begin(); it != j["Head"].end(); ++it)
  //{
  //  std::cout << it.key() << " | " << it.value() << "\n";
  //}
  vector < vector < int > > Gear;
  vector < int > HeadR = j["Head"]; //.get<std::vector<int>>();
  vector < int > ChestR = j["Chest"];
  vector < int > LegsR = j["Legs"];
  vector < int > HandsR = j["Hands"];
  vector < int > WeaponR = j["Weapon"];
  vector < int > Perks = {
    6
  };
  vector < vector < int > > Builds;
  for (const int & He: Head) {
    for (const int & Ch: Chest) {
      for (const int & Le: Legs) {
        for (const int & Ha: Hands) {
          for (const int & We: Weapon) {
            vector < int > ASet = {
              j["IDs"][std::to_string(He)]["1"],
              j["IDs"][std::to_string(He)]["2"],
              j["IDs"][std::to_string(Ch)]["1"],
              j["IDs"][std::to_string(Ch)]["2"],
              j["IDs"][std::to_string(Le)]["1"],
              j["IDs"][std::to_string(Le)]["2"],
              j["IDs"][std::to_string(Ha)]["1"],
              j["IDs"][std::to_string(Ha)]["2"],
              j["IDs"][std::to_string(We)]["1"],
              j["IDs"][std::to_string(We)]["2"],
              j["IDs"][std::to_string(We)]["3"]
            };
/*             vector < int > AASet = {
              He,
              Ch,
              Le,
              Ha,
              We
            };*/
            if (std::find(ASet.begin(), ASet.end(), Perks[0]) != ASet.end())
              Builds.push_back(ASet);
//            if (std::find(ASet.begin(), ASet.end(), Perks[0]) != ASet.end())
  //            vecToStr(AASet);
            //else
              //vecToStr(ASet);
            //                                    vecToStr(ASet);
            //Builds.push_back(ASet);
            //                        cout << "Head: " << He.value() << "Chest: " << Ch << "Legs: " << Le << "Hands: " << Ha << "Weapon: " << We << endl;
          }
        }
      }
    }
  }

  t = clock() - t;
  printf("It took me %d clicks (%f seconds).\n", t, ((float) t) / CLOCKS_PER_SEC);
  return 0;
}