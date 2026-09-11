/*
 * Course: COEN 2220 - Programming 2
 * Name: Logan N. Ramirez Rodriguez
 * Lab: Lab 4 - Object-Oriented Programming, Part 2
 * Description: Aggregation practice with CourseSection
 * Due date: 9/11/2026
 */

#include <iostream>
#include <string>
using namespace std;

class Instructor
{
	private:
		string name;  // State owned by one Instructor object.

	public:
		Instructor() { name = ""; }  // Start with a predictable empty value.
		void setName(string n) { name = n; }  // The public interface controls changes.
		string getName() const { return name; }  // Reading should not modify the object.
};

class TextBook
{
	private:
		string title;  // State owned by one TextBook object.

	public:
		TextBook() { title = ""; }  // Start with a predictable empty value.
		void setTitle(string t) { title = t; }  // Keep title changes inside the class interface.
		string getTitle() const { return title; }  // Reading should not modify the object.
};

class CourseSection
{
	private:
		string sectionId;
		Instructor instructor;
		TextBook textbook;

	public:
		CourseSection(string id, string instructorName, string bookTitle) {
			sectionId = id;
			instructor.setName(instructorName);
			textbook.setTitle(bookTitle);
		}

		void printInfo() const {
			cout << "Section: " << sectionId << endl;
			cout << "Instructor: " << instructor.getName() << endl;
			cout << "Textbook: " << textbook.getTitle() << endl;
		}
};

int main() {
	CourseSection section("COEN2220-01", "Wilson Lozano", "Starting Out with C++");
	section.printInfo();

	return 0;
}