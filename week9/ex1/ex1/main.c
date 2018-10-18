//
//  main.c
//  ex1
//
//  Created by admin on 18/10/2018.
//  Copyright © 2018 admin. All rights reserved.
//


//int main(int argc, const char * argv[])

#include<stdio.h>

int main()
    {
        int memsize=15;
        int pagesize,nofpage;
        int p[100];
        int frameno,offset;
        int logadd,phyadd;
        int i;
        int choice=0;
        printf("\nYour memsize is %d ",memsize);
        printf("\nEnter page size:");
        scanf("%d",&pagesize);
        
        nofpage=memsize/pagesize;
        
        for(i=0;i<nofpage;i++)
        {
            printf("\nEnter the page frame%d:",i);
            scanf("%d",&p[i]);
        }
        
        do
        {
            printf("\nEnter a logical address:");
            scanf("%d",&logadd);
            frameno=logadd/pagesize;
            offset=logadd%pagesize;
            phyadd=(p[frameno]*pagesize)+offset;
            printf("\nPhysical address is:%d",phyadd);
            printf("\nDo you want to continue(1/0)?:");
            scanf("%d",&choice);
        }while(choice==1);
    
        return 0;
    }
