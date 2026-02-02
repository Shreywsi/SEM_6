#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    int s1, s2;
    cout << "enter the length of set 1: ";
    cin >> s1;
    cout << "enter the length of set 2: ";
    cin >> s2;

    vector<int> sn1(s1), sn2(s2);

    for (int i = 0; i < s1; i++)
    {
        cout << "enter the no. for set 1: ";
        cin >> sn1[i];
    }

    for (int i = 0; i < s2; i++)
    {
        cout << "enter the no. for set 2: ";
        cin >> sn2[i];
    }

    sort(sn1.begin(), sn1.end());
    sort(sn2.begin(), sn2.end());

    vector<int> uni, intersection, difference;

    set_union(sn1.begin(), sn1.end(),
              sn2.begin(), sn2.end(),
              back_inserter(uni));

    set_intersection(sn1.begin(), sn1.end(),
                     sn2.begin(), sn2.end(),
                     back_inserter(intersection));

    set_difference(sn1.begin(), sn1.end(),
                   sn2.begin(), sn2.end(),
                   back_inserter(difference));
    cout <<"Union is: ";
    for (int x : uni)
        cout << x << " ";
    cout << endl;
    cout<<"intersection is: ";
    for (int x : intersection)
        cout<<x << " ";
    cout << endl;
    cout << "difference is: ";
    for (int x : difference)
        cout << x << " ";

    return 0;
}
