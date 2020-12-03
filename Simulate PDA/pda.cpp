#include<iostream>
#include<string.h>
using namespace std;
int top;
char s[50];
class Stack
{
    public:
    void push(int x)
    {
        s[top++]=x;
    }
    void pop(int x)
    {
        s[top--]=x;
    }
};
int main()
{
    int i,n,flag;
    int invalid=0;
    char a[10];
    cout<<"\nProgram For PDA Which Accept (a^n)(b^2n)\n";
    cout<<"\nEnter input String::";
    cin>>a;
    n=strlen(a);
    Stack s;
    top=-1;
    if(n>=1)
    {
    	flag=0;
	    for(i=0;i<n;i++) 
	    {   
	        
	        if(a[i]=='a' || a[i]=='b')
	        {
	            if(a[i]=='a'&& flag==0)
	            {
	                s.push(a[i]);
	                s.push(a[i]);
	                cout<<"a is pushed into stack two times\n";
	                cout<<"(q0, a, z) =>(q1, aaz) \n";
	                flag+=2;
	            }
	            else if(a[i]=='a'&& flag==2)
	            {
	                s.push(a[i]);
	                s.push(a[i]);
	                cout<<"a is pushed into stack two times\n";
	                cout<<"(q1, a, z) =>(q1, aaaaz) \n";
	                flag+=2;
	            }
	            
	            else
	            {
	                s.pop(a[i]);
	                flag--;
	                cout<<"a is popped out of stack as it encountered b\n(q1, b, a)=>(q2, ";
	                if(flag>0){
	                	
		                for(int c=0;c<flag;c++){
		                	cout<<"a";
						}
						cout<<"z";
					}else{
						cout<<"epsilon";
					}
					cout<<")\n";
	                
	            }    
	        }
	        else
	        {
	        	printf("You entered invalid symbol\n");
	        	invalid=1;
	            break;    
	            
	        }    
	    }
	    if(top==-1)
	    {
	    	if(invalid==0){
	    		cout<<"The stack is empty hence ";
	        	cout<<"\nString is Accepted.\n";
			}
	    }
	    else
	    {
	    	if(invalid==0){
	    		cout<<"The stack is not empty hence ";
	        	cout<<"\nString is Rejected.\n";
			}
	    }  
    }
    else 
    {
    	if(invalid==0){
	        	cout<<"\nString is Rejected.\n";
			}
    }
    return 0;
}
