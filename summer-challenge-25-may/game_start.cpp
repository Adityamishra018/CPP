#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int t,n,m,x;
	vector<int> farr(101),sarr(101),ans(101);
	std::vector<int>::iterator it;
	set <int> seta,setb;
	cin>>t;

	while(t--){
		cin>>n>>m;
		farr.erase(farr.begin(),farr.end());
		sarr.erase(sarr.begin(),sarr.end());
		seta.erase(seta.begin(),seta.end());
		setb.erase(setb.begin(),setb.end());
		while(n--){
			cin>>x;
			if(x%3 == 0)
				farr.emplace_back(x);
		}
		while(m--){
			cin>>x;
			if(x%3 == 0)
				sarr.emplace_back(x);
		}
        std::sort(farr.begin(),farr.end());
        std::sort(sarr.begin(),sarr.end());
        ans.assign((farr.size()<sarr.size())?farr.size():sarr.size(), 0);
        for(auto i: farr)
        	if(std::count(farr.begin(),farr.end(),i) > 1)
        		continue;
        	else
        		seta.insert(i);
        for(auto i: sarr)
        	if(std::count(sarr.begin(),sarr.end(),i) > 1)
        		continue;
        	else
        		setb.insert(i);

       if(seta.size() == 0 || setb.size() == 0){
       		cout<<"-1\n";
       		continue;
       }
       it = std::set_intersection(seta.begin(),seta.end(),setb.begin(),setb.end(),ans.begin());
       ans.resize(it-ans.begin());
       for(auto i : ans)
       	  cout<<i<<" ";

        cout<<"\n";
	}
	return 0;
}