/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/27/2020 at 10:50 PM
 * 
 * Chapter21_Drill_Map.cc
 * 
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;


void read_to_msi(map<string, int> &msi, int amount){
    int temp_int;
    string temp_string;
    
    for (int i = 0; i < amount && (cin >> temp_string >> temp_int); i++){
		msi[temp_string] = temp_int;
    }

}

int main(void){
    // Define a map<string, int> called msi
    map<string, int> msi;
    // Insert ten (name, value) pairs into it. (e.g msi["lecture"] = 21)
    msi["book"] = 1;
    msi["alphabet"] = 2;
    msi["steak"] = 3;
    msi["bagel"] = 4;
    msi["Pepperoni Pizza"] = 5;
    msi["Wine"] = 6;
    msi["Sake"] = 7;
    msi["bread"] = 8;
    msi["Ramen"] = 9;
    msi["Soda Water"] = 10;

    // Output the (name, value) pairs to cout in some format of your choice.
    for (auto &i : msi)
		cout << "Item: " << i.first << "\tValue: " << i.second << endl;
    
    // Erase the (name, values pairs from msi:
    msi.erase("book");
    msi.erase("alphabet");
    
    // Write a function that reads value pairs from cin and places them in msi:
    cout << "Please enter pairs of <string, int> (10 times):" << endl;
    // Read ten pairs from input and enter them into msi.
    read_to_msi(msi, 10);
    // Write the elements of msi to cout.
    for (auto &i : msi)
		cout << "Item': " << i.first << "\tValue: " << i.second << endl;
    
    // Output the sum of the integer values in msi
    int val{0};
    val = accumulate(msi.begin(), msi.end(), val,
					 [](int value, const map<string, int>::value_type& p){ return value + p.second; });
    cout << "Result: " << val << endl;
    // Define a map<int, string> called mis
    map<int, string> mis;
    // Enter the values from msi into mis; that is, if msi has an element
    // ("lecture", 21), mis should have an element (21, "lecture")
    for (auto &i : msi)
		mis[i.second] = i.first;

    // Output the elements of mis to cout.
    cout << "mis Output: " << endl;
    for (auto &i : mis)
		cout << "First: " << i.first << "\tSecond: " << i.second << endl;
    
}
