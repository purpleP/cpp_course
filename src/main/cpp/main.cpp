#include <iterator>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void const print_vector(vector<string>& v) {
    cout << '[';
    for (auto b : v) {
        cout << b << ", ";
    }
    cout << ']';
}

void const print_tasks(vector<string>& tasks) {
    cout << tasks.size();
    for (auto t : tasks) {
        cout << ' ' << t;
    }
    cout << endl;
}

int main() {
    unsigned int num_of_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unsigned int index = 0;
    unsigned int op_count;
    vector<vector<string>> month_tasks(31);
    month_tasks.assign(31, vector<string>());
    cin >> op_count;
    string operation;
    unsigned int day_no;
    while (op_count--) {
        cin >> operation;
        if (operation == "ADD") {
            string task;
            cin >> day_no >> task;
            month_tasks[day_no - 1].push_back(task);
        } else if (operation == "DUMP") {
            cin >> day_no;
            print_tasks(month_tasks[day_no - 1]);
        } else if (operation == "NEXT") {
            unsigned int old_days = num_of_days[index];
            index++;
            unsigned int new_days = num_of_days[index];
            int diff = new_days - old_days;
            if (diff > 0) {
                for (unsigned int i = 0; i < diff; i++) {
                    month_tasks.push_back(vector<string>());
                }
            } else if (diff < 0) {
                vector<string> last = month_tasks[new_days - 1];
                for (auto it = next(begin(month_tasks), new_days); it != end(month_tasks); it++) {
                    last.insert(end(last), begin(*it), end(*it));
                }
                for (int i = diff; i != 0; i++) {
                    month_tasks.pop_back();
                }
            }
        }
    }
    return 0;
}
