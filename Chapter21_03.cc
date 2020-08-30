/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/29/2020 at 12:05 AM
 * 
 * Chapter21_03.cc
 * Implement count() yourself. Test it.
 * 
 * I essently took the function declaration from cppreference since I didn't
 * know how to set it up. My algorithm is essently the same.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;


// For simplicity, use uint32_t
template<typename InputIterator, typename T>
typename iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, const T& val){
    typename iterator_traits<InputIterator>::difference_type sum = 0;
    while (first != last){
	if (*first == val)
	    sum++;
	
	first++;
    }

    return sum;
}



int main(void){
    vector<int> vi = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
    vector<string> vs = {"Hello", "World", "!", "Hello", "World", "!", "Hello", "World", "!"};
    
    auto result_int = count(vi.begin(), vi.end(), 1);
    auto result_str = count(vs.begin(), vs.end(), "Hello");
    
    cout << "Occurrence of 1 in vi: " << result_int << endl;
    cout << "Occurrence of \"Hello\" in vs: " << result_str << endl;
}
