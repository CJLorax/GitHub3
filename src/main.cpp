#include <stdio.h>

#if defined (_WIN32) ||  (_WIN64)
#include <direct.h>
#define GetCurrentDir _getcwd
#endif


#if defined (__linux__)
#include <unistd.h>
#include <limits.h>
#define GetCurrentDir getcwd
#endif

#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    
#if defined (_WIN32) ||  (_WIN64)
    

	char cCurrentPath[FILENAME_MAX];

	cCurrentPath[sizeof(cCurrentPath) - 1] = '/0'; /* not really required */

	//printf("The current working directory is %s", cCurrentPath);

	cout << "The current working directory is " + cCurrentPath << endl;
    
#endif
    
#if defined (__APPLE__)
    
    cout << "This is Apple" << endl;

    
    
#endif
    
#if defined (__linux__)
    
    cout << "This is Linux" << endl;

	char result[PATH_MAX];
	string test = getcwd(result, PATH_MAX);

	cout << "The current working directory is " + test << endl;

#endif
    


    //test link
    cin.get();
    return 1;
}
