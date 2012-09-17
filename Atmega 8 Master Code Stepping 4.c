#include <mega8.h>
// Standard Input/Output functions
#include <stdio.h>
#include <delay.h>

// Declare your global variables here
    char b1,b2,b3,b4,b5,b6,b7;

void kirim_cm510(int a){
    b1 = 0xff;
    b2 = 0x55;
    b3 = a%256;
    b4 = b1-b3;
    b5 = a/256;
    b6 = b1-b5;
    
    printf("%c%c%c%c%c%c",b1,b2,b3,b4,b5,b6);
}

void baca_cm510(){
        b1=getchar();
        b2=getchar();
        b3=getchar();
        b4=getchar();
        b5=getchar();
        b6=getchar();
        }
        
int baca_cm510_modif(){
        b7=1;
        while(b7!=0){
        b1=getchar();
        while(b1==0xFE){
        b2=getchar();
        while(b2==0x66){
        b3=getchar();
        while(b3==0x66){
        b4=getchar();
        b5=getchar();
        b6=getchar();
        while(b6==0x00){
        b7=getchar();
        if (b7==0xFE)
        {b7=0;
        return 0;
        }        
        }
        }
        }
        }
        }
}

int baca_cm510_new(){
b1=getchar();
if(b1==0xFE){
b2=getchar();
if(b2==0x66){
b3=getchar();
if(b3==0x66){
b4=getchar();
b5=getchar();
if(b4==0x00&&b5==0xFE){
return 0;
}
b6=getchar();
if(b5==0x00&&b6==0xFE){
return 0;
}
b7=getchar();
if(b6==0x00&&b7==0xFE){
return 1;
}
else{
return 0;
}
}
else{
return 0;}
}
else{
return 0;}
}
else{
return 0;}
}


int rev(int a){

    return -a;
}
   
void gs_ns_kanan(int degree1)
{      
   int a = 1037 + degree1*622.0/90.0;
   
    OCR1A = a;
}

void gs_ns_kiri(int degree1)
{      
   int a = 1037 + degree1*622.0/90.0;
   
    OCR1B = a;
}

void gs_ns_sama(int degree1)
{      
   int a = 1037 + degree1*622.0/90.0;
   
    OCR1A = a;
    OCR1B = a;
}

void gs_ns_beda(int degree1)
{      
   int a = 1037 + degree1*622.0/90.0;
   int b = 1037 + rev(degree1)*622.0/90.0;   
    
    OCR1A = a;
    OCR1B = b;
}

void gs_s_kanan(int degree1, int degree2, int inc)
{      
   int x = 1037 + degree1*622.0/90.0;
   int z = 1037 + degree2*622.0/90.0;           
   
    while(x < z)
    {
     
    x= x+inc;
    OCR1A = x;
    delay_ms(10);
    }
    
    while(z < x)
    {
     
    x= x-inc;
    OCR1A = x;
    delay_ms(10);
    }   
    
}

void gs_s_kiri(int degree1, int degree2, int inc)
{      
   int x = 1037 + degree1*622.0/90.0;
   int z = 1037 + degree2*622.0/90.0;           
   
    while(x < z)
    {
     
    x= x+inc;
    OCR1B = x;
    delay_ms(10);
    }
    
    while(z < x)
    {
     
    x= x-inc;
    OCR1B = x;
    delay_ms(10);
    }   
    
}

