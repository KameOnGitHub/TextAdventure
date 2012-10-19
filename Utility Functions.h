int strToInt(string input){
	int output;
	stringstream converter;
	converter << input;
	converter >> output ? output : 0;
	converter.clear();
	return output;
}

void fuckingWorkAlready(){
	int WIDTH = 70;
	int HEIGHT = 35;

	HANDLE writeHandle;
	HANDLE readHandle;
	vector<CHAR_INFO> newBuffer; 
    newBuffer.resize(WIDTH*HEIGHT);
    
  srand(time(0));
  

  SMALL_RECT windowSize = {0, 0, WIDTH - 1, HEIGHT - 1};

  COORD bufferSize = {WIDTH, HEIGHT};
  
  COORD characterBufferSize = {WIDTH, HEIGHT};
  COORD characterPosition = {0, 0};
  SMALL_RECT consoleWriteArea = {0, 0, WIDTH - 1, HEIGHT - 1};
 

  writeHandle = GetStdHandle(STD_OUTPUT_HANDLE);//
  readHandle = GetStdHandle(STD_INPUT_HANDLE);//
 
  SetConsoleWindowInfo(writeHandle, TRUE, &windowSize);

  SetConsoleScreenBufferSize(writeHandle, bufferSize);
  
  while(true){
	  for (int y = 0; y < HEIGHT; ++y){
		for (int x = 0; x < WIDTH; ++x){
			newBuffer[x + WIDTH * y].Char.AsciiChar = (unsigned char)200;
			newBuffer[x + WIDTH * y].Attributes = rand() % 256;
		}
	}
  WriteConsoleOutputA(writeHandle, &newBuffer[0], characterBufferSize, characterPosition, &consoleWriteArea);
  }
}