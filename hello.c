#include<stdio.h>
#include<string.h>

void data_input(char *data,char *type); //register
int  login     (char *name,char *pass); //login

void main(){
	int flag,scanf_flag; 		
	char str_n[256],str_p[256]; 
	
	/* while loop */
	while(1){
	printf("select\n 1:Register user 2:login 3:end\n:");
		
		/* scanf*/
		while(1){
			scanf_flag=scanf("%d",&flag);
			if(scanf_flag!=1 || flag<=0 || flag>3){
			if(scanf_flag!=1) scanf("%*s");	
			printf("the number is incorrect. please select again\n:");
			continue;
			}
			break;
		}
			
		if(flag==1){
		
			printf("Write the user name\n:");
			scanf("%s",str_n);
			data_input(str_n,"name");
			
			printf("Write the user password\n:");
			scanf("%s",str_p);
			data_input(str_p,"pass");
			
			printf("registerd\n");
		}else if(flag==2){
			printf("Write the user name\n:");
			scanf("%s",str_n);
			printf("Write the password\n:");
			scanf("%s",str_p);
			
			flag=login(str_n,str_p);
			if(flag==1) printf("login successful\n");
			else printf("login unsuccessful\n");
			
		}else if(flag==3){
			printf("fin\n");
			break;
		}
	}
}

/*regiseter file*/
void data_input(char *data,char *type){
	FILE *fp;
	char str[256];
	
	/* register */
	sprintf(str,"%s.txt",type); 
	fp=fopen(str,"a");
	fprintf(fp,"\n%s",data);
	fclose(fp);
}

/*login*/
int login(char *name,char *pass){
	FILE *fp;
	char str[256];
	int flag=0,count=0,count_p=0,no=0;
	
	/*get user name*/
	fp=fopen("name.txt","r");
	while((fscanf(fp,"%s",str))!=EOF){
		count++;
		if(strcmp(name,str)==0){
			no=count;
			break;
		}
	}
	fclose(fp);
	
	/*password*/
	fp=fopen("pass.txt","r");
	while((fscanf(fp,"%s",str))!=EOF){
		count_p++;
		if(no==count_p){
			if(strcmp(pass,str)==0) flag=1; //if password = correct
			break;
		}
	}
	fclose(fp);
	return flag;
}
