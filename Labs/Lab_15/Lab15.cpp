#include <iostream>
using namespace std;

//Base
class Dinosaur{
  public:
    void eatHumans(int &humans);
};

void Dinosaur::eatHumans(int &humans){
  cout << humans << endl;
}



//Derived 
class Velociraptor: public Dinosaur
{
  public:
    void eatHumans(int &humans);
};

void Velociraptor::eatHumans(int &humans){
    humans = humans - 1;
    cout << humans << endl;
  }




class Trex: public Dinosaur
{
public:
  void eatHumans(int &humans);
};


void Trex::eatHumans(int &humans){
    humans = humans - 2;
    cout << humans << endl;
}




class Brontosaur: public Dinosaur
{
  public:
  void eatHumans(int &humans);
};

void Brontosaur::eatHumans(int &humans){
    cout << "I eat grass" << endl;
}


int main()
{
  int humans = 100;
  Velociraptor eat_one;
  Trex eat_two;
  Brontosaur eat_none;
try{
      do{
        cout << "The number of victims left are:";
        eat_one.eatHumans(humans);
        cout << "The number of victims left are:";
        eat_two.eatHumans(humans);
        eat_none.eatHumans(humans);
        }while (humans != 1);
      if (humans == 1)
      {
        throw 99;
      }
   }catch(int x){cout << "Not enough victims left to eat. Only 1 survivor left in the Park."<< endl;}

  return 0;
}
