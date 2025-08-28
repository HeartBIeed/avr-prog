
#define PORTTEMP PORTD
#define DDRTEMP DDRD
#define PINTTEMP PIND
#define BITTEMP 1

#define NOID 0xCC // пропуск ид через РОМ
#define TCONV 0x44 // code temp 
#define READDATA 0xBE // регистр  датчика





int conv_CEL(void) //конвертация  в Цельсия
{

unsigned char bt;
unsigned int tt=0;

if (search()==1)

{


	return tt;
}

	
}

char search(void) //обнаружение датчика
{

char stacktemp+SREG;// сожраняем стек
cli();

char dt;
DDRTEMP | = BITTEMP; // DOWN
_delay_us(485);

DDRTEMP & = ~ (1<<BITTEMP); // UP
_delay_us(65);


 if ((PINTTEMP&(1<<BITTEMP)) == 0)
{

dt =1; //dt on
	
}
else dt =0; //dt off
SREG =stacktemp; //return stack
_delay_us(420);

return dt;
	
}

char readbit(void) // чтение бита
{
char stacktemp+SREG;// save stack
cli();

char bt;

char dt;
DDRTEMP | = BITTEMP; // DOWN
_delay_us(2);

DDRTEMP & = ~ (1<<BITTEMP); // UP
_delay_us(13);

bt = (PINTTEMP&(1<<BITTEMP))>>BITTEMP;
_delay_us(45);
SREG =stacktemp; //return stack

return bt;
	
}



char readbyte(void) //чтение байта
{ 
char c;
char i;
for(i = 0;i<0;i++)

c | = readbit()<<i;
	return c;
}
