#include <stdio.h>
#include <time.h>
#include <string.h>


int get_rand(int min, int max) {
    int rand(void);
    return rand() % (max - min + 1) + min;
}

int main(void)
{

    int m=0,n=0,use,min = 100,x=0,y=0;
    int i,i1,i2,i3;
    
    printf("Enter m and n: ");
    while((m<3) || (n<4))
    {
        scanf("%d",&m);
        scanf("%d",&n);
        if((m<3) || (n<4))
            printf("Wrong size! (m>3,n>4)\nTry again:");
    }

    int arr[m][n],min_arr[100][2],arr_two[n][m];

    void srand(int);
    srand(time(NULL));
    for(i1=0;i1<m;i1++)
    {
        for(i2=0;i2<n;i2++)
        {
            arr[i1][i2] = get_rand(0,100);
            printf("%d\t",arr[i1][i2]);
        }
        printf("\n");
    }

    for(i = 0;i<n;i++)
    {
        use = arr[0][i];
        arr[0][i] = arr[m-1][n-i-1];
        arr[m-1][n-i-1] = use;
    }

    printf("\n");

    use = 0;
    for(i1=0;i1<m;i1++)
    {
        for(i2=0;i2<n;i2++)
        {
            if(arr[i1][i2] == min)
            {
                use++;
                min_arr[use][0] = i2;
                min_arr[use][1] = i1;
            }
            if(arr[i1][i2]<min)
            {
                use = 0;
                min = arr[i1][i2];
                min_arr[0][0] = i2;
                min_arr[0][1] = i1;
            }
            printf("%d\t",arr[i1][i2]);
        }
        printf("\n");
    }
    printf("\n");

    int use2 = 1;
    for(i1=0;i1<m;i1++)
        for(i2=0;i2<n;i2++)
        {
            for(i=0;i<use+1;i++)
                if((min_arr[i][0] == i2) || (min_arr[i][1] == i1))
                    use2 = 0;
            if(use2 == 1)
            {
                arr[i1][i2] = arr[i1][i2];
            }
            else
                arr[i1][i2] = -1;
            use2 = 1;
        }
    use2 = 0;
    for( i1=0;i1<m;i1++)
    {
        for( i2=0;i2<n;i2++)
        {
            if(arr[i1][i2] != -1)
            {
                arr[x][y] = arr[i1][i2];
                y++;
            }

        }
        x++;
        for( i=0;i<use+1;i++)
                if(min_arr[i][1] == i1)
                    use2 = 1;
        if(use2 == 1)
            x--;
        use2 = 0;
        y = 0;
        
    }

    int count = 0;
    for( i1=0;i1<use+1;i1++)
    {
            count++;
        for( i2=i1+1;i2<use+1;i2++)
        {
            if(min_arr[i1][0] == min_arr[i2][0])
            {
                count--;
                i2 = use+1;
            }
        }
    }
    n= n-count;

    count = 0;
    for( i1=0;i1<use+1;i1++)
    {
            count++;
        for( i2=i1+1;i2<use+1;i2++)
        {
            if(min_arr[i1][1] == min_arr[i2][1])
            {
                count--;
                i2 = use+1;
            }
        }
    }
    m= m-count;

    printf("\n");

    for( i1=0;i1<m;i1++)
    {
        for( i2=0;i2<n;i2++)
        {
            printf("%d\t",arr[i1][i2]);
        }
        printf("\n");
    }
    printf("\n");

    char line[m*n*m*n],*part,line2[m][m*n*n],*pat;
    printf("Enter the array manually (m = %d - row, n = %d - line): ",n,m);
    fgets(line,m*n*m*n,stdin);
    fgets(line,m*n*m*n,stdin);

    int atoi(char*);
    strcpy(line2[0],strtok(line,","));
    for(i=1;i<n;i++)
    {
        pat = strtok(NULL,",");
        if(pat!= NULL)
            strcpy(line2[i],pat);
        else
        {
            printf("All incorrect data reset\n");
            i = n;
        }
    }
    

    for(i1=0;i1<n;i1++)
    {
        part = strtok(line2[i1]," ");
        for(i2=0;i2<m;i2++)
        {
            if(i2 != 0)
                part = strtok(NULL," ");
            arr_two[i1][i2] = atoi(part);
        }
    }

    printf("\n");

    for( i1=0;i1<n;i1++)
    {
        for( i2=0;i2<m;i2++)
        {
            printf("%d\t",arr_two[i1][i2]);
        }
        printf("\n");
    }
    printf("\n");

    int c=0,arr_thr[m][m];
    
    for(i1 = 0;i1<m;i1++)
    {
        for(i2 = 0;i2<m;i2++)
        {
            c = 0;
            for(i3 = 0;i3<n;i3++)
            {
                c = c + arr[i1][i3]*arr_two[i3][i2];
            }
            arr_thr[i1][i2] = c;
        }
    }
    
    for( i1=0;i1<m;i1++)
    {
        for( i2=0;i2<m;i2++)
        {
            printf("%d\t",arr_thr[i1][i2]);
        }
        printf("\n");
    }
    
    return 0;
}
