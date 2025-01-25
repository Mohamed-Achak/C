  #include<stdio.h>
  #include<string.h>
  #include<stdlib.h>



  typedef struct nd{
    int id; 
    char s_name[100]; 
    char a_name[100];
    char s_major[100];
    double cgpa;  
    struct nd*next;
  }node;

  void menu(void); 
  void traverse_LL(node*);
  node* create_LL(FILE* infp);
  node* create_fill_node(void) ;

  /*         Main Function        */
  int main(void){
    int choice; 
    node*head=NULL;
    FILE*infp;
    
    infp = fopen("Section07_Data.txt","r");
    
    if(infp==NULL)
      return 0;
      
    do{
        menu();
        scanf("%d",&choice);
        switch(choice){
        case 1://create a LL from the file content.
            head = create_LL(infp);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:traverse_LL(head);
                break;
        case 5:
              break;
          case 6:printf("\n\t\tYou decided to QUIT\n\n\t\tBYE!\n\n\t\t");
                break;
        default:printf("\n\t\tThat was an INVALID CHOICE!\n");
      }//end of switch
    }while(choice!=6);    
  }
  /*  Functions Definitions */
  void menu(void){
    printf("\n\t\t----------------------------------------\n");
    printf("\n\t\t1. Create an Initial List\n");
    printf("\n\t\t2. Add a New Student\n");
    printf("\n\t\t3. Drop a Student\n");
    printf("\n\t\t4. Traverse LL\n");
    printf("\n\t\t5. Count Students in the LL\n");
    printf("\n\t\t6. Quit\n");
    printf("\n\t\t----------------------------------------\n");
    printf("\n\t\tYour choice please:");
  }
  void add_node(node**phead,node*ToAdd){ //the node must be created in advance
    node*walker; 
    if(*phead==NULL)
      *phead=ToAdd; 
    else{
      walker=*phead; 
      while(walker->next!=NULL){
      walker=walker->next;
    }
    walker->next=ToAdd;  
    }
  }
  void traverse_LL(node*head){
    node*walker=head; 
    if(head==NULL)
      printf("\n\t\tLinked list is EMPTY!\n");
    else{	    
      while(walker!=NULL){
        printf("\n\t\tStudent Name:%s\n",walker->s_name);
        printf("\n\t\tMajor:%s\n",walker->s_major);
        printf("\n\t\tAdvisor:%s\n",walker->a_name);
        printf("\n\t\tCGPA:%.2f\n",walker->cgpa);
        printf("\n\t\t--------------------------\n");
        walker=walker->next;   
        }
    }
  }
  node* create_LL(FILE* infp){
    node* head=NULL, *ToAdd;
    char ch, line[100];
    while (!feof(infp)) 
    {
      ToAdd = (node*)malloc(sizeof(node));
    fscanf(infp, "%d", &ToAdd->id);
    getc(infp);
    fgets(ToAdd->s_name, 100, infp);
    fgets(ToAdd->s_major, 100, infp);
    fgets(ToAdd->a_name, 100, infp) ;
    fscanf (infp, "%lf", &ToAdd->cgpa);
    ch  = getc(infp);
    fgets (line, 100, infp) ;
    ToAdd->next = NULL;
    add_node(&head, ToAdd);




    }
    return head;
  }
  node* create_fill_node(void){
node* new_node;

new_node = (node*) malloc(sizeof(node));
printf("\n\t\tInput student ID:");
scanf("%d", &new_node->id); // enter will cause a problem
getchar();
printf("\n\t\tInput student Name:");
gets(new_node->s_name);
printf("\n\t\tInput student Major:");
gets(new_node->s_major);
printf("\n\t\tInput student Advisor Name:");
gets(new_node->a_name);
printf("\n\t\tInput %s CGPA:", new_node->s_name);
scanf("%lf", &new_node->cgpa);
new_node->next = NULL;
  return new_node;
}