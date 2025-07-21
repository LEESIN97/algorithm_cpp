#include<iostream>
#include<algorithm>
using namespace std;


int x; // 구멍 단위 센티미터
int num;
int lego[1000000];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> x) {

		x = x * 1e7; // cm to nano

		cin >> num;

		for (int j = 0; j < num; j++) {
			cin >> lego[j];
		}

		sort(lego, lego + num);

		int st = 0;
		int end = num - 1;

		bool ok = false;
		int l1, l2;

		while (st < end) {
			int current_sum = lego[st] + lego[end];

			if (current_sum < x) {
				st += 1;
			}
			else if (current_sum > x) {
				end -= 1;
			}
			else {
				l1 = lego[st];
				l2 = lego[end];
				ok = true;
				break;
			}
		}

		if (ok) {
			
			cout << "yes " << l1 << " " << l2 << "\n";
		}
		else {
			cout << "danger\n";
		}
		
	}

	return 0;
}