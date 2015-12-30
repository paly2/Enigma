#ifndef ENIGMA_H_INCLUDED
#define ENIGMA_H_INCLUDED

#include <string>

#define ROTORS_NUMBER 3 // Including the reflector

using namespace std;

class Rotor {
	public:
	void init(const char position, const string wiring_file);
	bool get_char(char &ch, const char pre_pos, const int dir, const bool rotation = false);
	char get_pos();

	private:
	char m_wiring[2][26];
	char m_position;
};

class Rotors {
    public:
    Rotors(const char settings[ROTORS_NUMBER], const string wiring_files[ROTORS_NUMBER]);
    void get_char(char &ch);

    private:
    Rotor m_rotors[ROTORS_NUMBER];
};

#endif // ENIGMA_H_INCLUDED
