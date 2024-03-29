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
    vector < int > Head = j["Head"];
    vector < int > Chest = j["Chest"];
    vector < int > Legs = j["Legs"];
    vector < int > Hands = j["Hands"];
    vector < int > Weapon = j["Weapon"];
    vecToStr(Hands);

//    for (auto it = j["IDs"].begin(); it != j["IDs"].end(); ++it) {
  //      vector < int > test = {
    //        it.value()["1"],
      //      it.value()["2"],
        //    it.value()["3"]
       // };
       // vecToStr(test);
       // Gear.push_back(test);
        //strfunct(test);
        //        std::string itt = vecToStr(test);
        /*    for (vector < int > & GG: Gear) {
             vecToStr(GG);
             std::cout << j["Head"];
           }*/
   // };

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
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    return 0;
}