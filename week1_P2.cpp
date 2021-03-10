//////Problem W1_P2 : DS21_Week1_P2_F (퀴즈 2번문제는 W1_P4)
//////첫주차 퀴즈 2번째 문제 변형 (퀴즈때 못풂) 
////// 3/6
///// 3/10 성공! 


#include<iostream>
using namespace std;
class Array {
private:
	int* arr;
	int arrSize;
public:
	Array(int sz) {
		this->arrSize = sz;
		this->arr = new int[arrSize];
		for (int i = 0; i < sz; i++)
			arr[i] = 0;
	}
	void Aset(int idx, int value) {
		arr[idx] = value; 
	}
	void Asift(int d) {
		for (int i = 0; i < d; i++) {
			int k = arr[arrSize-1]; //k=arr[4]
			for (int j = arrSize-2; j >=0; j--) {
				arr[j+1] = arr[j];// arr[4]=arr[3],arr[3]=arr[2],arr[2]=arr[1],arr[1]=arr[0]
			}
			arr[0] = k; //arr[0]=k=arr[4]
		}
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
	}
};

int main() {
	int t, n, d, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> d;
		Array Ar(n);
		for (int i = 0; i < n; i++) {
			cin >> k;
			Ar.Aset(i, k);
		}
		Ar.Asift(d);
	}
	return 0;
}