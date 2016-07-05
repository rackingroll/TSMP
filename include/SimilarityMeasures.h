#ifndef SIMILARITYMEASURES_H
#define SIMILARITYMEASURES_H

#include "TimeSeries.h"
/*
Given two time series A, and B
Distance Type:
Minhash, L1, L2, DTW, Pearson, SST correlation
*/

class SimilarityMeasures
{
    public:
        SimilarityMeasures();

        double L1(TimeSeries* A, TimeSeries* B) ;
        double L2(TimeSeries* A, TimeSeries* B) ;
        double Pearson(TimeSeries* A, TimeSeries* B) ;
        double DTW(TimeSeries* A, TimeSeries* B, int r) ; // r is the parameter
        double SST(TimeSeries* A, TimeSeries* B,  int w, int l, int g, int m, int n) ;
        double ChangeCorrelation (TimeSeries* A, TimeSeries* B) ;

        virtual ~SimilarityMeasures();
    private:
};

#endif // SIMILARITYMEASURES_H
