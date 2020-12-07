/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/31/2020 at 12:12 AM
 * 
 * Chapter21_10.cc
 * Compute the total value of the orders in the two files from the previ-
 * ous exercise. The value of an individual Purchase is (of course) its
 * unit_price*count .
 * -----------------------------------------------------------------------------
 */

// From Chapter21_09.cc

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cstdint>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iterator>
#include <numeric>
using namespace std;


struct Purchase{
    string product_name{};
    double unit_price{0.0};
    uint32_t quantity{0};

    Purchase()=default;
    Purchase(string pn, double up, uint32_t q) : product_name{pn} , unit_price{up}, quantity{q} { }
    friend istream& operator>>(istream &is, Purchase &p);
    friend ostream& operator<<(ostream &os, Purchase &p);
};



// Operator is not meant to be used in any other case besides a file
// So don't use with cin UNLESS its like this:
// ["Apples" 1.25 10]
istream& operator>>(istream &is, Purchase &p){
    char ch;
    string str;
    double up;
    uint32_t q;
    is >> ch;

	// If ch isn't [, then throw an error.
    if (ch != '[')
		throw runtime_error("Purchase does not start with an \"[\".");
    // next char should be \", it's fine if it isn't.
    is >> ch;
    if (ch != '\"')
		throw runtime_error("Product name should start with an \"");

    // Read the rest of the string.
    getline(is, str, '\"');

    // Next char should be \", if not, something is completely fucked.
    //is >> ch;

    // Now get unit_price and quantity:
    is >> up >> q;

    // Make sure that ] is the last character to be read.
    is >> ch;
    if (ch != ']')
    	throw runtime_error("Purchase must end with an \"]\"");

    // Now populate p:
    p.product_name = str;
    p.unit_price = up;
    p.quantity = q;

    return is;

}

ostream& operator<<(ostream &os, Purchase &p){
    return os << "[" << "\"" << p.product_name << "\" "
			  << p.unit_price << " " << p.quantity
			  << "]";
	
}

class Order{
public:
    Order()=default;
    Order(string cus, string add, vector<Purchase> &data):
		customer_name{cus}, address{add} { this->data = data; }
    
    string get_name() const { return customer_name; }
    void set_name(string &v) { customer_name = v; }

    string get_address() const { return address; }
    void set_address(string add){ address = add; }
    
    vector<Purchase>& get_data() { return data; }
    const vector<Purchase>& get_data() const { return data; }
    
    friend istream& operator>>(istream &is, Order &p);
    friend ostream& operator<<(ostream &os, Order &p);
private:
    string customer_name{"John Doe"};
    string address{"123 Park Place"};
    vector<Purchase> data{};
};

double sum_order(double val, const Order &o){
    for (auto &i : o.get_data())
		val += (i.unit_price * i.quantity);
    
    return val;
}

istream& operator>>(istream &is, Order &o){
    // [Customer Name]
    // [Address]
    // {Data }
    // Space:
    string cn, add;
    char ch;
    vector<Purchase> datum;

    getline(is, cn);
    getline(is, add);
    is >> ch;

    // if file is newline or \0, stop
    if (ch == '\n' || ch == '\0')
    	return is;
    // Data must start with {
    if (ch != '{')
		throw runtime_error("Purchase vector must start with \"{\"");

    Purchase p;

    for (ch; is >> ch;){
    	if (ch == '}') {
			is.unget();
			break;
		}

    	is.unget();
    	is >> p;
		datum.push_back(Purchase{p});
    }

    // Now make sure data ends with }
    is >> ch;
    if (ch != '}')
		throw runtime_error("Purchase vector must end with \"}\"");

    // Disregard the newline for the next Order.
	char remove = is.get();
    o.set_name(cn);
    o.set_address(add);
    o.get_data() = datum;
    
    return is;
}

ostream& operator<<(ostream &os, Order &p){
    ostringstream oss;
    oss << p.get_name() << endl
		<< p.get_address() << endl
		<< "{ ";
    
    for (auto &i : p.get_data())
		oss << i << " ";
    
    oss << "}";

    return os << oss.str();
    // Now print all of Purchase:
	       
}


// Order will be as follows:
// [Customer Name]
// [Customer Address]
// [Data -- Held together in brackets]


// The data in a vector will be written like this:
// {[Data Member 1], [Data Member 2], ... , [Data Member n] }
// where Data Member will be written as
// ["Product Name", Price, Quantity]

void read_orders_from_file(ifstream &ifs, vector<Order> &vo){
	Order temp{};
	for (; (ifs.good() && ifs >> temp);){
		vo.push_back(Order{temp});
	}
}

