#include <stdio.h>
#include <string>
#include <iostream>


#if defined (_WIN32) ||  (_WIN64)
#include <direct.h>
#define getcwd _getcwd
#endif


#if defined (__linux__)
#include <unistd.h>
#endif



using namespace std;



int main(int argc, const char * argv[]) {
    
#if defined (_WIN32) ||  (_WIN64)
	cout << "This is Windows" << endl;
	
	string s_cwd(getcwd(NULL, 0));

	cout << s_cwd << endl;

#endif
    
#if defined (__APPLE__)
    
    cout << "This is Apple" << endl;

    
    
#endif
    
#if defined (__linux__)
    
    cout << "This is Linux" << endl;
	
	string s_cwd(getcwd(NULL, 0));

	cout << s_cwd << endl;

#endif
    


    //test link
    cin.get();
    return 1;
}
