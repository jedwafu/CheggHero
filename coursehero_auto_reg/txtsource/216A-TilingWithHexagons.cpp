#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	//Niraj sazzie
	//The given hexagonal array HH of beads can be viewed (in two ways) 
	//as the union of three parallelogram shaped arrays containing abab, bcbc, and caca beads respectively,
	//any two of them sharing an edge of length aa, bb, or cc,
	//and all three of them having one bead in the interior of HH in common.
	//By the inclusion-exclusion principle the total number NN of beads is therefore given by
	//N=(a*b+b*c+c*a)-(a+b+c)+1.
	cin>>a>>b>>c;
	cout<<(a*b+b*c+c*a)-(a+b+c)+1;
	return 0;
}