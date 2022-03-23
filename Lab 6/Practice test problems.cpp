#include <iostream>
#include <fstream>
using namespace std;

// number 3

void bestDonor(string kellyDonationFile, string sarahDonationsFile) {
	ifstream inFS;
	inFS.open(kellyDonationFile)
	unsigned num_causes_k =0;
	unsigned total_k=0;
	
	while (!fin.eof()) {
		unsigned value;
		fin >> value;
		num_causes_k++
		num_causes_k+=value;
	}
	unsigned num_causes_s=0;
	unsigned total_s=0;
	
	{
		ifstream fin(sarahDonationsFile);
		while (!fin.eof()) {
		unsigned value;
		fin >> value;
		num_causes_s++
		num_causes_s+=value;
			
		}
	
}
double avg_k=double(total_k)/num_causes_k;
double avg_s=double(total_s)/num_causes_s;

bool q_k = num_causes_k >= 5 && total_k >= 300;
bool q_s = num_causes_s >= 5 && total_s >= 300;

if (avg_s > avg_k && q_s == true && total_s >= 300) {
	cout << "Sarah wins!" << endl;
}
if (avg_s < avg_k && q_k == true && total_k >= 300) {
	cout << "Katie wins!" << endl;
} else if (q_k==false && q_s == true && total_s >= 300) {
	cout << "Sarah wins!" << endl; 
}else if (q_s==false && q_k == true && total_k >= 300) {
	cout << "Katie wins!" << endl; 
} else if (q_k==false && q_s == false) {
	cout << "Niether wins!" << endl; 
} else {
	cout << "It's a tie!" << endl; 
}


}

// number 7

int main() {
	unsigned n;
	cin >> n;
	int seg=1;
	int prev;
	for (int i  = 1; i<n; i++) {
		int v;
		cin >> v;
		if (v!=prev) {
			seg++;
			prev = v;
		}
		
	}
	
}


// number 4


int main() {
	int n;
	cin >> n;
	unsigned i=1;
	unsigned k=i+1;
	unsigned j=k+1;
	for (int l =0; l < n; i++) {
		if (i*k*j==n){
		cout "n is triangular." << endl;
		end(1);
		} else {
			i++;
			k++;
			j++;
		}
	}
	
	
}


// number 2

unsigned sum_of_digits (unsigned n, unsigned b) {
	unsigned sum = 0;
		while (n>0) {
			sum += n%b;
			n /= b;
		}
		return sum;
}

bool isHarshad(unsigned int n, unsigned int b) {
	int sum=0;
	int temp = n;
	unsigned digit_sum = sum_of_digits(n,b)
	return n % digit_sum ==0;
}


