#include <iostream>
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

void rename(
    map<string, string>& capitals,
    const string& old_name,
    const string& new_name
) {
    string msg = "Incorrect rename, skip";
    if (old_name == new_name) {cout << msg << endl; return;}
    if (capitals.find(new_name)->first == new_name) {cout << msg << endl; return;}
    auto it = capitals.find(old_name);
    if (it == end(capitals)) { cout << msg << endl; return;}
    string capital = it->second;
    capitals.erase(it);
    capitals[new_name] = capital;
    cout
        << "Country " << old_name
        << " with capital " << it->second
        << " has been renamed to " << new_name
        << endl;
}

void insert_or_update(
    map<string, string>& capitals,
    const string& country,
    const string& new_capital
) {
    auto [it, inserted] = capitals.insert({country, new_capital});
    if (inserted) {
        cout << "Introduce new country " << country << " with capital " << new_capital;
    } else {
        string old_capital = it->second;
        cout << "Country " << country;
        if (old_capital == new_capital) {
            cout << " hasn't changed its capital";
        } else {
            cout
                << " has changed its capital from " << old_capital
                << " to " << new_capital;
        }
        it->second = new_capital;
    }
    cout << endl;
}

void about(const map<string, string>& capitals, const string& country) {
    auto it = capitals.find(country);
    cout << "Country " << country;
    if (it == end(capitals)) {
        cout << " doesn't exist";
    } else {
        cout << " has capital " << it->second;
    }
    cout << endl;
}


int main() {
    unsigned int n;
    map<string, string> capitals;
    cin >> n;
    while (n--) {
        string cmd;
        cin >> cmd;
        if (cmd == "CHANGE_CAPITAL") {
            string country, capital;
            cin >> country >> capital;
            insert_or_update(capitals, country, capital);
        } else if (cmd == "RENAME") {
            string from, to;
            cin >> from >> to;
            rename(capitals, from, to);
        } else if (cmd == "ABOUT") {
            string country;
            cin >> country;
            about(capitals, country);
        } else if (cmd == "DUMP") {
            dump(capitals);
        }
    }
}
