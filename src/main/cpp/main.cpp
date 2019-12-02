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

void update_state(
    vector<vector<string>>& state,
    unsigned short old_num_of_days,
    unsigned short num_of_days
) {
    short diff = num_of_days - old_num_of_days;
    if (diff == 0) { return; }
    if (diff > 0) {
        while (diff--) {
            state.push_back(vector<string>());
        }
    } else {
        vector<string>& temp = state[num_of_days - 1];
        for (unsigned int i = num_of_days; i < state.size(); ++i) {
            temp.insert(end(temp), begin(state[i]), end(state[i]));
        }
        while (diff++) {
            state.pop_back();
        }
    }
}

int main() {
    unsigned short num_of_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unsigned short index = 0;
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
            if (index == 11) { continue;}
            unsigned short old_num_of_days = num_of_days[index];
            update_state(month_tasks, old_num_of_days, num_of_days[++index]);
        }
    }
    return 0;
}
