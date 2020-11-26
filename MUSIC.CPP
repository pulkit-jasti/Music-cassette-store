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

class admin{
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

}user;


int login(){
    fstream file;

    file.open("login-data.dat",ios::app|ios::in|ios::out);

    int flag=0;
    char username[15];
    char password[20];
    cout<<"Enter your User Name: ";
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

    return flag;
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

void main()
{
   clrscr();
   cout<<"Enter data";
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

//   char ch;
   do
   {
       clrscr();
       cout<<"\n\nMENU"<<endl;
       cout<<"1. Add Casset"<<endl;
       cout<<"2. Open Catelog"<<endl;
       cout<<"3. Exit"<<endl;
       cout<<"Select any one option: ";
       cin>>ch;

       switch(ch)
       {
	   case '1': addCasset();
		     break;

	   case '2': displayCassets();
		     break;

	   case '3': exit(0);

	   default: cout<<"Select a correct option";
       }
   }
   while(ch!='3');



   getch();
}