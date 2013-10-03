#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define A(X,Y,Z)while(i<=X##9){r=(R(a,5))+(Y)+e+0x##Z+W(0);e=d;d=c;c=R(b,30);b=a;a=r;i++;}
#define R(X,Y)(X<<Y)|(X>>(32-Y))
#define W(A)w[i-A]
#define T typedef unsigned
T int u;T char v;int main(int argc,char**argv){char*s=argv[1];u m=0x67452301,n=
0xEFCDAB89,o=0x98BADCFE,p=0x10325476,q=0xC3D2E1F0,a=m,b=n,c=o,r=24,d=p,e=q,i,w[
80],l=strlen(s),k=0;v t[l+1];memcpy(t,s,l);t[l++]=128;for(i=0;i++<l;){w[k]+=t[i
-1]<<r;((r-=8)>24)?k++,r=24:0;}w[15]=(l-1)*8;for(i=15;i++<80;){r=W(3)^W(8)^W(14
)^W(16);w[i]=R(r,1);}i=0;A(1,(b&c)|((~b)&d),5A827999)A(3,b^c^d,6ED9EBA1)A(5,(b&
c)|(b&d)|(c&d),8F1BBCDC)A(7,b^c^d,CA62C1D6);printf("%08x%08x%08x%08x%08x\n",m+a
,n+b,o+c,p+d,q+e);}
