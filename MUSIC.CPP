#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>

class casset
{
       int cassetNum;
       int rating;
       char track[20];
       char artist[20];
       char album[20];

       public:
       void createCasset()
       {
	   clrscr();
	   cout<<"\nEnter casset number: ";
	   cin>>cassetNum;
	   cout<<"Enter the rating of the track: ";
	   cin>>rating;
	   cout<<"Enter the track name: ";
	   gets(track);
	   cout<<"Enter the artist name: ";
	   gets(artist);
	   cout<<"Enter the album name: ";
	   gets(album);
       }

       void displayCasset()
       {
	   clrscr();
	   cout<<"\nCasset number: "<<cassetNum;
	   cout<<"\nRating: "<<rating;
	   cout<<"\nTrack: "<<track;
	   cout<<"\nArtist: "<<artist;
	   cout<<"\nAlbum: "<<album;
       }
   }obj1;

class User{
    int adminStatus;
    char userName[15];
    char email[30];
    char password[20];

    public:

    char* getUsername()
    {
	return userName;
    }

    char* getPassword()
    {
	return password;
    }

    void setPassword(char pass[])
    {
	strcpy(password,pass);
    }

    void createUser()
    {
	clrscr();
	cout<<"Enter new username";
	gets(userName);
	cout<<"Enter email";
	gets(email);
	cout<<"Enter your new password";
	gets(password);
	cout<<"Enter the admin status (1/0)";
	cin>>adminStatus;
    }

}user;


void login(){
    fstream file;

    file.open("login-data.dat",ios::app|ios::in|ios::out);

    int flag=0;
    char username[15];
    char password[20];

    do{
    clrscr();
    cout<<"\nLOGIN";
    cout<<"\n\nEnter your User Name: ";
    gets(username);
    cout<<"\nEnter your Password: ";
    gets(password);

    while(file.read((char*)&user,sizeof(casset)))
    {
	if(strcmp(user.getUsername(),user.getPassword())==0)
	{
	    flag=1;
	    break;
	}
    }

      if(flag==1)
      {
	  cout<<"\n\nCorrect Password. Press enter to continue to main menu";
      }
      else if(flag==0)
      {
	  cout<<"\n\nWrong User Name Password combination. Try again!";
      }
    }
    while(flag==1);
    getch();
}

void addNewUser()
{
    fstream file;
    file.open("login-data.dat",ios::app,ios::out);

    user.createUser();
    file.write((char*)&user,sizeof(User));
    file.close();
}

void changePassword()
{
    fstream file;

    file.open("login-data.dat",ios::app|ios::in|ios::out);

    int flag=0;
    char username[15];
    char oldPassword[20];
    char newPassword[20];

    clrscr();
    cout<<"CHANGE PASSWORD";
    cout<<"\n\nEnter your User Name: ";
    gets(username);
    cout<<"\nEnter your old Password: ";
    gets(oldPassword);

    while(file.read((char*)&user,sizeof(User)))
    {
	if(strcmp(user.getUsername(),user.getPassword())==0)
	{
	    flag=1;
	    cout<<"Enter your new password";
	    gets(newPassword);
	    user.setPassword(newPassword);
	}
    }

    file.write((char*)&user,sizeof(User));

    if(flag==0)
    {
	cout<<"Wrong username password combination, Try again";
    }
}


void addCasset()
   {
       fstream file;
       file.open("music-data.dat",ios::app|ios::out);
       char ch;
       do
       {
	   obj1.createCasset();
	   file.write((char*)&obj1,sizeof(casset));
	   cout<<"Want to add more?  y/n ";
	   cin>>ch;
       }
       while(ch=='y');
       file.close();
   }

void displayCassets(){
       fstream file;
       file.open("music-data.dat",ios::app|ios::in);
       while(file.read((char*)&obj1,sizeof(casset)))
       {
	   obj1.displayCasset();
       }
       file.close();

       cout<<"\n\nPress enter to continue";
       getch();
}

void options()
{
    char ch;

	clrscr();
	cout<<"OPTIONS";
	cout<<"1. Add new user";
	cout<<"2. Change password";
	cin>>ch;

	switch(ch)
	{
	    case '1': addNewUser();
		      break;

	    case '2': changePassword();
		      break;

	    default: cout<<"Select a correct option";
	}
}

void main()
{
   clrscr();
   fstream file;

   login();

   char ch;

   do
   {
       clrscr();
       cout<<"\n\nMENU"<<endl;
       cout<<"1. Add Cassette"<<endl;
       cout<<"2. Open Catalogue"<<endl;
       cout<<"3. Options"<<endl;
       cout<<"4. Exit"<<endl;
       cout<<"Select any one option: ";
       cin>>ch;

       switch(ch)
       {
	   case '1': addCasset();
		     break;

	   case '2': displayCassets();
		     break;

	   case '3': options();
		     break;

	   case '4': exit(0);

	   default: cout<<"Select a correct option";
       }
   }
   while(ch!='3');



   getch();
}