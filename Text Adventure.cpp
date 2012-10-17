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
#include "Map.h"




int main(){


	map testMap;
	testMap.loadFromFile("3x3.txt");
	testMap.debug();


     
	
    while(true){        
//* extra comments for extra protection, duh
//        if(GetAsyncKeyState(VK_LEFT)){
//            playerx-=1;
//        }else if(GetAsyncKeyState(VK_RIGHT)){
//            playerx+=1;    
//        }else if(GetAsyncKeyState(VK_UP)){
//            playery-=1;   
//        }else if(GetAsyncKeyState(VK_DOWN)){
//            playery+=1;   
//        }
//        */
//		
		system("cls");
		cout << "W:" << testMap.getWidth() << endl
			 << "H:" << testMap.getHeight() << endl;
		testMap.loadFromFile("3x3.txt");
		testMap.debug();
//        
//       // Sleep(1000);
   }

    return(0);
}
