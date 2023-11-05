//
//  WeightedMovingAverage.cpp
//  weightedMovingAverage
//
//  Created by Jaeil Jeong on 2023/11/04.
//

#include "WeightedMovingAverage.hpp"

class WeightedMovingAverage{

private :
    double *values;
    double *weights;
    int n;
    int position;
public :
    WeightedMovingAverage(int n , double * w) : position(0) , n(n){
     
        //이동평균을 구하는데 필요한 공간은 동적으로 할당
        values = new double[n];
        weights = new double[n];
        n = n;
        for(int  i = 0; i <n ; i ++){
            weights[i] = w[i];
        }
    }
    
    
    void calculateWMA(double * v , int vSize){
        
        double sum = 0;
        double weightSum = 0;
        int size = 0;
        if(vSize>n){
            size = vSize;
        }else{
            size = n;
        }

        for(int i = 0 ; i< n ; i++){
            
            sum += v[(vSize -1 -i) %n] * weights[i];
            std::cout <<v[(vSize-1-i)];
            std::cout <<"\n";
            weightSum += weights[i];
        }
        
        std::cout << (sum / weightSum);
    
                
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout <<"gdgd\n";
double weights[] = {0.5, 0.3, 0.15, 0.05};
   double values[] = {10,5,8,12,10,14};
    WeightedMovingAverage w(4,weights);
    w.calculateWMA(values , sizeof(values)/sizeof(values[0]));
    return 0;
}