void gs_s_beda(int degree1, int degree2, int inc)
{  int w = 0;
   int z = 0;
   int x = 0;
   int y = 0;
   
   if(degree2 >= 0){
        if (degree1 > degree2) {
            w = 1037 + degree2*622.0/90.0;
            z = 1037 + degree2*622.0/90.0;
            x = 1037 + degree1*622.0/90.0;
            y = 1037 + rev(degree1)*622.0/90.0; 
        }
        else if(degree1 < 0){
            w = 1037 + degree2*622.0/90.0;
            z = 1037 + degree2*622.0/90.0;
            x = 1037 + degree1*622.0/90.0;
            y = 1037 + rev(degree1)*622.0/90.0; 
        }                          
        else{
            w = 1037 + degree1*622.0/90.0;
            z = 1037 + degree1*622.0/90.0;
            x = 1037 + degree2*622.0/90.0;
            y = 1037 + rev(degree2)*622.0/90.0; 
        }           
   }
   else{
        w = 1037 + degree1*622.0/90.0;
        z = 1037 + degree1*622.0/90.0;
        x = 1037 + degree2*622.0/90.0;
        y = 1037 + rev(degree2)*622.0/90.0;   
   }
   
    while(x < z && y < w)
    {
        z= z-inc;
        w= w-inc;    
        OCR1A = z;
        OCR1B = w;
        delay_ms(10);              
    }
    
    
    while(z < x && w < y)
    {
        z= z+inc;
        w= w+inc;    
        OCR1A = z;
        OCR1B = w;
        delay_ms(10);      
    }
    
    while(z < x && y < w)
    {
        x= x-inc;
        y= y+inc;    
        OCR1A = x;
        OCR1B = y;
        delay_ms(10);
    }
    
    while(x < z && w < y)
    {
        x= x+inc;
        y= y-inc;    
        OCR1A = x;
        OCR1B = y;
        delay_ms(10);
    }
    
    
}

void gs_s_sama(int degree1, int degree2, int inc)
{      
   int x = 1037 + degree1*622.0/90.0;
   int z = 1037 + degree2*622.0/90.0;           
   
    while(x < z)
    {
     
    x= x+inc;
    OCR1A = x;
    OCR1B = x;
    delay_ms(10);
    }
    
    while(z < x)
    {
     
    x= x-inc;
    OCR1A = x;
    OCR1B = x;
    delay_ms(10);
    }
    
    
}

void tipe1(){

    gs_s_beda(0,60,5);
    delay_ms(10);
}

// gerakan tipe2, tangan kanan dan kiri berjalan berbeda arah, dari 0 sampai 60
void tipe2(){

    gs_s_sama(0,60,5);
    delay_ms(10);
}

// gerakan tipe3, tangan kanan bergerak dari 0 sampai 40, tangan kiri diam di 0
void tipe3(){

    gs_s_kanan(0,40,5);
    gs_ns_kiri(0);
    delay_ms(10);
}                

// gerakan tipe4, tangan kiri bergerak dari 0 sampai 40, tangan kanan diam di 0
void tipe4(){

    gs_s_kiri(0,40,5);
    gs_ns_kanan(0);
    delay_ms(10);
}
         
// gerakan tipe5, tangan kanan dan tangan kiri diam
void tipe5(){
    gs_ns_kanan(5);
    gs_ns_kiri(5);
    delay_ms(10);
}
// Tipe 6: tangan kiri -15 tangan kanan diem
void tipe6(){
    gs_ns_kanan(0);
    gs_ns_kiri(-15);
    delay_ms(10);
}
// Tipe 7: tangan kanan kiri 60,cocok buat gerakan jalan kalo tangan ngadep bawah
void tipe7(){
    gs_ns_beda(60);
    delay_ms(10);
}

//void sama(int degree1, int degree2, int inc)
//{      
//   int x = 1037 + degree1*622.0/90.0;
//   int z = 1037 + degree2*622.0/90.0;           
//   
//    while(x <= z)
//    {
//     
//    x= x+inc;
//    OCR1A = x;
//    OCR1B = x;
//    delay_ms(10);
//    }
//    
//    while(z <= x)
//    {
//     
//    x= x-inc;
//    OCR1A = x;
//    OCR1B = x;
//    delay_ms(10);
//    }
//    
//}
//
//int rev(int a){
//
//    return -a;
//}
//
//void beda(int degree1, int degree2, int inc)
//{  int w = 0;
//   int z = 0;
//   int x = 0;
//   int y = 0;
//   
//   if (degree1 > degree2) {
//    w = 1037 + degree2*622.0/90.0;
//    z = 1037 + degree2*622.0/90.0;
//    x = 1037 + degree1*622.0/90.0;
//    y = 1037 + rev(degree1)*622.0/90.0;
//   }                          
//   else{
//    w = 1037 + degree1*622.0/90.0;
//    z = 1037 + degree1*622.0/90.0;
//    x = 1037 + degree2*622.0/90.0;
//    y = 1037 + rev(degree2)*622.0/90.0;
//   }
//   
//    while(x <= z && y <= w)
//    {
//        z= z-inc;
//        w= w-inc;    
//        OCR1A = z;
//        OCR1B = w;
//        delay_ms(10);              
//    }
//    
//    
//    while(z <= x && w <= y)
//    {
//        z= z+inc;
//        w= w+inc;    
//        OCR1A = z;
//        OCR1B = w;
//        delay_ms(10);      
//    }
//    
//    while(z <= x && y <= w)
//    {
//        z= z+inc;
//        w= w-inc;    
//        OCR1A = z;
//        OCR1B = w;
//        delay_ms(10);
//    }
//    
//    while(x <= z && w <= y)
//    {
//        z= z-inc;
//        w= w+inc;    
//        OCR1A = z;
//        OCR1B = w;
//        delay_ms(10);
//    }
//    
//}

