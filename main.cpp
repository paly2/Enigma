#include <iostream>
#include <string>
#include "rotors.h"
#include "plugboard.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "Enigma Implementation test version" << endl;

	if (argc != ROTORS_NUMBER+1) {
		cout << "Usage: " << argv[0] << " first_rotor_file second_rotor_file reflector_file" << endl;
		return 1;
	}

	cout << "Please give the rotors initial settings (format: XXX, where X is a capital characeter) : ";
	string rotors_settings;
	cin >> rotors_settings;
	if (rotors_settings.length() != ROTORS_NUMBER) {
		cout << "You must give " << ROTORS_NUMBER << " characters !" << endl;
		return 1;
	}
    Rotors rotors(rotors_settings.c_str(), reinterpret_cast<string*>(argv+1));

    cout << "Please give " << PLUGBOARD_WIRING_NUMBER << " characters, wich will be paired, for the plugboard wiring: ";
	string plugboard_wiring;
	cin >> plugboard_wiring;
	if (plugboard_wiring.length() != PLUGBOARD_WIRING_NUMBER) {
		cout << "You must give " << PLUGBOARD_WIRING_NUMBER << " characters !" << endl;
		return 1;
	}
    Plugboard plugboard(plugboard_wiring.c_str());

    cout << "Message:" << endl;
    string message;
    cin >> message;
    for (unsigned int i = 0 ; i < message.length() ; i++) {
    	char ch = message[i];
    	plugboard.get_char(ch);
    	rotors.get_char(ch);
    	plugboard.get_char(ch);
    	cout << ch;
    }
    cout << "\n";

    return 0;
}
