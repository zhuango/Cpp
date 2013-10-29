#include <windows.h>
#include <iostream> 
using namespace std; 
const int DO = 261; 
const int RE = 293; 
const int MI = 329; 
const int FA = 349; 
const int SO = 392; 
const int LA = 440; 
const int TI = 493; 
const int DO_ = 130;
const int RE_ = 147; 
const int MI_ = 165; 
const int FA_ = 174;
const int SO_ = 186; 
const int LA_ = 220; 
const int TI_ = 247; 
int main()
{ 
	Beep(LA,300);//6 
	Beep(SO,100);//5 
	Beep(MI,300);//3 
	Beep(RE,100);//2 
	Beep(DO,400);//1 
	Beep(MI,300);//3 
	Beep(RE,100);//2 
	Beep(DO,200);//1 
	Beep(LA_,100);//6. 
	Beep(SO_,400);//5. 
	Beep(SO_,300);//5. 
	Beep(LA_,100);//6. 
	Beep(SO_,300);//5. 
	Beep(LA_,100);//6. 
	Beep(DO,300);//1
	Beep(RE,100);//2 
	Beep(MI,200);//3 
	Beep(SO,200);//5 
	Beep(LA,300);//6 
	Beep(SO,100);//5 
	Beep(MI,100);//3 
	Beep(RE,100);//2 
	Beep(DO,200);//1 
	Beep(RE,400);//2
	Beep(LA,300);//6
	Beep(SO,100);//5 
	Beep(MI,300);//3 
	Beep(RE,100);//2 
	Beep(DO,400);//1 
	Beep(MI,300);//3 
	Beep(RE,100);//2 
	Beep(DO,200);//1 
	Beep(LA_,100);//6. 
	Beep(SO_,400);//5.
	Beep(SO_,300);//5. 
	Beep(LA_,100);//6.
	Beep(SO_,300);//5. 
	Beep(LA_,100);//6. 
	Beep(DO,300);//1 
	Beep(RE,100);//2 
	Beep(MI,200);//3 
	Beep(SO,200);//5 
	Beep(LA,300);//6 
	Beep(SO,100);//5 
	Beep(MI,100);//3 
	Beep(RE,100);//2 
	Beep(DO,200);//1 
	Beep(DO,400);//2 
	return 0; 
} 