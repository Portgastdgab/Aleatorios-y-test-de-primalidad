#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;




class Trivium{

private:
    int s[288];
    int IV[80],key[80];
    int t1,t2,t3;
    int bits;
    ZZ base10;

    void generate_Key_and_IV(){
        for(int i=0;i<80;i++){
            IV[i]=rand()%2;
            key[i]=rand()%2;
        }
    }

    void rotate(){
        for(int j=93;j>=1;--j)
            s[j]=s[j-1];
        for(int j=177;j>=94;--j)
            s[j]=s[j-1];
        for(int j=288;j>=178;--j)
            s[j]=s[j-1];
        s[0]=t3;  s[93]=t1;  s[177]=t2;
    }


    void init(){
        generate_Key_and_IV();

        for(int i=0;i<288;i++) s[i]= 0;

        for(int i=0;i<80;++i){
            s[i]=key[i];
            s[i+93]=IV[i];
        }
        for(int i=285;i<288;++i) s[i]=1;

        //rotate
        for(int i=1;i<1152;i++){
            t1 = ((s[65] ^ (s[90] & s[91]) )^ s[92] )^ s[170];
            t2 = ((s[161] ^ (s[174] & s[175]) )^ s[176] )^ s[263];
            t3 = ((s[242] ^ (s[285] & s[286]) )^ s[287] )^ s[68];
            rotate();
        }
    }
public:
    ZZ keyStream(){
        ZZ z(0);
        base10 =0;
        for(int i=0;i<bits;i++){

            t1 = s[65] ^ s[92];
            t2 = s[161] ^ s[176];
            t3 = s[242] ^ s[287];

            z = t1 ^ t2 ^ t3;

            t1 ^= s[90] ^ s[91] & s[170] ;
            t2 ^= s[174] ^ s[175] & s[263] ;
            t3 ^= s[285] ^ s[286] & s[68] ;
            rotate();
            base10 += z<<i;
        }

        return z;
    }


    Trivium(int bits){
        this ->bits = bits;
        init();
    }

    ZZ PseudoRandom(){
        ZZ n;
        do{
            n = keyStream();
        }while(countBits(base10)!=bits);

        return base10;
    }

    int countBits(ZZ n){
        int count =0;
        while(n != 0){
            count++;
            n>>=1;
        }
        return count;
    }

    double entropy(){
        double uno=0,zero=0,total=0;
        for(int i=0;i<bits;i++){
            ZZ bit ( keyStream());
            if(bit == 1) uno++;
            else zero ++;
            total++;
        }
        double p1= uno/total;
        double p2= zero/total;
        return -p1 * log2(p1) - p2* log2(p2);
    }

};




int main() {


	srand(time(0));


    int bits = 2048;

    ZZ n;
    Trivium test(bits);
    n= test.PseudoRandom();

    //ENTROPIA - TEST
    cout<<"\nEntropy: "<<test.entropy();

    /*
    cout<<"\nnumero: "<<n<<endl;
    cout<<"\nbits: "<<test.countBits(n);*/

    cout<<endl;



}
