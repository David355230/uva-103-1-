//此題有n dim 用c++比較快
#include<cstdio>
#include<algorithm>

//創建架構
struct Box
{
	int d;//dim
	int dim[10];
	int tag;//紀錄位置
	
	bool operator>(const Box &b)//用來同時比較 Box的n dim 
	{
		int i;
		for(i=0;i<d;i++)
		{
			if(dim[i]<=b.dim[i])
			return false;
		}
		return true;
	 } 
	
 };
 bool comp(const Box &a,const Box&b)
 {
 	int i;
 	for(i=0;i<a.d;i++)
 	{
 		if(a.dim[i]>=b.dim[i])
 		{
 			return false;
 			break;
		 }
 		
 		else
 		return true;
	 }
 }

 int LIS(Box box[],int n,int listbi[])
 {
 	int lislen[n];
 	std::fill(lislen,lislen+n,1);
 	int prev[n]={};
 	int i,j;
 	for(i=1;i<n;i++)
 	{
 		for(j=0;j<i;j++)
 		{
 			if(box[i]>box[j])
 			{
 				if(lislen[j]+1>lislen[i])
 				{
 					lislen[i]=lislen[j]+1;
 					prev[i]=j;//紀錄最大長度前一個位置 
				 }
			 }
		 }
	 }
	 
	 int temp=0;
	 int last;
	 for(i=0;i<n;i++)
	 {
	 	if(lislen[i]>temp)
	 	{
	 		temp=lislen[i];
	 		last=i;
		 }
	 }
	 
	 for(i=temp;i>=1;i--)
	 {
	 	listbi[i-1]=box[last].tag;
	 	last=prev[last];
	 	
	 }
	 return temp;
 }

 int main()
 {
 	int n,dim,i,j,len;
 	int N=30;
 	Box box[N];
 	
 	while(scanf("%d %d",&n,&dim)!=EOF)
 	{
 		int listbi[N]={};
 		for(i=0;i<n;i++)
 		{
 			box[i].d=dim;
 			box[i].tag=i+1;
 			for(j=0;j<dim;j++)
 			scanf("%d",&box[i].dim[j]);
 			
 			std::sort(box[i].dim,box[i].dim+dim);
 			//對橫列做sort
		}
		std::sort(box,box+n,comp);
		//對直列作sort
		 len=LIS(box,n,listbi);
		 printf("%d\n",len);
		 for(i=0;i<len;i++)
		 {
		 	if(i==len-1)
		 	printf("%d\n",listbi[i]);
		 	else
		 	printf("%d ",listbi[i]);
		 	
		 }
	 }
	 return 0;
	 
 }
