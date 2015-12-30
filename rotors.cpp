#include "rotors.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

void Rotor::init(char position, const string wiring_file_name) {
	m_position = position;

	FILE* wiring_file = fopen(wiring_file_name.c_str(), "r");
	if (wiring_file == NULL) {
		cout << "Couldn't open rotor file " << wiring_file_name << ": ";
		perror("fopen");
		exit(1);
	}

	char wiring_ch;
	for (int i = 0 ; (wiring_ch = fgetc(wiring_file)) != EOF && i < 26 ; i++) {
		m_wiring[0][i] = wiring_ch;
		m_wiring[1][wiring_ch-'A'] = i+'A';
	}

	fclose(wiring_file);
}

/* In this function, pre_pos is the pos of the previous rotor.
                     dir is the direction of the signal (0 = forward, 1 = backward). */
bool Rotor::get_char(char &ch, const char pre_pos, const int dir, const bool rotation) {
	bool ret = false;
	if (rotation) {
		m_position++;
		if(m_position > 'Z') {
			m_position = 'A'; // Complete rotation
			ret = true;
		}
	}

	// The entry character is pre_ch-pre_pos+m_position
	int entry;
	entry = ch - pre_pos + m_position - 'A';

	if (entry < 0) entry += 26;
	else if (entry > 25) entry -= 26;

	ch = m_wiring[dir][entry];

	return ret;
}

char Rotor::get_pos() {
	return m_position;
}

Rotors::Rotors(const char settings[ROTORS_NUMBER], const string wiring_files[ROTORS_NUMBER]) {
    for (int i = 0 ; i < ROTORS_NUMBER ; i++)
    	m_rotors[i].init(toupper(settings[i]), wiring_files[i]);
}

void Rotors::get_char(char &ch) {
	ch = toupper(ch);

	// Forward...
	char pre_pos = 'A';
	bool rotation = true;
	for (int i = 0 ; i < ROTORS_NUMBER ; i++) {
		rotation = m_rotors[i].get_char(ch, pre_pos, 0, rotation);
		pre_pos = m_rotors[i].get_pos();
	}

	// And backward ! Note : the last rotor is the reflector
	for (int i = ROTORS_NUMBER-2 ; i >= 0 ; i--) {
        m_rotors[i].get_char(ch, pre_pos, 1);
        pre_pos = m_rotors[i].get_pos();
	}

	// We need to take account the last rotor position to get the real character.
	ch -= (m_rotors[0].get_pos()-'A');
	if (ch < 'A') ch += 26;
}
