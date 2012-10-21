#include <sstream>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
#include "Defines.h"
#include "Utility Functions.h"
#include "Output.h"
#include "NewMap.h"





int main(){
	//Initialization
	srand((unsigned int)time((0))); //initialize random function
	renderer render(WINDOW_WIDTH, WINDOW_HEIGHT);
	map location; location.loadFromFile("map.txt");
	map displaySegment;//section of map data to render
	//--------

	while (true){
		location.loadFromFile("map.txt");
		render.blankOutputBuffer();
		render.generateColorNoise();
		render.addToBuffer(location.get_vvPixel(), 1, 1, location.get_height(), location.get_width());
		render.updateScreen();
		//rend.testDebug();
		Sleep(1);
	}



    return(0);
}
