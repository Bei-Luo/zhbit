/*
	题意给定 一个数字序列 每次都出队 并且将第二个放在队尾 直到剩余最后一个
	给出 出队序列 和最后一张牌
*/ 
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include<sstream>
using namespace std;
int main (){
	int b;
	while(cin>>b,b){
		queue< int > a;
		for(int i=1;i<=b;++i)
		a.push(i);
		cout<<"Discarded cards:";
		if(a.size()==1){
			cout<<endl;
			cout<<"Remaining card: "<<a.front()<<endl;
		}
		else{
			cout<<" ";
			while(a.size()>=2){
				cout<<a.front();a.pop();
				a.push(a.front());a.pop();
				if(a.size()>=2)
				cout<<", ";
				else
				cout<<endl;
			}
			cout<<"Remaining card: "<<a.front()<<endl;
		}
	}
}
