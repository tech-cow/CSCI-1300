/*
----------------------------------------------------Read Me-------------------------------------------------------
if you encounter following while compiling:
cipher.cpp:(.text+0x624): undefined reference to `EVP_CIPHER_CTX_init'
cipher.cpp:(.text+0x629): undefined reference to `EVP_aes_128_ecb'
cipher.cpp:(.text+0x654): undefined reference to `EVP_EncryptInit_ex'
cipher.cpp:(.text+0x6b8): undefined reference to `EVP_EncryptUpdate'
cipher.cpp:(.text+0x722): undefined reference to `EVP_EncryptFinal_ex'
cipher.cpp:(.text+0x74b): undefined reference to `EVP_CIPHER_CTX_cleanup'
/tmp/ccaU34QD.o: In function `decrypt(unsigned char*, int, unsigned char*, unsigned char*)':
cipher.cpp:(.text+0x7a5): undefined reference to `EVP_CIPHER_CTX_init'
cipher.cpp:(.text+0x7aa): undefined reference to `EVP_aes_128_ecb'
cipher.cpp:(.text+0x7d5): undefined reference to `EVP_DecryptInit_ex'
cipher.cpp:(.text+0x830): undefined reference to `EVP_DecryptUpdate'
cipher.cpp:(.text+0x869): undefined reference to `EVP_DecryptFinal_ex'
cipher.cpp:(.text+0x89a): undefined reference to `EVP_CIPHER_CTX_cleanup'
collect2: error: ld returned 1 exit status

you need openssl library installed, and include openss/evp.h
and try this: g++ Crypto.cc -lssl -lcrypto

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
    
    //这个EVP_EncryptUpdate的实现实际就是将in按照inl的长度去加密，实现会取得该cipher的块大小（对aes_128来说是16字节）并将block-size的整数倍去加密。
    //如果输入为50字节，则此处仅加密48字节，outl也为48字节。输入in中的最后两字节拷贝到ctx->buf缓存起来。  
    //对于inl为block_size整数倍的情形，且ctx->buf并没有以前遗留的数据时则直接加解密操作，省去很多后续工作。 
    
    
    //without update function, aes_128 size would be 16 bytes, and padding after that will show up random segment of !#@$%^&, with update,
    //it will multiply the block-size to the bytes, if input is around 50 bytes, it will encrypt 48 and decrpt 48 bytes only 
    EVP_EncryptUpdate(&ctx, out+*len, &outl, in+*len, inl);
    *len+=outl;
    
    //余下最后n字节。此处进行处理。
    //如果不支持pading，且还有数据的话就出错，否则，将block_size-待处理字节数个数个字节设置为此个数的值，如block_size=16,数据长度为4，则将后面的12字节设置为16-4=12，补齐为一个分组后加密 
    //对于前面为整分组时，如输入数据为16字节，最后再调用此Final时，不过是对16个0进行加密，此密文不用即可，也根本用不着调一下这Final。
    
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
    //此init做的仅是将ctx内存 memset为0  
    
    //set memset 0 again
    EVP_CIPHER_CTX_init(&ctx);
 
    //cipher  = EVP_aes_128_ecb();  
    //原型为int EVP_EncryptInit_ex(EVP_CIPHER_CTX *ctx,const EVP_CIPHER *cipher, ENGINE *impl, const unsigned char *key, const unsigned char *iv)   
    //另外对于ecb电子密码本模式来说，各分组独立加解密，前后没有关系，也用不着iv  
    
    //blah blah again like before
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
      //EVP_DecodeBlock内部同样调用EVP_DecodeInit + EVP_DecodeUpdate + Evp_DecodeFinal实现，但是并未处理尾部的'='字符，因此结果字符串长度总是为3的倍数
      while(base64[--encode_str_size] == '=') length--;
     
      aes_decrypt(base64_out, length, de, key);
      cout << "AES decryption: " << de << endl;



  return 0;
}
