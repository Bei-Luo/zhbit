/*
	洗字符串 全部是小写 饭后去除标点符号 去重 并且按升序输出 
	所以用set自带去重 自带升序
	先把所有非字符串换成空格 这个地方有坑
	然后 采用流 分割单词进入set 接着输出就好了
*/ 
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
#include<sstream>
using namespace std;
set<string> a;
int main (){
	string b,c;
	while(cin>>b){
		for(int i=0;i<b.length();++i){
			if(isalpha(b[i]))
			b[i]=tolower(b[i]);
			else
			b[i]=' ';
		}
		stringstream s(b);
		while(s>>c)
		a.insert(c);
	}
	for(set<string>::iterator i=a.begin();i!=a.end();i++)
	cout<<*i<<endl;
}
