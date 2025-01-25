#include <stdio.h>
#include  <string.h>




typedef struct
{
    char ip[20];
    char d_name[20];
    char d_type[20];

}d_info;


void printMenu();
void printMenu(){
    printf("\n 1. Fill Array\n 2. Display Array Content\n 3. Check Devices in the same Network\n 4. Disconnect a machine\n 5. Quit");
}

int fill(d_info arr[20]) {
    int ConnectedDevices =0;
    for (int i = 0; i < 20; i++) {
        printf("Enter IP address for device %d: ", i + 1);
        scanf("%s", arr[i].ip); 
    ConnectedDevices++;
        if (strcmp(arr[i].ip, "0.0.0.0") == 0) {
            break; 
        }

        printf("please enter device name for device %d: ", i + 1);
        scanf("%s", arr[i].d_name);

        printf("please enter device type for device %d: ", i + 1);
        scanf("%s", arr[i].d_type);


    }
    return ConnectedDevices;
}

    

void DisplayContent(d_info arr[20], int x){

    for (int i = 0; i < x-1; i++)
    {
        printf("Device %d: IP Address: %s, Device Name: %s, Device type: %s",i+1, arr[i].ip, arr[i].d_name, arr[i].d_type );
    
    }
    
}

void DinthesameNet(d_info arr[20], int x){
    for (int i = 0; i < x; i++)
    {
        printf("these devices are on the same network\n");
        for (int j = i+1; j < i; j++){
            
            if (strncmp(arr[i].ip, arr[j].ip, 7) == 0){
            printf("devices on the same network\n %s, %s", arr[i].ip, arr[j]);
        
        }
        
        }
        
        
    }
    

}

void Disconnect(d_info arr[20], int devices){
    int delete;
    printf("please enter the ip index to disconnect \n");
    scanf("%d", &delete);

    for (int i = delete; i <  devices; i++){
        strcpy(arr[i].ip, arr[i+1].ip);
        
    }
    devices--;

}

int main(){
    int choice;
    int nCD =0;
    int keeprunning = 1;
    d_info connected[50];


    
    
    while (keeprunning)
    {
        printMenu();
        printf("\nplease choose an option\n");
    scanf("%d", &choice);
        switch (choice)
    {
    case 1:
        nCD = fill(connected);
        printf("Array filled. Returning to menu...\n");
        break;
    case 2:
        DisplayContent(connected,  nCD);
        break;
    case 3:
        DinthesameNet(connected, nCD);
        break;
    case 4:
        Disconnect(connected, nCD);

    default:
        printf("invalid choice\n");
        break;
    }
    
    
    
    }
    
    
    

    





    return 0;
}