void main(void)
{
// Declare your local variables here
// Input/Output Ports initialization
// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=Out Func1=Out Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=0 State1=0 State0=T 
PORTB=0x00;
DDRB=0x06;

// Port C initialization
// Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0b00000001;
DDRC=0xff;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
TCCR0=0x00;
TCNT0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 1382,400 kHz
// Mode: Ph. correct PWM top=ICR1
// OC1A output: Non-Inv.
// OC1B output: Non-Inv.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0xA2;
TCCR1B=0x12;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x36;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer 2 Stopped
// Mode: Normal top=FFh
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
MCUCR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 115200
UCSRA=0x00;
UCSRB=0x18;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x05;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;
gs_ns_beda(30);
//printf("Starting!\n");
delay_ms(200);
while (1)
      {
//tipe7();
//PORTC.0=0;
//delay_ms(200);
//PORTC.0=1;
//tipe1();
//delay_ms(200);
baca_cm510_modif();
//int stat=0;
//while(stat==0){
//PORTC.0=1;
//stat=baca_cm510_new();
//}


if(b4==0x06&&b5==98){//5
//Servo diem di 10derajat
PORTC.0=0;
gs_ns_beda(10);
}

else if(b4==0x00&&b5==0x86){//6
//Servo dua-duanya gerak 35 derajat
PORTC.0=0;
gs_s_beda(0,60,5);
delay_ms(200);
}

else if(b4==0x00&&b5==0x80){//7
//Sero kanan gerak kiri 15drajat
gs_s_kanan(0,50,5);
gs_ns_kiri(30);
delay_ms(200);
}

else if(b4==0x80&&b5==0x7E){//8
//Sero kiri gerak 15derajat kanan diam
gs_s_kiri(0,50,5);
gs_ns_kanan(20);
delay_ms(200);
}
else if(b4==0x18&&b5==0x78){//9
//Sero kanan gerak kiri 15drajat
gs_ns_kiri(-20);
gs_s_kanan(0,50,5);
delay_ms(200);
}
else if(b4==0x06&&b5==0x66){//10
gs_ns_beda(0);
//PORTC.0=0;
//tipe2();
//delay_ms(200);
//PORTC.0=1;
//tipe2();
//delay_ms(200);
}
else if(b4==0x06&&b5==0x60){//11
gs_ns_kiri(-30);
gs_ns_kanan(0);
delay_ms(200);
}
else if(b4==0x80&&b5==0x1E){//12
gs_ns_kiri(0);
gs_ns_kanan(-30);
delay_ms(200);
}
else if(b4==0x1E&&b5==0x18){//13
gs_ns_beda(60);
delay_ms(200);
}
else if(b4==0x80&&b5==0x06){//14
tipe7();
delay_ms(200);
}
else if(b4==0x80&&b5==0x00){//15
tipe6();
delay_ms(200);
}
else if(b4==0x60&&b5==0xFE){//16
tipe6();
delay_ms(200);
}
else if(b4==0x66&&b5==0x98){//21

}
else if(b4==0x60&&b5==0xF8){//24

}
else if(b4==0x78&&b5==0x78){//25

}
else if(b4==0x1E&&b5==0x66){//26
gs_ns_beda(0);
}
else
{PORTC.0=0;
gs_ns_beda(40);
}

}



}


