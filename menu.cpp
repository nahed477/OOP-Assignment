// 1. Farah Amr Gaber Elsayed  
//    ID:20250466       Filters:Grayscale & Flip Filters
//2. Maya Hossam Abdelaziz Mahmoud 
//    ID:20250528      Filters: Black and White & Rotate Filters
//3. Nahed Adel Abd Elfadeel Ahmed 
//    ID:20250698     Filters:Invert & Darken/Lighten Filters & Menu
//4. Yassmin Sherif Abd Elhafeez Elsayed
//    ID:20250730     Filters: Frame & Resize Filters
// Section : Monday From 09:30 To 11:00 (S31,S32)


#include<iostream>
#include"Image_Class.h"
#include <utility>

using namespace std;

void menu(){
    cout<<"Please Enter a Filter Number :"<<endl;
    cout<<"1.Grayscale"<<endl;
    cout<<"2.Black & White"<<endl;
    cout<<"3.Invert"<<endl;
    cout<<"4.Frame"<<endl;
    cout<<"5.Flip"<<endl;
    cout<<"6.Rotate"<<endl;
    cout<<"7.Brightness"<<endl;
    cout<<"8.Resize"<<endl;
    cout<<"9.Merge Photos"<<endl;
    cout<<"10."<<endl;
    cout<<"11.Crop Image"<<endl;
    cout<<"12."<<endl;
    cout<<"13."<<endl;
    cout<<"14."<<endl;
    cout<<"15.Purple "<<endl;
    cout<<"16."<<endl;
    cout<<"17.Upload A New Photo"
    cout<<"Enter 0 to Exit "<<endl;

    cout<<"___________________________________________________________"<<endl;
}
void grayscale(Image &photo){
    for(int i = 0;i < photo.width; ++i){
        for(int j = 0;j < photo.height; ++j){
            unsigned int avg = 0;
            for(int k = 0;k < 3; ++k){
                avg += photo(i, j, k);
            }
            avg /= 3;
            for (int k = 0;k < 3; ++k){
                photo(i,j,k)= avg;
            }
        }
    }
}
//***/ /***//*** //***//* **//* **
void invert(Image &photo){
    for (int i=0;i<photo.width;++i){
        for(int j=0;j<photo.height;++j){
            for(int k=0;k<photo.channels;++k){
                photo(i,j,k)=255 - photo(i,j,k);
            }
        }
    }
}
//***/ /***//*** //***//* **//* **
void GetRGB(int Color, int& R, int& G, int& B)
{
    if (Color == 1){R = 255; G = 255; B = 255;}
    else if (Color == 2){R = 0; G = 0; B = 0;}
    else if (Color == 3){R = 255; G = 0; B = 0;}
    else if (Color == 4){R = 0; G = 255; B = 0;}
    else if (Color == 5){R = 0; G = 0; B = 255;}
}
//***/ /***//*** //***//* **//* **
void ChooseColor()
{
    cout << "1. White" << endl;
    cout << "2. Black" << endl;
    cout << "3. Red" << endl;
    cout << "4. Green" << endl;
    cout << "5. Blue" << endl;
}
//***/ /***//*** //***//* **//* **
void frame(Image &photo)
{
    int FrameType;

    cout << "Choose frame type :" << endl;
    cout << "1. simple" << endl;
    cout << "2. fancy" << endl;
    cin >> FrameType;

    int Color, OuterColor, InnerColor, Thickness, OuterThickness, InnerThickness;

    if (FrameType == 1)
    {
        cout << "Choose frame color" << endl;
        ChooseColor();
        cin >> Color;
        
        cout << "Enter frame Thickness :" << endl;
        cin >> Thickness;
    }
    else
    {
        cout << "Choose Outer frame color" << endl;
        ChooseColor();
        cin >> OuterColor;

        cout << "Enter Outer frame Thickness :" << endl;
        cin >> OuterThickness;

        cout << "Choose Inner frame color" << endl;
        ChooseColor();
        cin >> InnerColor;
    
        cout << "Enter Inner frame Thickness :" << endl;
        cin >> InnerThickness;
    }

    int R, G, B, OuterR, OuterG, OuterB, InnerR, InnerG, InnerB;

    if (FrameType == 1)
    {
        GetRGB(Color, R, G, B);

        for (int y = 0; y < photo.height; y++)
        {
            for (int x = 0; x < photo.width; x++)
            {
                if(y < Thickness || y >= photo.height - Thickness ||
                   x < Thickness || x >= photo.width - Thickness)
                {
                    photo(x, y, 0) = R;
                    photo(x, y, 1) = G;
                    photo(x, y, 2) = B;    
                }   
            }
        }
    }
    else
    {
        GetRGB(OuterColor, OuterR, OuterG, OuterB);
        GetRGB(InnerColor, InnerR, InnerG, InnerB);

        int TotalThickness = OuterThickness + InnerThickness;

        for(int y = 0; y < photo.height; y++){
            for(int x = 0; x < photo.width; x++){
                if(y < OuterThickness || y >= photo.height - OuterThickness ||
                   x < OuterThickness || x >= photo.width - OuterThickness)
                {
                    photo(x, y, 0) = OuterR;
                    photo(x, y, 1) = OuterG;
                    photo(x, y, 2) = OuterB;  
                }  
                else if (y < TotalThickness || y >= photo.height - TotalThickness ||
                         x < TotalThickness || x >= photo.width - TotalThickness)
                {
                    photo(x, y, 0) = InnerR;
                    photo(x, y, 1) = InnerG;
                    photo(x, y, 2) = InnerB;
                }
            }
        }
    }
}
//***/ /***//*** //***//* **//* **
void light(Image &photo,int brightnessvalue){
    for (int i=0;i<photo.width;++i){
        for(int j=0;j<photo.height;++j){
            for(int k=0;k<photo.channels;++k){
                int value = photo(i,j,k);
                if(value + brightnessvalue>255){
                    photo(i,j,k)=255;
                }
                else{
                    photo(i,j,k)= value + brightnessvalue;
                }
            }
        }
    }
}
//***/ /***//*** //***//* **//* **
void dark(Image &photo,int brightnessvalue){
    for (int i=0;i<photo.width;++i){
        for(int j=0;j<photo.height;++j){
            for(int k=0;k<photo.channels;++k){
                int value1 = photo(i,j,k);
                if(value1 - brightnessvalue <0){
                  
                    photo(i,j,k)=0;
                }
                else{
                    photo(i,j,k)=value1 - brightnessvalue;
                }
            }
        }
    }
}
//***/ /***//*** //***//* **//* **
void vertical(Image &photo) {
    for (int i = 0; i < photo.width; ++i) {
        for (int j = 0; j < photo.height / 2; ++j) {
            int new_j = photo.height - 1 - j;
            for (int k = 0; k < 3; ++k) {
                swap(photo(i, j, k), photo(i, new_j, k));
            }
        }
    }
}
//***/ /***//*** //***//* **//* **
void horizontal(Image &photo) {
    for (int i = 0; i < photo.width / 2; ++i) {
        int new_i = photo.width - 1 - i;
        for (int j = 0; j < photo.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                swap(photo(new_i, j, k), photo(i, j, k));
            }
        }
    }
}
//***/ /***//*** //***//* **//* **
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
//***/ /***//*** //***//* **//* **
void rotate_filter(Image &photo,int angle) {
    if(angle==180) {
        Image new_image(photo.width,photo.height);
        for(int i=0;i<photo.width;i++) {
            for (int j=0;j<photo.height;j++) {
                new_image(photo.width-1-i, photo.height-1-j, 0)=photo(i,j,0);
                new_image(photo.width-1-i, photo.height-1-j, 1)=photo(i,j,1);
                new_image(photo.width-1-i, photo.height-1-j, 2)=photo(i,j,2);
            }
        }
        photo=new_image; 
    }
    else if (angle==90) {
        Image new_image(photo.height,photo.width);
        for(int i=0;i<photo.width;i++) {
            for (int j = 0;j<photo.height;j++) {
                new_image(photo.height-1-j, i, 0)=photo(i,j,0);
                new_image(photo.height-1-j, i, 1)=photo(i,j,1);
                new_image(photo.height-1-j, i, 2)=photo(i,j,2);
            }
        }
        photo=new_image;
    }
    else if (angle==270) {
        Image new_image(photo.height,photo.width);
        for(int i=0;i<photo.width;i++) {
            for (int j=0;j<photo.height;j++) {
                new_image(j, photo.width-1-i, 0)=photo(i,j,0);
                new_image(j, photo.width-1-i, 1)=photo(i,j,1);
                new_image(j, photo.width-1-i ,2)=photo(i,j,2);
            }
        }
        photo=new_image;
    }
    else {
        cout<<"wrong angle of rotation"<<endl;
    }
}
//***/ /***//*** //***//* **//* **
void resize(Image &photo)
{
    int newWidth, newHeight;

    cout << "Enter new Width: ";
    cin >> newWidth;

    cout << "Enter new Height: ";
    cin >> newHeight;

    Image newImage(newWidth, newHeight);

    for (int y = 0; y < newHeight; y++)
    {
        for (int x = 0; x < newWidth; x++)
        {
            int oldX = x * photo.width / newWidth;
            int oldY = y * photo.height / newHeight;

            for (int color = 0; color < 3; color++)
            {
                newImage(x, y, color) = photo(oldX, oldY, color);
            }
        }
    }

    photo = newImage;
}
//***/ /***//*** //***//* **//* **
void crop_image(Image &photo){
    int widthstartingpoint,hieghtstartingpoint,newwidth,newheight;
    cout<<"Please Enter Width Starting Point"<<endl;
    cin>>widthstartingpoint;
    cout<<"Please Enter Height Startting Point"<<endl;
    cin>>hieghtstartingpoint;
    cout<<"Please Enter New Width :"<<endl;
    cin>>newwidth;
    cout<<"Please Enter New Height :"<<endl;
    cin>>newheight;
   Image new_photo(newwidth,newheight);
    for(int i=0;i<new_photo.width;i++){
        for(int j=0;j<new_photo.height;j++){
            for(int k=0;k<3;k++){
             new_photo(i,j,k) =photo(widthstartingpoint+i,hieghtstartingpoint+j,k);
            }
        }
    }
    photo=new_photo;

}
//***/ /***//*** //***//* **//* **
void purple_filter( Image &photo){
    for(int i=0;i<photo.width;i++){
        for(int j=0;j<photo.height;j++){
            int red,green,blue;
            red=photo(i,j,0);
            green=photo(i,j,1);
            blue=photo(i,j,2);
            green =0;
            int new_red=red * 1.2;
            int new_blue=blue * 1.2;
            if(new_red>255){new_red=255;}
            if(new_blue>255){new_blue=255;}
            photo(i,j,0)=new_red;
            photo(i,j,1)=0;
            photo(i,j,2)=new_blue;
        }
    }
}
//***/ /***//*** //***//* **//* **
void merge(Image &photo){
    string filename2;
    cout<<"Please Enter Another File Name With Extention"<<endl;
    cin>>filename2;
    Image photo2(filename2);
    if(photo.width == photo2.width && photo.height==photo2.height){
        Image mergedphoto(photo.width,photo.height);
        for(int i=0;i<photo.width;i++){
            for(int j=0;j<photo.height;j++){
                 for(int k=0;k<3;k++){
                   mergedphoto(i,j,k)=(photo(i,j,k)+photo2(i,j,k))/2;
                 }
            }
        }
        mergedphoto.saveImage("merged.jpg");
    }
    else{
        int option;
        do{
        cout<<"The Two Image Has Different Sizes, Please Choose:"<<endl;
        cout<<"1.Resize to The Maximum Image and Merge"<<endl;
        cout<<"2. Merge The Common Area"<<endl;
        cin>>option;
        }while(option != 1 && option!=2);
        if(option == 1){
           int max_width,max_height;
           max_width=max(photo.width,photo2.width);
           max_height=max(photo.height,photo2.height);
           Image mergedphoto(max_width,max_height);
              for(int i=0;i<mergedphoto.width;i++){
              for(int j=0;j<mergedphoto.height;j++){
                 for(int k=0;k<3;k++){
                 if(i<photo.width && j<photo.height && i<photo2.width && j<photo2.height){
                   mergedphoto(i,j,k)=(photo(i,j,k)+photo2(i,j,k))/2;
                 }
                 else if(i<photo.width && j<photo.height){
                  mergedphoto(i,j,k)=photo(i,j,k);
                 }
                 else{
                    mergedphoto(i,j,k)=photo2(i,j,k);
                 }
                 }
            }
        }
          mergedphoto.saveImage("merged.jpg");
        }
        else if(option==2){
            int min_width,min_height;
            min_width=min(photo.width,photo2.width);
            min_height=min(photo.height,photo2.height);
            Image mergedphoto(min_width,min_height);
              for(int i=0;i<mergedphoto.width;i++){
              for(int j=0;j<mergedphoto.height;j++){
                 for(int k=0;k<3;k++){
                   mergedphoto(i,j,k)=(photo(i,j,k)+photo2(i,j,k))/2;
                 }
            }
        }
          mergedphoto.saveImage("merged.jpg");
        }
        
    }
  
}
//***/ /***//*** //***//* **//* **
int main(){
     cout<<"Please Enter File Name With Extention : "<<endl; 
    string fileName;
    cin>>fileName;
    Image photo (fileName);
    int number;
   do{
     menu();
    cin>>number;
      if(cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Please Enter Number From 1 To 8";
        continue;
    }
    if(number ==0 ){
        cout<<"Exited Program ";
        break;   
    }
    if(1 <= number && number <= 15){
        switch (number){
            case 1:
                grayscale(photo);
            break;
            case 2:  
                blackandwhite_filter(photo);
                
            break;
            case 3:
                invert(photo);
               
            break;
            case 4:
                frame(photo);
                
            break;
            case 5:
                {
                    int flip_filter;
                cout<<"Enter 1 for vertical flip And 0 for horizontal flip"<<endl;
                cin>> flip_filter;
                while(flip_filter != 0 && flip_filter != 1){
                    cout<<"Enter 1 for vertical flip And 0 for horizontal flip"<<endl;
                    cin>>flip_filter;
                }
                if(flip_filter == 0){
                    horizontal(photo);
                    
                }
                else if(flip_filter == 1){
                    vertical(photo);
                    
                }
                }

            break;
            case 6: 
               {
                 int angle;
                cout<<"Enter The Angle of The Rotation "<<endl;
                cin>>angle;
                rotate_filter(photo, angle);
                
               }
            break;
            case 7:
               {
                 int filter,brightnessvalue;
                cout<<"Enter 1 for Darken And 0 For lighten"<<endl;
                cin>>filter;
                while(filter !=0 && filter != 1){
                    cout<<"Enter 1 for Darken And 0 For lighten"<<endl;
                    cin>>filter;
                }
                cout<<"Enter Brightness Value: "<<endl;
                cin>>brightnessvalue;
                if(brightnessvalue <0 || brightnessvalue>255){
                    cout<<"Precentage Not Valid ,Please Enter Valid Brightness Value :"<<endl;
                }else{

                   if(filter==0){

                    light(photo,brightnessvalue);
                    
                }
                else if(filter==1){
                    dark(photo,brightnessvalue);
                   
                }
                }
                
               }
            break;
            case 8:
                resize(photo);
                
            break;
            case 9:
            merge(photo);  
            break;
            case 10:

            break;
            case 11:
            crop_image(photo);
            break;
            case 12:

            break;
            case 13:

            break;
            case 14:

            break;
            case 15:
         purple_filter(photo);
            break;
            case 16:

            break;

        }
        photo.saveImage(fileName);
         cout<<"__________________________________________"<<endl;
        cout<<"Editing Done Successfully!"<<endl;
        cout<<"___________________________________________"<<endl;
    }
    else if(number == 16){
        cout<<"Enter 1 To Save Current Image And Any Number to Discard It "<<endl;
        int answer;
        cin>>answer;
        if(answer == 1 ){
            photo.saveImage(fileName);
            cout<<"__________________________________________"<<endl;
            cout<<"Photo Saved Successfully"<<endl;
            cout<<"__________________________________________"<<endl;
        }
        else{
            cout<<"__________________________________________"<<endl;
            cout<<"Photo Edits Discarded"<<endl;
            cout<<"__________________________________________"<<endl;
        }
         cout<<"Enter New File Name With Extention"<<endl;
            string newfile;
            cin>>newfile;
            photo = Image(newfile);
            fileName = newfile;
            cout<<"Photo Uploded Successfully"<<endl;
            cout<<"__________________________________________"<<endl;

    }
    else{
        cout<<"Number Invalid";
    }
   }while(number != 0);

}
