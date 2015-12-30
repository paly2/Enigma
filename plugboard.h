#ifndef PLUGBOARD_H_INCLUDED
#define PLUGBOARD_H_INCLUDED

#define PLUGBOARD_WIRING_NUMBER 6

class Plugboard {
	public:
	Plugboard(const char plugboard_wiring[PLUGBOARD_WIRING_NUMBER]);
	void get_char(char &ch);

	private:
	char m_plugboard[26];
};

#endif // PLUGBOARD_H_INCLUDED
