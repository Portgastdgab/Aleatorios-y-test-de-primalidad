#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;



/*----------Funciones-----------------*/


ZZ module(ZZ a, ZZ n){
	ZZ r = a-n*(a/n);
	r = r+(r<0)*n;
	return r;
}

ZZ modPow(ZZ a ,ZZ n,ZZ m){

	ZZ exp (1);
	ZZ x = module(a,m);

	while(n>0){
		if(module(n, ZZ(2)) == 1)
			exp = module(exp*x,m);
		x = module(x*x,m);
		n>>=1;
	}
	return exp;
}


ZZ RandomNumber(ZZ init,ZZ end) {
	ZZ k = end - init + 1;
	ZZ num = RandomBnd(k)+init;
	return num;
}


/*-----------end funciones -----------*/




bool millerRabinTest(ZZ number, ZZ iter)
{
	// Casos Base
	if(module(number,ZZ(2))== 0) return false;
	if (number <= 1 || number == 4)  return false;
	if (number <= 3) return true;

	// number-1 = 2^d * r ; r >= 1
	ZZ d = number - 1;

	//Hallar  el exponente d
	while (module(d,ZZ(2)) == 0)
		d >>= 1;


	// Iterar
	for (ZZ i (0); i < iter; i++){

		// obtener un numero random en [2..n-2]
		ZZ a = RandomNumber(ZZ(2),number-2);

		// X =  a^d mod( n)
		ZZ x = modPow(a, d, number);

		if (x == 1  || x == number-1)
			return true;

		while (d != number-1)
		{
			x= module(x*x,number);
			//x= x*x % n;
			d <<=1;

			if (x == 1)   return false;
			if (x == number-1)  return true;
		}
		return false;
	}

	return true;
}

bool Fermat(ZZ n,ZZ t){
    for(ZZ i = ZZ(1); i<=t;i++){
        ZZ a= RandomNumber(ZZ(2),n-2);
        ZZ r = modPow(a, n-1, n);
        if (r!=1)   return false;
    }
    return true;
}

ZZ _Jacobi(ZZ a,ZZ n){
    ZZ t=ZZ(1);
    while(a!=0){
        while((a & 1) == 0){
            a>>=1;
            if (module(n,ZZ(8))==3 || module(n,ZZ(8))==5) t=t*-1;
        }
        ZZ temp = a;
        a=n;
        n=temp;
        if(module(a,ZZ(4))==3 && module(n,ZZ(4))==3) t=t*-1;
        a=module(a,n);
    }
    if(n==1){
        return t;
    }
    else{
        return ZZ(0);
    }
}

bool Solovay_Strassen(ZZ n,ZZ t){
    for(ZZ i = ZZ(1); i<=t;i++){
        ZZ a = RandomNumber(ZZ(2),n-2);
        ZZ r = modPow(a,(n-1)/2,n);
        if (r!=1 && r!=n-1) return false;
        ZZ s = _Jacobi(a,n);
        if (module(r, n)!=s) return false;
    }
    return true;
}


int main() {
    ZZ num =  conv<ZZ>("300746832151829907887130288070820214432");

	cout<<millerRabinTest(ZZ(num),ZZ(5));
	//cout<<Fermat(ZZ(num),ZZ(5));
	//cout<<Solovay_Strassen(ZZ(num),ZZ(5));


}
