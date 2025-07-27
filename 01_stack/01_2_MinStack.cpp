#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> min_s;

public:
    void push(int val) {
        s.push(val);
        if (min_s.empty() || val <= min_s.top()) {
            min_s.push(val);
        }
    }

    void pop() {
        if (!s.empty()) {
            if (s.top() == min_s.top()) {
                min_s.pop();
            }
            s.pop();
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_s.top();
    }

    bool empty() {
        return s.empty();
    }
};

// Helper function to print a row with fixed width columns
void printRow(const string& op, const string& topVal, const string& minVal) {
    cout << left << setw(15) << op
         << setw(15) << topVal
         << setw(15) << minVal << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    MinStack st;

    // Print table header
    cout << setw(15) << left << "Operation" 
         << setw(15) << "Top"
         << setw(15) << "Min" << "\n";
    cout << string(45, '-') << "\n";

    st.push(3);
    printRow("push(3)", to_string(st.top()), to_string(st.getMin()));

    st.push(5);
    printRow("push(5)", to_string(st.top()), to_string(st.getMin()));

    printRow("getMin()", "-", to_string(st.getMin()));

    st.push(2);
    printRow("push(2)", to_string(st.top()), to_string(st.getMin()));

    st.push(2);
    printRow("push(2)", to_string(st.top()), to_string(st.getMin()));

    st.pop();
    printRow("pop()", st.empty() ? "-" : to_string(st.top()), st.empty() ? "-" : to_string(st.getMin()));

    printRow("getMin()", "-", to_string(st.getMin()));

    st.pop();
    printRow("pop()", st.empty() ? "-" : to_string(st.top()), st.empty() ? "-" : to_string(st.getMin()));

    printRow("top()", st.empty() ? "-" : to_string(st.top()), st.empty() ? "-" : to_string(st.getMin()));

    return 0;
}
