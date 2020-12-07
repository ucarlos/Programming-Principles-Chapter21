/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/29/2020 at 03:25 PM
 * 
 * Chapter21_05.cc
 * What would we have to do if we couldn’t return end() to indicate “not
 * found”? Redesign and re-implement find() and count() to take iterators to
 * the first and last elements. Compare the results to the standard versions.
 * 
 * I guess what you could do is that you return nullptr if the item is 
 * not found in the sequence (In the case of find). 
 * 
 * Yeah, it doesn't work. I can't return nullptr for the iterators
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

template<typename InputIterator, typename T>
InputIterator* my_find(InputIterator first,
					   InputIterator last, const T &item){

    while (first != last){
		if ((*first) == item)
			return &first;
		first++;    }
    
    // If item is not found in range, return nullptr?
    return nullptr;
}


template<typename InputIterator, typename T>
typename iterator_traits<InputIterator>::difference_type
my_count(InputIterator first, InputIterator last,
		 const T &item){
    typename iterator_traits<InputIterator>::difference_type sum = 0;

    typename iterator_traits<InputIterator>::difference_type range = (last - first);

    for (auto i = first; i < range; i++)
		if ((*i) == item) sum++;

    return sum;
}

int main(void){
    vector<int> vi = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
    auto result_my_find = my_find(vi.begin(), vi.end(), int{2});
    cout << result_my_find << endl;
    auto result_my_find2 = my_find(vi.begin(), vi.end(), int{5});



}
