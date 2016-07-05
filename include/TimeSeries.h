#ifndef TIMESERIES_H
#define TIMESERIES_H

#include <iostream>
using namespace std;

class TimeSeries
{
    public:
        TimeSeries();
        TimeSeries(double * data, long length);
        virtual ~TimeSeries();

        long Getlength ();
        double * GetData();
        double Get(int index) ;
    private:
        double * data ; // the data of the time series
        long length ; // the length of the time series

};

#endif // TIMESERIES_H
