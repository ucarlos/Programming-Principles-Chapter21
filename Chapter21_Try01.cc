/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/23/2020 at 11:20 PM
 * 
 * Chapter21_Try.cc
 * 
 * Define a vector<Record>, initialize it with four records of your choice, and
 * compute their total price using the functions above.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;

struct Record{
    double unit_price;
    int units;
    explicit Record(double u_p, int u) : unit_price{u_p}, units{u} { }
    friend ostream& operator<<(ostream &os, const Record &r);
};

ostream& operator<<(ostream &os, const Record &r){
    
    return os << "Price: $" << r.unit_price << " (Quantity " << r.units << ")";
}

double price_fun(double v, const Record&r){
    return v + r.unit_price * r.units;
}


int main(void){
    std::vector<Record> vec = {Record{15.65, 4}, Record{42.69, 16},
		Record{1.99, 15}, Record{20.20, 5}};

    for (auto i : vec)
		cout << i << endl;
    
    double total = 0;
    // Normal function pointer version
    // total = accumulate(vec.begin(), vec.end(), total, price_fun);

    // Lambda function version:
    total = accumulate(vec.begin(), vec.end(), total,
					   [](double v, const Record &r) {return v + r.unit_price * r.units;});

    cout << "Total is $" << total << endl;
}
