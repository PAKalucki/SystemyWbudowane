/**********************************************************************************/
/*     Program symulatora SP-841/AVR w wersji do zada� z Symulatorem Obiekt�w     */
/**********************************************************************************/
#include "WorkObiekt.h"				// Definicje zmiennych i prototypy funkcji SP841
#include "SchematA.h"				// Definicje wej�� i wyj�� obiektu A
#include "Zadania.h"				// Zadania u�ytkownika

void inicjuj(void)					// Inicjowanie programu (jednorazowo przy starcie)
{
}

void oblicz(void)					// Kod u�ytkownika - wykonywany co wCykl [ms]
{ 
	//L1=aK1; L2=aK2; L3=aK3; L4=aK4;	// Stan diody LED = Stan klawisza 
	
	test_A();						// Test obiektu "SchematA" (z pliku Zadania.h)
}

void int_T0(void)					// Przerwanie od T0/T1/T2 wywo�ywane tIntr [ms]
{
}

void WykresyPC()					// Opisy/warto�ci wykres�w i zmiennych pomocniczych
{ 
}
