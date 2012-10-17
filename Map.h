/*
Map Specification
--------------------------------
Inputs:
Pending-
load file: load the entire map from a file. input file must be specified. 
change element by location: alter an element within the map. element location and new type must be specified. 
change element by type: changes all of one element type to another. Type to replace and replacement type must be specified. 
Implemented-
----------------
Outputs:
Pending- 
save file: dump the data to a file to be persistently stored. file reference must be specified.
element at location: return the type of object at the given location. input is a x,y coordinate, output is a char.
draw: display a copy of the map on screen. 
Implemented-
----------------
Data:
height: the height in characters. 
width: the width in characters. 
objects: a 2d vector of chars whose size is specified by height and width
----------------

Map File Specification:
Header Information: The first line should contian information about the map, delimited by ';'. The values are the height, then the width. 
Map Data: 
	- Character Shape
	- Character Color
	- Background Color

Colors: Colors are represented as characters that need to be translated into actual color values. This translation should be done by the 
display functions. 

Example map:
3;4;	//height; width;
XXXX	//map symbol
XsfX	//symbol
XXXX	//symbol
RRRR	//symbol color
RGBR	//aka foreground color
RRRR	//or fcolor
BBBB	//background color
WWWW	//or bcolor
BBBB	//displays behind character

Notes:
	As of 10/17/12, If you incorrectly label the map's height in the map file you risk CRASHING the code. THAT IS BAD. If the code
doesn't crash then the map will not work correctly because it will not be read from the file completely. SO DONT FUCK UP UNTIL THIS
IS FIXED. Otherwise it should run fine. 

----------------
Last Edited 10/17/2012
--------------------------------
*/

//Function prototypes:


//mapData Definition
struct mapData{
	string symbol;//Character to display
	string fColor;//color of the character
	string bColor;//color of the background at that position. 
};
//mapData Constructor
mapData makeLine(string input){
	mapData line;
	line.symbol = input;
	return line;
}

//map Class Definition!
class map{
private:
	int width;
	int height;
	vector<mapData> mapArray; 

public:
	void reset(){
		height = width = 0; //Explicitly reset map size
		mapArray.erase(mapArray.begin(), mapArray.end()); //erase whatever was already in the map
	}

	void loadFromFile(std::string filename){
		//Declarations
		string currentLine;
		string sti;
		int semicolonPosition;

		ifstream file("Maps/"+filename/*, ios::in|ios::binary*/);//open file for reading, seems to work without the ios::in bit but let's hold onto it in case of whatever
		//Remove old data.
		reset();
		//--------
		//Read Map Header (height;width;)
		getline(file, currentLine);//read first line
		semicolonPosition = currentLine.find(';');
		sti = currentLine.substr(0, semicolonPosition);
		height = strToInt(sti);
		sti = currentLine.substr(++semicolonPosition);
		width = strToInt(sti);
		//--------
		//Read Map Body
		for(int y = 0; y < 3*height; y++){//WARNING: This function will CRASH if the wrong value is written in the file header for height!
			getline(file, currentLine);//read one line from the file and store it in currentLine. 
			if (y < height){// if this line is from the first third of the file
				mapArray.push_back(makeLine(currentLine));//push back the vector and make a line using the current line being read
			}
			else if (y >= height && y < 2*height){//if this line is from the second third of the file
				mapArray[y-height].fColor = currentLine;//write currentLine to the foreground color element of the corresponding array element
			}
			else if (y >= 2*height){//if this line is from the final third
				mapArray[y-2*height].bColor = currentLine;//write currentLine to the background color element of the array
			}
		}
		//Cleanup
		file.close();
	}

/*	void saveToFile(std::string filename){
		ifstream file("TestMaps/"+filename);
		for(int x = 0; x < height; x++){
			file << mapArray[x];
		}
	}
*/
	//void display(){
	//	for (int x = 0; x < height; x++){
	//			cout<<mapArray.at(x)<<endl;
	//	}
	//}

	void debug(){//quick 'n' dirty function to test the map read. 
		for (int y = 0; y < height; y++){
			cout<<mapArray[y].symbol<<mapArray[y].fColor<<mapArray[y].bColor<<endl; //displays the symbol, foreground color, and background color side by side per line. 
		}
	}

	int getWidth(){
		return width;
	}

	int getHeight(){
		return height;
	}

};