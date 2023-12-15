//---------------State-machine with all states and u-art ------------------//

#include <Servo.h>

//-----------define start position of each servo:-------------------

int pos_servo_rotate = 90;
int pos_servo_bund = 0;
int pos_servo_midt = 180;
int pos_servo_top = 90;


// --------------Define Servos connections:---------------------
Servo servo_rotate;
Servo servo_bund;
Servo servo_midt;
Servo servo_top;
//-----------Define variables for uart communication ------------------------
const int COMMUNICATION = 88;
const int WAKEUP = 1;
const int START= 2;
const int ROT1 =3;
const int ROT2 =4; 
const int ROT3 =5; 
const int ROT4 =6;
const int ROT5 =7;
const int ROT6 =8;
const int ROT7 =98;
const int ROT8 =10;
const int BUND1 =9; 
const int BUND2 =12;
const int BUND3 =13;
const int BUND4 =14;
const int TOP1 =15;
const int TOP2 =16;
const int DONE =11;
nn
//-------------------STRUCTS for statemachine----------------- 
  
  enum States{ 
    STATE_RESET,   
    STATE_INIT,
    STATE_IDLE,
    STATE_SERVO_ROT_1,
    STATE_SERVO_ROT_2,
    STATE_SERVO_ROT_3,
    STATE_SERVO_ROT_4,
    STATE_SERVO_ROT_5,
    STATE_SERVO_ROT_6,
    STATE_SERVO_ROT_7,
    STATE_SERVO_ROT_8,
    STATE_SERVO_BUND_MIDT_1,
    STATE_SERVO_BUND_MIDT_2,
    STATE_SERVO_BUND_MIDT_3,
    STATE_SERVO_BUND_MIDT_4,
    STATE_SERVO_TOP_1,
    STATE_SERVO_TOP_2,
    STATE_DONE,
};

struct overhead_module_t
{
  States state;
  bool goSignal; //change to bool
};

#define OVERHEAD_MODULE_RESET_STATE {.state = STATE_RESET, .goSignal = false}
static overhead_module_t overhead_module = OVERHEAD_MODULE_RESET_STATE;



        //-----------FUNCTION DEFINITIONS-----------//

//Statemachine functions  
void state_idle(void);
void state_init(void);
void state_movement_servo_rotate(void); 
void state_movement_servo_bund(void);
void state_movement_servo_midt(void);
void state_movement_servo_top(void);
void overhead_module_reset(void); 
void state_wait_for_goSignal(void); 
void state_operation_done(void);
void overhead_module_event(States state); 
void state_done(void);


        //------------setup--------------//

void setup() {
  
  Serial.begin(9600);
  //Serial.write(COMMUNICATION); //TEST-KAN SLETTES EFTER 
  
  servo_rotate.attach(7);
  servo_bund.attach(8);
  servo_midt.attach(10);
  servo_top.attach(9);


  servo_rotate.write(pos_servo_rotate);
  delay(100);
  servo_bund.write(pos_servo_bund);
  delay(100);
  servo_midt.write(pos_servo_midt);
  delay(100);
  servo_top.write(pos_servo_top);

  Serial.write(COMMUNICATION);
}

void loop() {
  
//---------------UART COMMUNICATION-------------------------//
if (Serial.available()) {
  char data_rcvd = Serial.read();

  switch (data_rcvd) {
    case START:
      break;
    case ROT1:
    case ROT2:
    case ROT3:
    case ROT4:
    case ROT5:
    case ROT6:
    case ROT7:
    case ROT8:
      overhead_module.goSignal = true;
      break;
    case BUND1:
    case BUND2:
    case BUND3:
    case BUND4:
      break;
    case TOP1:
    case TOP2:
      break;
    case DONE:
      break;
    default:
      return;  // Ignore unknown commands
  }

  overhead_module.state = static_cast<States>(data_rcvd);
  delay(2000);
  Serial.write(data_rcvd);
  overhead_module_event(overhead_module.state);
}
}

// -----------------ALL STATEMACHINE FUNCTIONS--------------------

void state_init(void){  
    Serial.write(111);
  //Move servo's to start opsition
  //check communication
    Serial.write(111);
  //SEND CHECK VALUE BEFORE AND AFTER INSTRUCTION
  //----------------------------------------------    
}

void state_idle(void){
//DENNE SKAL IKKE INDEHOLDE NOGET MEN BARE VENTE


}

