#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void clearScreen() {
#ifdef _WIN32
	// Command for Windows
	std::system("cls");
#else
	// Assume POSIX (Linux, macOS, Unix-like)
	std::system("clear");
#endif
}

class Song {
private:
	string name;
	string author;
	int year;
public:
	Song() : name("None"), author("None"), year(0) {};

	Song(string n, string a, int y) : name(n), author(a), year(y) {};

	// Getter
	void showSong() const {
		cout << "Song name: " << name << endl << "Author: " << author << endl << "Released year: " << year << endl;
	};

	// Grant permission to the global operator
	friend istream& operator>>(istream& iStream, Song& aSong);
};


class Playlist {
private:
	Song* currentlyPlaying;
	vector<Song*> loadedSongs;
public:
	Playlist(string fileName) {
		currentlyPlaying = nullptr;
		ifstream file(fileName);
		Song tempSong;	// This assign a random physical address will then be pointed at by pointer
		while (file >> tempSong) {
			// Create a permanent location in memory for this song 
			Song* newSongPtr = new Song(tempSong);
			loadedSongs.push_back(newSongPtr);
		}

		file.close();
		cout << "Loaded " << loadedSongs.size() << " songs." << endl << endl;
	};

	void showPlaylist() const {
		for (int i = 0; i < loadedSongs.size(); i++) {
			loadedSongs[i]->showSong();
			/*cout << &loadedSongs[i] << endl; This show the mem add of the SPOT in the vector, not the instance*/
			cout << loadedSongs[i] << endl; 
			cout << "=============" << endl;
		}
	};

	void play(int songIndex) {
		if (songIndex < loadedSongs.size() && songIndex >= 0) {
			Song* song = loadedSongs[songIndex];
			currentlyPlaying = song;
			cout << "-----Currently playing-----" << endl;
			currentlyPlaying->showSong();
			cout << "---------------------------" << endl;
		}
		else {
			cout << "Song doesn't exist." << endl;
			return;
		};
	};

	void ptrAdd() const {
		// Show the address of pointer
		cout << "Ptr pointing to: " << currentlyPlaying << endl;
	};

	// The Destructor (runs automatically when Playlist object is destroyed)
	~Playlist() {
		cout << "Cleaning up memory..." << endl;

		// Loop through every pointer in the vector
		for (Song* s : loadedSongs) {
			delete s; // This deletes the actual Song object on the Heap
		}

		// Optional: clear the vector (though vector destructor does this anyway)
		loadedSongs.clear();
	}
};

// read from file using istream
istream& operator>> (istream& iStream, Song& aSong) {
	// ws (a whitespace extractor) to clear out any leftover newlines before reading strings
	getline(iStream >> ws, aSong.name);
	getline(iStream >> ws, aSong.author);
	iStream >> aSong.year;
	return iStream;
}


int main() {
	Playlist pl("songs.txt");
	bool inApp = true;
	bool playing = false;
	int choice;

	while (inApp == true) {
		clearScreen();
		cout << "Music Player >>v1.0<<" << endl;
		pl.showPlaylist();
		cout << "Please choose a song number: ";
		cin >> choice;
		playing = true;
		while (playing == true) {
			pl.play(choice-1);
			pl.ptrAdd();
			cout << "Type 0 to stop... ";
			cin >> choice;
			if (choice == 0) {
				playing = false;
			}
		};
	};
}