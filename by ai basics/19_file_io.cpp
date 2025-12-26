/*
 * C++ FILE I/O - Essential for Testing DSA
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    // === WRITING ===
    ofstream out("output.txt");
    out << "Hello World\n";
    out << 42 << " " << 3.14 << endl;
    out.close();
    
    // Append mode
    ofstream append("output.txt", ios::app);
    append << "Appended line\n";
    append.close();
    
    // === READING ===
    // Line by line
    ifstream in("output.txt");
    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();
    
    // Read numbers into vector
    ofstream numFile("nums.txt");
    numFile << "5\n1 2 3 4 5\n";
    numFile.close();
    
    ifstream numIn("nums.txt");
    int n;
    numIn >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) numIn >> arr[i];
    numIn.close();
    
    cout << "Vector: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // === FOR COMPETITIVE PROGRAMMING ===
    // Redirect stdin/stdout:
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    return 0;
}

/*
 * REFERENCE:
 * ofstream - write
 * ifstream - read
 * fstream  - both
 * 
 * ios::app - append
 * ios::binary - binary mode
 * 
 * getline(stream, str) - read line
 * stream >> var - read value
 * stream << val - write value
 */
