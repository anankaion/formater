#include <iostream>
#include <fstream>
#include <deque>

#include "formater.h"

int read_file(std::string name, std::deque<std::deque<char>> *text) {
    std::ifstream input_file;

    std::string line;   //reading line by line
    std::deque<char> line_c;    //separating the line in characters

	input_file.open(name); 

	//file has to be open
	if (input_file.is_open()) {

		//read line by line
		while (getline(input_file, line)) {
			line_c.clear();

			//read char by char
			for (char i : line) {
				
				//put char into line
				line_c.push_back(i);
			}

			//put line into text
			text->push_back(line_c);
		}

		input_file.close();
		return 0;
	} else {
		return -1;
	}
}

int write_file(std::string name, std::deque<std::deque<char>> *text) {
    std::ofstream output_file;

	output_file.open(name);
	
	//if file is open
	if (output_file.is_open()) {
		
		for (std::deque<char> line: *text) {
			for(char c : line) {
				output_file.put(c);
			}

			output_file.put('\n');
		}

		output_file.close();
		return 0;
	} else {
		return -1;
	}
}

int main(int argc, char** argv) {
    std::deque<std::deque<char>> text;  //complete file

    if (argc > 1) {

		read_file(argv[1], &text);

		check_indents(&text);

        write_file("out.cpp", &text);

    } else {
        std::cout << "Too few arguments" << std::endl;
    }

    return 0;
}
