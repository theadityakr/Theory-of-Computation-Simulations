#include<bits/stdc++.h>
using namespace std;

string substring(string s, int i, int j){
	string a = "";
	for(int k=i; k<j; ++k)
	a+=s[k];
	return a;
}

void removeNullProductions(){
	fstream inputfile;
	inputfile.open("input.txt",ios::in);
    if (inputfile.is_open()){
	int n;		//No of lines to follow(no of variables)
	inputfile>>n;
	vector <string> v[n];		//Stores the right side of productions for n variables
	vector <char> variable;		//variables on left side of some production
	queue <char> nv;			//nv = nullable variable
	for(int i=0; i<n; ++i){
		int p=0;		//p = initial index for the substrings
		char q;
		string s, str;
		inputfile>>q>>s;
		variable.push_back(q);
		s = s + "|";
		for(int j=0; j<s.size(); j++){
			if(s[j]=='|'){
				str=substring(s, p, j);
				p=j+1;
				if(str=="$"){				//q is a nullable variable
					nv.push(q);
				}else{
					v[i].push_back(str);		//null values ("$") are not pushed into the vector storing all the productions
				}
			}
		}
	}

	while(!nv.empty()){
		char q  = nv.front();
		nv.pop();
		for(int i=0; i<n; ++i){			//for no of variables (row in v[][])
			for(int j=0; j<v[i].size(); ++j){			//for each production of row i
				for(int k=0; k < v[i][j].size(); ++k){			//for each character of the string v[i][j]
					if(v[i][j][k]==q){
						string t = substring(v[i][j], 0, k) + substring(v[i][j], k+1, v[i][j].size());
						if(t=="\0"){
							nv.push(variable[i]);
						}else{
							v[i].push_back(t);		//push the new production in the corresponding vector
						}
					}

				}
			}
		}
	}

	for(int i=0; i<n; ++i){
		cout<<variable[i]<<" -> ";

		v[i].erase( unique( v[i].begin(), v[i].end() ), v[i].end() );

		int j=0;
		for(j=0; j<v[i].size()-1; ++j)
		cout<<v[i][j]<<" | ";
		cout<<v[i][j]<<endl;
	}
    }else
    cout<<"Unable to open file\n";
}

int main() {
	cout<<"Assumptions:\n1. The variables are represented by single Capital letters.\n";
	cout<<"2. The null terminal is represented by $ symbol.\n";
	cout<<"3. In the file input.txt:\n\ta) The first line contains a positive integer denoting the number of lines \n\t   to follow (no of variables);\n";
	cout<<"\tb) All the productions for a particular variable are given in a single line, \n\t   seperated by \"|\" symbol and no spaces;\n";
	cout<<"\tc) Each line of the file after the 1st line is in the format: \n\t   a (different) Variable - a space - its corresponding right side of productions as described in (b).\n";
	cout<<"\t   Note, it is assumed that each line contains only one space - between \n\t   the variable and the string of right side of productions\n\n";

	cout<<"OUTPUT:\n";
	removeNullProductions();

	return 0;
}