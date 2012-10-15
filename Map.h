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


Last Edited 13/10/2012
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
		ifstream file("Maps/"+filename, ios::in|ios::binary);//open file for reading
		//std::vector<char> lineVector; //create 1d vector to use to build 2d vector
		//Remove old data.
		height = width = 0; //reset map size
		stringVector.erase(stringVector.begin(), stringVector.end()); //erase whatever was already in the map
		stringVector.resize(100);//100 seems like a safe amount for now
		//--------
		while(file.good()){
			getline(file, currentLine);
			stringVector.push_back(currentLine);
			cout<<currentLine<<endl;//temp debug
			//cout<<stringVector.at(height);
			//objects.append(currentLine); //assign the current line to the objects string
			++height;//show height has increased by one
		}
		width = currentLine.size();// the last line will have the true width as long as there isn't a CRLF
		//Cleanup
		file.close();
	}

	void display(){
		for (int x = 0; x < height; x++){
				cout<<stringVector.at(x);
		}
	}

	int getWidth(){
		return width;
	}

	int getHeight(){
		return height;
	}

};