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
Header Information: The first line should contian information about the map, delimited by ';'. Values should include the map's name, width, and height. 
Map Data: 
	- Character Shape
	- Character Color

----------------
Last Edited 14/10/2012
--------------------------------
*/

//Function prototypes:


//Class Definition
class map{
private:
	int width;
	int height;
	vector<string> stringVector; 
	string objects; //let's try and store the map as one string

public:
	void loadFromFile(std::string filename){
		//Declarations
		string currentLine;
		ifstream file("Maps/"+filename/*, ios::in|ios::binary*/);//open file for reading		
		//Remove old data.
		height = width = 0; //reset map size
		stringVector.erase(stringVector.begin(), stringVector.end()); //erase whatever was already in the map
		//--------
		while(file.good()){
			getline(file, currentLine);
			stringVector.push_back(currentLine);
			++height;//show height has increased by one
		}
		width = currentLine.size();// the last line will have the true width as long as there isn't a CRLF
		//Cleanup
		file.close();
	}

	void display(){
		for (int x = 0; x < height; x++){
				cout<<stringVector.at(x)<<endl;
		}
	}

	int getWidth(){
		return width;
	}

	int getHeight(){
		return height;
	}

};