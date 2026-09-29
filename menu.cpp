<<<<<<< HEAD
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

=======
#include<iostream>
#include"Image_Class.h"
using namespace std;
>>>>>>> 0d030f3c105664e62ec68af6ea6b3df0ce32bdbf
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
<<<<<<< HEAD
    cout<<"Enter 0 to Exit "<<endl;
=======
>>>>>>> 0d030f3c105664e62ec68af6ea6b3df0ce32bdbf
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

void invert(Image &photo){
    for (int i=0;i<photo.width;++i){
        for(int j=0;j<photo.height;++j){
            for(int k=0;k<photo.channels;++k){
                photo(i,j,k)=255 - photo(i,j,k);
            }
        }
    }
}
void GetRGB(int Color, int& R, int& G, int& B)
{
    if (Color == 1){R = 255; G = 255; B = 255;}
    else if (Color == 2){R = 0; G = 0; B = 0;}
    else if (Color == 3){R = 255; G = 0; B = 0;}
    else if (Color == 4){R = 0; G = 255; B = 0;}
    else if (Color == 5){R = 0; G = 0; B = 255;}
}

void ChooseColor()
{
    cout << "1. White" << endl;
    cout << "2. Black" << endl;
    cout << "3. Red" << endl;
    cout << "4. Green" << endl;
    cout << "5. Blue" << endl;
}

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

<<<<<<< HEAD
void light(Image &photo,int percentage){
    for (int i=0;i<photo.width;++i){
        for(int j=0;j<photo.height;++j){
            for(int k=0;k<photo.channels;++k){
                int value = photo(i,j,k);
                if(value + percentage>255){
                    photo(i,j,k)=255;
                }
                else{
                    photo(i,j,k)= value + percentage;
=======
void light(Image &photo,int precentage){
    for (int i=0;i<photo.width;++i){
        for(int j=0;j<photo.height;++j){
            for(int k=0;k<photo.channels;++k){
                if(photo(i,j,k)+precentage >255){
                    photo(i,j,k)=255;
                }
                else{
                    photo(i,j,k)+=precentage;
>>>>>>> 0d030f3c105664e62ec68af6ea6b3df0ce32bdbf
                }
            }
        }
    }
}

<<<<<<< HEAD
void dark(Image &photo,int percentage){
    for (int i=0;i<photo.width;++i){
        for(int j=0;j<photo.height;++j){
            for(int k=0;k<photo.channels;++k){
                int value1 = photo(i,j,k);
                if(value1 - percentage <0){
                  
                    photo(i,j,k)=0;
                }
                else{
                    photo(i,j,k)=value1 - percentage;
=======
void dark(Image &photo,int precentage){
    for (int i=0;i<photo.width;++i){
        for(int j=0;j<photo.height;++j){
            for(int k=0;k<photo.channels;++k){
                if(photo(i,j,k)-precentage <0){
                    photo(i,j,k)=0;
                }
                else{
                    photo(i,j,k)-=precentage;
>>>>>>> 0d030f3c105664e62ec68af6ea6b3df0ce32bdbf
                }
            }
        }
    }
}
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

int main(){
<<<<<<< HEAD
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
=======
    menu();
    int number;
    cin>>number;
    cout<<"Please Enter File Name With Extention : "<<endl; 
    string fileName;
    cin>>fileName;
    Image photo (fileName);
    
>>>>>>> 0d030f3c105664e62ec68af6ea6b3df0ce32bdbf
    if(1 <= number && number <= 8){
        switch (number){
            case 1:
                grayscale(photo);
<<<<<<< HEAD
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
=======
                photo.saveImage(fileName);
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
                frame(photo);
                photo.saveImage(fileName);
            break;
            case 5:
                int flip_filter;
>>>>>>> 0d030f3c105664e62ec68af6ea6b3df0ce32bdbf
                cout<<"Enter 1 for vertical flip And 0 for horizontal flip"<<endl;
                cin>> flip_filter;
                while(flip_filter != 0 && flip_filter != 1){
                    cout<<"Enter 1 for vertical flip And 0 for horizontal flip"<<endl;
                    cin>>flip_filter;
                }
                if(flip_filter == 0){
                    horizontal(photo);
<<<<<<< HEAD
                    
                }
                else if(flip_filter == 1){
                    vertical(photo);
                    
                }
=======
                    photo.saveImage(fileName);
                }
                else if(flip_filter == 1){
                    vertical(photo);
                    photo.saveImage(fileName);
>>>>>>> 0d030f3c105664e62ec68af6ea6b3df0ce32bdbf
                }

            break;
            case 6: 
<<<<<<< HEAD
               {
                 int angle;
                cout<<"Enter The Angle of The Rotation "<<endl;
                cin>>angle;
                rotate_filter(photo, angle);
                
               }
            break;
            case 7:
               {
                 int filter,percentage;
=======
                int angle;
                cout<<"enter the angle of rotation"<<endl;
                cin>>angle;
                rotate_filter(photo, angle);
                photo.saveImage(fileName);
            break;
            case 7:
                int filter,precentage;
>>>>>>> 0d030f3c105664e62ec68af6ea6b3df0ce32bdbf
                cout<<"Enter 1 for Darken And 0 For lighten"<<endl;
                cin>>filter;
                while(filter !=0 && filter != 1){
                    cout<<"Enter 1 for Darken And 0 For lighten"<<endl;
                    cin>>filter;
                }
                cout<<"Enter Percentage: "<<endl;
<<<<<<< HEAD
                cin>>percentage;
                if(percentage <0 || percentage>255){
                    cout<<"Precentage Not Valid ,Please Enter Valid Percentage :"<<endl;
                }else{

                   if(filter==0){

                    light(photo,percentage);
                    
                }
                else if(filter==1){
                    dark(photo,percentage);
                   
                }
                }
                
               }
            break;
            case 8:
                resize(photo);
                
            break;
        }
         photo.saveImage(fileName);
        cout<<"Editing Done Successfully!"<<endl;
    }
    else{
        cout<<"Number Invalid";
    }
   }while(number != 0);

}
=======
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
                resize(photo);
                photo.saveImage(fileName);
            break;
        }
    }
    else{
        menu();
    }
}
>>>>>>> 0d030f3c105664e62ec68af6ea6b3df0ce32bdbf
