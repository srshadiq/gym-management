#include<iostream>
#include<conio.h>
using namespace std;

struct member{
    int id;
    float height;
    float weight;
    bool exist;
    int att;
};

int total=-1;
struct member mx[10000];
int manu()
{
    int op;
    system("cls");
    cout<<"********** Main Menu ********"<<endl;
    cout <<"1. Add Member"<<endl;
    cout <<"2. Update Member"<<endl;
    cout <<"3. Remove Member" <<endl;
    cout <<"4. Max Height & Weight" <<endl;
    cout <<"5. Min Height and Weight" <<endl;
    cout <<"6. Average Height and Weight" <<endl;
    cout <<"7. BMI Classification" <<endl;
    cout <<"8. Display All" <<endl;
    cout <<"9. Attendance" <<endl;
    cout <<"0. Exit"<<endl;
    cout <<" Enter Your option(0-9): ";
    cin >>op;
    return op;
}

int searchMember(int x)
{
    int i;
    int flag=-1;
    for(i=0;i<=total;i++)
    {
        if(mx[i].id==x)
        {
            flag=i;
        }
    }
    return flag;
    getch();
}

void addMember()
{
    cout <<"Yor are inside addMember()"<<endl;

    cout << "Enter ID: " ;
    int a;
    cin >>a;
    if(searchMember(a)==-1)
    {
        total++;
        mx[total].id=a;
        cout << "Enter Height: " ;
        cin >> mx[total].height;
        cout << "Enter Weight: " ;
        cin >> mx[total].weight;
        mx[total].exist=true;
    }
    else
    {
        cout<<"Member ID already exists..."<< endl;
    }

    getch();

}

void updateMember()
{
    int n,idx;
    float h,w;
    cout <<"Enter ID for Update: ";
    cin >> n;
    cout << "Enter New Height: ";
    cin >> h;
    cout << "Enter New Weight: ";
    cin >>w;
    idx=searchMember(n);
    if(idx==-1)
    {
        cout << "Member Not Found..." <<endl;
    }
    else
    {
        mx[idx].height=h;
        mx[idx].weight=w;
        cout << "successfully Updated"<<endl;
    }

    getch();
}

void removeMember()
{
    int x,idx;
    cout <<"Enter Member ID: ";
    cin >> x;
    idx=searchMember(x);
    if(idx==-1)
    {
        cout <<"Member not found..."<<endl;
    }
    else
    {
        cout<<"Member to be removed"<<endl;
        cout<<mx[idx].id<<' '<<mx[idx].height<<' '<<mx[idx].weight<<endl;
        mx[idx].exist=false;
    }
    getch();
}

void MaxHeightWeight()
{
    float maxHeight=0.0;
    float maxWeight=0.0;
    int h_id,w_id;
    for (int i = 0; i <= total; i++)
    {
        if(mx[i].exist==true)
        {
            if(mx[i].height>maxHeight)
            {
                maxHeight=mx[i].height;
                h_id=mx[i].id;

            }
            if(mx[i].weight>maxWeight)
            {
                maxWeight=mx[i].weight;
                w_id=mx[i].id;
            }
        }
    }
    cout << "Maximum Height: " <<maxHeight <<" Meter " <<"ID No: "<<h_id << endl;
    cout << "Maximum Weight: " <<maxWeight <<" kg "<< "ID No: " << w_id <<endl;
    getch();

}

void MinHeightWeight()
{
    float minHeight=1000000.0;
    float minWeight=1000000.0;
    int h_id,w_id;
    for (int i = 0; i <= total; i++)
    {
        if(mx[i].exist==true)
        {
            if(mx[i].height<minHeight)
            {
                minHeight=mx[i].height;
                h_id=mx[i].id;
            }
            if(mx[i].weight<minWeight)
            {
                minWeight=mx[i].weight;
                w_id=mx[i].id;
            }
        }
    }
    cout << "Minimum Height: " <<minHeight <<" Meter " << "ID No: "<<h_id<<endl;
    cout << "Minimum Weight: " <<minWeight <<" kg "<<"ID No: "<<w_id<<endl;
    getch();
}

