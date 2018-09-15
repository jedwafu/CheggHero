#include<bits/stdc++.h>
using namespace std;

vector<int> Input(1000);
vector<int> Output(1000, -1 );
stack<int> S_values, S_indices;

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		Input.push_back(temp);
	}
	
    // = { 12, 15, 22,  9,  7,  2, 18, 23, 27};
    
    
    S_values.push(Input[0]);
    S_indices.push(0);
    for (int index = 1; index < Input.size(); ++index )
    {
        while ( !S_values.empty() && Input[index] > S_values.top() )
        {
            int output_index = S_indices.top();
            Output[ output_index ] = Input[ index ];
            S_values.pop();
            S_indices.pop();

        }
        S_values.push(Input[index]);
        S_indices.push( index );
    }

    for ( int i=0;i<n;i++)
        cout <<Output[i]<< " ";
    cout << endl;

    return 0;
}
