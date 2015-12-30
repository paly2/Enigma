#include "plugboard.h"
#include <iostream>

Plugboard::Plugboard(const char pb[PLUGBOARD_WIRING_NUMBER]) {
	for(int i = 0 ; i < 26 ; i++)
		m_plugboard[i] = i + 'A';

	for(int i = 0 ; i < PLUGBOARD_WIRING_NUMBER ; i += 2) {
		m_plugboard[toupper(pb[i])-'A'] = toupper(pb[i+1]);
		m_plugboard[toupper(pb[i+1])-'A'] = toupper(pb[i]);
	}
}

void Plugboard::get_char(char &ch) {
	ch = toupper(m_plugboard[ch-'A']);
}
