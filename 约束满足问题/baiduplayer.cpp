#include<stdio.h>  
struct players{  
    int num;  
}player[4];  
int main (){  
    scanf("%d%d%d%d",&player[0].num,&player[1].num,&player[2].num,&player[3].num);  
    int k;
    int d;
    scanf("%d",&k); 
    scanf("%d",&d); 
     
    int ret = 0;

    int sum=0;  
    for (int i=1;i<=6;i++){  
        for (int j=i;j<=6;j++){  
            int kk;
            if((i+j)%4 == 0) kk=4;
            else kk = (i+j)%4;
            int tem = 0;
            while(kk != k){
                tem=tem+player[kk-1].num;
                if(kk==4)kk=3;
                else if(kk==3)kk =2;
                else if(kk==2)kk =1;
                else if(kk==1)kk =4;
            }
            tem = tem+d;
            tem = tem-i;
            if(tem<22){
                if(tem == 1){
                    ++ret;
                }
                else if(tem == 9){
                    ++ret;
                }
                else if(tem == 17){
                    ++ret;
                }
            }
        }  
    }  
    printf ("%d\n",ret);  
    return 0;  
}