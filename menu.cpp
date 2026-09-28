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

void blackandwhite_filter(Image &photo) {
    for(int i=0;i<photo.width;i++) {
        for(int j=0;j<photo.height;j++) {
            int average=(photo(i,j,0)+photo(i,j,1)+photo(i,j,2))/3;
            if(average>127) {
                photo(i,j,0)=255;
                photo(i,j,1)=255;
                photo(i,j,2)=255;
            } 
            else {
                photo(i,j,0)=0;
                photo(i,j,1)=0;
                photo(i,j,2)=0;
            }
        }
    }
}

void rotate_filter(Image &photo) {
    int angle;
    cout<<"enter the rotation angle"<<endl;
    cin>>angle;
    if(angle==180) {
        Image new_image(photo.width,photo.height);
        for(int i=0;i<photo.width;i++) {
            for (int j=0;j<photo.height;j++) {
                new_image(photo.width-1-i, photo.height-1-j, 0)=photo(i,j,0);
                new_image(photo.width-1-i, photo.height-1-j, 1)=photo(i,j,1);
                new_image(photo.width-1-i, photo.height-1-j, 2) = photo(i,j,2);
            }
        }
        photo=new_image; 
    }
    else if (angle==90) {
        Image new_image(photo.height,photo.width);
        for(int i=0;i<photo.width;i++) {
            for (int j = 0;j<photo.height;j++) {
                new_image(photo.height-1-j, i, 0) = photo(i,j,0);
                new_image(photo.height-1-j, i, 1) = photo(i,j,1);
                new_image(photo.height-1-j, i, 2) = photo(i,j,2);
            }
        }
        photo=new_image;
    }
    else if (angle==270) {
        Image new_image(photo.height,photo.width);
        for(int i=0;i<photo.width;i++) {
            for (int j=0;j<photo.height;j++) {
                new_image(j, photo.width-1-i, 0) = photo(i,j,0);
                new_image(j, photo.width-1-i, 1) = photo(i,j,1);
                new_image(j, photo.width-1-i ,2) = photo(i,j,2);
            }
        }
        photo=new_image;
    }
    else {
        cout<<"Invalid angle!"<<endl;
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
                blackandwhite_filter(photo);
                photo.saveImage(fileName);
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
                rotate_filter(photo);
                photo.saveImage(fileName);
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
