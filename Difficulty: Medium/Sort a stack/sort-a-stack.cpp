//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);

cout << "~" << "\n";
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
private:
    void insert(int element);
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert(stack<int>& s,int element){
    if(s.empty() || s.top() <= element){
        s.push(element);
        return;
    }
    
    int top = s.top();
    s.pop();
    
    insert(s,element);
    
    s.push(top);
}
void SortedStack :: sort()
{
    if(s.empty()){
        return;
    }
    
    int top = s.top();
    s.pop();
    
    sort();
    
    insert(s,top);
}
