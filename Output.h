/*
Specification for the master output class. 

This class and it's methods provide the ability to send things to the screen. The map, 
player status, and dialogue are all sent to this interface in order to be drawn (aka rendered). 


--------
Last Modified:
10/17/2011
*/

class renderer{
private:
	//Important numbers 'n' stuff
	int windowWidth;
	int windowHeight;
	//Screen buffer requirements
	HANDLE writeHandle;
	HANDLE readHandle;
	SMALL_RECT windowSize;
	COORD bufferSize;
	COORD characterBufferSize;
	COORD characterPosition;
	SMALL_RECT consoleWriteArea;
	//Data Structure that we write to the screen. 
	vector<CHAR_INFO> outputBuffer;//Use a vector instead of an array because arrays are bad and should feel bad. 
	//The left index should always be considered the width, and the right the height. 


public:
	renderer::renderer(int widthIn, int heightIn){//Class constructor, duh. Currently takes the width, height
		windowWidth = widthIn; 
		windowHeight = heightIn;
		SetConsoleTitle(TEXT("Seizure Generator"));
		
		//windowSize = {0, 0, (windowWidth-1), (windowHeight-1)};
		windowSize.Left = 0;
		windowSize.Top = 0;
		windowSize.Right = windowWidth - 1;
		windowSize.Bottom = windowHeight - 1;
		//bufferSize = {windowWidth, windowHeight};
		bufferSize.X = windowWidth;
		bufferSize.Y = windowHeight;
		//characterBufferSize = {windowWidth, windowHeight};
		characterBufferSize.X = windowWidth;
		characterBufferSize.Y = windowHeight;
		//characterPosition = {0,0};
		characterPosition.X = 0;
		characterPosition.Y = 0;
		//consoleWriteArea = {0,0, windowWidth-1, windowHeight-1};
		consoleWriteArea.Left = 0;
		consoleWriteArea.Top = 0;
		consoleWriteArea.Right = windowWidth-1;
		consoleWriteArea.Bottom = windowHeight-1;
		
		writeHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		readHandle = GetStdHandle(STD_INPUT_HANDLE);

		SetConsoleWindowInfo(writeHandle, TRUE, &windowSize);
		
		SetConsoleScreenBufferSize(writeHandle, bufferSize);
		//Initialize the output storage vector
		outputBuffer.resize(windowWidth*windowHeight);
		//blankOutputBuffer();
		generateColorNoise();
		WriteConsoleOutputA(writeHandle, &outputBuffer[0], bufferSize, characterPosition, &consoleWriteArea);
	}

	void updateScreen(){
		WriteConsoleOutputA(writeHandle, &outputBuffer[0], bufferSize, characterPosition, &consoleWriteArea);
	}

	void addToBuffer(vector<vector<CHAR_INFO> > input, int yOffset, int xOffset, int inputHeight, int inputWidth){
		int lastY = yOffset + inputHeight;
		int lastX = xOffset + inputWidth;
		for (int y = 0; y < inputHeight; y++){
			for (int x = 0; x < inputWidth; x++){
				outputBuffer[(x+xOffset)+windowWidth*(y+yOffset)] = input[y][x];
			}
		}
	}

	void generateColorNoise(){//This'll store random colors in each member of outputchar. 
	for(int y = 0; y < windowHeight; y++){
		for(int x = 0; x< windowWidth; x++){
			outputBuffer[ x + windowWidth * y].Char.AsciiChar = (unsigned char)' ';//was 219, change bacak when this is fixed.
			outputBuffer[ x + windowWidth * y].Attributes = rand() % 256;
		}
	}
	}

	void testDebug(){
		//WriteConsoleOutput(writeHandle, &beta, bufferSize, characterPosition, &consoleWriteArea);
		
	}

	void blankOutputBuffer(){
	outputBuffer.clear();
	outputBuffer.resize(windowWidth*windowHeight);
	}



	void debugScreen(){
	for (int x = 0; x< windowWidth; x++){
		for( int y = 0; y < windowHeight; y++){
			cout<<outputBuffer[x + windowWidth * y].Attributes<<':';
		}
		cout<<endl;
	}
	}

};

//void paint(string color, string word){
//
//    WORD RED = 0xC;
//    WORD YELLOW = 0xE;
//    WORD GREEN = 0xA;
//    WORD BLUE = 0x9;
//    
//    HANDLE hstdin  = GetStdHandle(STD_INPUT_HANDLE);
//	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	// Remember how things were when we started
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	GetConsoleScreenBufferInfo(hstdout, &csbi);
//
//    if(color=="red"){
//        SetConsoleTextAttribute(hstdout, RED);
//    }else if(color=="yellow"){
//        SetConsoleTextAttribute(hstdout, YELLOW); 
//    }else if(color=="blue"){
//        SetConsoleTextAttribute(hstdout, BLUE); 
//    }else if(color=="green"){
//        SetConsoleTextAttribute(hstdout, GREEN); 
//    }
//
//    cout << word;
//    
//    FlushConsoleInputBuffer(hstdin);
//    
//	// Keep users happy
//	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
//    
//}



