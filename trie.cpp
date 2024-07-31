#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


struct trie {

	trie * children[26];
	bool last;
	int length;
	int index;
	trie() {
		last = false;
		length = INT_MAX;
		index = -1;
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}

	}

};



void insert(string &s , trie * root , int index ) {
	int length = s.size();

	trie *currentnode = root;
	for (int i = 0; i < s.size(); i++) {

		char ch = s[i];

		if (currentnode->children[ch - 'a'] == NULL) {
			trie * n = new trie();
			currentnode->children[ch - 'a'] = n;
		}


		currentnode = currentnode->children[ch - 'a'];
		if (length < currentnode->length) {
			// cout<<" works "<<index<<endl;
			currentnode->length = length;
			currentnode->index = index;
		}
	}
	currentnode->last = true;


}



int present(string & s , trie * root) {
	trie * currentnode = root;
	int pre = -1;
	for (int i = 0; i < s.size(); i++) {
		char ch = s[i];
		if (currentnode->children[ch - 'a'] == NULL) {

			return currentnode->index;
		}
		pre = currentnode->index;
		currentnode = currentnode->children[ch - 'a'];
	}
	return currentnode->index;

}





int main() {
#ifndef ONLINE_JUDGE
	// for getting input
	freopen("input1.txt", "r", stdin);
	// for writing output
	freopen("output1.txt", "w", stdout);
#endif


	trie * root = new trie();
	trie *currentnode = root;
	int n ;
	cin >> n;
	vector<string> s(n);
	vector<string> t(n);


	for (int i = 0; i < s.size(); i++) {
		cin >> s[i];
	}
	for (int i = 0; i < s.size(); i++) {
		cin >> t[i];
	}
	int min_length = INT_MAX;
	int min_index = -1;
	for (int i = 0; i < s.size(); i++) {
		string temp = s[i];
		reverse(temp.begin(), temp.end());
		int size = temp.size();

		if (size < min_length) {
			min_index = i;
			min_length = size;
		}
		insert(temp, root, i);
	}


	vector<int> ans;

	for (int i = 0; i < t.size(); i++) {
		string temp = t[i];
		reverse(temp.begin(), temp.end());
		int index = present(temp, root);
		if (index == -1) {
			ans.push_back(min_index);
		} else {
			ans.push_back(index);
		}

	}


	for (auto it : ans)cout << it << " "; cout << endl;


}