void state_movement_servo_rotate_1(void){
//MOVE SERVO
  //servo_rotate.write(-------);
  servo_rotate.write(90);
  Serial.write(10);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_rotate_2(void){
//MOVE SERVO
  servo_rotate.write(110);
  Serial.write(20);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_rotate_3(void){
//MOVE SERVO
  servo_rotate.write(130);
  Serial.write(30);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_rotate_4(void){
//MOVE SERVO
  servo_rotate.write(150);
  Serial.write(40);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_rotate_5(void){
//MOVE SERVO
  servo_rotate.write(10);
  Serial.write(50);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_rotate_6(void){
//MOVE SERVO
  servo_rotate.write(30);
  Serial.write(60);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_rotate_7(void){
//MOVE SERVO
  //servo_rotate.write(--------);
  servo_rotate.write(50);
  Serial.write(70);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_rotate_8(void){
//MOVE SERVO
  //servo_rotate.write(--------);
  servo_rotate.write(70);
  Serial.write(80);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_bund_1(void){
//MOVE SERVO
  //servo_bund.write(-------);
  servo_bund.write(70);
  Serial.write(11);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_bund_2(void){
//MOVE SERVO
  //servo_bund.write(-------);
  servo_bund.write(90);
  Serial.write(12);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_bund_3(void){
//MOVE SERVO
  servo_bund.write(135);
  Serial.write(13);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_bund_4(void){
//MOVE SERVO
  servo_bund.write(150);
  Serial.write(14);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_midt_1(void){
//MOVE SERVO
  servo_midt.write(135);
  Serial.write(15);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_midt_2(void){
//MOVE SERVO
  servo_midt.write(90);
  Serial.write(16);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_midt_3(void){
//MOVE SERVO
  servo_midt.write(45);
  Serial.write(17);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_midt_4(void){
//MOVE SERVO
  servo_midt.write(10);
  Serial.write(18);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_top_1(void){
//MOVE SERVO
  servo_top.write(135);
  Serial.write(19);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_movement_servo_top_2(void){
//MOVE SERVO
  servo_top.write(45);
  Serial.write(20);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}

void state_done(void){
  servo_bund.write(pos_servo_bund);
  delay(100);
  servo_midt.write(pos_servo_midt);
  delay(100);
  servo_top.write(pos_servo_top);
  delay(100);
   servo_rotate.write(pos_servo_rotate);
  Serial.write(30);
  overhead_module.state = STATE_IDLE;
  overhead_module.goSignal = false;
}


//------------CASES PART---------------

void overhead_module_event(States state)
{
  switch (state)
  {
    case STATE_INIT:
    {
      state_init();
      break;
    }
    case STATE_IDLE:
    {
      state_idle();
      break;
    }

  //---------------ROTATE PART----------------------   
    case STATE_SERVO_ROT_1:
    {
      state_movement_servo_rotate_1();
      break;
    }
    case STATE_SERVO_ROT_2:
    {
      state_movement_servo_rotate_2();
      break;
    }
    case STATE_SERVO_ROT_3:
    {
      state_movement_servo_rotate_3();
      break;
    }
     case STATE_SERVO_ROT_4:
    {
      state_movement_servo_rotate_4();
      break;
    }
     case STATE_SERVO_ROT_5:
    {
      state_movement_servo_rotate_5();
      break;
    }
    case STATE_SERVO_ROT_6:
    {
      state_movement_servo_rotate_6();
      break;
    }
    case STATE_SERVO_ROT_7:
    {
      state_movement_servo_rotate_7();
      break;
    }
    case STATE_SERVO_ROT_8:
    {
      state_movement_servo_rotate_8();
      break;
    }

 //---------------BUND&MIDT PART-----------------------    
    case STATE_SERVO_BUND_MIDT_1:
    {
      state_movement_servo_bund_1();
      state_movement_servo_midt_1();
      break;
    }
     case STATE_SERVO_BUND_MIDT_2:
    {
      state_movement_servo_bund_2();
      state_movement_servo_midt_2();
      break;
    }
     case STATE_SERVO_BUND_MIDT_3:
    {
      state_movement_servo_bund_3();
      state_movement_servo_midt_3();
      break;
    }
    case STATE_SERVO_BUND_MIDT_4:
    {
      state_movement_servo_bund_4();
      state_movement_servo_midt_4();
      break;
    }
//---------------------TOP SERVO PART------------------------- -    
    case STATE_SERVO_TOP_1:
    {
      state_movement_servo_top_1();
      break;
    }
      case STATE_SERVO_TOP_2:
    {
      state_movement_servo_top_2();
      break;
    }

    //--------------------OPEN/CLOSE PART----------------------- 


    case STATE_DONE:
    {
      state_done();
      break;
    }
    
    default:
    {
      //Do nothing
      break;
    }
  }
}
