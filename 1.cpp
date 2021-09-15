#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

template <class Container, class T>
void insert_sorted(Container &cont, const T &value)
{
	typename Container::iterator it = upper_bound(begin(cont), end(cont), value);
	cont.insert(it, value);
}

int main()
{
	vector<int> num = { 1,2,3,4,6 };
	insert_sorted(num, 5);
	for (const auto &n : num)
	{
		cout << n << " ";
	}
	cout << endl;
	list<string> str = { "a","c","d","e","f" };
	insert_sorted(str, "b");
	for (const auto &s : str)
	{
		cout << s << " ";
	}
	return 0;
}