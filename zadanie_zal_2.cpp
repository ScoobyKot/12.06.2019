#include <iostream>
#include <vector>

using namespace std;
// szblon funkcji
template<typename T>
// funkcja przyjmująca stały vector , stały klucz i pusty wektor 
void vec_fun(const vector<T> &source,const T& key,vector<T> &result)
{
	int size_of_arr = source.size(); // rozmiar wektora source 
	cout << " size of source : "<<size_of_arr<<endl;
    for (int i = 0; i<size_of_arr;i++) // pętlia przepisująca warości z wektora source według klucza do wektora result
	{
		if (source[i]< key)
		{
			result.push_back(source[i]);
		}
	}
	
	int size_of_res = result.size();
	cout << " size of result : "<<size_of_res<<endl;
    for (int i = 0; i<size_of_res;i++) 
	{
		cout<<result[i]<<" ";
	}cout<<endl;
	
};


int main()
{
	const vector <double> source={3.432,4.2341,5.4342,6.43,7.43,85.21,3.432};
	const double key = 20.55;
	vector <double> result;
	vec_fun<double>(source,key,result);
	const vector <int> source_1={33,54,32,4,1,434,4,-23,43,3,53,2,1,3};
	const int key_1 = 35;
	vector <int> result_1;
	vec_fun<int>(source_1,key_1,result_1);

	
	return 0;
}
