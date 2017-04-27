#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
typedef struct tagpoint point;
struct tagpoint{
    double x,y;
};
double distance(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

    
static point p[100];
static point mpt[100];





void swap(point *a, point *b)
{
	point temp = *a;
	*a = *b;
	*b = temp;
}

/**拆分为两个部分*/
double patition(point *num, int left, int right)
{
	double tmp = num[right].x;

	while(left < right)
	{
		while(left < right && num[left].x <= tmp)
		{
			left++;
		}

		swap(&num[left], &num[right]);

		while(left < right && num[right].x >= tmp)
		{
			right--;
		}

		swap(&num[left], &num[right]);
	}
	return left;
}

/**快速排序*/
void quickSort(point *num, int left, int right)
{
	double tmp;

	if(left < right)
	{
		tmp = patition(num, left, right);
		quickSort(num, left, tmp - 1);
		quickSort(num, tmp + 1, right);
	}
}

/*void sortx(point *p,int n){
    for(i=0;i<n;i++){
        num[i]=p[i].x;
    }
*/    
double Closest_Pair(int left, int right){
    //int i;
    /*int i,m;
    m=n/2;
    p[m].x;
    for(i=0;i<m;i++){
        l[i]=p[i];
    }
    for(i=0;i<n-m;i++){
        r[i]=p[i+m];
    }
    i=0;
    if(m==1){
        return 10000.0;
    }
    if(m==2){
        return distance(l[0],l[1]);
    }
    
    if(n-m==1){
        return 10000;
    }
    if(n-m==2){
        dr=distance(r[0],r[1]);
    }
    
    else {
        dr=Closest_Pair();
    }*/
     double d = 10000;
     if (left == right)
        return d;
     if (left + 1 == right)
         return distance(p[left],p[right]);
     int mid = (left + right)/2;
     double d1 = Closest_Pair(left, mid);
     double d2 = Closest_Pair(mid + 1, right);
     //d = min(d1, d2);
     if(d1<=d2)
         d=d1;
     else
         d=d2;
     int i, j=0, k = 0;
     //分离出宽度为d的区间  
     for (i = left; i <= right; i++){
         if (fabs(p[mid].x - p[i].x) <= d){
             mpt[k] = p[i];
             k++;
         }
     }
     //sort(mpt, mpt + k, cmpy);
     //线性扫描  
     for (i = 0; i < k; i++){
         for (j = i + 1; j < k && p[j].y - p[i].y<d; j++){
             double d3 = distance(mpt[i], mpt[j]);
             if (d > d3)    d = d3;
         }
     }
     return d;
 }





int main(){
    /*double a[]={1.1,1.2,8.5,4.3};
    quickSort(a,0,3);
    printf("%lf",a[2]);*/
    int n,i=0,j,k,ls=0;
    double d;
    printf("how many point do you want:\n");
    scanf("%d",&n);
    srand(time(NULL));
    //point p[100];
    for(i=0;i<n;i++){
        p[i].x=rand()%100;
        p[i].y=rand()%100;
    }
    quickSort(p,0,n-1);
    for(i=0;i<n;i++){
        printf("%d:(%lf,",i+1,p[i].x);
        printf("%lf)\n",p[i].y);
    }
    for(i=0;i<100;i++){
        printf("|\n");
        for(j=0;j<n;j++){
            if(p[j].y==100-i){
                
                for(k=0;k<p[j].x;k++){
                    printf(" ");
                }
                printf("*\n");
            }
            

        }
    }



    //quickSort(p,0,n-1);
    /*for(i=0;i<n;i++){
        printf("%d:(%lf,",i+1,p[i].x);
        printf("%lf)\n",p[i].y);
    }*/
    d=Closest_Pair(0,n-1);
    printf("%lf\n",d);


}
