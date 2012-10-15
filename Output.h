void paint(string color, string word){

    WORD RED = 0xC;
    WORD YELLOW = 0xE;
    WORD GREEN = 0xA;
    WORD BLUE = 0x9;
    
    HANDLE hstdin  = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

    if(color=="red"){
        SetConsoleTextAttribute(hstdout, RED);
    }else if(color=="yellow"){
        SetConsoleTextAttribute(hstdout, YELLOW); 
    }else if(color=="blue"){
        SetConsoleTextAttribute(hstdout, BLUE); 
    }else if(color=="green"){
        SetConsoleTextAttribute(hstdout, GREEN); 
    }

    cout << word;
    
    FlushConsoleInputBuffer(hstdin);
    
	// Keep users happy
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
    
}