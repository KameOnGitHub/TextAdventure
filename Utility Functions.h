int strToInt(string input){
	int output;
	stringstream converter;
	converter << input;
	converter >> output ? output : 0;
	converter.clear();
	return output;
}