void czekaj(unsigned long int del)
{  
  unsigned int tp;
  for(;del>0;del--)
    for(tp=200;tp!=0;tp--)
	  asm("nop");	
}