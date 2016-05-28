////////////////////////////////////////////////////////////////////////////////////
// Uwaga! Przed kompilacj¹ programu dopasowaæ do³¹czany plik #inlude "Schemat?.h" //
////////////////////////////////////////////////////////////////////////////////////

// Program testowy do obiektu "SchematA"

void manual(void)
{
	if(!X1)
	{
		Z1 = aK2 ? 1 : 0;
	}
	else 
	{
		Z1=0;
	}
	if(!X3)
	{
		Z2 = aK3 ? 1 : 0;
	}
	else
	{
		Z2=0;
	}
	if(!X5)
	{
		Z3 = aK4 ? 1 : 0;

		Z4 = aK5 ? 1 : 0;
	}
	else
	{
		Z3=0; Z4=0;
	}

	if(X1||X3||X5)
	{
		LCD_xy(1,2); LCD_puts("Uwaga: Blokada  ");
	}
	else
	{
		LCD_xy(1,2); LCD_puts("                ");
	}
	Z5 = aK6 ? 1 : 0;				// Otwórz Z5
	M  = aK7 ? 1 : 0;				// W³¹cz  M (mieszanie)
}

void test_A(void)
{
	switch(stan0)
	{
		case 1: manual();
				LCD_xy(1,1); LCD_puts("Tryb: Manualny  ");
				//LCD_xy(1,2); LCD_puts("                ");
				
				if(aK1&&!pK1)
					stan0=2;
				break;
		case 2:
				LCD_xy(1,1); LCD_puts("Tryb: Auto      ");
				LCD_xy(1,2); LCD_puts("                ");
				if(aK1&&!pK1)
					stan0=1;
				else
				{
					LCD_xy(1,2); LCD_puts("Produkcja w Toku");
					switch(stan1)
					{
						case 1: Z1=1; 
								if(X1) 
									stan1=2;
								break;
						case 2: Z1=0;
								if(!X1)
									stan1=1;
								break;
					}

					switch(stan2)
					{
						case 1: Z2=1; 
								if(X3) 
									stan2=2;
								break;
						case 2: Z2=0;
								if(!X3)
									stan2=1;
								break;
					}
					if(X2&&X4)
					{
						switch(stan3)
						{
							case 1: Z3=0; Z4=0; Z5=0; M=0;
									if(stan1==2&&stan2==2)
									{
										stan3=2;
										tim=20;
									}
									break;
							case 2: Z3=1; Z4=0; Z5=0; M=0;
									if(!tim)
									{
										tim=10;
										stan3=3;
									}
									else
										if(X5)
										{
											tim=30;
											stan3=4;
										}
									break;
							case 3: Z3=0; Z4=1; Z5=0; M=0;
									if(!tim)
									{
										tim=20;
										stan3=2;
									}
									else 
										if(X5)
										{
											tim=30;
											stan3=4;
										}
									break;
							case 4: Z3=0; Z4=0; Z5=1; M=1;
									if(!tim)
									{
										tim=10;
										stan3=5;
									}
									else
										if(!X7)
										{
											tim=100;
											stan3=6;
										}
									break;
							case 5: Z3=0; Z4=0; Z5=0; M=0;
									if(!tim)
									{
										tim=30;
										stan3=4;
									}
									break;
							case 6: Z3=0; Z4=0; Z5=1; M=0;
									if(!tim)
										stan3=1;
									break;
						}
					}
					if(tim)
						--tim;
				}
	}
}

////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematB"
void test_B(void)
{
	Z1 = aK1 ? 1 : 0;				// Otwórz Z1 jeœli naciœniêty K1
	Z2 = aK2 ? 1 : 0;				// Otwórz Z2 jeœli naciœniêty K2
	Z3 = aK3 ? 1 : 0;				// Otwórz Z3 jeœli naciœniêty K3
	Z4 = aK4 ? 1 : 0;				// Otwórz Z4 jeœli naciœniêty K4
	Z5 = 0x1 ? 1 : 0;				// Otwórz Z5
	Z6 = 0x1 ? 1 : 0;				// Otwórz Z6
	Z7 = 0x1 ? 1 : 0;				// Otwórz Z7
	Z8 = 0x1 ? 1 : 0;				// Otwórz Z8

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematC"
void test_C(void)
{
	Z1 = aK1 ? 1 : 0;				// Otwórz Z1 jeœli naciœniêty K1
	Z2 = aK2 ? 1 : 0;				// Otwórz Z2 jeœli naciœniêty K2
	Z3 = aK3 ? 1 : 0;				// Otwórz Z3 jeœli naciœniêty K3
	Z4 = aK4 ? 1 : 0;				// Otwórz Z4 jeœli naciœniêty K4
	Z5 = 0x1 ? 1 : 0;				// Otwórz Z5
	M  = 0x1 ? 1 : 0;				// W³¹cz  M (mieszanie)
	G  = 0x0 ? 1 : 0;				// Wy³¹cz G (grzanie)

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematD"
void test_D(void)
{
	Z1 = aK1 ? 1 : 0;				// Otwórz Z1 jeœli naciœniêty K1
	Z2 = aK2 ? 1 : 0;				// Otwórz Z2 jeœli naciœniêty K2

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematE"
void test_E(void)
{
	Z1 = aK1 ? 1 : 0;				// Otwórz Z1 jeœli naciœniêty K1
	Z2 = aK2 ? 1 : 0;				// Otwórz Z2 jeœli naciœniêty K2

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematF"
char tryb = 1;						// Stan sterownika (AUTO=1/MAN=0)
double r=0.0, u=0.0, y=0.0, e=0.0, um=0;

void test_F(void)
{
	y=(float)Y4/32767;				// Odczyt przetwornika A/C

	if(aK1&&!pK1) u=u>0?0:0.5;		// Prze³¹czanie trybu pracy regulatora

	U1 = (int)(u*32767);			// Wys³anie na przetwornik C/A
	R = (int)(r*32767);				// Wys³anie na przetwornik C/A

	sprintf(buf,"r=%4.2fu=%4.2fy=%4.2f ",r,u,y);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"%c:  ",tryb?'A':'M');
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematG"
void test_G(void)
{
	Z1 = Z2 = aK1 ? 1 : 0;				// W³¹cz Z1 i Z2 jeœli naciœniêty K1
	Z3 = Z4 = aK2 ? 1 : 0;				// W³¹cz Z3 i Z4 jeœli naciœniêty K2
	Z5 = Z6 = aK3 ? 1 : 0;				// W³¹cz Z5 i Z6 jeœli naciœniêty K3
	Z7 = Z8 = aK4 ? 1 : 0;				// W³¹cz Z7 i Z8 jeœli naciœniêty K4

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////
