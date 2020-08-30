/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/27/2020 at 04:38 PM
 * 
 * Chapter21_Try04.cc
 * 
 * First get the program as written to work and test it with a small file of,
 * say, a few hundred words. Then try the emphatically not recommended version 
 * that guesses about the size of input and see what happens when the input 
 * buffer overflows. Note that the worst-case scenario is that the overflow 
 * led to nothing bad in your particular example, so that you would be 
 * tempted to ship it to users.
 *
 * After testing it out, all it did was just create a bunch of empty lines
 * (Exactly the same as the size of the vector).
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iterator>
using namespace std;


void result(string &from, string &to){
    //Open both input and output streams:
    ifstream is {from};
    ofstream os {to};

    //Make input iterator for stream
    istream_iterator<string> ii {is};
    // Input Sentinel
    istream_iterator<string> eos;
    // Make output iterator for stream
    ostream_iterator<string> oo {os, " "};

    // B is a vector initialized from input;
    vector<string> vec {ii, eos};
	
    // Not recommended version:
    //vector<string> vec {256};
    sort(vec.begin(), vec.end());
    //copy(vec.begin(), vec.end(), oo);
    unique_copy(vec.begin(), vec.end(), oo);
    cout << "It is done." << endl;

}

int main(void){
    cout << "Enter a source and destination:" << endl;
    string from, to;
    // Get source and target file name:
    getline(cin, from);
    //cin >> from >> to;
    getline(cin, to);

	result(from, to);

}
