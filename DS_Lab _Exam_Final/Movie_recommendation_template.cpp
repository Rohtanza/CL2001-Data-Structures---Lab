#include <iostream>
#include <string>

using namespace std;

class Node {
		int movieID;
		string title;
		string genre;
		int ratings;
		Movie* left;
		Movie* right;

		// define the constructor
};

class MovieRecommendationSystem {
	private:
		Node* root;

	public:
		// define the constructor

		// Insert a movie into the BST
		void insertMovie(Node* root, int movieID, string title, string genre, int ratings) {
			if (node == nullptr) {
				node = new Movie(movieID, title, genre, ratings);
			} else if (movieID < node->movieID) {
				insertMovie(node->left, movieID, title, genre, ratings);
			} else {
				insertMovie(node->right, movieID, title, genre, ratings);
			}
		}

		// Recommend movies of a given genre
		void recommendMoviesByGenre(string genre) {

		}

		// Delete a movie by ID
		Movie* deleteMovieByID(Node *root, int movieID) {

		}

};

int main() {
	MovieRecommendationSystem engine;
	int choice;
	while (true) {
		cout << "Menu:\n";
		cout << "1. Add a Movie\n";
		cout << "2. Delete a Movie by ID\n";
		cout << "3. Recommend Movies by Genre\n";
		cout << "4. Display Movies Sorted by Ratings\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1: {
				int movieID;
				string title, genre;
				double ratings;
				cout << "Enter Movie ID: ";
				cin >> movieID;
				cin.ignore(); // Clear newline character from the buffer
				cout << "Enter Movie Title: ";
				getline(cin, title);
				cout << "Enter Movie Genre: ";
				getline(cin, genre);
				cout << "Enter Ratings: ";
				cin >> ratings;

				engine.insertMovie(root, movieID, title, genre, ratings);
				cout << "Movie added successfully!" << endl;
				break;
			}
			case 2: {
				int deleteID;
				cout << "Enter Movie ID to delete: ";
				cin >> deleteID;
				root = deleteMovieByID(root, deleteID);
				cout << "Movie with ID " << deleteID << " deleted successfully!" << endl;
				break;
			}
			case 3: {
				string genre;
				cout << "Enter your favorite genre: ";
				cin.ignore(); // Clear newline character from the buffer
				getline(cin, genre);
				recommendMoviesByGenre(genre);
				break;
			}
			case 4:
				displayMovies();
				break;
			case 5:
				cout << "Exiting the program." << endl;
				return;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	}
	return 0;
}
