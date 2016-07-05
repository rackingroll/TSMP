#include "TimeSeries.h"

TimeSeries::TimeSeries()
{
    this->data = NULL ;
    this->length = 0 ;
}

TimeSeries::~TimeSeries()
{
    delete this->data;
}

TimeSeries::TimeSeries(double * data, long length)
{
    this->data = new double[length] ;
    this->length = length;
    for (int i=0;i<length;i++)
    {
        this->data[i] = data[i] ;
    }
}

long TimeSeries::Getlength()
{
    return this->length ;
}

double * TimeSeries::GetData()
{
    return this->data;
}

double TimeSeries::Get(int index)
{
    return this->data[index] ;
}
