#include <iostream>
using namespace std;
#define N  4 // liczba ciągów uczących

//Program realizujący pojedynczy neuron
//Na wejściu neuronu beda podawane dwie liczby
//   we1 > we2  => na wy -1
//	 we1 <= we2  => na wy 1

//neuron - dwa wejcia x1, x2 i jedno wyjście y
//neuron dodatkowo bedzie posiadal bias x3

// sukces w działaniu neuronu leży we wagach
// waga  x3 - waga bias,  x1, x2

  
//definicja neuronu
class neuron
{
 int x1, x2, x3, x4, x5, x6, x7, x8, x9;      //wejścia neuronu
 int w1, w2, w3, w4, w5, w6, w7, w8, w9;      //wagi     -||-
 int y;               //wyjście  
 
 public:
 void inicjalizacja();
 void nauka(int we1, int we2, int we3, int we4, int we5, int we6, int we7, int we8, int we9, int wy); //stany na wejsciu i poprawne wyjscie
 int sprawdzaj(int we1, int we2, int we3, int we4, int we5, int we6, int we7, int we8, int we9, int wy);
 void wyswietl();           //wyswietl wagi
};

void neuron::wyswietl()
{
	cout<<w1<<" "<<w2<<" "<<w3<<endl;
}

void neuron::inicjalizacja()
{   //x3 - bias dlatego wartosc 1
	x1 = 1; x2 = 0; x3 = 0; x4 = 0; x5 = 1; x6 = 0; x7 = 0; x8 = 0; x9 = 1;
	w1 = 3; w2 = 1; w3 = 1; w4 = 2; w5 = 4; w6 = 3; w7 = 1; w8 = 6; w9 = 5; 
}

int neuron::sprawdzaj(int we1, int we2, int we3, int we4, int we5, int we6, int we7, int we8, int we9, int wy)
{ 
  x1 = we1;
  x2 = we2;
  x3 = we3;
  x4 = we4;
  x5 = we5;
  x6 = we6;
  x7 = we7;
  x8 = we8;
  x9 = we9;  
  int z; 
  // liczmy wartosc w bloku sumuj¹cym
  //blok sumujacy	
  z = (x1*w1) + (x2*w2) + (x3*w3);
  cout<<"\n  z: "<<z;
   
  //blok aktywacji
  if (z < 0)
  	y = 0;
  else
  	y = 1;	
  	
  return y;	
}

//definicja wektora uczacego
// N - wektorow uczacych
// kazdy wektor sklada sie z x1, x2 i   y1
int w_uczacy[N][10]={
{1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
{0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 1, 0},

};  


void neuron::nauka(int we1, int we2, int we3, int we4, int we5, int we6, int we7, int we8, int we9, int wy)
{   
  x1 = we1;
  x2 = we2;
  x3 = we3;
  x4 = we4;
  x5 = we5;
  x6 = we6;
  x7 = we7;
  x8 = we8;
  x9 = we9;  
	
	y = sprawdzaj(we1, we2, we3, we4, we5, we6 , we7, we8, we9, wy);
	
	//warunek czy zmeiniamy wagi
	cout<<"\n y:"<<y<<endl;
	if(y != wy)
	{
		w1 = w1 + 2*wy*we1;
		w2 = w2 + 2*wy*we2;
		w3 = w3 + 2*wy*y;   //bias 
	}
	
}


int main(int argc, char** argv) {
int x1, x2, x3, x4, x5, x6, x7, x8, x9, y1;	
neuron test;
test.inicjalizacja();

for(int i=0; i<N; i++)
{ x1 = w_uczacy[i][0];
  x2 = w_uczacy[i][1];
  x3 = w_uczacy[i][2];
  x4 = w_uczacy[i][3];
  x5 = w_uczacy[i][4];
  x6 = w_uczacy[i][5];
  x7 = w_uczacy[i][6];
  x8 = w_uczacy[i][7];
  x9 = w_uczacy[i][8];
  y1 = w_uczacy[i][9];
  test.	nauka(x1, x2, x3, x4, x5, x6, x7, x8, x9, y1); 	
  test.wyswietl();
}
cout<<"rozpoznajemy: ";
cout <<endl<<test.sprawdzaj(1, 0, 0, 1, 0, 0, 0, 0, 1, 1);	
	
	

}
