/*
与很多奶牛一样，Farmer John那群养尊处优的奶牛们对食物越来越挑剔，随便拿堆草就能打发她们午饭的日子自然是一去不返了。
现在，Farmer John不得不去牧草专供商那里购买大量美味多汁的牧草，来满足他那N(1 <= N <= 100,000)头挑剔的奶牛。 
所有奶牛都对FJ提出了她对牧草的要求：第i头奶牛要求她的食物每份的价钱不低于A_i(1 <= A_i <= 1,000,000,000)，并且鲜嫩程度不能低于B_i(1 <= B_i <= 1,000,000,000)。
商店里供应M(1 <= M <= 100,000)种不同的牧草，第i 种牧草的定价为C_i(1 <= C_i <= 1,000,000,000)，鲜嫩程度为D_i (1 <= D_i <= 1,000,000,000)。 
为了显示她们的与众不同，每头奶牛都要求她的食物是独一无二的，也就是说，没有哪两头奶牛会选择同一种食物。 
Farmer John想知道，为了让所有奶牛满意，他最少得在购买食物上花多少钱。
Input
* 第1行: 2个用空格隔开的整数：N 和 M

* 第2..N+1行: 第i+1行包含2个用空格隔开的整数：A_i、B_i * 第N+2..N+M+1行: 第j+N+1行包含2个用空格隔开的整数：C_i、D_i
Output
* 第1行: 输出1个整数，表示使所有奶牛满意的最小花费。如果无论如何都无法 满足所有奶牛的需求，输出-1
Input示例
4 7
1 1
2 3
1 4
4 2
3 2
2 1
4 3
5 2
5 4
2 6
4 4
Output示例
12
*/

#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100020];
pair<int,int> b[100020];
int n,m,p;
long long z;
multiset<int> s;
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++){
		scanf("%d%d",&a[i].second,&a[i].first);
		a[i].first = -a[i].first;
	}
	for(int i = 0;i < m;i++){
		scanf("%d%d",&b[i].second,&b[i].first);
		b[i].first = -b[i].first;
	}
	sort(a,a + n);
	sort(b,b + m);
	for(int i = 0;i < n;i++){
		while(p < m && b[p].first <= a[i].first){
			s.insert(b[p++].second);
		}
		multiset<int>::iterator it = s.lower_bound(a[i].second);
		if(it == s.end()){
			z = -1;
			break;
		}else{
			z += *it;
			s.erase(it);
		}
	}
	printf("%lld\n",z);
	return 0;
}
