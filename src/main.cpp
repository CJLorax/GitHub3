#include <stdio.h>

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
#if defined (_WIN32) ||  (_WIN64)
    
    cout << "This is Windows" << endl;
    cout << "Would this show in windows" << endl;
    
#endif
    
#if defined (__APPLE__)
    
    cout << "This is Apple" << endl;
    cout << "Does this add more???" << endl;
    cout << "AND Does this add more???" << endl;
    
    
#endif
    
#if defined (_linux__)
    
    cout << "This is Linux" << endl;
    
#endif
    
    //test link
    cin.get();
    return 1;
}