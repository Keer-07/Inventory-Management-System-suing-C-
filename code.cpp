#include<iostream>
#include<string>
using namespace std;
struct Item{
    int id;
    string name;
    int quantity;
};
int main(){
    Item inventory[100];
    int count=0;
    int choice;
    do{
        cout<<"\n=====INVENTORY MANAGEMENT SYSTEM====\n";
        cout<<"1.Add Items\n";
        cout<<"2.Display Items\n";
        cout<<"3.Search Items by ID\n";
        cout<<"4.Search Items by Name\n";
        cout<<"5.Update Quantity\n";
        cout<<"6.Delete Item\n";
        cout<<"7.Exit\n";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter Item ID: ";
                cin>>inventory[count].id;
                cout<<"Enter Item Name: ";
                cin>>inventory[count].name;
                cout<<"Enter Quantity: ";
                cin>>inventory[count].quantity;
                count++;
                cout<<"Item added Successfully!\n";
                break;
            }
            case 2:{
                if(count==0){
                    cout<<"Inventory is empty!\n";
                }
                else{
                    cout<<"\n------------------------------\n";
                    cout<<"ID\tName\tQuantity";
                    cout<<"\n------------------------------\n";
                    for(int i=0;i<count;i++){
                        cout<<inventory[i].id<<"\t"<<inventory[i].name<<"\t"<<inventory[i].quantity<<endl;
                        if(inventory[i].quantity<5){
                            cout<<"Low stock alert for "<<inventory[i].name<<"!\n";
                        }
                    }
                }
                break;
            }
            case 3:{
                int searchId;
                bool found=false;
                cout<<"Enter ID to search: ";
                cin>>searchId;
                for(int i=0;i<count;i++){
                    if(inventory[i].id==searchId){
                        cout<<"Item Found!\n";
                        cout<<inventory[i].id<<" "<<inventory[i].name<<" "<<inventory[i].quantity<<endl;
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Item not Found!\n";
                }
                break;
            }
            case 4:{
                string searchName;
                bool found=false;
                cout<<"Enter Name to search: ";
                cin>>searchName;
                for(int i=0;i<count;i++){
                    if(inventory[i].name==searchName){
                        cout<<"Item Found!\n";
                        cout<<inventory[i].id<<" "<<inventory[i].name<<" "<<inventory[i].quantity<<endl;
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Item not Found!\n";
                }
                break;
            }
            case 5:{
                int updateId;
                bool found=false;
                cout<<"Enter ID to update quantity: ";
                cin>>updateId;
                for(int i=0;i<count;i++){
                    if(inventory[i].id==updateId){
                        cout<<"Enter new quantity: ";
                        cin>>inventory[i].quantity;
                        cout<<"Quantity updated successfully!\n";
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Item not Found!\n";
                }
                break;
            }
            case 6:{
                int deleteId;
                bool found=false;
                cout<<"Enter ID to delete: ";
                cin>>deleteId;
                for(int i=0;i<count;i++){
                    if(inventory[i].id==deleteId){
                        for(int j=i;j<count-1;j++){
                            inventory[j]=inventory[j+1];
                        }
                        count--;
                        found=true;
                        cout<<"Item deleted successfully!\n";
                        break;
                    }
                }
                if(!found){
                    cout<<"Item not Found!\n";
                }
                break;
            }
            case 7:{
                cout<<"Exiting Program...\n";
                break;
            }
            default:{
                cout<<"Invalid Choice!\n";
            }
        }
    }while(choice!=7);
    return 0;
}
