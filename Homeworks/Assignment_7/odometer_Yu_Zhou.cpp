/*Define  a class called  Odometer  that  will  be  used  to  track fuel  and mileage for an  
automobile. Include private member  variables to  track the miles driven  and the fuel  
efficiency  of  the vehicle in  miles per gallon. The class should  also  have  a constructor that  
initializes these values  to  zero. Also  include a member  function  to  reset the odometer  to  
zero  miles,  a member  function  to  set the fuel  efficiency, a member  function  that  accepts 
miles driven  for a trip  and adds  it  to  the odometer’s  total,  and a member  function  that  
returns the number  of  gallons that  the vehicle has consumed  since the odometer  was last  
reset.
You can use the main()  below to  test  your  program:*/

#include <iostream>
using namespace std;


class Odometer{
  private:
    double miles;
    double fuel_efficiency;

  public:
  Odometer(){
    miles = 0.0;
    fuel_efficiency = 0.0;
  }

  void reset(){
    miles = 0.0;
    //fuel_efficiency = 0.0;
  }

  void setFuelEfficiency(double Fuel_efficiency){
    fuel_efficiency = Fuel_efficiency;
  }

  void logMiles(double Miles){
    miles = Miles;
  }

  double gasConsumed(){
    return miles/fuel_efficiency;
  }



};


int main()
{
  
 Odometer trip1, trip2;
 trip1.reset();
 trip1.setFuelEfficiency(45);
 trip1.logMiles(100);
 cout << "For your fuel-efficient small car:" << endl;
 cout << "After 100 miles, " << trip1.gasConsumed() <<
 " gallons were used." << endl;
 trip1.logMiles(50);
 cout << "After another 50 miles, " << trip1.gasConsumed() <<
 " gallons were used." << endl; 

 cout << endl;

 trip2.reset();
 trip2.setFuelEfficiency(13);
 trip2.logMiles(100);
 cout << "For your gas guzzler:" << endl;
 cout << "After 100 miles, " << trip2.gasConsumed() <<
 " gallons were used." << endl;
 trip2.logMiles(50);
 cout << "After another 50 miles, " << trip2.gasConsumed() <<
 " gallons were used." << endl;

 return 0;
}