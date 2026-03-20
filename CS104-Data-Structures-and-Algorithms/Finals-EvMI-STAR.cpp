//Bronilla, Evana Isabella 
//Julian, Mariah Judea 
//Llave, Isabella Mikaella
//CS104 - 2

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

struct Transaction {
    string receiver;
    double amount;
    int time;
    bool isCashOut;
};

unordered_map<string, vector<Transaction>> graph;
unordered_map<string, int> suspiciousCount;

int convertToMinutes(const string& timeStr) {
    int hours = stoi(timeStr.substr(0, 2));
    int minutes = stoi(timeStr.substr(3, 2));
    return hours * 60 + minutes;
}

string convertToHHMM(int totalMinutes) {
    int hour = totalMinutes / 60;
    int minute = totalMinutes % 60;
    stringstream ss;
    ss << setfill('0') << setw(2) << hour << ":" << setw(2) << minute;
    return ss.str();
}

void inputTransactions(int n) {
    for (int i = 1; i <= n; ++i) {
        string sender, receiver, timeStr, isCashOutStr;
        double amount;
        bool isCashOut;
        
        cout << "\nTransaction " << i << ":" << endl;
        cout << "Sender: "; cin >> sender;
        cout << "Receiver: "; cin >> receiver;
        cout << "Amount: "; cin >> amount;
        cout << "Time (HH:MM): "; cin >> timeStr;
        cout << "Is this a CASH-OUT? (yes/no): "; cin >> isCashOutStr;
        
        isCashOut = (isCashOutStr == "yes");
        int timeInMinutes = convertToMinutes(timeStr);
        graph[sender].push_back({receiver, amount, timeInMinutes, isCashOut});
    }
}

void saveTransactionsToCSV(const string& filename) {
    ofstream file(filename);
    file << "Sender,Receiver,Amount,Time (HH:MM),Cash-Out\n";
    for (const auto& [sender, txList] : graph) {
        for (const auto& tx : txList) {
            file << sender << "," << tx.receiver << "," << tx.amount << "," 
                 << convertToHHMM(tx.time) << "," << (tx.isCashOut ? "yes" : "no") << "\n";
        }
    }
    file.close();
}

void printBar(int length) {
    for (int i = 0; i < length; ++i) cout << "#";
    cout << endl;
}

void dfs(string current, vector<string>& path, int startTime, int& suspiciousPathCount) {
    path.push_back(current);

    if (graph.find(current) != graph.end()) {
        for (const auto& tx : graph[current]) {
            if (find(path.begin(), path.end(), tx.receiver) != path.end()) continue;

            int newStartTime = (startTime == -1) ? tx.time : startTime;
            int elapsedTime = tx.time - newStartTime;

            if (tx.isCashOut && (path.size() + 1) >= 4 && elapsedTime <= 30) {
                suspiciousPathCount++;
                suspiciousCount[path[0]]++;

                cout << "\nSuspicious Path #" << suspiciousPathCount << ": ";
                for (size_t i = 0; i < path.size(); ++i) {
                    cout << path[i] << " -> ";
                }
                cout << tx.receiver << " [" << elapsedTime << " mins]" << endl;
                printBar((path.size() + 1) * 10);
            }

            dfs(tx.receiver, path, newStartTime, suspiciousPathCount);
        }
    }
    path.pop_back();
}

void detectSuspiciousTransactions() {
    cout << "\nDetecting Suspicious Transactions..." << endl;
    int suspiciousPathCount = 0;

    for (const auto& [sender, _] : graph) {
        vector<string> path;
        dfs(sender, path, -1, suspiciousPathCount);
    }

    if (suspiciousPathCount == 0) {
        cout << "\nNo suspicious transactions found." << endl;
    }
}

void displaySuspiciousSummary() {
    cout << "\nSuspicious Transaction Count by User:" << endl;
    cout << "+-----------+--------------------------+" << endl;
    cout << "| USER      | Suspicious Paths         |" << endl;
    cout << "+-----------+--------------------------+" << endl;
    for (const auto& entry : suspiciousCount) {
        cout << "| " << setw(9) << left << entry.first
             << "| " << setw(25) << left << entry.second << "|" << endl;
    }
    cout << "+-----------+--------------------------+" << endl;
}

int main() {
    int numTransactions;
    cout << "Enter number of transactions: ";
    cin >> numTransactions;

    inputTransactions(numTransactions);
    detectSuspiciousTransactions();
    displaySuspiciousSummary();
    saveTransactionsToCSV("transactions.csv");
    
    cout << "\nAll transactions saved to 'transactions.csv'." << endl;

    return 0;
}
