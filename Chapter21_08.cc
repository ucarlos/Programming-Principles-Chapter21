/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 05/29/2020 at 09:28 PM
 * 
 * Chapter21_08.cc
 * Take the word-frequency example from §21.6.1 and modify it to output
 * its lines in order of frequency (rather than in lexicographical order). An
 * example line would be 3: C++ rather than C++: 3 .
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

struct Words_Comparison{
	bool operator()(const pair<string, int> &p1, const pair<string, int> &p2) const{
		return p1.second < p2.second;
	}

};

int main(void){
    std::string file_path = "../Navy Seals Copypasta.txt";
    // Ignore this 
    //std::map<std::string, int, Words_Comparison> words;
    std::map<string, int> words;
    ifstream ifs{file_path, ios_base::in};
    
    for (string s; ifs >> s;)
		words[s]++;

    cout << "Initial Map:" << endl;
    for (auto &i : words)
    	cout << i.second << "\t " << i.first << endl;


}
