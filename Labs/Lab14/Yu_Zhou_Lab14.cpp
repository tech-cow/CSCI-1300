#include <math.h>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;


class Throne{
public:
    void crown(string *player);
};




void Throne::crown(string *player){
      player->append("is the ruler of the seven kingdoms");
      //(*player).append
  }


int main()
{
    string cersei = "Cersei Lannister";
    string daenerys = "Daenerys Targaryen";
    string jaime = "Jaime Lannister";

    string * queen = &cersei;
    string * mother_of_dragons = &daenerys;
    string * kingslayer = &jaime;

    Throne * iron_throne = new Throne;
    iron_throne->crown(queen);
    iron_throne->crown(mother_of_dragons);
    iron_throne->crown(kingslayer);

    cout << *queen << endl;
    cout << *mother_of_dragons << endl;
    cout << *kingslayer << endl;

    free(iron_throne);
    iron_throne = NULL;

}