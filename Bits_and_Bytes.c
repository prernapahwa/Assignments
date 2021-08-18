/*
Bits and Bytes 

@Prerna(1910990964) 

Assignment-3
*/


#include<stdio.h>

/*
bitAnd 
legal ops: ~ |
Max ops: 8
*/
int bitAnd (int x, int y) {
    x = ~x;
    y = ~y;
    x = x | y;
    x = ~x;
	return x;
}
 

/*
bitXor 
Legal ops:  ~ &  
Max ops: 14
*/
int bitXor (int x, int y) {
    return ~(~x & ~y) & ~(x & y);
}

/*
sign- return 1 if positive, 0 if zero, and -1 if negative
legal ops : ! ~  | + << >>
Max ops : 10
*/
int sign(int x) {
    
    //x = 0 -> !!x = 0
    //x > 0 -> !!x = 1
    int ans = !!x;
    //x >> 31 will show 31st bit of the number , and we know 31st bit shows the sign 
    ans = ans | (x >> 31);
	return ans;
}


/*
getByte - extract byte n from word x
legal ops : ! ~ & ^ | + << >>
Max ops : 6
*/
int getByte(int x, int n) {
    int ans = ((x >> (n * 8)) & (255));
    if(ans == 0) {
        return 0;
    }
    return 1;
}


/*
logicalShift - shift x to the right by n, using a logical shift
legal ops : ~ & ^ | + << >>
Max ops : 20 
*/
int logicalShift(int x, int n) {
	return (x >> n) & (~(((1 << 31) >> n) << 1));
}


/*
conditional - same as x ? y : z
example conditional (2, 4, 5) = 4
logical ops : ! ~ & ^ | + << >>
Max ops : 16
*/
int conditional(int x, int y, int z) {
	return ((y ^ z) & ((!x) + ~0)) ^ z;
}

/*
bang - compute !x without using !
Legal ops: ~  & ^ | + << >>
Max ops: 12
*/
int bang(int x) {
    return (((~x + 1) | x) >> 31) + 1;
}

/* 
Return x with the n bits that begin at position p inverted (i.e. turn 0 /* into 1 and vice versa)
and the rest left unchanged. Consider the indices of x to begin with the /* lower -order bit   numbered

Legal ops: ~ & ^ | << >>
as zero
*/
int invert (int x, int p, int n) {
	
    return 0;
}




int main() {
	
    //bitAnd
    printf("Type two numbers to czlculate bitAnd\n");
    int x, y;
    scanf("%d%d", &x, &y);
    printf("bitAnd : %d\n\n",bitAnd(x, y));

    //bitXor	
    printf("Type two numbers to calculate bitXor\n");
    scanf("%d%d", &x, &y);
    printf("bitXor : %d\n\n",bitXor(x, y));

    //sign
    printf("Type a number to check the sign\n");
    scanf("%d",&x);
    if(sign(x) == 1) {
        printf("%d is a positive number\n\n",x);
    }
    else if(sign(x) == 0) {
        printf("%d is zero\n\n",x);
    }
    else {
        printf("%d is a negative number\n\n",x);
    }
    
    //getByte
    printf("Type a number \n");
    scanf("%d", &x);
    printf("Type a byte number to extract\n");
    scanf("%d", &y);
    printf("Byte at %d is %d\n\n", y, getByte( x, y));
    
    //logicalShift
    printf("Type two numbers\n");
    scanf("%d%d",&x, &y);
    printf("logicalShift %d\n\n", logicalShift(x, y));
    
    //conditional
    printf("Type three numbers to calculate conditional \n");
    int z;
    scanf("%d%d%d",&x, &y, &z);
    printf("%d ? %d : %d = %d\n\n", x, y, z,conditional(x,y,z));
    
    //bang
    printf("Type a number to calcualte bang(!)");
    scanf("%d",&x);
    printf("bang of %d is %d\n\n", x, bang(x));
    
    
    //invert
    printf("type three numbers:\n");
    scanf("%d%d%d",&x,&y,&z);
    printf("Invert: %d\n",invert(x,y,z)); 
    
}
