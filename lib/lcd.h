unsigned char i;

void piszilcd(unsigned char rozkaz)
{
  PORTC &= ~_BV(PC2);
  PORTC |= _BV(PC3);
  PORTC=(PORTC&0x0f)|(rozkaz&0xf0);
  asm("nop");
  asm("nop");
  asm("nop");
  PORTC &= ~_BV(PC3);
  czekaj(1);
  PORTC |= _BV(PC3);
  PORTC=((PORTC&0x0f)|((rozkaz&0x0f)<<4));
  asm("nop");
  asm("nop");
  asm("nop");
  PORTC &= ~_BV(PC3);
  czekaj(1);
}

void piszdlcd(unsigned char dana)
{
  PORTC |= _BV(PC2);
  PORTC |= _BV(PC3);
  PORTC=(PORTC&0x0f)|(dana&0xf0);
  asm("nop");
  asm("nop");
  asm("nop");
  PORTC &= ~_BV(PC3);
  czekaj(1);
  PORTC |= _BV(PC3);
  PORTC=((PORTC&0x0f)|((dana&0x0f)<<4));
  asm("nop");
  asm("nop");
  asm("nop");
  PORTC &= ~_BV(PC3);
  czekaj(1);
}

void czysclcd(void)
{
  piszilcd(0x01);
  czekaj(20);
}

void lcdxy(unsigned char w, unsigned char k)     //ustaw wspó³rzêdne kursora
{
  piszilcd((w*0x40+k)|0x80);  //standardowy rozkaz sterownika LCD
} 

void pisztekst(char * s) 
{
 while(*s) 
  {
   piszdlcd(*s); 
   s++; 
  }
}

void inicjuj_lcd(void)
{
  PORTC &= ~_BV(PC2);
  PORTC &= ~_BV(PC3);
  czekaj(45);
  for(i=0;i<3;i++)
  {
    PORTC |= _BV(PC3);
	PORTC=(PORTC&0x0f)|0x30;
	asm("nop");
	asm("nop");
	asm("nop");
	PORTC &= ~_BV(PC3);
	czekaj(5);
  }
  PORTC |= _BV(PC3);
  PORTC=(PORTC&0x0f)|0x20;
  asm("nop");
  asm("nop");
  asm("nop");
  PORTC &= ~_BV(PC3);
  czekaj(1);
  piszilcd(0x28);
  piszilcd(0x08);
  piszilcd(0x01);
  czekaj(20);
  piszilcd(0x06);
  piszilcd(0x0c);
}