#define A(Y,Z)for(i=0;i++<20;a=r){r=(a<<5|a>>27)+(b Y d)+e+0x##Z+w[x++];e=d;d=c;c=b<<30|b/4;b=a;}
w[80],i,k;int main(x,y)char**y;{unsigned int m=0x67452301,n=0xEFCDAB89,o=
0x98BADCFE,p=0x10325476,q=0xC3D2E1F0,a=m,b=n,c=o,r=24,d=p,e=q,l=strlen(y[1]);y[
1][l++]=128;for(;i<l;){w[k]+=(unsigned char)y[1][i++]<<r;((r-=8)>24)?k++,r=24:0
;}w[i=15]=(l-1)*8;for(;i++<80;){r=w[i-3]^w[i-8]^w[i-14]^w[i-16];w[i]=r*2|r>>31;
}x=0;A(&c|~b&,5A827999)A(^c^,6ED9EBA1)A(&c|b&d|c&,8F1BBCDC)A(^c^,CA62C1D6)
printf("%08x%08x%08x%08x%08x\n",m+a,n+b,o+c,p+d,q+e);}
