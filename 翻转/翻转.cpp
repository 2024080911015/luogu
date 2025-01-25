#include<iostream>
using namespace std;
int main()
{
	int D = 0,count=0;
	cin >> D;
	string T, S;
	int* p = new int(D);
	for (int i = 0; i < D; i++) {
		cin >> T;
		cin >> S;
		if ((T[0] != S[0]) || (T[T.size() - 1] != S[S.size() - 1])) {
			p[i] = -1;
			continue;
		}
		else {
			for (int j = 1; j < T.size(); j++) {
				if (S[j] != T[j]) {
					if ((S[j - 1] != S[j]) && (S[j] != S[j + 1])) {
						count++;
						p[i] = count;
					}
					else {
						p[i] = -1;
						break;
					}
				}
			}
		}
	}
	for (int j = 0; j < D; j++) {
		cout << p[j] << endl;
	}
	return 0;
}