void read_orders_from_file(ifstream &ifs, list<Order> &lo) {
	Order temp{};
	for (; ifs >> temp;)
		lo.push_back(Order{temp});
}

void write_orders_to_file(ofstream &ofs, vector<Order> &vo){
	for (auto &i : vo)
		ofs << i << endl;

}

void write_orders_to_file(ofstream &ofs, list<Order> &lo){
	for (auto &i : lo)
		ofs << i << endl;
}

//Use this if you forget:
// ["Peaches" 1.99 20] ["Steak" 5.99 2] ["Wine" 9.99 1] ["Oranges" 0.99 5] ["Apples" 1.99 10]
void generate_file(void){
	// Example: ["Apples" 1.99 10]
	string file_path = "../Chapter21_09_File.txt";
	ofstream ofs{file_path, ios_base::trunc};
	vector<Purchase> vec;
	Purchase temp;
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		vec.push_back(Purchase{temp});
	}

	// Now store that in an order:
	vector<Order> vo;
	vo.push_back(Order{"Ulysses Carlos", "123 Main Street", vec});
	vector<Purchase> cev = vec;
	reverse(cev.begin(), cev.end());
	vo.push_back(Order{"Daniel Carlos", "321 Main Street", cev});

	// Another one
	vector<Purchase> vec1 = {Purchase{"Rice", 0.99, 100}, Purchase{"Water", 0.10, 100},
		Purchase{"Oatmeal", 1.99, 2}, Purchase{"Frozen Pizza", 3.99, 5},
		Purchase{"Spaghetti", 2.99, 2}};
	vo.push_back(Order{"Bjarne Stroustrup", "1 Road Ahead", vec1});
	vo.push_back(Order{"Reviewbrah", "123 Food Street", vec1});
	vo.push_back(Order{"Donald Trump", "725 5th Ave, New York, NY 10022", vec1});
	vector<Purchase> vec2 = {Purchase{"Kobe Beef", 9.99, 1}, Purchase{"Jamon Iberico", 99.99, 1}};
	vo.push_back(Order{"James Rolfe", "123 AVGN road", vec2});
	vector<Purchase> vec3 = {Purchase{"Pizza", 0.99, 100}, Purchase{"Pasta", 1.99, 10}};
	vo.push_back(Order{"Vinny Vinesauce", "123 Speen Road", vec3});
	vo.push_back(Order{"Joel", "123 Sweden Road", vec1});
	vo.push_back(Order{"Dennis Ritche", "123 C Road", vec1});
	vo.push_back(Order{"Jermey Soule", "123 Skyrim Road", vec1});
	vo.push_back(Order{"Hideo Kojima", "123 Konami Road", vec1});
	vo.push_back(Order{"Adam Jensen", "123 Never asked for this Road", vec1});
	// Now write to file:
	write_orders_to_file(ofs, vo);

}
int main(void){
	//generate_file();
    vector<Order> vo;
    string file_path = "../Chapter21_09_File.txt";
    string copy_path = "../Chapter21_09_Copy.txt";

    ifstream ifs{file_path, ios_base::in};
    read_orders_from_file(ifs, vo);

    // Sort vector by customer name:
    sort(vo.begin(), vo.end(),
		 [](const Order &a, const Order &b) { return a.get_name() < b.get_name();});
    ofstream ofs1{copy_path, ios_base::trunc};
    write_orders_to_file(ofs1, vo);

    // Now use a list:
    list<Order> lo;
    string list_path = "../Chapter21_09_File_List.txt";
    string list_copy_path = "../Chapter21_09_Copy_List.txt";
    string final_path = "../Chapter21_09_Merged.txt";
    ifstream ifss{list_path, ios_base::in};

    read_orders_from_file(ifss, lo);
    lo.sort([](const Order &a, const Order &b){ return a.get_address() < b.get_address();});
    ofstream ofs2{list_copy_path, ios_base::trunc};
    write_orders_to_file(ofs2, lo);
    
    // Now merge both files into final path:
    ofstream final{final_path, ios_base::trunc};
    //ostream_iterator<Order> ostreamIterator{final};
    vector<Order> vf{vo.size() + lo.size()};

    std::merge(vo.begin(), vo.end(), lo.begin(), lo.end(), vf.begin(),
			   [](const Order &a, const Order &b){ return a.get_name() < b.get_name();});

    // Now write to file:
    write_orders_to_file(final, vf);


//------------------------------------------------------------------------------
// Chapter21_10.cc stuff
//------------------------------------------------------------------------------
	
    double val = accumulate(vo.begin(), vo.end(), double{0.0}, sum_order);
    val = accumulate(lo.begin(), lo.end(), val, sum_order);
    cout << "Total Price is $" << val << endl;
}
