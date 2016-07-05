#include "SimilarityMeasures.h"
#include <cmath>
#include <limits>
#include <algorithm>

SimilarityMeasures::SimilarityMeasures()
{
}

SimilarityMeasures::~SimilarityMeasures()
{
}

double SimilarityMeasures::L1(TimeSeries* A, TimeSeries* B)
{

    if (A->Getlength() != B->Getlength()) return 0.0 ;


    double dist = 0.0 ;
    for (int i=0;i<A->Getlength();i++)
    {
        cout << "I am here        " << A->GetData()[i]<< endl ;
        dist += std::abs(A->GetData()[i] - B->GetData()[i]) ;
    }

    return dist ;
}

double SimilarityMeasures::L2(TimeSeries* A, TimeSeries* B)
{
    if (A->Getlength() != B->Getlength()) return 0.0 ;


    double dist = 0.0 ;
    for (int i=0;i<A->Getlength();i++)
    {
        cout << "I am here        " << A->GetData()[i]<< endl ;
        dist += (A->GetData()[i] - B->GetData()[i])*(A->GetData()[i] - B->GetData()[i]) ;
    }

    return std::sqrt(dist) ;
}

/*
* This measure can deal with the time series with different length.
*/
double SimilarityMeasures::DTW(TimeSeries *A, TimeSeries*B, int r)
{
    int n = A->Getlength() ;
    int m = B->Getlength() ;

    //int w = w > A->Getlength() ? w : A->Getlength() ;
    int w = std::max(r,std::abs(n-m)) ;


    // initial the matrix of dtw
    double ** dtw = new double*[n];
    for (int t=0;t<n;t++)
    {
        dtw[t] = new double[m] ;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            dtw[i][j] = std::numeric_limits<double>::infinity();
        }
    }
    dtw[0][0] = 0.0 ;

    // Do dynamic time warping
    double cost = 0.0 ;
    for (int i=1; i<n;i++)
    {
        for (int j=std::max(1,i-w);j< std::min(m,i+w);j++)
        {
            cost = std::abs(A->GetData()[i]-B->GetData()[j]) ;
            dtw[i][j] = cost + std::min(dtw[i-1][j],std::min(dtw[i][j-1],dtw[i-1][j-1])) ;
        }
    }

    return dtw[n-1][m-1] ;
}

double SimilarityMeasures::Pearson(TimeSeries *A, TimeSeries *B)
{}
