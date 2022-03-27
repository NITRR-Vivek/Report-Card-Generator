//Program Made By Vivek Kumar (21111071) on "School Report Card Generator"
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

char dash='-';

void line();
void headline();
void message();

class Run
{
  private:

     string sub[40] = {"Maths","Physics","Basic-Biomed","Data-Structure","Computer-programming","Environment-&-Ecology" };
     int enroll;
     char name[40]={0};
     float percentage,marks[40]={0},total;
     char more;
     int slen,i,j,k,a,b,x;

   public:

        void input()
        {
          //Input Taking Starts .......

            cout<<"Please Enter the Details of the Student Below ! \n";
            line();
            cout<<"Name of the Student : ";
            cin.getline(name,40);
            cout<<"Enrollment Number of the Student : ";
            cin>>enroll;
            line();
            cout<<"Enter the Marks of Compulsary Subjects Below !\n\n";
            for (int x = 0; x < 6; x++){
               cout <<"\nEnter the Marks of "<<sub[x] <<":  ";
               cin>>marks[x];
            }
            
            do{
              cout<<"\n\nDo You Want to Enter More Subjects (Y/N) : ";
              {
               more=getche();
                //  char ch=more;
                 x=6;
                 while(more=='y'|| more=='Y')
                 {
	                 system("cls");
	                 headline();
	                 cout<<"\n\n\t\tENTER THE Name and Marks Details of Additional Subject :- ";
	                 cout<<"\n\n\n\t\tEnter the "<<x+1<<"th Subject Name : ";
	                 cin>>(sub[x]);
	                 cout<<"\n\t\tEnter the Marks of \'"<<sub[x]<<"\' Subject : ";
	                 cin>>marks[x];
                     x++;
	                 cout<<"\n\n\n\t\tDo you want to add more Subjects (y/n) :  ";
	                 more=getche();
	               }
              }

              }while(more=='y'|| more=='Y');
         }

    void output()
    {
     total=0;
     for(a=1;a<=x;a++)
     {
      total=total+marks[a-1];
     }
     percentage=(total/x);
      //Console Output Printing Starts.........
      system("cls");
      headline();
      cout<<"Name of the Student : "<<name<<endl;
      cout<<"Enrollment Number : "<<enroll<<"\t\t\t\tYear : 2021-2025"<<endl;
      line();
      cout<<"SL.No\t"<<"Subject\t\t\t"<<"\t\tFull Marks\t"<<"  Marks Obtained\n";
      line();
    for(i=0;i<=x-1;i++)
    {
      slen=sub[i].length();
      if(slen>0 && slen<8){
      cout<<endl<<" "<<i+1<<"\t"<<sub[i]<<"\t\t\t\t\t  "<<100<<"\t\t\t"<<marks[i]<<endl;
      }
      else if (slen>7 && slen<16){
      cout<<endl<<" "<<i+1<<"\t"<<sub[i]<<"\t\t\t\t  "<<100<<"\t\t\t"<<marks[i]<<endl;
      }
      else if (slen>15 && slen<24){
      cout<<endl<<" "<<i+1<<"\t"<<sub[i]<<"  \t\t\t  "<<100<<"\t\t\t"<<marks[i]<<endl;
      }
      else {
      cout<<endl<<" "<<i+1<<"\t"<<sub[i]<<"  \t\t  "<<100<<"\t\t\t"<<marks[i]<<endl;
      }
    }
    line();
    cout<<"\n\nTotal number of Subjects : "<<x;
    cout<<"\nTotal Marks : "<<total<<" Out of "<<x*100;
    cout<<"\n% Marks Obtained : "<<setprecision(3)<<percentage<<"%";
    cout<<"\n\nRemarks : ";
    cout<<"\n\n\n\n\tParent's Sign";
    cout<<"\t\t\t\t\tClass Tearcher's Sign\n";
    cout<<"\n\n\n\t\t*****  Best wishes For your Future !  *****";

    //Now Console Input & OutPut ends and File Output Starts..........

   {
      ofstream fout;
      fout.open("Report_card.doc",ios::out);
      fout<<setw(72)<<setfill('-')<<dash<<endl;
      fout<<"\t\t\t\t\t Annual Report Card \n";
      fout<<setw(72)<<setfill('-')<<dash<<endl;
      fout<<endl<<"\t\t\t\tNational Institute of Technology ";
      fout<<endl<<"\t\t\t\t\t  G.E. Road,Raipur";
      fout<<endl<<"\t\t\t\t\t\t 492010"<<endl;
      //
    fout<<setw(72)<<setfill('-')<<dash<<endl;
    fout<<"Name of the Student is : "<<name<<endl;
    fout<<"Enrollment Number : "<<enroll<<"\t\t\t\tYear : 2021-2025"<<endl;
    fout<<setw(72)<<setfill('-')<<dash<<endl;
    fout<<"SL.No\t"<<"Subject\t\t\t\t\t"<<"Full Marks "<<"  \tMarks Obtained\n";
    fout<<setw(72)<<setfill('-')<<dash<<endl;
    for(i=0;i<=x-1;i++)
    {
      slen=sub[i].length();
      if(slen>0 && slen<6){
      fout<<endl<<" "<<i+1<<"\t"<<sub[i]<<"\t\t\t\t\t\t\t"<<100<<"\t\t\t"<<marks[i]<<endl;
      }
      else if (slen>5 && slen<12){
      fout<<endl<<" "<<i+1<<"\t"<<sub[i]<<"\t\t\t\t\t\t"<<100<<"\t\t\t"<<marks[i]<<endl;
      }
      else if (slen>11 && slen<18){
      fout<<endl<<" "<<i+1<<"\t"<<sub[i]<<"\t\t\t\t\t"<<100<<"\t\t\t"<<marks[i]<<endl;
      }
      else if (slen>17 && slen<25){
      fout<<endl<<" "<<i+1<<"\t"<<sub[i]<<"\t\t\t\t"<<100<<"\t\t\t"<<marks[i]<<endl;
      }
      else {
      fout<<endl<<" "<<i+1<<"\t"<<sub[i]<<"\t\t\t"<<100<<"\t\t\t"<<marks[i]<<endl;
      }
    }
    fout<<setw(72)<<setfill('-')<<dash<<endl;
    fout<<"\nTotal number of Subject : "<<x;
    fout<<"\nTotal Marks : "<<total<<" Out of "<<x*100;
    fout<<"\nPercentage marks obtained : "<<setprecision(3)<<percentage<<"%";
    fout<<"\n\nRemarks: ";
    fout<<setw(72)<<setfill('_')<<dash<<"\n\n";
    fout<<"\n\n\tParent's Sign"<<"\t\t\t\t\t\tClass Teacher's Sign"<<endl;
    fout<<setw(72)<<setfill('-')<<dash<<endl;
    fout<<"\t\t\t\t  We Wish Best For Your Future"<<endl;
    fout<<setw(72)<<setfill('-')<<dash<<endl;
    fout<<"\n\t\t\t\t *****  Learn and Serve  *****";
  }
}
         

};
    

