/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/27/2020 at 11:43 PM
 * 
 * Chapter21_Drill_Vector2.cc
 * More Vectors
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <string>
#include <string>
#include <fstream>
#include <algorithm>
#include <numeric>
using namespace std;

struct Less_than{
    double val;
    Less_than(double v) : val{v} { }
    bool operator()(const double &d) { return d < val; }
};

int main(void){
    // Read some floating-point values (at least 16 values) from a file into a
    // vector<double> called vd.
    string file_path = "../Chapter21_Drill_2.txt";
    ifstream ifs{file_path, ios_base::in};
    
    vector<double> vd;
    for (double val; (ifs >> val);)
	vd.push_back(val);

    // Output vd to cout.
    cout << "Outputing the vector: " << endl;
    for (auto &i : vd)
	cout << i << endl;
    
    // Make a vector vi of type vector<int> with the same number of elements
    vector<int> vi(vd.size());
    // as vd; copy the elements from vd into vi.
    int temp;
    for (int i = 0; i < vd.size(); i++){
	temp = static_cast<int>(i);
	vi[i] = temp;
    }
    // Output the pairs of (vd[i], vi[i]) to cout, one pair per line
    cout << endl << "Outputing Pairs..." << endl;
    for (int i = 0; i < vd.size(); i++)
	cout << "(" << vd[i] << ", " << vi[i] << ")" << endl;
   
    // Output the sum of the elements of vd.
    double val = accumulate(vd.begin(), vd.end(), double{0.0});
    cout << endl << "Sum of all elements in vd: " << val << endl;
    // Output the difference between the sum of the elements of vd and the sum
    // of the elements of vi.
    int vi_val = accumulate(vi.begin(), vi.end(), int{0});
    cout << endl << "Difference b/w sum of vd and sum of vi: " << (val - vi_val);
    // There is a standard library algorithm called reverse that takes a sequence
    // (pair of iterators) as arguments; reverse vd, and output vd to cout.
    reverse(vd.begin(), vd.end());
    cout << endl << "Reversed vd: " << endl;
    for (auto &i : vd)
	cout << i << endl;
    // Compute the mean value of the elements in vd; output it.
    double mean_vd = (val / vd.size());
    cout << endl << "Mean value of all elements in vd: " << mean_vd << endl;
    
    // Make a new vector<double> called vd2 and copy all elements of vd with
    // values lower than (less than) the mean into vd2.
    vector<double> vd2(vd.size());
    copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(mean_vd));
    cout << endl << "Printing all values less than " << mean_vd << endl;
    for (auto &i : vd2)
	cout << i << endl;
    
    // Sort vd; Output it again.
    sort(vd.begin(), vd.end());
    cout << endl << "Sorted vd.." << endl;
    for (auto &i : vd)
	cout << i << endl;
}
