#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;

char readmap(char map[][1000], int *mapwidth = 0, int *mapheight = 0){

    int x,y;

    int mapw = 0;
    int maph = 0;

    string line = "";
    string tmp = "";
    string mapdirectory = "Maps/";

    ifstream mapfile("Maps/map.txt", ios::in|ios::binary);
    while(!mapfile.eof()){
        getline(mapfile, tmp);

        maph+=1;

        if(tmp.size()>mapw){
            mapw = tmp.size();
        }

        line.append(tmp);

    }

    for(x=0, y=0;x<line.size();x++){
        if(line[x]=='\r'){
            y++;
            map[x][y] = line[x];
        }else{
            map[x][y] = line[x];
        }
    }
    
    *mapheight = maph;
    *mapwidth = mapw;

}


int main(){

    int x, y;
    int playerx = 1;
    int playery = 1;

    int mapwidth, mapheight; 
    char map[1000][1000];

    readmap(map, &mapwidth, &mapheight);

    char playersymbol = '@';
    
    string playground;
    
    while(true){
        
        playground = "";
        system("cls");

        if(GetAsyncKeyState(VK_LEFT)){
            playerx-=1;
        }else if(GetAsyncKeyState(VK_RIGHT)){
            playerx+=1;    
        }else if(GetAsyncKeyState(VK_UP)){
            playery-=1;   
        }else if(GetAsyncKeyState(VK_DOWN)){
            playery+=1;   
        }
        
        cout << mapwidth << "x" << mapheight << endl;

        
        for(y=0;y<=41;y++){
            for(x=0;x<=12;x++){
                if(map[x][y]=='\r'){
                    cout << endl;
                }else{
                    cout << map[x][y];
                }

            }
        }
        
        cout << playground;
        Sleep(10000);
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