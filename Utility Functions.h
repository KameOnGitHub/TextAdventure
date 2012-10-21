int strToInt(string input){
	int output;
	stringstream converter;
	converter << input;
	converter >> output ? output : 0;
	converter.clear();
	return output;
}

unsigned char lookupColor(char input){//translate color character to corresponding binary value
	int output = 0;
	input = toupper(input);//make sure we are looking at an uppercase character
	if		(input == 'R'){output = 4;}// binary 0100 red
	else if (input == 'G'){output = 2;}// binary 0010 green
	else if (input == 'B'){output = 1;}// binary 0001 blue
	else if (input == 'W'){output = 15;}//binary 1111 white
	else if (input == 'K'){output = 0;}// binary 0000 black
	else {output = 0;}//default to 0

	return output;
}
