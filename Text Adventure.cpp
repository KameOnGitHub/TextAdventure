#include <sstream>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
#include "Defines.h"
#include "Utility Functions.h"
#include "Output.h"
//#include "Map.h"





int main(){
	//Initialization
	renderer rend(WINDOW_WIDTH, WINDOW_HEIGHT);
	srand(time((0)));
	//--------

	while (true){
		rend.blankOutputBuffer();
		rend.generateColorNoise();
		rend.updateScreen();
		//rend.testDebug();

	}



    return(0);
}
