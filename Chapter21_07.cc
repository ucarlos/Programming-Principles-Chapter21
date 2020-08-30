/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/29/2020 at 07:53 PM
 * 
 * Chapter21_07.cc
 * Write a binary search function for a vector<int> (without using the stan-
 * dard one). You can choose any interface you like. Test it. How confident
 * are you that your binary search function is correct? Now write a binary
 * search function for a list<string> . Test it. How much do the two binary
 * search functions resemble each other? How much do you think they
 * would have resembled each other if you had not known about the STL?
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;

vector<int>::iterator binary_search_vec(vector<int> &vec, int &item){
    //
    // While
    auto low = vec.begin() - vec.begin();
    auto high = vec.end() - vec.begin();
    
    while (low <= high){
	auto mid = (high + low) / 2;
	if (vec[mid] == item)
	    return (vec.begin() + mid);
	else if (vec[mid] < item){ // Item is greater than mid
	    low = mid + 1;
	}
	else
	    high = mid - 1;

    }

    // If not found:
    return vec.end();
}


list<string>::iterator binary_search_str(list<string> &ls, string &item){
    //auto low = distance(ls.end(), ls.begin());
    auto low = ls.begin();
    auto high = ls.end();

    auto range = distance(low, high);
    while (distance(low, ls.begin()) <= distance(high, ls.end())){
	
	// copy of low:
	auto mid = low;
	advance(mid, range / 2);

	if (*mid == item)
	    return mid;
	else if ((*mid) < item){
	    low = mid;
	    low++;
	}
	else {
	    high = mid;
	    high--;
	}

	range = distance(low, high);
    }

    // If not found
    return ls.end();
}

int main(void){
    vector<int> vi;
    for (int i = 50; i >= 0; i--)
	vi.push_back(i);

    //Sort array
    sort(vi.begin(), vi.end());
    
    int temp = 30;
    auto bin = binary_search_vec(vi, temp);
    if (bin != vi.end())
        cout << *bin << " was found at index " << (bin - vi.begin()) << endl;

    // Now use the STL:
    auto stl_bin = binary_search(vi.begin(), vi.end(), temp);
    cout << "STL Binary Search:" << endl;
    cout << *bin << "was found at index " << (bin - vi.begin()) << endl;

    cout << "As for the List Binary Search:" << endl;
    list<string> ls = {"what", "the", "fuck", "did", "you",
		       "just", "fucking", "say", "about",
		       "me", "you", "little", "bitch"};
    string str = "did";
    // First sort the list:
    ls.sort();
	for (string &i : ls)
		cout << i << endl;

    auto ls_result0 = binary_search_str(ls, str);

    if (ls_result0 == ls.end())
	cout << "Result not found.\n";
    else
	cout << *ls_result0 << " was found at index "
	     << distance(ls.begin(), ls_result0);
    
    
		       
		       
		       
		       
}
