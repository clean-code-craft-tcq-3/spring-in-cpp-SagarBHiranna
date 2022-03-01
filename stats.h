#include <vector>


struct Stats
{
    float average, min, max ;
};

namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& vector_ref);
}

struct EmailAlert{int emailSent;};
struct LEDAlert{int ledGlows;};

//typedef void (*IAlerter)(EmailAlert a, LEDAlert b);
//typedef struct IAlerter{struct a;} ;
typedef void (*IAlerter) ;



//class EmailAlert
//{
//
//};

//class LEDAlert
//{
//
//};

//struct IAlerter 
//{
 //   EmailAlert a;
  //  LEDAlert b;
//};

//int IAlerter ;

class StatsAlerter
{   
    
   public :
   float ThresholdMax;
    std::vector<IAlerter> alerters_alias;
        //float maxThreshold;
        //std::vector<IAlerter*> alerters;
        EmailAlert email;
           LEDAlert led ;
       StatsAlerter(const float maxThreshold, std::vector<IAlerter> alerters)
       {
           ThresholdMax = maxThreshold;
           alerters_alias = alerters;
       };

       void checkAndAlert(const std::vector<float>& vector_ref)
       {
           
           int flag = 0;
           std::vector<IAlerter> alerters_alias1 = { &email, &led};
            
           for (int i = 0; i < int(vector_ref.size()); i++)
        {
            if (vector_ref[i] > ThresholdMax)
            {
                //struct_variable.max = vector_ref[i];
                //alerters_alias[0].emailSent = 1 ;
                
                flag = 1;

            }
            if (flag)
            {
                email.emailSent=1;
                led.ledGlows=1;
            }
            else
            {
                email.emailSent=0;
                led.ledGlows=0;
            }
        }
        //return 0;
       };

       int update_email(){
           return email.emailSent;
       };
       int update_led(){
           return led.ledGlows;
       };
};
