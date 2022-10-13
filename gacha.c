#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int number_of_seconds){
int milli_seconds = 1000 * number_of_seconds;
clock_t start_time = clock();
while (clock() < start_time + milli_seconds) ;
}

int random_manny();
void random_character(int);

    char character3star[][40] = { //รายชื่อตัวละคร 3 ดาว
        "uiop" , "puy" , "ak456"
    };
    char character2star[][40] = { //รายชื่อตัวละคร 2 ดาว
        "avsrpo" , "numasdffd" , "nuwqtt" , "nur8mbe5" ,"touy"
    };
    char character1star[][40] = { //รายชื่อตัวละคร 1 ดาว
        "asd" , "sdqw" , "qdfas" , "qdfvoi" ,"jam" , "muten" , "resd" ,"oiuhj"
    };

int main(){
    int quantity , menu = 1;
        do{
            switch(menu){
            case 1 :
                system("cls");
                quantity =0;
                quantity = random_manny(); //จำนวนการสุ่ม 
                printf("--------------------------------\n");
                random_character(quantity);//สุ่มตัวละคร
                printf("agin? yes in number 1 or no in number 2 : ");
                scanf("%d" ,&menu);
                break ;
            case 2 :
                break ;
            default :
                printf("please enter 1 or 2 : ");
                scanf("%d" ,&menu);
                break ;
            }
        } while (menu != 2);
    return 0;
}

int random_manny(){ // ฟังก์ชัน หาจำนวนการสุ่ม
    int number ,i=1;
        printf("--------------------------------\n");
        printf("How many times random : "); //สุ่มกี่ครั้ง
        scanf("%d" ,&number); //ใส่เลขจำนวณการสุ่ม
            while(number <= 0){ //ลูปถ้าได้เท่ากับหรือต่ำกว่า 0
                system("cls");
                printf("(plase enter over 0)\n");
                printf("How many times random : "); 
                scanf("%d" ,&number);
            }
    return number ;
}

void random_character(int quantity){ // ฟังก์ชัน การสุ่ม
    int chance ; //โอกาส
    int guarantee2star=1 ,guarantee3star = 1; //ตัวการันตี
    srand (time (NULL)); //สุ่มไม่ซำ้กัน
        for(int count = 1 ; count <= quantity ; count++){ //เริ่มสุ่ม
        int numcharacter = 0; //คืนค่าจำนวนตัวละคร
            printf("%d. " ,count); //เรียงเลขจำนวณการสุ่ม
                if( guarantee3star == 30 ){ //การันตี 3 ดาว ทุก 30 ครั้ง ถ้าไม่ได้ 3 ดาวเลย
                    numcharacter = sizeof(character3star) / sizeof(character3star[0]);//หาจำนวนตัวละคร 3 ดาว
                    printf("*** %s" ,character3star[rand() % numcharacter]);
                    printf("   (guarantee 3 star !!)");
                    guarantee3star = 0 ; //เริ่มนับใหม่
                }else if(guarantee2star == 5){ //ทุก 5 ครั้งถ้าไม่ได้ 2 ดาว จะได้การันตี 2 ดาว
                    numcharacter = sizeof(character2star) / sizeof(character2star[0]);//หาจำนวนตัวละคร 2 ดาว
                    printf("**  %s" ,character2star[rand() % numcharacter]);
                    printf("   (guarantee 2 star !!)");
                    guarantee2star = 0;
                }else{
                    chance = rand() % 100 ; //สุ่ม 0-99
                        if (chance >= 0 && chance < 6)
                        {    // 3 ดาว โอกาส 5%
                            numcharacter = sizeof(character3star) / sizeof(character3star[0]); //หาจำนวนตัวละคร 3 ดาว
                            printf("*** %s" ,character3star[rand() % numcharacter]);
                            guarantee3star = 0 ;
                        }if (chance >= 6 && chance < 41)
                        {  // 2 ดาว โอกาส 35 %
                            numcharacter = sizeof(character2star) / sizeof(character2star[0]); //หาจำนวนตัวละคร 2 ดาว
                            printf("**  %s" ,character2star[rand() % numcharacter]);
                            guarantee2star = 0 ;
                        }if (chance >= 41 && chance < 100)
                        { // 1 ดาว โอกาส 60 %
                            numcharacter = sizeof(character1star) / sizeof(character1star[0]); //หาจำนวนตัวละคร 1 ดาว
                            printf("*   %s" ,character1star[rand() % numcharacter]);
                        }
                }
            printf("\n");
            guarantee3star++ ; //1-30
            guarantee2star++ ; //1-5 แรก
            delay(1);
        }
    printf("--------------------------------\n");
}