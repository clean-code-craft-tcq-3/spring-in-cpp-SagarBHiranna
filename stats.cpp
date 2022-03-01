#include "stats.h"
#include <math.h>

//#include <iostream>


Stats Statistics::ComputeStatistics(const std::vector<float>& vector_ref) {
    //Implement statistics here
    Stats struct_variable;
    float sum = 0.0;
    if (vector_ref.empty() == true )
    {
        struct_variable.average = NAN;
        struct_variable.min = NAN;
        struct_variable.max = NAN;       
    }
    else
    {   
        struct_variable.min = vector_ref[0];
        struct_variable.max = vector_ref[0];
        struct_variable.average = 0;
        for (int i = 0; i < int(vector_ref.size()); i++)
        {
            if (vector_ref[i] > struct_variable.max)
            {
                struct_variable.max = vector_ref[i];
            }
            if (vector_ref[i] < struct_variable.min)
            {
                struct_variable.min = vector_ref[i];
            }
            sum = sum + vector_ref[i];
            
        }
        struct_variable.average = sum/vector_ref.size();

    }

    return struct_variable;
    
}
