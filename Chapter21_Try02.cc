/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/27/2020 at 12:36 AM
 * 
 * Chapter21_Try02.cc
 * Get this little example to work. Then add a few companies of your own
 * choice, with weights of your choice.
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <numeric>
using namespace std;
double weighted_value(const pair<string, double> &a,
		     const pair<string, double> &b){

    return a.second * b.second;
}


int main(void){
    map<string, double> dow_price = {{"MMM", 81.84}, {"AA", 34.69},
				     {"MO", 53.42}};
    
    map<string, double> dow_weight = {{"MMM", 5.849}, {"AA", 2.4808},
				      {"MO", 3.8940}};

    map<string, string> dow_name = {{"MMM", "3M Co."}, {"AA", "Alcoa Inc."},
				    {"MO", "Altra Group Inc."}};

    map<string, double> food_prices = {{"Flour", 1.23}, {"Steak", 7.32},
				       {"Iberian Ham", 150.21}};
				       
    // Iteration
    // Write price for each company in the Dow index:
    for (const auto &p: dow_price){
	const string &symbol = p.first;
	cout << symbol << "\t" << p.second << "\t"
	     << dow_name[symbol] << "\n";
    }

    // Example of inner product with parameters:
    double dji_index = inner_product(dow_price.begin(), dow_price.end(),
				     dow_weight.begin(),
				     0.0,
				     plus<double>(),
				     weighted_value);
	
    cout << "Index: " << dji_index << endl;
}
