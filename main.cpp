#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>


using namespace std;

int main(){
    int x, y;
    
    string playground;
    
    char map[15][15];
    int playerx=1,playery = 1;
    char playersymbol = '@';
    
    
    for(x=0;x<=15;x++){
        for(y=0;y<=15;y++){
            if((y==0 || y==14) || (x==0 || x==14) || (y==0 || y==14) && (x==0 || x==14)){
                map[x][y] = '#';
            }else{
                map[x][y] = '.';
            }
        }
    }
    while(true){
        if(GetAsyncKeyState(VK_RIGHT)){
            playerx+=1;
            map[playerx-1][playery] = '.';
        }else if(GetAsyncKeyState(VK_LEFT)){
            playerx-=1;
            map[playerx+1][playery] = '.';
        }else if(GetAsyncKeyState(VK_UP)){
            playery-=1;
            map[playerx][playery+1] = '.';
        }else if(GetAsyncKeyState(VK_DOWN)){
            playery+=1;
            map[playerx][playery-1] = '.';
        }
        if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN)){
                    
            map[playerx][playery] = '@';
        
            playground = "";
        
            for(y=0;y<15;y++){
                for(x=0;x<15;x++){
                    //cout << map[x][y];
                    playground+=map[x][y];
                }
                //cout << endl;
                playground+='\n';
            }
        system("cls");   
        cout << playground;
   }
   
        Sleep(5);
}
    Sleep(10000);
    
    return(0);
}
/*
######
#.....
#.....
######
*/
