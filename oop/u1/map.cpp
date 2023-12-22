#include<iostream>
#include<map>
#include<iterator>
using namespace std;


int main() {
    map<int, int> mymap;
    mymap[1] = 10;
    mymap[2] = 20;
    mymap[3] = 30;

    map<int, int>::iterator iter;
    for (iter = mymap.begin(); iter != mymap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}