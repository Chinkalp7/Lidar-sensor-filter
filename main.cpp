/*
The temporal median filter returns the median of the current and the previous D scans:
y i(t) = median(x i(t), x i(t 1), ... , x i(t D))
where x and y are input and output lengthN scans and i ranges from 0 to N 1. The number of previous scans D is a parameter that should be given when creating a new temporal median filter. Note that, although the update method will receive a single scan, the returned array depends on the values of previous scans. Note also that the for the first D scans, the filter is expected to return the median of all the scans so far. Here is a short example of the result (Y) of a temporal median filter object with D =3 for an input (X) of dimension N=5, for the first five updates:

T (time) 	X (input scan) 		Y (return of the update)
0 		[0., 1., 2., 1., 3.]		 [0., 1., 2., 1., 3.]
1 		[1., 5., 7., 1., 3.]		 [0.5, 3. , 4.5, 1. , 3. ]
2		 [2., 3., 4., 1., 0.] 		[ 1., 3., 4., 1., 3.]
3	 	[3., 3., 3., 1., 3.] 		[ 1.5, 3. , 3.5, 1. , 3. ]
4 		[10., 2., 4., 0., 0.] 		[ 2.5, 3. , 4. , 1. , 1.5]
*/


#include <iostream>

#include "range_filter.h"
#include "temporal_median_filter.h"

using namespace std;

int main()
{

    int D = 3;
    temporalMedianFilter test(D);


    vector<float> temp;
    vector<float> vec1 = {0, 1, 2, 1, 3};
    temp = test.filterUpdate(vec1);
    for (unsigned int j=0 ; j<temp.size(); j++)
        {
            cout << temp[j] << "-";
        }
    cout << "1st Vector" << endl;


    vector<float> vec2 = {1, 5, 7, 1, 3};
    temp = test.filterUpdate(vec2);
    for (unsigned int j=0 ; j<temp.size(); j++)
        {
            cout << temp[j] << "-";
        }
    cout << "2nd Vector" << endl;


    vector<float> vec3 = {2, 3, 4, 1, 0};
    temp = test.filterUpdate(vec3);
    for (unsigned int j=0 ; j<temp.size(); j++)
        {
            cout << temp[j] << "-";
        }
    cout << "3rd Vector" << endl;

    vector<float> vec4 {3, 3, 3, 1, 3};
    temp = test.filterUpdate(vec4);
    for (unsigned int j=0 ; j<temp.size(); j++)
        {
            cout << temp[j] << "-";
        }
    cout << "4th Vector" << endl;

    vector<float> vec5 = {10, 2, 4, 0, 0};
    temp = test.filterUpdate(vec5);
    for (unsigned int j=0 ; j<temp.size(); j++)
        {
            cout << temp[j] << "-";
        }
    cout << "5th Vector" << endl;


    return 0;
}
