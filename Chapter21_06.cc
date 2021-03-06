/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/29/2020 at 05:10 PM
 * 
 * Chapter21_06.cc
 * In the Fruit example in §21.6.5, we copy Fruit s into the set . What if
 * we didn’t want to copy the Fruit s? We could have a set<Fruit*> instead.
 * However, to do that, we’d have to define a comparison operation for that
 * set. Implement the Fruit example using a set<Fruit*, Fruit_comparison>.
 * Discuss the differences between the two implementations.
 *
 * For the set<Fruit*, Fruit_comparison>, I had to implement a binary predicate
 * that could work with pointers of type Fruit. So in my Fruit_Comparison
 * class, I did just than. Ususally, the default set comes with a less than
 * predicate, but I had to implement one in this case.
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

struct Fruit{
    string name;
    int count;
    double unit_price;
    
    explicit Fruit(string n, int c, double up) :
		name{n}, count{c}, unit_price{up} { }
    
    friend ostream& operator<<(ostream &os, Fruit &f);

};

ostream& operator<<(ostream &os, Fruit &f) {
	return os << "Fruit Name: " << f.name << "\tQuantity: "
			  << f.count << "\tPrice: " << f.unit_price;
}

struct Fruit_Comparison{
    bool operator()(const Fruit *a, const Fruit *b) const{
		return (a->name < b->name);
    }
};

int main(void){
    Fruit a{"Apple", 10, 1.99};
    Fruit b{"Orange", 1, 0.50};
    Fruit c{"Pear", 2, 0.99};
    Fruit d{"Peach", 3, 2.99};

    set<Fruit*, Fruit_Comparison> sf;
    sf.insert(&a);
    sf.insert(&b);
    sf.insert(&c);
    sf.insert(&d);


    cout << "Printed Fruit Set:" << endl;
	for (auto &i : sf)
		cout << *i << endl;
}
