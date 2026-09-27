#include<iostream>
#include"Image_Class.h"
using namespace std;
void menu(){
cout<<"Please Enter a Filter Number :"<<endl;
cout<<"1.Greyscale"<<endl;
cout<<"2.Black & White"<<endl;
cout<<"3.Invert"<<endl;
cout<<"4.Frame"<<endl;
cout<<"5.Flip"<<endl;
cout<<"6.Rotate"<<endl;
cout<<"7.Brightness"<<endl;
cout<<"8.Resize"<<endl;
cout<<"___________________________________________________________"<<endl;
}
        void invert(Image &photo){
  for (int i=0;i<photo.width;++i){
 for(int j=0;j<photo.height;++j){
      for(int k=0;k<photo.channels;++k){
           photo(i,j,k)=255 - photo(i,j,k);
       }
   }
}
}
void light(Image &photo,int precentage){
    for (int i=0;i<photo.width;++i){
    for(int j=0;j<photo.height;++j){
        for(int k=0;k<photo.channels;++k){
            if(photo(i,j,k)+precentage >255){
                photo(i,j,k)=255;
            }
            else{
                photo(i,j,k)+=precentage;
            }
        }
    }
}
}
void dark(Image &photo,int precentage){
    for (int i=0;i<photo.width;++i){
    for(int j=0;j<photo.height;++j){
        for(int k=0;k<photo.channels;++k){
            if(photo(i,j,k)-precentage <0){
                photo(i,j,k)=0;
            }
            else{
                photo(i,j,k)-=precentage;
            }
        }
    }
}
}
int main(){
menu();
int number;
cin>>number;
cout<<"Please Enter File Name With Extention : "<<endl; 
string fileName;
cin>>fileName;
Image photo (fileName);
if(1 <= number && number <= 8){
    switch (number){
        case 1:
          
    break;
        case 2:


    break;
        case 3:
           
            invert(photo);
            photo.saveImage(fileName);
            break;
         case 4:








        break;
          case 5:









        break;
          case 6:




        break;
          case 7:
          int filter,precentage;
        cout<<"Enter 1 for Darken And 0 For lighten"<<endl;
        cin>>filter;
        while(filter !=0 && filter != 1){
        cout<<"Enter 1 for Darken And 0 For lighten"<<endl;
        cin>>filter;
        }
        cout<<"Enter Percentage: "<<endl;
        cin>>precentage;
        if(filter==0){
            
            light(photo,precentage);
            photo.saveImage(fileName);
        }
        else if(filter==1){
         
            dark(photo,precentage);
            photo.saveImage(fileName);
        }
    





        break;
          case 8:


    break;
    }
}
else{
    menu();
}




}