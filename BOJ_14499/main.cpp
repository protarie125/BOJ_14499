#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

vi faces;
int n, m, x, y, k;
vvi mf;

bool canRoll(int p) {
	if (1 == p) {
		return y + 1 < m;
	}
	else if (2 == p) {
		return 0 <= y - 1;
	}
	else if (3 == p) {
		return 0 <= x - 1;
	}
	else if (4 == p) {
		return x + 1 < n;
	}

	return false;
}

void roll(int p) {
	auto d = faces[0];
	auto u = faces[1];
	auto f = faces[2];
	auto b = faces[3];
	auto l = faces[4];
	auto r = faces[5];

	if (1 == p) {
		++y;
		faces[0] = r;
		faces[1] = l;
		faces[4] = d;
		faces[5] = u;
	}
	else if (2 == p) {
		--y;
		faces[0] = l;
		faces[1] = r;
		faces[4] = u;
		faces[5] = d;
	}
	else if (3 == p) {
		--x;
		faces[0] = b;
		faces[1] = f;
		faces[2] = d;
		faces[3] = u;
	}
	else if (4 == p) {
		++x;
		faces[0] = f;
		faces[1] = b;
		faces[2] = u;
		faces[3] = d;
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	faces = vi(6, 0);
	cin >> n >> m >> x >> y >> k;

	mf = vvi(n, vi(m));
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			cin >> mf[i][j];
		}
	}

	while (0 < (k--)) {
		int p;
		cin >> p;

		if (!canRoll(p)) {
			continue;
		}

		roll(p);
		if (0 == mf[x][y]) {
			mf[x][y] = faces[0];
		}
		else {
			faces[0] = mf[x][y];
			mf[x][y] = 0;
		}

		cout << faces[1] << '\n';
	}

	return 0;
}