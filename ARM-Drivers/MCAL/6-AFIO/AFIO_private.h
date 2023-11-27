#ifndef AFIO_private_h
#define AFIO_private_h


/*BASE ADRESS 0x40010000*/

typedef struct {
	u32 MAPR;
	u32 EXTICR[4];
	u32 MAPR2;
}AFIO_t;

#define AFIO ((volatile AFIO_t *) 0x40010000)



#endif
