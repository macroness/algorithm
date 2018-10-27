#include <iostream>
#include <vector>

using namespace std;

static int m;
int goRstr(const vector<vector<int> >& relArr, const int p, int catsNum, int count, vector<bool>& visited, const vector<bool>& cat){
	if (visited[p]) {
		return count;
	}

	visited[p] = true;

	if (cat[p]) {
		catsNum = catsNum + 1;
		if (catsNum > m)
			return count;
	}
	else {
		catsNum = 0;
	}

	if (relArr[p].size() == 1 && p != 1){ 
		return count + 1;
	}

	for (int i = 0; i < relArr[p].size(); ++i){ 
		count = goRstr(relArr, relArr[p][i], catsNum, count, visited, cat);
	}

	return count;
}
int main(){

	int n;
	cin >> n >> m;

	vector<bool> cat;
	cat.push_back(0);
	for(int i=0; i< n; ++i){
		int c;
		cin >> c;
		cat.push_back(c);
	}

	vector<vector<int> > relArr;
	relArr.resize(n + 1);

	for(int i=0; i < n - 1; ++i){
		int x, y;
		cin >> x >> y;
		relArr[x].push_back(y);
		relArr[y].push_back(x);
	}

	vector<bool> visited(n + 1);
	cout << goRstr(relArr, 1, 0, 0, visited, cat);
	/*for(int i=1; i < n + 1; ++i){
		cout << i << " : ";
		for(int y=0; y < relArr[i].size(); ++y){
			cout << relArr[i][y] << " "; 
		}
		cout << "\n";
	}
	*/
	return 0;
}
