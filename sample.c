#include <stdio.h>


void main(){
    char c = 0x07;
    char *c_ptr = (char *)0xffffa000;
	long long *lp;

	unsigned int i;

    printf("cのアドレス: %p\n",&c);

	
	lp=&c;
	*lp = 0xffffffffffff;

	for(i=0;i<10000;i++){
		*c_ptr=(char)i+0x21;//c_ptrの指すメモリ領域に値をブチ込む
		c_ptr++;//一つ次の領域を指すようにする
	}
	
	c_ptr = (char *)0xffffa000;
	for(i=0;i<10000;i++){
		*c_ptr=0;
		c_ptr++;
	}
	
	
}
