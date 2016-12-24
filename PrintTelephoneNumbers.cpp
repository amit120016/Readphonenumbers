#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<stack>
#include<string>
#include<sys/types.h>
#include<dirent.h>
#include<fstream>
#include<iterator>
using namespace std;

void listdir(const char *,int );

int main(int argc, char ** argv) {

  char s[100],s1[100];
  cout<<"Enter the path of the folder where documents are kept"<<endl;
  gets(s);
  DIR *dp;
  dirent *d;
  dp = opendir(s);
  int count=0;
  while((d = readdir(dp)) != NULL){
  	count++;
  }

  listdir(s,count);
   return 0;
}

void listdir(const char *dirname,int n) {

  DIR *dp;
  dirent *d;

  int i=0,j,k,l;
  dp = opendir(dirname);
  vector<string> names(n);
  int z=0;
  while((d = readdir(dp)) != NULL)
  {

  	if(d->d_name[0]=='.')
  	continue;

  	ifstream file1;
  	string  str1="";

  	for(l=0;dirname[l]!='\0';l++){
	  	str1+=dirname[l];
    }

  	str1+=(char)92;
  	l++;

    for(j=0;d->d_name[j]!='\0';j++){
  		str1+=d->d_name[j];
  		names[z].push_back(d->d_name[j]);
     }

  	z++;
  	char str2[100];

  	for(j=0;j<100;j++){
	  	str2[j]='\0';
    }
	  for(j=0;j<str1.size();j++){
  		str2[j]=str1[j];
  	}

  	file1.open(str2);
	  	string number;

    int c,i;
        while(file1>>number){
            c=0;i=0;
            if( number.size() >= 10 ){
                while( i < number.size()){
                    string s1="";c=0;
                    if(number[i] == '+'){
                        if(number[i+1] == '9' && number[i+2] == '1'){
                            s1+="+91";
                            c=0;
                            for(j=i+3;j<number.size();j++){
                                if(number[j] >= 48 && number[j] <=57 ){
                                    s1+=number[j];
                                    c++;
                                }
                                else
                                    break;
                            }
                        }
                        if(c==10){
                            cout<<s1<<endl;
                            i+=13;
                        }
                        else
                        {
                            i+=c;
                        }
                    }
                    else if(number[i] == '0'){
                            s1+="0";
                            c=0;
                            for(j=i+1;j<number.size();j++){
                                if(number[j] >= 48 && number[j] <=57 ){
                                    s1+=number[j];
                                    c++;
                                }
                                else{
                                    break;
                                }
                            }
                        if(c==10){
                            cout<<s1<<endl;
                            i+=11;
                        }
                        else
                        {
                            i+=c;
                        }

                    }
                    else
                    {
                        int a=0;

                        if(number[i] >= 48 && number[i] <= 57){
                            s1+="";
                            c=0;
                            for(j=i;j<number.size();j++){
                                if(number[j] >= 48 && number[j] <=57 ){
                                    s1+=number[j];
                                    c++;
                                }
                                else
                                    break;
                            }

                        if(c==10){
                            cout<<s1<<endl;
                            i+=10;
                        }
                        else
                        {
                            i+=c;
                        }
                }
                else
                    i++;
                    }
                }
        }
  }
  }
}

