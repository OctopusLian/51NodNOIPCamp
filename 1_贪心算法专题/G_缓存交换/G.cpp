/*
在计算机中，CPU只能和高速缓存Cache直接交换数据。当所需的内存单元不在Cache中时，则需要从主存里把数据调入Cache。
此时，如果Cache容量已满，则必须先从中删除一个。 例如，当前Cache容量为3，且已经有编号为10和20的主存单元。
此时，CPU访问编号为10的主存单元，Cache命中。 
接着，CPU访问编号为21的主存单元，那么只需将该主存单元移入Cache中，造成一次缺失（Cache Miss）。 
接着，CPU访问编号为31的主存单元，则必须从Cache中换出一块，才能将编号为31的主存单元移入Cache，假设我们移出了编号为10的主存单元。 
接着，CPU再次访问编号为10的主存单元，则又引起了一次缺失。我们看到，如果在上一次删除时，删除其他的单元，则可以避免本次访问的缺失。 
在现代计算机中，往往采用LRU(最近最少使用)的算法来进行Cache调度——可是，从上一个例子就能看出，这并不是最优的算法。 
对于一个固定容量的空Cache和连续的若干主存访问请求，聪聪想知道如何在每次Cache缺失时换出正确的主存单元，以达到最少的Cache缺失次数。
Input
输入文件第一行包含两个整数N和M(1<=M<=N<=100,000)，分别代表了主存访问的次数和Cache的容量。 
第二行包含了N个空格分开的正整数，按访问请求先后顺序给出了每个主存块的编号(不超过1,000,000,000)。
Output
输出一行，为Cache缺失次数的最小值。
Input示例
6 2
1 2 3 1 2 3
Output示例
4
*/

#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
map<int,int> g;
int p[100020];
int a[100020];
int n,m,z;
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",a[i]);
	}
	for(int i = 1;i <= n;i++){
		p[i] = n + 1;
		p[g[a[i]]] = i;
		g[a[i]] = i;
	}
	for(int i = 1;i <= n;i++){
		if(s.find(i) != s.end()){
			s.erase(i);
			s.insert(p[i]);
		}else{
			z++;
			if(s.size() == m){
				s.erase(--s.end());
			}
			s.insert(p[i]);
		}
	}
	printf("%d\n",z);
	return 0;
} 