int main()
{
    //  int choice=0;
     Run r;
     char choice='y';
     while(choice=='y'||choice=='Y')
  {
	 system("cls");
     cout<<"\n\n\n";
   cout<<"''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
	 cout<<"                                                                                "<<endl;
	 cout<<" __________________________________________________________________________     "<<endl;
	 cout<<" __________________________________________________________________________     "<<endl;
	 cout<<"                                                                                "<<endl;
	 cout<<"     *       *  * * * *  *        * * * *  * * * *  *       *  * * * *          "<<endl;
	 cout<<"     *       *  *        *        *        *     *  * *   * *  *                "<<endl;
	 cout<<"     *       *  *        *        *        *     *  *   *   *  *                "<<endl;
	 cout<<"     *   *   *  * * *    *        *        *     *  *       *  * * *            "<<endl;
	 cout<<"     *  * *  *  *        *        *        *     *  *       *  *                "<<endl;
	 cout<<"     * *   * *  *        *        *        *     *  *       *  *                "<<endl;
	 cout<<"     *       *  * * * *  * * * *  * * * *  * * * *  *       *  * * * *          "<<endl;
	 cout<<" __________________________________________________________________________     "<<endl;
	 cout<<" __________________________________________________________________________     "<<endl;
	 cout<<"                                                                                "<<endl;
	 cout<<"     PLEASE CHOOSE ANY OPTION FROM BELOW, THEN PRESS THE KEY.....               "<<endl;
	 cout<<"       ____________________               ________                              "<<endl;
	 cout<<"       [Y] Make Report-Card               [N] EXIT                              "<<endl;
	 cout<<"       ~~~~~~~~~~~~~~~~~~~~               ~~~~~~~~                              "<<endl;
	 cout<<"       ________________                                                         "<<endl;
	 cout<<"       [I] INSTRUCTIONS                                                         "<<endl;
	 cout<<"       ~~~~~~~~~~~~~~~~                                                         "<<endl;
	 cout<<"''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
   
      choice=getche();
     {
     if(choice=='y'||choice=='Y')
      {
         system("cls");
         headline();
         r.input();
         r.output();
      }
      if(choice=='i'||choice=='I')
      {
         system("cls");
         message();
         choice='y';
      }

      else{
          exit (0);
      }
    }
   
    getch();
  } 
    return 0;
}
void line()
{
    cout<<setw(85)<<setfill('-')<<dash<<endl;
}
void headline()
{
      line();
      cout<<"\t\t\t\tAnnual Report Card \n";
      line();
      cout<<endl<<"\t\t\t  National Institute of Technology ";
      cout<<endl<<"\t\t\t\t G.E. Road,Raipur";
      cout<<endl<<"\t\t\t\tChattisgarh-492010"<<endl;
      line();
}
void message()
{
       headline();
       cout<<"\n\n\t INSTRUCTIONS TO THE Report Card Generator ";
       cout<<"\n\n\n\t1. When You are Ready to Make Report-Card ,PRESS 'Y' in Welcome Screen.";
       cout<<"\n\n\t2. Enter the Details of Student CAREFULLY ";
       cout<<"\n\n\t3. Enter the Marks of 6 Compulsary Subjects. ";
       cout<<"\n\n\t4. Add Extra Subjects and Marks if You Want. ";
       cout<<"\n\n\t5. Do not Use Space in Subject Name, Use Special Characters Instead ";
       cout<<"\n\n\t6. Share or Print the \"Report_card.doc\" File Generated in same Folder. ";
       cout<<"\n\n\n\n\t\t Kindly Press any button to Continue........... ";      
}