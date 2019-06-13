#include <iostream>
#include <string.h>

using namespace std;

//szablon funkcji
template <typename T> 
//funkcja wyznaczająca sumę elementów tablicy elementów T
void sum_el (T  array, int size)
{
	int sum=0; 
	for (int i = 0; i < size; i++)
	{
		cout<<array[i]<<" ";
		sum += array[i];
	}	cout<<endl;
	cout << "Suma elementów tablicy wynosi: " << sum <<endl;	
}

int main()
{
	string test = "Test funkcji";
	int array_size = strlen(test.c_str());
	sum_el<string>(test,array_size);
	return 0;
}
