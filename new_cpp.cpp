#include <fstream>

using std::ofstream;
using std::endl;

int main() {
	// open file "new.cpp" for writing
	// if it exists, delete contents
	// else, creates the file
	ofstream fout("new.cpp");
	
	// write a simple program
	
	fout << "#include <iostream>" << endl << endl;
	fout << "using std::cout, std::endl;" << endl << endl;
	fout << "int main() {" << endl;
	fout << "	cout << \"Let's Go!\" << endl;" << endl;
	fout << endl;
	fout << "	return 0; " << endl;
	fout << "}" << endl;
	
	return 0;
}