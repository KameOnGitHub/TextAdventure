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
		CHAR_INFO currentChar;
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
		vvPixel.resize(height);//set the outer array to the height.
		for(int y = 0; y < 3 * height; y++){
			
			getline(file, currentLineS);
			vvPixel[y].resize(width);//make each line *width CHAR_INFO wide
			
			for (int x = 0; x<width; x++){
				if (y < height){// if this line is from the first third of the file
				vvPixel[y][x].Char = currentLineS[x];
				}
				else if (y >= height && y < 2*height){//if this line is from the second third of the file (foreground attribute)
				vvPixel[y][x].Attributes = lookupColor(currentLineS[x]);
				}
				else if (y >= 2*height){//if this line is from the final third
				vvPixel[y][x].Attributes = (vvPixel[y][x].Attributes<<4) + lookupColor(currentLineS[x]);
				}
			}
		}

		//Close File
		file.close();
	}


