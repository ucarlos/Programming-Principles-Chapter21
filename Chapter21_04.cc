/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/29/2020 at 01:43 AM
 * 
 * Chapter21_04.cc
 * Implement count_if() yourself. Test it.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

template<typename InputIterator, typename Predicate>
typename iterator_traits<InputIterator>::difference_type
count_if(InputIterator first, InputIterator last, Predicate pred){
    typename iterator_traits<InputIterator>::difference_type sum = 0;
    while (first != last){
	if (pred(*first)) sum++;
	first++;
    }

    return sum;
}



int main(void){
    vector<int> vi;
    for (int i = 0; i < 50; i++)
	vi.push_back((i + 1));

    auto result_vi = count_if(vi.begin(), vi.end(),
			   [](const int &i){ return i > 12; } );
    
    cout << "Result of values > 12 : " << result_vi << endl;
}
