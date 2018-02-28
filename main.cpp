#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

vector<int>::iterator my_find(vector<int>& v, int el){
    for(vector<int>::iterator iter = v.begin(); iter!= v.end(); ++iter){
        if(*iter == el)
            return iter;
    }
    return v.end();
}

int main()
{
    vector<int> v = {1,3,5,1,2};

    int cycles = 1000000;
    double t0 = clock();
    for(int i=0; i < cycles; i++)
    my_find(v, 5);
    double t1 = clock();
    double time_seconds = (t1-t0)*CLOCKS_PER_SEC/cycles;


    auto iter  = my_find(v, 5);
    cout << *iter << endl;

    auto iter2 = std::find(v.begin(), v.end(), 5);
    cout << *iter2 << endl;


    double t0_std = clock();
    for(int i=0; i < cycles; i++)
    std::find(v.begin(), v.end(), 5);
    double t1_std = clock();
    double time_seconds_std = (t1_std-t0_std)*CLOCKS_PER_SEC/cycles;

    if(time_seconds > time_seconds_std) {
            cout << "Function 'my_find' works faster then std::find() " << endl;
        }else if (time_seconds < time_seconds_std) {
            cout << "std::find() works faster then function 'my_find'" << endl;
        }

        cout << "1) my_find() : " << time_seconds << endl;
        cout << "2) std::find() : " << time_seconds_std << endl;


    return 0;
}
