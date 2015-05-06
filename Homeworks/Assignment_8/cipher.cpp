#include <iostream>
#include <string>
using namespace std;


class Cipher{
  public:
    virtual string encrypt(string text);
    virtual string decrypt(string text);
//string decrypt(string text)
};

string Cipher::encrypt(string text){
  return text;
}

string Cipher::decrypt(string text){
  return text;
}



class Rot13 : public Cipher{
  public:
    string encrypt(string text);
    string decrypt(string text);
};



string Rot13::encrypt(string text){
  for(int i = 0; i< text.length(); i++){
   // a- z checkx 
    if (text[i] <= 'z' && text[i] >= 'a'){
     if (text[i] >= 'n'){
        text[i] = text[i] - 13;
      }
      else
      {
        text[i] = text[i] + 13;
      }
    }
  }

for(int j = 0; j< text.length(); j++){
   // a- z checkx 
    if (text[j] <= 'Z' && text[j] >= 'A'){
     if (text[j] >= 'N'){
        text[j] = text[j] - 13;
      }
      else
      {
        text[j] = text[j] + 13;
      }
    }

  }
  return text;
}




string Rot13::decrypt(string text){
  for(int i = 0; i<= text.length(); i++){
   // a- z checkx 
    if (text[i] <= 'z' && text[i] >= 'a'){
     if (text[i] >= 'n'){
        text[i] = text[i] - 13;
      }
      else
      {
        text[i] = text[i] + 13;
      }
    }
  }

for(int j = 0; j< text.length(); j++){
   // a- z checkx 
    if (text[j] <= 'Z' && text[j] >= 'A'){
     if (text[j] >= 'N'){
        text[j] = text[j] - 13;
      }
      else
      {
        text[j] = text[j] + 13;
      }
    }

  }
  return text;
}

string decrypt_with(Cipher *cipher, string text){
  return cipher -> decrypt(text);
}



string encrypt_with(Cipher *cipher, string text){
  return cipher -> encrypt(text);
}



int main()
{
  string fox = "The quick brown fox jumped over the lazy dog";

  Rot13 *messenger = new Rot13;
  //Rot13 messenger(fox);
 string encrypt = encrypt_with(messenger, fox);
 string decrypt = decrypt_with(messenger, encrypt);

cout << encrypt << endl;
cout << decrypt << endl;

  delete messenger;

  /* code */
  return 0;
}