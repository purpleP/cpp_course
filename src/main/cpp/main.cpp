#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

void const print_vector(vector<bool>& v) {
    cerr << '[';
    for (auto b : v) {
        cerr << b << ", ";
    }
    cerr << ']';
}

int main() {
    vector<bool> queue;
    unsigned int opsCount;
    cin >> opsCount;
    string operation;
    int arg;
    while (opsCount--) {
        cin >> operation;
        if (operation == "COME") {
            cin >> arg;
            if (arg >= 0) {
                while (arg-- != 0) {
                    queue.push_back(false);
                }
            }
            else {
                while (arg++ != 0) {
                    queue.pop_back();
                }
            }
        }
        if (operation == "WORRY") {
            cin >> arg;
            queue[arg] = true;
        }
        if (operation == "WORRY_COUNT") {
            unsigned int count = accumulate(begin(queue), end(queue), 0);
            cout << count << endl;
        }
    }
}
