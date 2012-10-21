class map{
private:
	//private members
	int width;
	int height;
	vector<vector<CHAR_INFO> > vvPixel;
	//--------
	//private functions
	void reset(){
		width = height = 0;
		vvPixel.erase(vvPixel.begin(), vvPixel.end());
	}
	//--------

public:
	void loadFromFile(string filename){
		//Local variables
		string currentLineS;
		vector<CHAR_INFO> currentLineV;
		char currentChar;
		int semicolonPosition;
		ifstream file("maps/"+filename);

		//Empty the map
		reset();

		//Read header
		getline(file, currentLineS);
		semicolonPosition = currentLineS.find(';');
		height = strToInt(currentLineS.substr(0, semicolonPosition));
		width = strToInt(currentLineS.substr(++semicolonPosition));
		
		//Read body
		int debug = 0;
		vvPixel.resize(height);//set the outer array to the height.
		for(int f = 0; f < 3; f++){

			for(int y = 0; y < height; y++){
			
				getline(file, currentLineS);
				vvPixel[y].resize(width);
				++debug;
				for (int x = 0; x<width; x++){
					if (x  == 0){++debug;}//make each line *width CHAR_INFO wide
					if (f == 0){// if this line is from the first third of the file
					vvPixel[y][x].Char.AsciiChar = currentLineS[x];
					}
					else if (f == 1){//if this line is from the second third of the file (foreground attribute)
					vvPixel[y][x].Attributes = lookupColor(currentLineS[x])<<4;
					}
					else if (f == 2){//if this line is from the final third
					vvPixel[y][x].Attributes = vvPixel[y][x].Attributes + lookupColor(currentLineS[x]);
					}
					currentChar = currentLineS[x];
				}
			}
		}
		//Close File
		file.close();
	}

	vector<vector<CHAR_INFO> > get_vvPixel(){
		return vvPixel;
	}
	int get_width(){
		return width;
	}
	int get_height(){
		return height;
	}
};
