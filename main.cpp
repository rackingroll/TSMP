#include <iostream>
#include "TimeSeries.h"
#include "SimilarityMeasures.h"
#include "SearchFramework.h"

using namespace std;

int main()
{
    SimilarityMeasures* measure = new SimilarityMeasures();

    double a[10] = {1,2,3,4,5,7,8,9,7,5} ;
    double b[10] = {1,3,3,43,5,6,8,9,7,5} ;

    TimeSeries *A = new TimeSeries(a,10) ;
    TimeSeries *B = new TimeSeries(b,10) ;

    cout << "Hello world!" << endl;
    cout << measure->DTW(A,B,4) << endl ;

    cout << "Just test!" << endl ;
    delete A ;
    delete B ;
    return 0;
}
