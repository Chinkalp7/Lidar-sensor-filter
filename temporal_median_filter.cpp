#include <iostream>
#include <vector>
#include <algorithm>

#include "temporal_median_filter.h"

using namespace std;

/** \brief
 *  constructor: This constructor will be invoked when no parameter is passed while Initialization.
 */

TemporalMedianFilter::TemporalMedianFilter()
{
    num_of_scan = 3;
    counter = 0;
    //ctor
}

/** \brief
 * Parameterized constructor: This constructor will invoked when parameter are provided
 */

TemporalMedianFilter::TemporalMedianFilter(int x): num_of_scan(x),counter(0)
{
    //ctor
}

/** \brief
 * Destructor:
 */

TemporalMedianFilter::~TemporalMedianFilter()
{
    //dtor
}

/** \brief
 * getMedianVector: This is a private methods that calculates Median of
 * individual vector value and provides updated vector
 * \return  It returns Vectors of float type with calculate median values
 */

vector<float> TemporalMedianFilter::getMedianVector()
{

    size_t msize= multi_dim_vector.size();
    float median;


    vector<float> temp_;        // Temp vector to hold sorted vector
    vector<float> median_vector;// Holds Median values

    /** \brief
     * If vector size is even then it will iterate through
     * current vector and previous vector based upon Multi-dimensional vector
     * size and calculates median value and stores in temporary vector and then
     * after sorting the vector median value of sorted vectors is stored in
     * Median vector
     */
    if((msize % 2) == 0)
    {
        for(size_t j=0; j<multi_dim_vector[0].size();j++)
        {
            for(size_t i=0; i<msize; i++)
            {
                 temp_.push_back(multi_dim_vector[i][j]);
            }

            sort(temp_.begin(),temp_.end());
            median = (temp_[msize / 2 - 1] + temp_[msize / 2]) / 2;
            median_vector.push_back(median);
            temp_.erase(temp_.begin(),temp_.end());
        }
    }
    else
    {
        for(size_t j=0; j<multi_dim_vector[0].size();j++)
        {
            for(size_t i=0; i<msize ;i++)
            {
                 temp_.push_back(multi_dim_vector[i][j]);
            }

            // sorting of temporary array
            sort(temp_.begin(),temp_.end());
            // Size of vector is odd so Median is center value of vector
            median = temp_[msize / 2 ];
            // median value pushed into median vector
            median_vector.push_back(median);
            // erasing temp vector so it can hold new value
            temp_.erase(temp_.begin(),temp_.end());
        }
    }
    return median_vector;
}

/** \brief
 * filterUpadte: This method provides updated scan value based on median of
 * previous scan values.
 * \return  It returns Vectors of float type with calculated median values
 */

vector<float> TemporalMedianFilter::filterUpdate(const vector<float>& input_scan)
{

    vector<float> temp = input_scan;
    vector<float> updated_median;

    /* This checks if it is the first input scan value if yes then it stores the size of
        the vector and copies input vector to the output vector */
   if(counter==0)
   {
       scan_size = temp.size();
       multi_dim_vector.push_back(temp);
       updated_median=temp;
       counter++;
   }

   /* If counter value is not zero then it checks the size of input vector just to make sure it matches with
        previous scan size and then adds input scan value into the multidimensional vector and erases vector
        element if the counter reaches to the number of scan value and it will maintain the size of Multi-
        Dimensional vector. */
   else
   {
       if(temp.size() == scan_size)
       {
           if(counter <= num_of_scan)
            {
                multi_dim_vector.push_back(temp);
                counter++;
            }
            else
            {
                multi_dim_vector.push_back(temp);
                multi_dim_vector.erase(multi_dim_vector.begin());
            }
            updated_median=getMedianVector();
       }
       else
       {
          cout <<  "Error: Scan length does not match" << endl; // Error message if previous vector size doesn't match
          updated_median=temp;
       }
   }
    return updated_median;          // returns updated Vector with calculated Median value.
}
