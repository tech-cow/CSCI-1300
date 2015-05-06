/*
----------------------------------------------------Read Me-------------------------------------------------------
If you encounter:
cipher.cpp:(.text+0x89a): undefined reference to `EVP_CIPHER_CTX_cleanup'
collect2: error: ld returned 1 exit status

you need openssl library installed, and include openss/evp.h
--------------------------------------------
and try this: g++ Crypto.cc -lssl -lcrypto
--------------------------------------------
Some comment are in chinese... for me to retreive memory later, I have general explaination through the code.

------------------------------------------------------------------------------------------------------------------
*/

//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>
#include <iostream>
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

void aes_encrypt(unsigned char* in, int inl, unsigned char *out, int* len, unsigned char * key){
    unsigned char iv[8];
    EVP_CIPHER_CTX ctx;
    //all it does is set memset 0
    EVP_CIPHER_CTX_init(&ctx); 
 
    //cipher  = EVP_aes_128_ecb();  
    //original block of code: int EVP_EncryptInit_ex(EVP_CIPHER_CTX *ctx,const EVP_CIPHER *cipher, ENGINE *impl, const unsigned char *key, const unsigned char *iv)   
    EVP_EncryptInit_ex(&ctx, EVP_aes_128_ecb(), NULL, key, iv);  
 
    *len = 0;
    int outl = 0;

    
    
    //without update function, aes_128 size would be 16 bytes, and padding after that will show up random segment of !#@$%^&, with update,
    //it will multiply the block-size to the bytes, if input is around 50 bytes, it will encrypt 48 and decrpt 48 bytes only 
    EVP_EncryptUpdate(&ctx, out+*len, &outl, in+*len, inl);
    *len+=outl;
    

    
    //the remainder bytes, will be padding here
    int test = inl>>4;
    if(inl != test<<4){
        EVP_EncryptFinal_ex(&ctx,out+*len,&outl);  
        *len+=outl;
    }
    EVP_CIPHER_CTX_cleanup(&ctx);
}
 
 
void aes_decrypt(unsigned char* in, int inl, unsigned char *out, unsigned char *key){
    unsigned char iv[8];
    EVP_CIPHER_CTX ctx;
    
    //set memset 0 again
    EVP_CIPHER_CTX_init(&ctx);
 
    EVP_DecryptInit_ex(&ctx, EVP_aes_128_ecb(), NULL, key, iv); 
    int len = 0;
    int outl = 0;
 
    EVP_DecryptUpdate(&ctx, out+len, &outl, in+len, inl);
    len += outl;
      
    EVP_DecryptFinal_ex(&ctx, out+len, &outl);  
    len+=outl;
    out[len]=0;
    EVP_CIPHER_CTX_cleanup(&ctx);
}


int main()
{
	 string fox = "The quick brown fox jumped over the lazy dog";

	  Rot13 *messenger = new Rot13;
	  //Rot13 messenger(fox);
	 string encrypt = encrypt_with(messenger, fox);
	 string decrypt = decrypt_with(messenger, encrypt);
	 
	 cout << endl;
	 cout <<"Rot13 encryption: " <<  encrypt << endl;
	 cout << "Rot13 decryption: " << decrypt << endl;
	 cout << endl;

     delete messenger; //free

     unsigned char content[400];
     unsigned char key[] = "The quick brown fox jumped over the lazy dog";
     
      unsigned char en[400],de[400],base64[400], base64_out[400];
      int len; 
      memset(content, 0,400);
      memset(en, 0, 400);
      memset(de, 0, 400);
      memset(base64, 0,400);
      memset(base64_out, 0, 400);
      strcpy((char*)content, "The quick brown fox jumped over the lazy dog");
     
      //cout <<"AES encryption: " content << endl;
      aes_encrypt(content,strlen((const char*)content), en, &len, key);
     
      int encode_str_size = EVP_EncodeBlock(base64, en, len);
      cout << "AES encryption: " << base64 << endl;
     
      int length = EVP_DecodeBlock(base64_out, base64, strlen((const char*)base64));
      
      while(base64[--encode_str_size] == '=') length--;
     
      aes_decrypt(base64_out, length, de, key);
      cout << "AES decryption: " << de << endl;



  return 0;
}
