#include <bits/stdc++.h>
/*
TASK: hidden
LANG: C++11
*/
using namespace std;
typedef long long ll;
typedef pair<int, int> pair2;
typedef pair<int, pair<int, int> > pair3;
typedef pair<int, pair<int, pair<int, int> > > pair4;
#define MAXN 100010
#define INF 1000000000000000LL
#define mp make_pair
#define add push_back
#define remove pop

int n, q, baseNode[4*MAXN]; //numbers[MAXN][10];
ll numbers[MAXN][10], tree[4 * MAXN][10];
int nxt[4 * MAXN][10];

void updFromChildren(int i) {
	for (int j = 0; j < 10; j++) {
		tree[i][j] = tree[2 * i][j] + tree[2 * i + 1][j];
	}
}

void build(int left, int right, int i) {

	if (left == right) {
		for (int j = 0; j < 10; j++) {
			tree[i][j] = numbers[left][j];
		}
		baseNode[i] = true;
		return;
	}

	int mid = (left + right) / 2;
	build(left, mid, 2 * i);
	build(mid + 1, right, 2 * i + 1);

	updFromChildren(i);
}

int n1[10], n2[10];
ll sum[10];
void push(int i, int left, int right) {
	for (int j = 0; j < 10; j++) {
		sum[j] = 0;
	}

	if (!baseNode[i]) {
		for (int j = 0; j < 10; j++) {
			n1[j] = nxt[i][nxt[2 * i][j]];
			n2[j] = nxt[i][nxt[2 * i + 1][j]];
		}

		for (int j = 0; j < 10; j++) {
			nxt[2 * i][j] = n1[j];
			nxt[2 * i + 1][j] = n2[j];
		}
	}

	for (int j = 0; j < 10; j++) {
		//if (i == 1) cout << "nxt[1][" << j << "] is " << nxt[i][j] << '\n';
		sum[nxt[i][j]] += tree[i][j]; 
	}

	for (int j = 0; j < 10; j++) {
		//if (i == 1) cout << "sum " << j << " is " << sum[j] << '\n';
		tree[i][j] = sum[j];//tree[i][j];
		nxt[i][j] = j;
	}
}

void update(int i, int left, int right, int start, int end, pair2 change) {
	if (i >= 4 * MAXN) return;
	push(i, left, right);
	if (start > right || left > end) return;
	//cout << "i is " << i << '\n';
	//cout << "tree[1][1] is " << tree[1][1] << '\n';
	if (start <= left && right <= end) {
		nxt[i][change.first] = change.second;
		push(i, left, right);

		return;
	}

	int mid = (left + right) / 2;
	update(2 * i, left, mid, start, end, change);
	update(2 * i + 1, mid + 1, right, start, end, change);

	updFromChildren(i);
}


ll query(int i, int left, int right, int start, int end) {
	if (i >= 4 * MAXN) return 0;
	push(i, left, right);
	if (start > right || left > end) return 0;
	if (start <= left && right <= end) {
		ll answer = 0;
		for (int j = 1; j < 10; j++) {
			answer += (ll) (j) * tree[i][j];
			//cout << "tree" << i << ' ' << j << " is " << tree[i][j] << '\n';
		}
		return answer;
	}
	
	int mid = (left + right) / 2;
	return query(2 * i, left, mid, start, end) + query(2 * i + 1, mid + 1, right, start, end);
}

int main() {
	//freopen("shufflegold.in", "r", stdin);
	//freopen("shufflegold.out", "w", stdout);
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> n >> q;

	int tenToThePowerOf[9];
	tenToThePowerOf[0] = 1;
	for (int i = 1; i < 9; i++) {
		tenToThePowerOf[i] = tenToThePowerOf[i - 1] * 10;
	}

		
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		for (int j = 0; j < 10; j++) {
			numbers[i][j] = 0;
		}

		for (int j = 0; j < 9; j++) {
			//numbers[i][j] = temp % 10;
			if (temp == 0) break;
			int cur = temp % 10;
			numbers[i][cur] += tenToThePowerOf[j];
			temp /= 10;
		}
	}

	for (int i = 0; i < 4 * MAXN; i++) {
		for (int j = 0; j < 10; j++) {
			tree[i][j] = 0;
			nxt[i][j] = j;
		}
	}


	build(0, n - 1, 1);
	//cout << "tree[1][1] is " << tree[1][1] << '\n';
	for (int i = 0; i < q; i++) {
		int id;
		cin >> id;

		if (id == 1) {
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			l--;
			r--;
		
		update(1, 0, n - 1, l, r, mp(x, y));
		} 
		else {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << query(1, 0, n - 1, l, r) << '\n';
		}
	}
}