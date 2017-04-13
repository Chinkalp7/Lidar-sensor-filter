#ifndef TEMPORALMEDIANFILTER_H
#define TEMPORALMEDIANFILTER_H

#include <vector>

using namespace std;

class TemporalMedianFilter
{
    /** \brief
    *  This is a Temporal Median filter class and it provides method that returns
    *  median of the current and the previous D scans value. Where D is the
    *  number of scans.
    */

    private:
        int num_of_scan;                // Number of previous scan
        int counter;                    // Counter to track the current scan number
        size_t scan_size;               // Stores value of input vector size
        vector<vector<float> > multi_dim_vector;    /* Multi-Dimensional vector to
                                                     store previous scan data  */

        vector<float> getMedianVector(void);

    public:
        TemporalMedianFilter();         // Default constructor
        TemporalMedianFilter(int);      // Parameterized constructor
        ~TemporalMedianFilter();        // Destructor


        vector<float> filterUpdate(const vector<float>& input_scan);
        /*   filterUpdate methods that takes vector of float type as input  and returns
             median of the current and the previous scans Value.   */
};

#endif // TEMPORALMEDIANFILTER_H
