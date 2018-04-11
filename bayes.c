#include <stdio.h>
#include <string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

float prob_func(int train_set[][192],int label[],int class,int feature,int value,float prob_class[] ){
    int i,j;
    float count1=0.0,count2=0.0;
    for(i=0;i<6670;i++){
        if(label[i]==class){
            if(train_set[i][feature]==value){
                count1++;
            }
            count2++;
        
        }
    }
    prob_class[class]=count2/6670.0;
    return count1/count2;
}

int pred_func(int test[],float probability_matrix[][192][5],float prob_class[]){
    float max= -99999.0;
    float sum;
    int i,j,index=-1;
    for(i=0;i<10;i++){
        sum=0.0;
        for(j=0;j<192;j++){
            sum=sum+log(probability_matrix[i][j][test[j]]);
        }
        sum=sum+log(prob_class[i]);
        if(sum>max){
            max = sum;
            index= i;
        }
    }
    return index;

}

int main(){
    FILE *f1 =fopen("pp_tra.dat","r");
    int train_set[6670][192];
    int label[6670];
    float prob_class[10];//matrix for storing priori prob
    int i,j,k,c;
    for(i=0;i<6670;i++){
        for(j=0;j<192;j++){
            fscanf(f1,"%d",&train_set[i][j]);
        }
        fscanf(f1,"%d",&label[i]);
    }
    float probability_matrix[10][192][5];


    for(i=0;i<10;i++){
        for(j=0;j<192;j++){
            for(k=0;k<5;k++){
                probability_matrix[i][j][k]=prob_func(train_set,label,i,j,k,prob_class);
            }
        }
    }
    for(i=0;i<10;i++){
        printf("%d\n\n ",i);
        for(j=0;j<192;j++){
            printf("%d ",j);
            for(k=0;k<5;k++){
                printf("%f ",probability_matrix[i][j][k]);
            }
            printf("\n");

        }
        printf("\n");
    }
    FILE *f2 =fopen("pp_tes.dat","r");
    int test[3333][192];
    int label_predicted[3333];
    int label_test[3333];
    for(i=0;i<3333;i++){
        for(j=0;j<192;j++){
            fscanf(f2,"%d",&test[i][j]);
        }
        fscanf(f2,"%d",&label_test[i]);
    }
    for(i=0;i<3333;i++){
        label_predicted[i]= pred_func(test[i],probability_matrix,prob_class);
    }
    int count=0;
    for(i=0;i<3333;i++){
        if(label_test[i]==label_predicted[i]){
            count++;
        }
    }

    for(i=0;i<3333;i++){
        printf("%d %d %d\n",i,label_predicted[i],label_test[i]);
    }

    printf("%lf\n",(count/3333.0)*100);

    return 0;



    


}