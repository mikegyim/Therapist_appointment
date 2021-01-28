#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int selectAppointment()
{
    system("cls");

    cout<<"\n ----- We Can't Wait To Meet You. Book Appointment ---- \n";
    cout<<"\n ----- Appointment Available Slots ---- \n";

    //Now, check if an appointment record already exist..
    ifstream read;
    read.open("appointment.dat");

    int bookHours = 8;

    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int foundRecord =0;

    if(read)
    {
	string line;
	char check = 'A';
	int i = 9;

	while(getline(read, line)) {
	char temp = line[0];
	int index = (temp - 65);
	arr[index]=1;
	foundRecord = 1;
	}
	if(foundRecord == 1)
	{
	cout<<"\n Appointment Summary by hours:";
	char check = 'A';
	int hours = 9;
	for(int i = 0; i<=12; i++)
	{
	if(i == 0){
	if(arr[i] == 0)
	cout<<"\n "<<check<<"-> 0"<<hours<<" - Available";
	else
	cout<<"\n "<<check<<"-> 0"<<hours<<" - Booked";
	}

	else
	{
	if(arr[i] == 0)
	cout<<"\n "<<check<<"->"<<hours<<" - Available";
	else
	cout<<"\n "<<check<<"->"<<hours<<" - Booked";
	}
	hours++; check++;
	}

	}

	read.close();
    }
	if(foundRecord == 0){
	cout<<"\n Appointment Available for following hours :";
	char check = 'A';
	for(int i = 9; i<=21; i++)
	{
		if(i==9)
		cout<<"\n "<<check<<" -> 0"<<i<<" - Available";
		else
		cout<<"\n "<<check<<" -> "<<i<<" - Available";
		check++;
	}

	}

   char choice;
   cout<<"\n\n Input your choice : ";
   cin>>choice;

   if( !(choice >= 'A' && choice <='Z'))
   {
	cout<<"\n Incorrect Entry. Try Again";
	cout<<"\n Choose correct value from menu A- Z";
	cout<<"\n Press any key to continue";
	getchar();getchar();
	system("cls");
	selectAppointment();
   }

   int index = (choice-65 );
   int isBooked = 1;
   if(arr[index] == 0)
      isBooked = 0;

   if(isBooked ==1)
   {
   	cout<<"\n This hour is unavailable. Appointment is already booked for this Hour!!!";
   	cout<<"\n Please choose different time !!";
   	cout<<"\n Press any key to continue!!";
   	getchar();getchar();
   	system("cls");
   	selectAppointment();
   }

   string name;
   cout<<"\n Enter your first name:";
   cin>>name;

   ofstream out;
   out.open("appointment.dat", ios::app);

   if(out){
	   out<<choice<<":"<<name.c_str()<<"\n";
	   out.close();
	   cout<<"\n Appointment booked for : "<< (choice-65) + 9 <<" :00 successfully !!";
    }
    else
    {
    	cout<<"\n Error while saving booking";
    }

    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;
}

int existingAppointment()
{
    system("cls");
    cout<<"\n ----- Appointments Summary ---- \n";
    //check if record already exist..
    ifstream read;
    read.open("appointment.dat");

    int bookHours = 8;

    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
     int foundRecord =0;

    if(read)
    {
	string line;
	char check = 'A';
	int i = 9;

	   while(getline(read, line)) {
	   	   char temp = line[0];
	   	   int index = (temp - 65);
	   	   arr[index]=1;
		   foundRecord = 1;
	  }
        if(foundRecord == 1)
        {
        cout<<"\n Appointment Summary by hours:";
        char check = 'A';
        int hours = 9;
        for(int i = 0; i<=12; i++)
        {
        	if(arr[i] == 0)
        	cout<<"\n "<<check<<"->"<<hours<<" - Available";
        	else
        	cout<<"\n "<<check<<"->"<<hours<<" - Booked";
        	hours++; check++;
        }

	}

	read.close();
    }
    else
    {
    char check = 'A';
	for(int i = 9; i<=21; i++)
	{
	if(i==9)
	cout<<"\n "<<check<<" -> 0"<<i<<" - Available";
	else
	cout<<"\n "<<check<<" -> "<<i<<" - Available";
	check++;
	}
    }

    cout<<"\n Please any key to continue..";
    getchar(); getchar();
    return 0;
}

int main(int argc, char** argv) {
	while(1)
	{
		system("cls");
		cout<<"\t\t\tDoctor Appointment System\n";
		cout<<"----------------------------------------\n\n";

		cout<<"1. BOOK APPOINTMENT\n";
		cout<<"2. CHECK AVAILABLE AND UNAVAILABLE SLOTS\n";
		cout<<"0. EXIT\n";
		int choice;

		cout<<"\n Enter you choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1: selectAppointment(); break;
			case 2: existingAppointment(); break;
			case 0:
		        while(1)
		        {
				 system("cls");
		        	cout<<"\n Are you sure, you want to exit? y | n \n";
		        	char w;
		        	cin>>w;
		        	if(w == 'y' || w == 'Y')
		        		exit(0);
		        	else if(w == 'n' || w == 'N')
                     		{
                     		 break;
                    		}
                     else{
                     	cout<<"\n Invalid Option !!!";
                     	getchar();
                     }
             	 }	break;

            default: cout<<"\n Invalid Entry. Try Again ";
                     getchar();

		}

	}
	return 0;
}
