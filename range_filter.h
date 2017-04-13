#ifndef RANGEFILTER_H
#define RANGEFILTER_H

#include <vector>

using namespace std;

class RangeFilter
{
    /** \brief
     *    This is a range filter class which takes  input scan of type vector<Float>
     *    and based on provided range it crops all the value below minimum range and
     *    maximum range and replaces with min and max range value.
     */
    private:
        float range_min_;       // Minimum range value
        float range_max_;       // Maximum range value

    public:
        RangeFilter();              // Default constructor
        RangeFilter(float, float);  // Parameterized constructor
        ~RangeFilter();             // Destructor

        float getRangeMin();        // Provides Minimum range value
        float getRangeMax();        // Provides Maximum range value

        void setRange(float range_min,float range_max);             // function to set minimum and maximum value
        vector<float> filterUpdate(const vector<float>& input_scan);// returns updated scan value
};

#endif // RANGEFILTER_H
