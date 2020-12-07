/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/27/2020 at 01:28 AM
 * 
 * Chapter21_Try03.cc
 * Write a small program using #include<unordered_map> . If that doesn’t
 * work, unordered_map wasn’t shipped with your C++ implementation. If
 * your C++ implementation doesn’t provide unordered_map , you have to
 * download one of the available implementations (e.g., see www.boost.org).
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(void){
    unordered_map<string, double> shopping_cart = {{"Steak", 8.99},
												   {"Ramen Pack", 4.99},
												   {"Soda Water", 0.99},
												   {"Wine", 9.99}};

    cout << "Inserting Doritos and Mountain Dew into the cart.\n";
    shopping_cart.insert({"Doritos", 2.99});
    shopping_cart.insert({"Mountain Dew", 1.99});
    
    for (auto &v : shopping_cart)
		cout << v.first << "\t" << v.second << endl;

    shopping_cart.erase({"Wine"});

    cout << "After removing Wine..." << endl;
    for (auto &v : shopping_cart)
		cout << v.first << "\t" << v.second << endl;
}
