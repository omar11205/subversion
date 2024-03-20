// CPP code to illustrate Queue in/ Quee out
#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void showq(queue<int> gq)
{
	queue<int> g = gq; //creating a working copy of gq
	while (!g.empty()) {
		cout << '\t' << g.front(); //g.front prints the front element of the quee
		g.pop(); //g.pop removes the front element of the queee
	}
	cout << '\n';
}

// Driver Code
int main()
{
	queue<int> gquiz;
	gquiz.push(10);
	gquiz.push(20);
	gquiz.push(30);
	
	cout << "The queue gquiz is : ";
	showq(gquiz);
	
	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.front() : " << gquiz.front();
	cout << "\ngquiz.back() : " << gquiz.back();
	
	//its spected that the first element pushed (10) pops out of the quee 
	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showq(gquiz);
	
	return 0;
}
