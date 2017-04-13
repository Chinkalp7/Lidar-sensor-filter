#include <iostream>
#include <vector>

#include "range_filter.h"

using namespace std;

/** \brief
 *  constructor: This constructor will be invoked when no parameter is passed while Initialization.
 */

RangeFilter::RangeFilter()
{
    range_min_=5.9;
    range_max_=20.4;
}

/** \brief
 * Parameterized constructor: This constructor will invoked when parameter are provided
 */

RangeFilter::RangeFilter(float low ,float high):range_min_(low) , range_max_(high)
{
    //ctor
}

/** \brief
 * Destructor:
 */
RangeFilter::~RangeFilter()
{
    //dtor
}

/** \brief
 * This method provides current Minimum range value.
 */

float RangeFilter::getRangeMin()
{
    return range_min_;
}

/** \brief
 * This method provides current Minimum range value.
 */
float RangeFilter::getRangeMax()
{
    return range_max_;
}

/** \brief
 * This function will set Minimum and maximum range value based upon
 * provided values.
 */

void RangeFilter::setRange(float range_min,float range_max)
{
    range_min_=range_min;
    range_max_=range_max;
}

/** \brief
 * FilterUpdate function crops value below minimum range and above maximum range and replaces
 * with Minimum and Maximum value.
 * \param input_scan
 * \return Vector of float type (vector<float>)
 */

vector<float> RangeFilter::filterUpdate(const vector<float>& input_scan)
{
    vector<float> updated_scan = input_scan;     // copied vector to temporary vector

    std::vector<float>::iterator ot = updated_scan.begin();         // iterator for updated_scan vector

    for(; ot != updated_scan.end();++ot)
        {
            if(*ot < range_min_)                // checks if value is less than minimum range
            {
                *ot = range_min_;               // updates value of vector with minimum range
            }
            else if(*ot > range_max_)           // checks if value is greater than maximum range
            {
                *ot = range_max_;               // updates value of vector with minimum range
            }
        }
        return updated_scan;                    // returns updated vector
}

