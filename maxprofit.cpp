#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct Property {
    char type;     
    int buildTime; 
    int earning;   
};

tuple<int, vector<pair<char, int>>> calculateMaxEarnings(int timeUnit) {
    vector<Property> properties = {
        {'T', 5, 1500},
        {'P', 4, 1000},
        {'C', 10, 3000}
    };

    int maxEarnings = 0;
    vector<pair<char, int>> propertyMix;

    for (const auto& prop : properties) {
        int numProperties = timeUnit / prop.buildTime;
        int earnings = numProperties * prop.earning;
        propertyMix.push_back({prop.type, numProperties});

        if (earnings > maxEarnings) {
            maxEarnings = earnings;
        }
    }

    return make_tuple(maxEarnings, propertyMix);
}

void printSolutions(int timeUnit, int maxEarnings, const vector<pair<char, int>>& propertyMix) {
    cout << "Time Unit: " << timeUnit << endl;
    cout << "Earnings: $" << maxEarnings << endl;
    cout << "Solutions:" << endl;
    for (const auto& property : propertyMix) {
        cout << property.first << ": " << property.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> testCases = {7, 8, 13};
    for (int timeUnit : testCases) {
        int maxEarnings;
        vector<pair<char, int>> propertyMix;
        tie(maxEarnings, propertyMix) = calculateMaxEarnings(timeUnit);
        printSolutions(timeUnit, maxEarnings, propertyMix);
    }

    return 0;
}