void avgHeightWeight()
{
    float sumHeight=0;
    float sumWeight=0;
    int count =0;
    for (int i = 0; i <= total; i++)
    {
        if(mx[i].exist==true)
        {
            sumHeight=sumHeight+mx[i].height;
            sumWeight=sumWeight+mx[i].weight;
            count++;
        }
    }
    cout<< "Average Height: " << sumHeight/count<<" Meters" << endl;
    cout<< "Average weight: " << sumWeight/count <<" Kg" << endl;
    getch();
}

void bmi()
{
    int ID,idx;
    float BMI;
    cout << "Enter Member ID: ";
    cin >> ID;
    idx=searchMember(ID);
    if(idx==-1||mx[idx].exist==false)
    {
        cout <<"Member not found..."<<endl;
    }
    else
    {
        if(mx[idx].exist==true)
        {
            BMI= (mx[idx].weight)/((mx[idx].height)*(mx[idx].height));
        }
    cout << "BMI of ID No " <<mx[idx].id<<" is: "<< BMI << endl;

    if(BMI>=0.0 && BMI < 16.0){
        cout<<"Classicifation: Severe Thinness\n";
    }
    else if(BMI>=16.0 && BMI < 17.0){
        cout<<"Classicifation: Moderate Thinness\n";
    }
    else if(BMI>=17.0 && BMI < 18.5){
        cout<<"Classicifation: Mild Thiness\n";
    }
    else if(BMI>=18.5 && BMI < 25.0){
        cout<<"Classicifation: Normal\n";
    }
    else if(BMI>=25 && BMI < 30.0){
        cout<<"Classicifation: Overweight\n";
    }
    else if(BMI>=30.0 && BMI < 35.0){
        cout<<"Classicifation: Obese Class I\n";
    }
    else if(BMI>=35.0 && BMI < 40.0){
        cout<<"Classicifation: Obese Class II\n";
    }
    else if(BMI>40.0){
        cout<<"Classicifation:Obese Class III\n";
    }
    }

    getch();
}

void displayAll()
{
    cout <<" ID Height Weight" <<endl;
    int i;
    for(i=0;i<=total;i++)
    {
        if(mx[i].exist==true)
        {
            cout << mx[i].id <<' '<<mx[i].height<<' '<<mx[i].weight<<endl;
        }
    }
    cout<<"Attendance (ID No):"<<endl;
    cout <<"Present(ID): ";
    for (int i = 0; i <= total; i++)
    {
        if(mx[i].exist==true)
        {

            if(mx[i].att!=0)
            {
                cout << mx[i].id<<" ";
            }
        }
    }
        cout <<"\nAbsent(ID): ";
    for (int i = 0; i <= total; i++)
    {
        if(mx[i].exist==true)
        {

            if(mx[i].att==0)
            {
                cout << mx[i].id<<" ";
            }
        }
    }


    getch();
}

void Attendance()
{
    int x,idx;
    cout<<"Enter your ID: ";
    cin>>x;
    idx=searchMember(x);
    if(idx==-1)
    {
        cout <<"ID didn't match..."<<endl;
    }
    else
    {
        mx[idx].att=x;
        cout<<"Your Attendance have been submitted successfully..."<<endl;
    }
    getch();
}

int main()
{
    int option;
    for(;;)
    {
        option=manu();
        cout <<"in main() option=" << option <<endl;
        if(option==0)
        {
            cout<<"end the program run....";
            break;
        }
        switch(option)
        {
            case 1: addMember(); break;
            case 2: updateMember(); break;
            case 3: removeMember(); break;
            case 4: MaxHeightWeight(); break;
            case 5: MinHeightWeight(); break;
            case 6: avgHeightWeight(); break;
            case 7: bmi(); break;
            case 8:displayAll();break;
            case 9:Attendance();break;
        }
        getch();
    }
}
