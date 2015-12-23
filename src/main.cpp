#include <iostream> 

using namespace std;

int main() {

#if defined (_WIN32) ||  (_WIN64) 

	cout << "This is Windows" << endl;

#endif

#if defined (__APPLE__) 

	cout << "This is Apple" << endl;

#endif

	//test link
	cin.get();
	return 1;
}