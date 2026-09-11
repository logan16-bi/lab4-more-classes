/*
 * Course: COEN 2220 - Programming 2
 * Name: Logan N. Ramirez Rodriguez
 * Lab: Lab 4 - Object-Oriented Programming, Part 2
 * Description: Guided example - static members, copies, and operators
 * Due date: 9/11/2026
 */

#include <iostream>
using namespace std;

class StudyTime
{
	private:
		int minutes;               // Each object stores its own duration.
		static int objectCount;    // One counter is shared by the entire class.

	public:
		StudyTime(int m = 0) {
			minutes = m;
			objectCount++;         // Every new object increases the shared count.
		}

		int getMinutes() const { return minutes; }

		static int getObjectCount() {
			return objectCount;    // A static function reads class-level data.
		}

		// --- STEP 2: copy constructor (uncomment the /* ... */ block later) ---
		StudyTime(const StudyTime &other) {
			minutes = other.minutes;  // Copy the source object's duration.
			objectCount++;            // The copy is a new object too.
		}

		// --- STEP 3: operator+ (uncomment the /* ... */ block later) ---
		StudyTime operator+(const StudyTime &other) const {
			// Return a new duration without changing either operand.
			return StudyTime(minutes + other.minutes);
		}
};

int StudyTime::objectCount = 0;    // Define the single shared variable.

int main() {
	StudyTime reading(45);          // The first StudyTime object.

	cout << "Reading: " << reading.getMinutes() << " minutes" << endl;
	cout << "Objects created: " << StudyTime::getObjectCount() << endl;

	StudyTime readingCopy = reading;  // Create a new object from reading.
	cout << "Copy: " << readingCopy.getMinutes() << " minutes" << endl;
	cout << "Objects created: " << StudyTime::getObjectCount() << endl;

	StudyTime practice(30);
	StudyTime total = reading + practice;  // Calls reading.operator+(practice).

	cout << "Total: " << total.getMinutes() << " minutes" << endl;
	cout << "Objects created: " << StudyTime::getObjectCount() << endl;
    	StudyTime fromReading(reading);         // Copy construction from reading.
	StudyTime another;                       // Default-constructed new object.
	another = reading;                       // Assignment: another already existed.

	cout << "\nFinal count: " << StudyTime::getObjectCount() << endl;
	cout << "fromReading: " << fromReading.getMinutes() << " minutes" << endl;
	cout << "another: " << another.getMinutes() << " minutes" << endl;

	return 0;
}