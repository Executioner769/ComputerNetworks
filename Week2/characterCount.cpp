#include "stdc++.h"
using namespace std;

vector<int> data;

void getFrames(int frameCount)
{
	for(int i = 0; i < frameCount; i++) {
		int size = 0;
		cout<<"Enter the size of the frame"<<(i+1)<<":";
		cin>>size;
		data.push_back(size);
		int temp;
		for(int j = 0; j < size; j++) {
			cin>>temp;
			data.push_back(temp);
		}
	}
}

void printData(vector<int> v) {
	for(int i = 0; i < v.size(); i++) {
		cout<<data[i]<<" ";
	}
	cout<<endl;
}

void extractFrames(vector<int> v) {
	int max = v.size();
	int count = 0;
	while(count <= max) {
		int size = v[count++];
		cout<<"|";
		for(int i = 0; i < size; i++) {
			cout<<v[count++]<<" ";
		}
	}
	cout<<endl;
}


int main() {
	int frameCount;
	cout<<"Enter the count of the frames: ";
	cin>>frameCount;
	getFrames(frameCount);
	printData(data);
	extractFrames(data);
	return 0;
}