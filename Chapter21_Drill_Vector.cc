/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/27/2020 at 08:54 PM
 * 
 * Chapter21_Drill_Vector.cc
 * After each operation (as defined by a line of this drill) print the vector.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <numeric>
#include <list>
using namespace std;


struct Item {
    string name;
    int id;
    double value;

    Item(string n, int idd, double val) : name{n}, id{idd}, value{val} { }
    friend ostream& operator<<(ostream &os, const Item &i){
	return os << "(ID " << i.id << ") " << i.name << " " << i.value;
    }
    
};
struct Find_Item{
	string search;
	bool operator()(const Item &i) const { return i.name == search; }
	explicit Find_Item(string s) : search{s} { }
};

template<typename T> void print_vector(vector<T> &vec){
    for (const T &i : vec)
	cout << i << endl;
}

template<typename T> void print_list(list<T> &l){
    for (const T &i : l)
	cout << i << endl;
}

int main(void){
    string file_path = "../Chapter21_Drill.txt";
    ifstream ifs {file_path, ios_base::in};
    vector<Item> vi;

    string temp_str;
    int temp_id;
    double temp_val;

    // Define a struct Item { string name; int iid; double value; /* . . . */ }; , make
    // a vector<Item> , vi , and fill it with ten items from a file.
    for (int i = 0; i < 10; i++){
	ifs >> temp_str >> temp_id >> temp_val;
	vi.push_back(Item{temp_str, temp_id, temp_val});
    }

    // Print Original Vector:
    cout << "Original Vector:" << endl;
    print_vector(vi);
    cout << endl;
    
    // Sort vi by name:
    sort(vi.begin(), vi.end(), [](const Item &a, const Item &b){ return a.name < b.name;});
    cout << "Sorted Vector by name: " << endl;
    print_vector(vi);
    cout << endl;

    // Sort vi by id:
    cout << "Sorted Vector by ID: " << endl;
    sort(vi.begin(), vi.end(), [](const Item &a, const Item &b) { return a.id < b.id; });
    print_vector(vi);
    cout << endl;
    
    // Sort vi by value; print it in order of decreasing value
    // (i.e. Largest value first)
    cout << "Sorted Vector by Largest Value:" << endl;
    sort(vi.begin(), vi.end(), [](const Item &a, const Item &b) { return a.value > b.value; });
    print_vector(vi);
    cout << endl;
    //Insert Item("horse shoe",99,12.34) and Item("Canon S400", 9988,499.95) .
    cout << "Inserting two items into the vector:" << endl;
    vi.push_back(Item{"Horseshoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});
    
    print_vector(vi);
    cout << endl;
    
    // Remove (erase) two items identified by name from vi
    cout << "Remove (erase) two items identified by name from vi: " << endl;
    string search_name = "Horseshoe";
    auto it = find_if(vi.begin(), vi.end(), Find_Item(search_name));
    if (it != vi.end())
	vi.erase(it);
    
    it = find_if(vi.begin(), vi.end(), Find_Item("Canon S400"));
    if (it != vi.end())
	vi.erase(it);

    print_vector(vi);
    cout << endl;
    // Remove (erase) two items identfied by id from vi.
    cout << "Remove (erase) two items identfied by id from vi: " << endl;
    it = find_if(vi.begin(), vi.end(), [](const Item &i){ return i.id == 10; });
    if (it != vi.end())
	vi.erase(it);

    it = find_if(vi.begin(), vi.end(), [](const Item &i){ return i.id == 9; });
    if (it != vi.end())
	vi.erase(it);

    print_vector(vi);
    cout << endl << endl;
    cout << "Now with Lists:" << endl;

//------------------------------------------------------------------------------
// Now everything with a List Item:
//------------------------------------------------------------------------------

	list<Item> li;
	// Return to beginning:
	ifs.seekg(0);

	for (int i = 0; i < 10; i++){
		ifs >> temp_str >> temp_id >> temp_val;
		li.push_back(Item{temp_str, temp_id, temp_val});
	}

	cout << "Original List:" << endl;
	print_list(li);

	cout << "Sorted List by name:" << endl;
	li.sort([](const Item &i, const Item &j){ return i.name < j.name; });
	print_list(li);

	cout << "Sorted List by id:" << endl;
	li.sort([](const Item &i, const Item &j){ return i.id < j.id; });
	print_list(li);

	cout << "Sorted List by decreasing value: " << endl;
	li.sort([](const Item &i, const Item &j){ return i.value > j.value; });

	print_list(li);

	// Insert Items
	li.insert(li.end(), Item{"Horseshoe", 99, 12.34});
	li.insert(li.end(), Item{"Canon S400", 9988, 499.95});

	// Now remove them:
	cout << "Remove (erase) two items identified by name from li: " << endl;
	auto lit = find_if(li.begin(), li.end(), Find_Item("Horseshoe"));
	if (lit != li.end())
		li.erase(lit);

	lit = find_if(li.begin(), li.end(), Find_Item("Canon S400"));
	if (lit != li.end())
		li.erase(lit);

	print_list(li);
	cout << endl;
	// Remove (erase) two items identfied by id from vi.

	cout << "Remove (erase) two litems identfied by id from li: " << endl;
	lit = find_if(li.begin(), li.end(), [](const Item &i){ return i.id == 10; });
	if (lit != li.end())
		li.erase(lit);

	lit = find_if(li.begin(), li.end(), [](const Item &i){ return i.id == 9; });
	if (lit != li.end())
		li.erase(lit);

	print_list(li);
}
