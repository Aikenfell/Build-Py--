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
    json j = json::parse(ifs);
    vector < vector < int > > Gear;
    vector < int > HeadR = j["Head"];
    vector < int > ChestR = j["Chest"];
    vector < int > LegsR = j["Legs"];
    vector < int > HandsR = j["Hands"];
    vector < int > WeaponR = j["Weapon"];
    vector < int > Perk = {
        3,
        48,
        3,
        48,
        3,
        48
    };
    vector < int > Test = {};
    vector < vector < int > > HeadP;
    vector < vector < int > > ChestP;
    vector < vector < int > > LegsP;
    vector < vector < int > > HandsP;
    vector < vector < int > > WeaponP;
    for (const int & He: HeadR) {
        for (const int & Pe: Perk) {
            if ((j["IDs"][std::to_string(He)]["1"] == Pe | j["IDs"][std::to_string(He)]["2"] == j["Cells"][std::to_string(Pe)])) {
                vector < int > ASet = {
                    j["IDs"][std::to_string(He)]["1"],
                    j["IDs"][std::to_string(He)]["2"]
                };
                Test.push_back(He);
                HeadP.push_back(ASet);
            }
        }
    }
    t = clock() - t;
    printf("It took me %d clicks (%f seconds).\n", t, ((float) t) / CLOCKS_PER_SEC);
    //    vecToStr(Test);
    for (const int & Ch: ChestR) {
        vector < int > ASet = {
            j["IDs"][std::to_string(Ch)]["1"],
            j["IDs"][std::to_string(Ch)]["2"]
        };
        ChestP.push_back(ASet);
    }
    for (const int & Le: LegsR) {
        vector < int > ASet = {
            j["IDs"][std::to_string(Le)]["1"],
            j["IDs"][std::to_string(Le)]["2"]
        };
        LegsP.push_back(ASet);
    }
    for (const int & Ha: HandsR) {
        vector < int > ASet = {
            j["IDs"][std::to_string(Ha)]["1"],
            j["IDs"][std::to_string(Ha)]["2"]
        };
        HandsP.push_back(ASet);
    }
    for (const int & We: WeaponR) {
        vector < int > ASet = {
            j["IDs"][std::to_string(We)]["1"],
            j["IDs"][std::to_string(We)]["2"],
            j["IDs"][std::to_string(We)]["3"]
        };
        WeaponP.push_back(ASet);
    }
    vector < int > Perks = {
        6
    };
    vector < vector < int > > Builds = {};
    int i = 0;
    for (vector < int > & He: HeadP) {
        vector < int > ASet = {
            He[0],
            He[1]
        };
        for (vector < int > & Ch: ChestP) {
            vector < int > BSet = ASet;
            BSet.push_back(Ch[0]);
            BSet.push_back(Ch[1]);
            for (vector < int > & Le: LegsP) {
                vector < int > CSet = BSet;
                CSet.push_back(Ch[0]);
                CSet.push_back(Ch[1]);
                for (vector < int > & Ha: HandsP) {
                    vector < int > DSet = CSet;
                    DSet.push_back(Ha[0]);
                    DSet.push_back(Ha[1]);
                    for (vector < int > & We: WeaponP) {
                        vector < int > ESet = DSet;
                        ESet.push_back(We[0]);
                        ESet.push_back(We[1]);
                        for (const int & Pe: Perk) {
                            if (std::find(ESet.begin(), ESet.end(), Pe) != ESet.end()) {
                                ++i;
                            } 
                            else {
                                break;
                            }

                            //cout << "Meh";

                        }
                        Builds.push_back(ESet);
                    };
                };
            };
        };
    };
    t = clock() - t;
    cout << i;
    //        for (vector < int > & GG: Builds) {
    //        vecToStr(GG);
    //}
    printf("It took me %d clicks (%f seconds).\n", t, ((float) t) / CLOCKS_PER_SEC);

    return 0;
}