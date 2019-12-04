#include <iostream>
#include <iterator>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

void print_vector(const vector<string>& v) {
    cout << '[';
    for (auto b : v) {
        cout << b << ", ";
    }
    cout << ']';
}


void dump(const map<string, string>& capitals) {
    if (capitals.empty()) {
        cout << "There are no countries in the world";
    } else {
        auto it = begin(capitals);
        cout << it->first << '/' << it->second;
        it++;
        for (; it != end(capitals); it++) {
            cout << ' ' << it->first << '/' << it->second;
        }
    }
    cout << endl;
}

bool is_palindrom(const string& word) {
    for (unsigned int i = 0; i < word.size() / 2; i++) {
        if (word[i] != word[word.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> result;
    auto predicate = [minLength](auto w) {return w.size() >= minLength && is_palindrom(w);};
    copy_if(begin(words), end(words), back_inserter(result), predicate);
    return result;
}

void add_route(
    map<string, vector<string>>& routes,
    const string& bus,
    const vector<string>& stops
) {
    vector<string> route = routes[bus];
    route.insert(end(route), begin(stops), end(stops));
}

void print_all_buses(map<string, vector<string>> routes) {
    for (auto& [bus, route] : routes) {
        cout << "Bus " << bus << ':';
        auto it = begin(route);
        for (auto stop : route) {
            cout << ' ' << stop;
        }
    }
}

void print_buses_for_stop(const string& stop, const set<string>& buses) {
    cout << "Stop " << stop << 
}

int main() {
    map<string, vector<string>> routes;
    unsigned int i;
    string operation;
    cin >> i;
    while (i--) {
        cin >> operation;
        if (operation == "ALL_BUSES")
    }
}
