#include<iostream>
#include<deque>

#include "formater.h"

#define TABSPACE 4

int check_indents(std::deque<std::deque<char>> *text) {
	int indent_level = 0;
	int spaces_needed = 0;
	int spaces_actual = 0;

	bool first_whites;

	for (auto & it : *text) {
	    first_whites = true;
	    spaces_actual = 0;
		spaces_needed = indent_level * TABSPACE;

		for (char c : it) {
			if (c == ' ') {
			    if (first_whites) {
                    spaces_actual++;
                }
			} else {
			    first_whites = false;

			    if ((c == '{') && (c == it.at(it.size()-1))) {
			        indent_level++;
			    } else if ((c == '}') && (c == it.at(it.size()-1))) {
                    indent_level--;
                }
			}
		}

		if (spaces_needed > spaces_actual) {
			for (int i = 0; i < (spaces_needed - spaces_actual); i++) {
				it.push_front(' ');
			}
		} else if (spaces_needed < spaces_actual) {
			for (int i = 0; i < (spaces_actual - spaces_needed); i++) {
				it.pop_front();
			}
		}
	}

	return 0;
}
